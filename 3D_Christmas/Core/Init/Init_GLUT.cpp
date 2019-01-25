#include "Init_GLUT.h"

using namespace Core::Init;

Core::IListener* Init_GLUT::listener = NULL;
Core::WindowInfo Init_GLUT::windowInformation;

void Init_GLUT::init(	const Core::WindowInfo& windowInfo,
						const Core::ContextInfo& contextInfo,
						const Core::FramebufferInfo& framebufferInfo)
{
	int fakeargc = 1;
	char *fakeargv[] = { _strdup("fake"), NULL };
	glutInit(&fakeargc, fakeargv);

	if (contextInfo.core)
	{
		glutInitContextVersion(	contextInfo.major_version, contextInfo.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(framebufferInfo.flags);
	glutInitWindowSize(windowInfo.width, windowInfo.height);
	glutInitWindowPosition(	windowInfo.position_x, windowInfo.position_y);

	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT:initialized\n";
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_CULL_FACE);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);
	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	Init::Init_GLEW::Init();
	glDebugMessageCallback(DebugOutput::myCallback, NULL);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	printOpenGLInfo(windowInfo, contextInfo);
	windowInformation = windowInfo;
}

void Init_GLUT::run()
{
	std::cout << "GLUT:\t Start Running\n";
	glutMainLoop();
}

void Init_GLUT::close()
{
	std::cout << "GLUT:\t Finished\n";
	glutLeaveMainLoop();
}

void Init_GLUT::idleCallback(void)
{
	glutPostRedisplay();
}

void Init_GLUT::displayCallback()
{
	if (listener)
	{
		listener->notifyBeginFrame();
		listener->notifyDisplayFrame();
		glutSwapBuffers();
		listener->notifyEndFrame();
	}
}

void Init_GLUT::reshapeCallback(int width, int height)
{
	if (windowInformation.isReshapable == true)
	{
		if (listener)
		{
			listener->notifyReshape(width, height,
									windowInformation.width,
									windowInformation.height);
		}
		windowInformation.width = width;
		windowInformation.height = height;
		glViewport(0, 0, width, height); // #reshape
	}
}

void Init_GLUT::closeCallback()
{
	close();
}

void Init_GLUT::enterFullscreen()
{
	glutFullScreen();
}

void Init_GLUT::exitFullscreen()
{
	glutLeaveFullScreen();
}

void Init_GLUT::printOpenGLInfo(const Core::WindowInfo& windowInfo,
								const Core::ContextInfo& contextInfo)
{
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);
	const unsigned char* renderer = glGetString(GL_RENDERER);

	std::cout << "**************************************************************\n";
	std::cout << "GLUT:Initialise\n";
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;
}

void Init_GLUT::setListener(Core::IListener*& iListener)
{
	listener = iListener;
}