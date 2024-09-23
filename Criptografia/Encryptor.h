#pragma once
#include <fstream> // Include the fstream header
#include "CypherStrategy.h"

class Encryptor
{
private:
    CypherStrategy* strategy;
public:
    Encryptor(CypherStrategy* strategy) : strategy(strategy) {}

    void encrypt(int key, std::ifstream& inFile); // Use the full parameter name for clarity
};