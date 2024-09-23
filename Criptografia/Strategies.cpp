#include <fstream>
#include "Strategies.h"
#include <iostream>
#include <filesystem>


std::ofstream& CaesarCypherStrategy::encrypt(int key, std::ifstream& inFile) {
	static std::ofstream outFile("encrypted.txt");

	std::string data((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

	for (char& c : data) {
		c += key; // Simples cifra de César
	}
	outFile << data;

	std::cout << "O arquivo serah salvo em: " << std::filesystem::current_path() << "\\encrypted.txt" << std::endl;


	return outFile;
}