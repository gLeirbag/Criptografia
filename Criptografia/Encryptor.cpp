#include "Encryptor.h" 
#include "CypherStrategy.h"

// Implementação do método encrypt
void Encryptor::encrypt(int key, std::ifstream& inFile) {
    // Usa a estratégia para realizar a criptografia
    std::ofstream& outFile = strategy->encrypt(key, inFile);

    // Fecha o arquivo de saída após a criptografia
    outFile.close();
}
