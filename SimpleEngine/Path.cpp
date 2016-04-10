#include "Path.h"

#include <windows.h>	//	TODO: Cross Platform?

#include <iostream>

//static
std::string Path::AbsolutePathRelativeToAssetsDirectory(const char* relativePath)
{
	std::string myString = GetExecutingDirectory();

	myString.append("\\..\\Assets\\");
	myString.append(relativePath);

	return myString;
}

//static
std::string Path::GetExecutingDirectory()
{
	const int maxPathLength = 1024;

	char result[maxPathLength];

	GetModuleFileName(NULL, result, maxPathLength);

	std::string myString(result, maxPathLength);

	int lastOf = myString.find_last_of('\\', maxPathLength);
	myString = myString.substr(0, lastOf);

	return myString;
}