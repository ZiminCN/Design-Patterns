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
#ifndef __05_COR_HPP__
#define __05_COR_HPP__

#include <iostream>
#include <string>

struct Creature {
	std::string name;
	int attack, defense;
};

class CreatureModifier
{
	CreatureModifier *next{nullptr};

      protected:
	Creature &creature; // pointer or shared_ptr

      public:
	explicit CreatureModifier(Creature &creature) : creature(creature)
	{
	}
	void add(CreatureModifier *cm)
	{
		if (next)
			next->add(cm);
		else
			next = cm;
	}

	virtual void handle()
	{
		std::cout << "Creature: " << creature.name << " attack: " << creature.attack
			  << " defense: " << creature.defense << std::endl;
		if (next)
			next->handle();
	}
};

class DoubleAttackBuff : public CreatureModifier
{
      public:
	explicit DoubleAttackBuff(Creature &creature) : CreatureModifier(creature)
	{
	}

	void handle() override
	{
		creature.attack *= 2;
		CreatureModifier::handle();
	}
};

class ModifiedAttackBuff : public CreatureModifier
{
      private:
	int value;

      public:
	explicit ModifiedAttackBuff(Creature &creature, int value)
		: CreatureModifier(creature), value(value)
	{
	}
	void handle() override
	{
		creature.attack += value;
		CreatureModifier::handle();
	}
};

class ModifiedDefenseBuff : public CreatureModifier
{
      private:
	int value;

      public:
	explicit ModifiedDefenseBuff(Creature &creature, int value)
		: CreatureModifier(creature), value(value)
	{
	}
	void handle() override
	{
		creature.defense += value;
		CreatureModifier::handle();
	}
};

class DisperseBuff : public CreatureModifier
{
      public:
	explicit DisperseBuff(Creature &creature) : CreatureModifier(creature)
	{
	}
	void handle() override
	{
		creature.attack = 0;
		creature.defense = 0;
		// do not call next->handle();
	}
};

#endif // __05_COR_HPP__