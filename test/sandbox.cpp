#include <cstdio>
#include <string>
#include <boost/filesystem.hpp>

#include <curl.hpp>
#include <ceneo_scraper.hpp>
#include <tidy.hpp>

int main(int argc, char** argv) {
	cart_opt::curl c;

	std::string tmp_file = boost::filesystem::unique_path().native();

	puts(tmp_file.c_str());
	c.download("http://www.skapiec.pl/site/cat/1066/comp/2419475", tmp_file);

	cart_opt::tidy::tidy t;
	t.process(tmp_file);


	cart_opt::scraper::ceneo_scraper scraper;
	scraper.process(tmp_file);

	boost::filesystem::remove(tmp_file);
}
