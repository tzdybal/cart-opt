#ifndef _CENEO_SCRAPER_HPP
#define _CENEO_SCRAPER_HPP

#include <string>

namespace cart_opt { namespace scraper {

class ceneo_scraper {
public:
	ceneo_scraper();
	void process(const std::string& file);
private:
};

}} // namespace cart_opt::scraper

#endif // _CENEO_SCRAPER_HPP
