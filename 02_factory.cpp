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

#include "02_factory.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	std::cout << "### Factory Pattern ###" << std::endl;

	AnimalFactory animalFactory;
	std::unique_ptr<AnimalBase> animal = animalFactory.createAnimal(ANIMAL_E::dog);
	std::string language = animal->speak();
	std::cout << "The animals says: " << language << std::endl;

	animal = animalFactory.createAnimal(ANIMAL_E::cat);
	language = animal->speak();
	std::cout << "The animals says: " << language << std::endl;

	animal = animalFactory.createAnimal(ANIMAL_E::bird);
	language = animal->speak();
	std::cout << "The animals says: " << language << std::endl;
	return 0;
}