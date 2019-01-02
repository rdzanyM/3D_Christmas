#pragma once
#include "Core/Init/Init_GLUT.h"
#include "Managers/Scene_Manager.h"

using namespace Core;
using namespace Init;

int main(int argc, char **argv)
{
	WindowInfo window(	std::string("in2gpu OpenGL Beginner Tutorial "),
						400, 200,	//position
						800, 600,	//size
						true);		//reshape

	ContextInfo context(4, 3, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	Init_GLUT::init(window, context, frameBufferInfo);
	
	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::setListener(scene);
	
	Init_GLUT::run();

	delete scene;
	return 0;
}