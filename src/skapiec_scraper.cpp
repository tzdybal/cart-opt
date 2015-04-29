#include <skapiec_scraper.hpp>

#include <iostream>
#include <vector>

#include <boost/lexical_cast.hpp>

#include <pugixml.hpp>

#include <types.hpp>


namespace cart_opt { namespace scraper {

skapiec_scraper::skapiec_scraper() {
}

std::vector<offer> skapiec_scraper::process(const std::string& file) {
	pugi::xml_document doc;

	/* auto result = */doc.load_file(file.c_str());
	/* std::cout << "Error description: " << result.description() << "\n";
	std::cout << "Error offset: " << result.offset << "\n\n"; */

	pugi::xpath_node_set nodes = doc.select_nodes("//li[@class='offer-row gtm_or_bs']");


	std::vector<offer> offers;
	for (auto offer : nodes) {
		pugi::string_t shop;
		pugi::string_t price;
		pugi::string_t url;

		for (pugi::xml_node column : offer.node().children("div")) {
			for (pugi::xml_node cell : column.children("div")) {
				pugi::string_t cls = cell.attribute("class").value();

				if ("store" == cls) {
					shop = cell.child_value("a");

				} else if ("offer" == cls) {
					pugi::xml_node offer = cell.child("a").child("strong");
					price = offer.child_value("b");
					price += offer.child("b").child_value("sup");
					price[price.find(',')] = '.';
					url = std::string("http://skapiec.pl/") + offer.parent().attribute("href").value();
				}
			}
		}

		offers.emplace_back(shop, url, boost::lexical_cast<double>(price));
	}

	return offers;
}		


}} // namespace cart_opt::scraper
