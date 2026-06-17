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

#include "08_Strategy.hpp"

#include <iostream>

int main(int argc, char **argv)
{
      std::cout << "### Strategy Pattern ###" << std::endl;

      // Markdown 格式
      TextProcessor tp{OutputFormat::markdown};
      tp.append_list({"foo", "bar", "baz"});
      std::cout << tp.str() << std::endl;

      // HTML 格式
      TextProcessor tp2{OutputFormat::html};
      tp2.append_list({"foo", "bar", "baz"});
      std::cout << tp2.str() << std::endl;

      tp.clear();
      tp.set_output_format(OutputFormat::html);
      tp.append_list({"foo", "bar", "baz"});
      std::cout << tp.str() << std::endl;

      tp2.clear();
      tp2.set_output_format(OutputFormat::markdown);
      tp2.append_list({"foo", "bar", "baz"});
      std::cout << tp2.str() << std::endl;

      return 0;
}