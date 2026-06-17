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

#include "03_Adapter.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	std::cout << "### Adapter Pattern ###" << std::endl;

	FahrenheitDegree fahrenheit(100);
	Fahrenheit2Celsius converter;

	CelsiusDegree celsius(converter.Convert(fahrenheit.GetFahrenheit()));

	std::cout << "CelsiusDegree: " << celsius.GetCelsius() << std::endl;

	return 0;
}