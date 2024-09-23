#include<string>
#include<iostream>
#include<format>
#include "Utils.h"
constexpr bool debug{ true };

// Converte ASCII para int
// Se for um número, converte para int
int aToInt(const std::string_view& value) {
	int intValue{ 0 };
	bool doAgain{};
	if (value[0] <= '9' || value[0] >= '1') {
		try {
			size_t pos{ 0 };
			intValue = std::stoi(value.data(), &pos);
			doAgain = (pos == value.size()) ? false : true;
		}
		catch (const std::invalid_argument& e) {
			doAgain = true;
		}
	}
	if (doAgain) {
		for (int i = 0; i < value.size(); i++) {
			intValue += value[i];
		}
	}

	if (debug) {
		std::cout << std::format("	DEBUG - {} convertido para {}", value, intValue) << std::endl;
	}

	return intValue;
}