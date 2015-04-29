#pragma once

#include <string>
#include <curl/curl.h>

namespace cart_opt {

class curl {
public:
	curl();
	virtual ~curl();

	void download(const std::string& url, const std::string& target_file);

private:
	// CURL callback
	static size_t write_to_file(void* ptr, size_t size, size_t nmemb, void* stream);

	CURL* curl_handle;
};

} // namespace cart_opt
