#pragma once
#include <iostream>
#include "Init_GLEW.h"
#include "WindowInfo.h"
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "IListener.h"
#include "DebugOutput.h"

namespace Core
{
	namespace Init
	{
		class Init_GLUT
		{
		public:
			static void init(	const Core::WindowInfo& window,
								const Core::ContextInfo& context,
								const Core::FramebufferInfo& framebufferInfo);
			static void run();
			static void close();

			void enterFullscreen();
			void exitFullscreen();

			static void printOpenGLInfo(const Core::WindowInfo& windowInfo,
										const Core::ContextInfo& context);
			
			static void setListener(Core::IListener*& iListener);
		private:
			static void idleCallback(void);
			static void displayCallback(void);
			static void reshapeCallback(int width, int height);
			static void closeCallback();
			static Core::IListener* listener;
			static Core::WindowInfo windowInformation;
		};
	}
}