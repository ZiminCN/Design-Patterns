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
#ifndef __02_FACTORY_HPP__
#define __02_FACTORY_HPP__

#include <string>

enum class ANIMAL_E {
	dog = 0,
	cat,
	bird,
};

class AnimalBase
{
      public:
	virtual ~AnimalBase() = default;
	virtual std::string speak() = 0;
};

class Dog : public AnimalBase
{
      public:
	~Dog() = default;
	std::string speak() override
	{
		return "wang wang";
	}
};

class Cat : public AnimalBase
{
      public:
	~Cat() = default;
	std::string speak() override
	{
		return "miao miao";
	}
};

class Bird : public AnimalBase
{
      public:
	~Bird() = default;
	std::string speak() override
	{
		return "ji ji";
	}
};

class AnimalFactory
{
      public:
	static std::unique_ptr<AnimalBase> createAnimal(ANIMAL_E type)
	{
		switch (type) {
		case ANIMAL_E::dog:
			return std::make_unique<Dog>();
		case ANIMAL_E::cat:
			return std::make_unique<Cat>();
		case ANIMAL_E::bird:
			return std::make_unique<Bird>();
		}
		return {};
	}
};

#endif // __02_FACTORY_HPP__
