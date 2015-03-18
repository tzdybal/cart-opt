#ifndef _CENEO_SCRAPER_HPP
#define _CENEO_SCRAPER_HPP

#include <string>

#include <xercesc/sax2/DefaultHandler.hpp>

namespace cart_opt { namespace scraper {

class ceneo_scraper {
public:
	ceneo_scraper();
	void process(const std::string& file);
private:
};

class ceneo_handler : public xercesc::DefaultHandler {
public:
	void startElement(
			const   XMLCh* const    uri,
			const   XMLCh* const    localname,
			const   XMLCh* const    qname,
			const   xercesc::Attributes&     attrs
			);
	void fatalError(const xercesc::SAXParseException&);
};

}} // namespace cart_opt::scraper

#endif // _CENEO_SCRAPER_HPP
