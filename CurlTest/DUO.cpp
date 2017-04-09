#include "DUO.h"
#include "Utils.h"
#include "HMACUtil.h"
#include "base64.h"
#include "DUOLines.h"
#include "HTTPMethods.h"

#include <iostream>

DUO::DUO(HTTP_METHOD req, std::string hostname, std::string endpoint, std::string params, std::string intKey, std::string secKey)
{
	DUO::type = req;
	DUO::hostname = hostname;
	DUO::endpoint = endpoint;
	DUO::params = params;
	DUO::intKey = intKey;
	DUO::secKey = secKey;
	DUO::date = getRFC_2822_Time();
	//curl = curl_easy_init();
}

void DUO::assembleHeaderList()
{
	HMACUtil hmac(secKey, date + '\n' + methodToString(type) + '\n' + hostname + '\n' + endpoint + '\n' + params);
	std::cout << date + '\n' + methodToString(type) + '\n' + hostname + '\n' + endpoint + '\n' + params << std::endl;
	std::string auth(intKey + ':' + hmac.SHA1());
	std::string b64sig = base64_encode((unsigned char*)auth.c_str(), auth.length());

	list = curl_slist_append(list, std::string("Date: " + date).c_str());
	list = curl_slist_append(list, std::string("Authorization: Basic " + b64sig).c_str());
	list = curl_slist_append(list, std::string("Host: " + hostname).c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
}

void DUO::doCurl()
{
	if (curl) {
		int httpResponse;

		curl_easy_setopt(curl, CURLOPT_URL, getURL().c_str());
		std::cout << getURL() << std::endl;

		if (type == HTTP_METHOD::POST) {
			curl_easy_setopt(curl, CURLOPT_POST, 1L);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(params.c_str()));
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());
		}
		

		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpResponse);
		std::cout << std::endl << "Result = " << httpResponse << std::endl;
		curl_easy_cleanup(curl);
		curl_slist_free_all(list);
	}
}

std::string DUO::getURL()
{
	return std::string("https://" + hostname + endpoint);
}
