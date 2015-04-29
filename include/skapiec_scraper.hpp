#pragma once

#include <string>
#include <vector>

#include <types.hpp>

namespace cart_opt { namespace scraper {


class skapiec_scraper {
public:
	skapiec_scraper();
	std::vector<offer> process(const std::string& file);
private:
};

}} // namespace cart_opt::scraper
