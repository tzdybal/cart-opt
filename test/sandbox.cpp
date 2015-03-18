#include <curl.hpp>

#include <cstdio>
#include <string>
#include <boost/filesystem.hpp>

int main(int argc, char** argv) {
	cart_opt::curl c;

	std::string tmp_file = boost::filesystem::unique_path().native();

	puts(tmp_file.c_str());
	c.download("https://github.com/tzdybal/cart-opt", tmp_file);

	//boost::filesystem::remove(tmp_file);
}
