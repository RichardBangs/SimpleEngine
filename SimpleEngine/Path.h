#pragma once

#include <iostream>

class Path
{
public:
	static std::string AbsolutePathRelativeToAssetsDirectory(const char* relativePath);

private:
	static std::string GetExecutingDirectory();
};