#pragma once
#include <string>

namespace Core
{
	struct WindowInfo
	{
		std::string name;
		int width, height;
		int position_x, position_y;
		bool isReshapable;

		WindowInfo()
		{
			name = "OpenGL tutorial";
			width = 800; height = 600;
			position_x = 300;
			position_y = 300;
			isReshapable = true;
		}

		WindowInfo(	std::string name,
					int start_position_x, int start_position_y,
					int width, int height,
					bool is_reshapable)
		{
			this->name = name;
			this->width = width;
			this->height = height;
			this->isReshapable = is_reshapable;
			this->position_x = start_position_x;
			this->position_y = start_position_y;
		}
	};
}