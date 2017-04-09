#pragma once

#include<string>

#include<curl\curl.h>

#include "HTTPMethods.h"

class DUO {
public:
	DUO(HTTP_METHOD, std::string hostname, std::string endpoint, std::string params, std::string intKey, std::string secKey);
	void DUO::assembleHeaderList();
	void DUO::doCurl();
private:

	std::string DUO::getURL();

	CURL *curl = curl_easy_init();
	struct curl_slist *list = nullptr;
	HTTP_METHOD type;
	std::string hostname;
	std::string endpoint;
	std::string params;
	std::string intKey;
	std::string secKey;
	std::string date;
	CURLcode res;
};