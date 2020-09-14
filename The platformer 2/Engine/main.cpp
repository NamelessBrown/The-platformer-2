#include "Engine.h"
#include <iostream>

int main()
{
	try
	{
		Engine e;
		e.Running();
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << '\n';
		return -1;
	}
}
