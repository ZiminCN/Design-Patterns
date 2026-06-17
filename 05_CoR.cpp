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

#include "05_CoR.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	std::cout << "### Chain of Responsibility Pattern ###" << std::endl;

	Creature goblin{"Goblin", 1, 1};
	Creature vampire{"Vampire", 20, 20};

	CreatureModifier goblin_root{goblin};
	CreatureModifier vampire_root{vampire};

	ModifiedAttackBuff goblin_atk_buff{goblin, 10};
	ModifiedDefenseBuff goblin_def_buff{goblin, 10};
	DoubleAttackBuff goblin_double_atk_buff{goblin};

	DisperseBuff vampire_disperse_buff{vampire};

	goblin_root.add(&goblin_atk_buff);
	goblin_root.add(&goblin_def_buff);
	goblin_root.add(&goblin_double_atk_buff);

	vampire_root.add(&vampire_disperse_buff);

	goblin_root.handle();
	vampire_root.handle();

	return 0;
}