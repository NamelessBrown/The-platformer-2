#pragma once

#include <exception>

struct ParsingException : public std::exception
{
public:
	using std::exception::exception;
};

