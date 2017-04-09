#pragma once

#include <string>

enum class HTTP_METHOD
{
	GET, POST
};

HTTP_METHOD strToMethod(std::string);

std::string methodToString(HTTP_METHOD) noexcept;