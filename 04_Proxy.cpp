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

#include "04_proxy.hpp"

#include <iostream>

void draw_image(Image &img)
{
	std::cout << "About to draw the image" << std::endl;
	img.draw();
	std::cout << "Finished drawing the image" << std::endl;
}

int main(int argc, char **argv)
{
	std::cout << "### Proxy Pattern ###" << std::endl;

	ProxyBitmap proxy_bitmap{"pokemon.png"};
	draw_image(proxy_bitmap);

	return 0;
}