#include "Screen.h"

Screen&
Screen::clear(char c)
{
	contents = std::string(height*width, c);
	return *this;
}

