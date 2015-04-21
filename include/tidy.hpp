#pragma once

#include <string>

#include <tidy.h>

namespace cart_opt { namespace tidy {

class tidy {
public:
	void process(const std::string& file);
};

}} // namespace cart_opt::tidy
