#pragma once

#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <vector>

namespace Util {
	// Ignores all remaining input until reaching a newline, discarding it.
	inline std::istream& ignore_newline(std::istream& is) {
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return is;
	}

	inline bool is_empty(std::string& st) {
		return std::all_of(st.cbegin(), st.cend(), isspace);
	}
}

