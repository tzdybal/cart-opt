#include <skapiec_scraper.hpp>

#include <iostream>

#include <pugixml.hpp>


namespace cart_opt { namespace scraper {

skapiec_scraper::skapiec_scraper() {
}

void skapiec_scraper::process(const std::string& file) {
	pugi::xml_document doc;

	auto result = doc.load_file(file.c_str());
	std::cout << "Error description: " << result.description() << "\n";
	std::cout << "Error offset: " << result.offset << "\n\n";

	pugi::xpath_node_set offers = doc.select_nodes("//li[@class='offer-row gtm_or_bs']");
	std::cout << "offers:" << std::endl;


	for (auto offer : offers) {
		pugi::string_t shop;
		pugi::string_t price;
		pugi::string_t uri;

		for (pugi::xml_node column : offer.node().children("div")) {
			for (pugi::xml_node cell : column.children("div")) {
				pugi::string_t cls = cell.attribute("class").value();

				if ("store" == cls) {
					std::cout << "store" << std::endl;
					shop = cell.child_value("a");

				} else if ("offer" == cls) {
					std::cout << "offer" << std::endl;
					pugi::xml_node offer = cell.child("a").child("strong");
					price = offer.child_value("b");
					price += offer.child("b").child_value("sup");
					price[price.find(',')] = '.';
					uri = offer.parent().attribute("href").value();
				}
			}
		}



		std::cout << "Offer:" << "http://skapiec.pl/" << uri << " : " << shop << " : " << price << std::endl;
	}

}		


}} // namespace cart_opt::scraper
