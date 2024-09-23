#pragma once
#include "CypherStrategy.h"

struct CaesarCypherStrategy : public CypherStrategy {
    virtual ofstream& encrypt(int key, ifstream& inFile);
};