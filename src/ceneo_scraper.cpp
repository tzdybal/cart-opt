#include <ceneo_scraper.hpp>

#include <iostream>

#include <pugixml.hpp>


namespace cart_opt { namespace scraper {

ceneo_scraper::ceneo_scraper() {
}

void ceneo_scraper::process(const std::string& file) {
	pugi::xml_document doc;

	auto result = doc.load_file(file.c_str());
	std::cout << "Error description: " << result.description() << "\n";
	std::cout << "Error offset: " << result.offset << "\n\n";

	pugi::xpath_node_set offers = doc.select_nodes("//li[@class='offer-row gtm_or_bs']//strong[@class='price']");
	std::cout << "offers:" << std::endl;

	for (auto offer : offers) {
		std::cout << "offer" << std::endl;
		std::string price = offer.node().child_value("b");
		price += offer.node().child("b").child_value("sup");
		price[price.find(',')] = '.';

		std::string uri = offer.parent().attribute("href").value();


		std::cout << uri << ": " << price << std::endl;
	}

}		


}} // namespace cart_opt::scraper
