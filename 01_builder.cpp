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

#include "01_builder.hpp"

#include <iostream>

inline EmploymentBuilder PersonBuilderBase::works() const
{
	return EmploymentBuilder{person};
}

inline AddressBuilder PersonBuilderBase::lives() const
{
	return AddressBuilder{person};
}

int main(int argc, char **argv)
{
	std::cout << "### Builder Pattern ###" << std::endl;
	Person person = PersonBuilder()
				.lives()
				.at("kings street")
				.in("london")
				.of("England")
				.works()
				.at("Google")
				.in("Num 1 Main Street");

	std::cout << "person company: [" << person.company << "]" << std::endl;
	std::cout << "person position: [" << person.position << "]" << std::endl;
	std::cout << "person street: [" << person.street << "]" << std::endl;
	std::cout << "person city: [" << person.city << "]" << std::endl;
	std::cout << "person country: [" << person.country << "]" << std::endl;

	return 0;
}