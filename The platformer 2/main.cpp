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
		system("pause"); //Testing Remove later!!!!
		return -1;
	}
}
