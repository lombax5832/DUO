#include "HMACUtil.h"
HMACUtil::HMACUtil(std::string key, std::string data) {
	HMACUtil::key = key;
	HMACUtil::data = data;
}

std::string HMACUtil::SHA1() {
	unsigned char* digest;

	digest = HMAC(EVP_sha1(), key.c_str(), key.length(), (unsigned char*)data.c_str(), strlen(data.c_str()), NULL, NULL);
	char mdString[41];
	for (int i = 0; i < 20; i++)
		sprintf(&mdString[i * 2], "%02x", digest[i]);
	std::string output(mdString);
	return output;
}