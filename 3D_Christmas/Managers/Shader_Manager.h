#pragma once
#include "GL/glew.h"
#include "GL/freeglut.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

namespace Managers
{
	class Shader_Manager
	{
	public:

		Shader_Manager(void);
		~Shader_Manager(void);

		void CreateProgram(	const std::string& shaderName,
							const std::string& VertexShaderFilename,
							const std::string& FragmentShaderFilename);

		static const GLuint GetShader(const std::string&);

	private:
		GLuint CreateShader(GLenum shaderType,
							const std::string& source,
							const std::string& shaderName);
		
		std::string ReadShader(const std::string& filename);

		static std::map<std::string, GLuint> programs;
	};
}