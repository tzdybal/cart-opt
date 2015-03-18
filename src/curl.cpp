#include <curl.hpp>

#include <cstdio>
#include <stdexcept>


namespace cart_opt {

curl::curl() {
	curl_handle = curl_easy_init();
}

curl::~curl() {
	curl_easy_cleanup(curl_handle);
}

void curl::download(const std::string& url, const std::string& target_file) {
	curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_to_file);

	FILE* file = fopen(target_file.c_str(), "wb");
	if (!file) {
		throw std::runtime_error(target_file + ": cannot open file for writing");
	}
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, file);
	
	CURLcode res = curl_easy_perform(curl_handle);
	if (res != CURLE_OK) {
		throw std::runtime_error(curl_easy_strerror(res));
	}

	fclose(file);
}

size_t curl::write_to_file(void* ptr, size_t size, size_t nmemb, void* stream) {
	return fwrite(ptr, size, nmemb, (FILE *)stream);
}

} // namespace cart_opt
