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

#include "06_Mediator.hpp"

#include <iostream>

void Person::receive(const std::string &origin, const std::string &message)
{
	std::string s{origin + ": \"" + message + "\""};
	std::cout << "[" << name << "'s chat session] " << s << "]" << std::endl;
	chat_log.push_back(s);
}

void Person::say(const std::string &message) const
{
	this->room_uid->boardcast(name, message);
}

void Person::pm(const std::string &who, const std::string &message) const
{
	this->room_uid->message(name, who, message);
}

void ChatRoom::join(Person *person)
{
	std::string join_msg = person->name + " joins the chat room";
	boardcast("room_uid", join_msg);
	person->room_uid = this;
	this->people.push_back(person);
}

void ChatRoom::boardcast(const std::string &origin, const std::string &message)
{
	for (auto p : people) {
		if (p->name != origin) {
			p->receive(origin, message);
		}
	}
}

void ChatRoom::message(const std::string &origin, const std::string &who,
		       const std::string &message)
{
	auto target = std::find_if(people.begin(), people.end(),
				   [&](const Person *p) { return p->name == who; });
	if (target != end(people)) {
		(*target)->receive(origin, message);
	}
}

int main(int argc, char **argv)
{
	std::cout << "### Mediator Pattern ###" << std::endl;

	ChatRoom room;
	Person john("John");
	Person jane("Jane");

	room.join(&john);
	room.join(&jane);

	john.say("Hi room!");
	jane.say("oh, hi John!");

	Person simon("simon");
	room.join(&simon);
	simon.say("hi everyone!");

	jane.pm("simon", "glad you could join us, simon!");

	return 0;
}