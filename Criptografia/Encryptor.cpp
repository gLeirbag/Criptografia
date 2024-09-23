#include "Encryptor.h" 
#include "CypherStrategy.h"

// Implementa��o do m�todo encrypt
void Encryptor::encrypt(int key, std::ifstream& inFile) {
    // Usa a estrat�gia para realizar a criptografia
    std::ofstream& outFile = strategy->encrypt(key, inFile);

    // Fecha o arquivo de sa�da ap�s a criptografia
    outFile.close();
}
