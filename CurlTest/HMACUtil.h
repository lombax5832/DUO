
#pragma once
#include<string>
#include<openssl/hmac.h>
class HMACUtil {
public:
	HMACUtil(std::string key, std::string data);
	std::string SHA1();
private:
	std::string key;
	std::string data;
};