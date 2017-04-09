#include <curl\curl.h>
#include <curl\easy.h>
#include <iostream>
#include <string>

#include "DUOLines.h"
#include "Utils.h"
#include "HMACUtil.h"
#include "base64.h"
#include "DUO.h"

//curl_httppost *newpost = new curl_httppost();
//newpost->name = 'C';

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);

const std::string integrationKey = "DI2QBKL73LFMRHWDIUCX";
const std::string secretKey = "IY0yYkMFhrHhkNn3cmEnK3kbZdnzSydz3nIC5Y1r";
const std::string host = "api-8c494539.duosecurity.com";

int main() {
	/*
	CURL *curl = curl_easy_init();
	if (curl) {
		CURLcode res;
		int httpResponse;
		std::string timestr(getRFC_2822_Time());
		struct curl_slist *list = NULL;
		const char* data = "device=auto&factor=push&username=lombax";

		curl_easy_setopt(curl, CURLOPT_URL, "https://api-8c494539.duosecurity.com/auth/v2/auth");
		//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

		DUOLines lines{ timestr,"POST",host,"/auth/v2/auth",data };
		HMACUtil hmac(secretKey, lines.toString());
		std::string sha(hmac.SHA1());

		std::string auth(integrationKey + ':' + sha);

		std::string b64sig = base64_encode((unsigned char*)auth.c_str(), auth.length());
		std::cout << sha << std::endl << b64sig << std::endl << std::endl << lines.toString() << std::endl;

		list = curl_slist_append(list, std::string("Date: " + timestr).c_str());
		list = curl_slist_append(list, std::string("Authorization: Basic " + b64sig).c_str());
		list = curl_slist_append(list, std::string("Host: " + host).c_str());

		curl_easy_setopt(curl, CURLOPT_POST, 1L);

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
		//curl_easy_setopt(curl, CURLOPT_USERPWD, makeUserPass(integrationKey, b64sig));

		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(data));
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpResponse);
		std::cout << std::endl << "Result = " << httpResponse << std::endl;
		
		curl_easy_cleanup(curl);
		curl_slist_free_all(list);
	}
	*/
	std::string typ;
	std::string endpt;
	std::string params;


	std::cout << "Enter Type Endpoint Params" << std::endl;
	std::cin >> typ >> endpt >> params;

	while (true) {
		DUO duoGo(strToMethod(typ), host, endpt, params, integrationKey, secretKey);
		duoGo.assembleHeaderList();
		duoGo.doCurl();
		std::cout << std::endl << "Enter Type Endpoint Params" << std::endl;
		std::cin >> typ >> endpt >> params;
	}
	return 0;
}

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
	return size * nmemb;
}