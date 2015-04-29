#include <types.hpp>

namespace cart_opt {

offer::offer(const std::string& shop, const std::string& url, double price)
	: shop(shop), url(url), price(price)
{}

double offer::get_price() const {
	return price;
}

std::string offer::get_shop() const {
	return shop;
}

} // namespace cart_opt
