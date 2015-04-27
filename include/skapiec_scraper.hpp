#ifndef _skapiec_scraper_HPP
#define _skapiec_scraper_HPP

#include <string>

namespace cart_opt { namespace scraper {

class skapiec_scraper {
public:
	skapiec_scraper();
	void process(const std::string& file);
private:
};

}} // namespace cart_opt::scraper

#endif // _skapiec_scraper_HPP
