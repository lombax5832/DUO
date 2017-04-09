#include "Utils.h"

using namespace std;
#include<iostream>
#include<time.h>


string getRFC_2822_Time() {
	time_t current;
	char rfc_2822[40];

	time(&current);
	strftime(
		rfc_2822,
		sizeof(rfc_2822),
		"%a, %d %b %Y %T %z",
		localtime(&current)
	);
	return string(rfc_2822);
}

const char* makeUserPass(const std::string user, const std::string pass)
{
	//std::string str('[' + user + "]:[" + pass + ']');
	return std::string(user + ':' + pass).c_str();
}
