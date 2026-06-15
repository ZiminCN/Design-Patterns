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

#include <string>

class Person
{
      public:
	std::string company, position;
	std::string street, city, country;
	Person()
	{
	}
};

class EmploymentBuilder; // 前向声明
class AddressBuilder;	 // 前向声明

class PersonBuilderBase
{
      protected:
	Person &person;
	explicit PersonBuilderBase(Person &person) : person(person)
	{
	}

      public:
	operator Person()
	{
		return std::move(person);
	}
	EmploymentBuilder works() const;
	AddressBuilder lives() const;
};

class EmploymentBuilder : public PersonBuilderBase
{
	typedef EmploymentBuilder self;

      public:
	explicit EmploymentBuilder(Person &person) : PersonBuilderBase{person}
	{
	}
	self &at(const std::string &company)
	{
		person.company = company;
		return *this;
	}
	self &in(const std::string &position)
	{
		person.position = position;
		return *this;
	}
};

class AddressBuilder : public PersonBuilderBase
{
	typedef AddressBuilder self;

      public:
	explicit AddressBuilder(Person &person) : PersonBuilderBase{person}
	{
	}
	self &at(std::string street)
	{
		person.street = street;
		return *this;
	}
	self &in(std::string city)
	{
		person.city = city;
		return *this;
	}
	self &of(std::string country)
	{
		person.country = country;
		return *this;
	}
};

class PersonBuilder : public PersonBuilderBase
{
	Person person;

      public:
	PersonBuilder() : PersonBuilderBase{person}
	{
	}
};