#include "HTTPMethods.h"

HTTP_METHOD strToMethod(std::string str) {
	if (str == "GET") {
		return HTTP_METHOD::GET;
	}
	else if (str == "POST") {
		return HTTP_METHOD::POST;
	}
	else {
		throw std::invalid_argument("Method is not Supported: " + str + " Supported methods are GET and POST");
	}
}

std::string methodToString(HTTP_METHOD method) noexcept
{
	switch (method) {
	case HTTP_METHOD::GET:
		return "GET";
		break;
	case HTTP_METHOD::POST:
		return "POST";
		break;
	}

	return "GET";
}