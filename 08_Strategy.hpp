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
#ifndef __08_STRATEGY_HPP__
#define __08_STRATEGY_HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

enum class OutputFormat {
	markdown,
	html
};

struct ListStrategy {
	virtual ~ListStrategy() = default;
	virtual void start(std::ostringstream& oss) {};
	virtual void add_list_item(std::ostringstream& oss, const std::string& item) {};
	virtual void end(std::ostringstream& oss) {};
};

struct HtmlListStrategy : ListStrategy
{
	void start(std::ostringstream& oss) override
	{
		oss << "<ul>\n";
	}

	void end(std::ostringstream& oss) override
	{
		oss << "</ul>\n";
	}

	void add_list_item(std::ostringstream& oss, const std::string& item) override
	{
		oss << "  <li>" << item << "</li>\n";
	}
};

struct MarkdownListStrategy : ListStrategy
{
	void add_list_item(std::ostringstream& oss, const std::string& item) override
	{
		oss << "* " << item << "\n";
	}
};

struct TextProcessor
{
	TextProcessor(OutputFormat fmt) : format(fmt) {
		set_output_format(fmt);
	}

	void set_output_format(const OutputFormat fmt)
	{
		this->format = fmt;
		switch(fmt)
		{
			case OutputFormat::markdown:
				list_strategy = std::make_unique<MarkdownListStrategy>();
				break;
			case OutputFormat::html:
				list_strategy = std::make_unique<HtmlListStrategy>();
				break;
		}
	}

	void append_list(const std::vector<std::string> items)
	{
		list_strategy->start(oss);
		for(auto& item : items)
		{
			list_strategy->add_list_item(oss, item);
		}
		list_strategy->end(oss);
	}

	void clear()
	{
		oss.str("");
		oss.clear();
	}

	std::string str() const { return oss.str(); }

private:
	OutputFormat format;
	std::ostringstream oss;
	std::unique_ptr<ListStrategy> list_strategy;
};

#endif // __08_STRATEGY_HPP__