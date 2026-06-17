// Copyright (c) All rights reserved.
// Author: Zi Min <18171190533@163.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http:#www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#ifndef __07_OBSERVER_HPP__
#define __07_OBSERVER_HPP__

#include <iostream>
#include <mutex>
#include <string>
#include <vector>

template <typename T> struct Observer {
	virtual void field_changed(T &source, const std::string &field_name) = 0;
};

template <typename T> struct Observable {
	void notify(T &source, const std::string &name)
	{
		std::vector<std::shared_ptr<Observer<T>>> observers_snapshot;
		{
			std::scoped_lock<std::mutex> lock{mtx};
			for(auto it = weak_observers.begin(); it != weak_observers.end(); ++it){
				if(auto s_ptr = it->lock()){
					observers_snapshot.push_back(s_ptr);
				}else{
					weak_observers.erase(it);
				}
			}

		}

		for (auto obs : observers_snapshot) {
			obs->field_changed(source, name);
		}
	}
	void subscribe(std::shared_ptr<Observer<T>> ptr)
	{
		std::scoped_lock<std::mutex> lock{mtx};
		weak_observers.push_back(ptr);
	}
	void unsubscribe(std::shared_ptr<Observer<T>> ptr)
	{
		std::scoped_lock<std::mutex> lock{mtx};

		std::erase_if(weak_observers, [&](const std::weak_ptr<Observer<T>>& w) {
			auto sp = w.lock();
			// sp is not nullptr and sp is the same as ptr
			return (sp) && (sp == ptr);  // 比较指向的对象
		});
	}

      private:
	std::vector<std::weak_ptr<Observer<T>>> weak_observers;
	std::mutex mtx;
};

struct Person : Observable<Person> {
	int getAge()
	{
		return age;
	}
	void setAge(const int age)
	{
		if (this->age == age)
			return;
		this->age = age;
		notify(*this, "age");
	}
	Person(int age) : age(age)
	{
	}

      private:
	int age;
};

struct ConsolePersonObserver : Observer<Person> {
	void field_changed(Person &source, const std::string &field_name) override
	{
		if (field_name == "age") {
			std::cout << "Person's age has changed to " << source.getAge() << std::endl;
		}
	}
};

#endif // __07_OBSERVER_HPP__