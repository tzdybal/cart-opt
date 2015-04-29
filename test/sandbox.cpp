#include <cstdio>
#include <map>
#include <string>
#include <boost/filesystem.hpp>
#include <iostream>

#include <curl.hpp>
#include <skapiec_scraper.hpp>
#include <tidy.hpp>


int main(int argc, char** argv) {
	std::vector<std::string> uris { "http://www.skapiec.pl/site/cat/1066/comp/2419475", "http://www.skapiec.pl/site/cat/1030/comp/686629", "http://www.skapiec.pl/site/cat/1030/comp/706629" };

	std::map<std::string, std::pair<size_t, double>> results;

	for (auto& uri : uris) {
		cart_opt::curl c;
		std::string tmp_file = boost::filesystem::unique_path().native();
		c.download(uri, tmp_file);

		cart_opt::tidy::tidy t;
		t.process(tmp_file);

		cart_opt::scraper::skapiec_scraper scraper;
		std::vector<cart_opt::offer> offers = scraper.process(tmp_file);

		for (auto offer : offers) {
			auto& r = results[offer.get_shop()];
			r.first++;
			r.second += offer.get_price();
		}

		boost::filesystem::remove(tmp_file);

	}

	for (auto r : results) {
		if (r.second.first == uris.size()) {
			std::cout << r.first << ": " << r.second.second << std::endl;
		}
	}
}
