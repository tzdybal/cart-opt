#include <cstdio>
#include <string>
#include <boost/filesystem.hpp>

#include <curl.hpp>
#include <ceneo_scraper.hpp>

int main(int argc, char** argv) {
	cart_opt::curl c;

	std::string tmp_file = boost::filesystem::unique_path().native();

	puts(tmp_file.c_str());
	c.download("http://www.ceneo.pl/35307540", tmp_file);

	system(("tidy -q -m -asxml " + tmp_file).c_str());

	cart_opt::scraper::ceneo_scraper scraper;
	scraper.process(tmp_file);

	boost::filesystem::remove(tmp_file);
}
