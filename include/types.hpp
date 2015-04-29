#pragma once

#include <string>

namespace cart_opt {

class offer {
public:
	offer(const std::string& shop, const std::string& url, double price);

	std::string get_shop() const;
	void set_shop(const std::string& new_shop);

	double get_price() const;
	void set_price(double new_price);

	std::string get_url() const;
	void set_url(const std::string& url);

private:
	std::string shop;
	std::string url;
	double price;
};

} // namespace cart_opt
