#include <tidy.hpp>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

namespace cart_opt { namespace tidy {

void tidy::process(const std::string& file) {
	system(("tidy -q -m -asxml " + file + " 2> /dev/null").c_str()); // TODO: change to library calls

	// ugly way to do it...
	std::ifstream istr(file);
	std::string contents = static_cast<std::stringstream const&>(std::stringstream() << istr.rdbuf()).str();	
	istr.close();

	size_t pos;
	while ((pos = contents.find("<script")) != std::string::npos) {
		size_t close = contents.find("</script>", pos)+strlen("</script>");;
		contents.erase(pos, close-pos);
	}

	std::ofstream ostr(file);
	ostr << contents;
	std::cout << contents << std::endl;
	ostr.flush();
	ostr.close();
}

}} // namespace cart_opt::tidy
