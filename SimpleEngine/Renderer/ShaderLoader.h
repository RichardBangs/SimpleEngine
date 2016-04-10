#pragma once

#include "glew.h"

#include <iostream>
#include <vector>

namespace Renderer
{
	class ShaderLoader
	{
	public:
		static unsigned int ShaderLoader::CreateProgram(const char* vertexShaderRelativeFilename, const char* pixelShaderRelativeFilename);

		static void DestroyAllShaders();

	private:

		static std::vector<unsigned int> _programs;

		static std::string ReadShader(const char* filename);
		static unsigned int CreateShader(GLenum shaderType, const std::string source, const char* shaderName);
	};
}