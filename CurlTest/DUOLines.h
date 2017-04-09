#pragma once
#include<string>

struct DUOLines {
	//DUOLines(std::string);
	std::string date;
	std::string method;
	std::string host;
	std::string path;
	std::string params;

	std::string toString() {
		return date + '\n' + method + '\n' + host + '\n' + path + '\n' + params;
	}
};