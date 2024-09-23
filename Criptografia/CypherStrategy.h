#pragma once
#include <fstream>
using namespace std;

struct CypherStrategy {
    // Destrutor virtual para garantir a limpeza correta
    virtual ~CypherStrategy() = default;

    // Método virtual puro, para ser implementado pelas subclasses
    virtual ofstream& encrypt(int key, ifstream& inFile) = 0;
};
