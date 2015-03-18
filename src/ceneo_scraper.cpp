#include <ceneo_scraper.hpp>

#include <iostream>

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

using namespace xercesc;

namespace cart_opt { namespace scraper {

ceneo_scraper::ceneo_scraper() {
	try {
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Error during initialization! :\n";
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
		throw;
	}
}

void ceneo_scraper::process(const std::string& file) {
	const char* xmlFile = file.c_str();
	SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();
	parser->setFeature(XMLUni::fgSAX2CoreValidation, false);
	parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, false);
	parser->setFeature(XMLUni::fgXercesContinueAfterFatalError, true);

	DefaultHandler* defaultHandler = new ceneo_handler();
	parser->setContentHandler(defaultHandler);
	parser->setErrorHandler(defaultHandler);

	try {
		parser->parse(xmlFile);
	}
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
		throw;
	}
	catch (const SAXParseException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
		throw;
	}
	catch (...) {
		std::cout << "Unexpected Exception \n" ;
		throw;
	}
}		

void ceneo_handler::startElement(const   XMLCh* const    uri,
		const   XMLCh* const    localname,
		const   XMLCh* const    qname,
		const   Attributes&     attrs)
{
	char* message = XMLString::transcode(qname);
	std::cout << "I saw element: "<< message << std::endl;
	XMLString::release(&message);
}

void ceneo_handler::fatalError(const SAXParseException& exception)
{
	char* message = XMLString::transcode(exception.getMessage());
	std::cout << "Fatal Error: " << message
		<< " at line: " << exception.getLineNumber()
		<< std::endl;
	XMLString::release(&message);
}

}} // namespace cart_opt::scraper
