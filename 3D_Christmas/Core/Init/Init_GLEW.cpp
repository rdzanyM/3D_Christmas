#include "Init_GLEW.h"

using namespace Core;
using namespace Core::Init;

void Init_GLEW::Init()
{
	glewExperimental = true;
	if (glewInit() == GLEW_OK)
	{
		std::cout << "GLEW: Initialize" << std::endl;
	}
	if (glewIsSupported("GL_VERSION_4_3"))
	{
		std::cout << "OpenGL version is 4.3\n";
	}
	else
	{
		std::cout << "OpenGL version 4.3 not supported\n";
	}
}