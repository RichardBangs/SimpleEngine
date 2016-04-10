#include "ShaderLoader.h"

#include <fstream>
#include <vector>

#include "glut.h"

#include "../Path.h"

namespace Renderer
{
	//static
	std::vector<unsigned int> ShaderLoader::_programs;

	//static
	std::string ShaderLoader::ReadShader(const char* filename)
	{
		std::string shaderCode;
		std::ifstream file(filename, std::ios::in);

		if (!file.good())
		{
			std::cout << "Can't read file " << filename << std::endl;
			return "";
		}

		file.seekg(0, std::ios::end);
		shaderCode.resize((unsigned int)file.tellg());

		file.seekg(0, std::ios::beg);
		file.read(&shaderCode[0], shaderCode.size());
		file.close();
		
		return shaderCode;
	}

	//static
	unsigned int ShaderLoader::CreateShader(GLenum shaderType, const std::string source, const char* shaderName)
	{
		int compileResult = 0;

		unsigned int shaderHandle = glCreateShader(shaderType);

		const char* shaderCodePointer = source.c_str();
		const int shaderCodeSize = source.size();

		glShaderSource(shaderHandle, 1, &shaderCodePointer, &shaderCodeSize);
		glCompileShader(shaderHandle);
		glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileResult);

		if (compileResult == GL_FALSE)
		{
			int infoLength = 0;
			glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &infoLength);
			
			std::string info;
			info.resize(infoLength);

			glGetShaderInfoLog(shaderHandle, infoLength, NULL, &info[0]);

			std::cout << "ERROR compiling shader: " << shaderName << std::endl << info.c_str() << std::endl;

			return 0;
		}

		return shaderHandle;
	}

	//static
	unsigned int ShaderLoader::CreateProgram(const char* vertexShaderRelativeFilename, const char* pixelShaderRelativeFilename)
	{
		std::string vertexPath = Path::AbsolutePathRelativeToAssetsDirectory(vertexShaderRelativeFilename);
		std::string fragmentPath = Path::AbsolutePathRelativeToAssetsDirectory(pixelShaderRelativeFilename);

		std::string vertexShaderCode = ReadShader(vertexPath.c_str());
		std::string pixelShaderCode = ReadShader(fragmentPath.c_str());

		unsigned int vertexShader = CreateShader(GL_VERTEX_SHADER, vertexShaderCode, "vertex shader");
		unsigned int pixelShader = CreateShader(GL_FRAGMENT_SHADER, pixelShaderCode, "pixel shader");

		int linkResult = 0;

		unsigned int program = glCreateProgram();
		glAttachShader(program, vertexShader);
		glAttachShader(program, pixelShader);

		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &linkResult);

		if (linkResult == GL_FALSE)
		{
			int infoLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLength);

			std::string info;
			info.resize(infoLength);

			glGetProgramInfoLog(program, infoLength, NULL, &info[0]);

			std::cout << "ERROR linking shaders: " << info.c_str() << std::endl;

			return 0;
		}

		return program;
	}

	//static
	void ShaderLoader::DestroyAllShaders()
	{
		std::vector<unsigned int>::iterator it;
		for (it = _programs.begin(); it < _programs.end(); ++it)
		{
			glDeleteProgram(*it);
		}

		_programs.clear();
	}
}