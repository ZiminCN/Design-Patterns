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

#include <algorithm>
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
		std::scoped_lock<std::mutex> lock{mtx};
		for (auto obs : observers) {
			obs->field_changed(source, name);
		}
	}
	void subscribe(Observer<T> *f)
	{
		std::scoped_lock<std::mutex> lock{mtx};
		observers.push_back(f);
	}
	void unsubscribe(Observer<T> *f)
	{
		std::scoped_lock<std::mutex> lock{mtx};
		observers.erase(std::remove(observers.begin(), observers.end(), f),
				observers.end());
	}

      private:
	std::vector<Observer<T> *> observers;
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