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
#ifndef __06_MEDIATOR_HPP__
#define __06_MEDIATOR_HPP__

#include <iostream>
#include <string>
#include <vector>

struct ChatRoom;

struct Person {
	std::string name;
	ChatRoom *room_uid{nullptr};
	std::vector<std::string> chat_log;

	Person(const std::string &name) : name(name) {};

	void receive(const std::string &origin, const std::string &message);
	void say(const std::string &message) const;
	void pm(const std::string &who, const std::string &message) const;
};

struct ChatRoom {
	std::vector<Person *> people;
	void join(Person *person);
	void boardcast(const std::string &origin, const std::string &message);
	void message(const std::string &origin, const std::string &who, const std::string &message);
};

#endif // __06_MEDIATOR_HPP__