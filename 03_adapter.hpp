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
#ifndef __03_ADAPTER_HPP__
#define __03_ADAPTER_HPP__

#include <string>

class FahrenheitDegree
{
	uint16_t fahrenheit;

      public:
	FahrenheitDegree(uint16_t fahrenheit) : fahrenheit(fahrenheit)
	{
	}
	uint16_t GetFahrenheit() const
	{
		return fahrenheit;
	}
};

class CelsiusDegree
{
	uint16_t celsius;

      public:
	CelsiusDegree(uint16_t celsius) : celsius(celsius)
	{
	}
	uint16_t GetCelsius() const
	{
		return celsius;
	}
};

template <typename TFrom, typename TTo> class Converter
{
      public:
	virtual TTo Convert(const TFrom &from) = 0;
	virtual TFrom ConvertBack(const TTo &to) = 0;
};

class Fahrenheit2Celsius : public Converter<FahrenheitDegree, CelsiusDegree>
{
      public:
	CelsiusDegree Convert(const FahrenheitDegree &from) override
	{
		return CelsiusDegree((from.GetFahrenheit() - 32) * 5 / 9);
	};

	FahrenheitDegree ConvertBack(const CelsiusDegree &to) override
	{
		return FahrenheitDegree(to.GetCelsius() * 9 / 5 + 32);
	};
};

#endif // __03_ADAPTER_HPP__