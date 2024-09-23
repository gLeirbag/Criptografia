#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include "Pages.h"

using namespace std;

static constexpr bool debug{ true };

namespace pages {

    // Fun��o para selecionar a estrat�gia
    short welcome() {
        short input{};
        cout << "Programa de Criptografia de Arquivos" << endl;
        cout << "=====================================" << endl;
        cout << "Sistemas Operacionais 2 - prof. Modesto" << endl;
        cout << "Encontrados as seguintes estrategias de criptografia:" << endl; // estrat�gias
        cout << "    1. Cifra de Cesar" << endl;
        cout << "    2. Algoritmo XOR" << endl;
        cout << "Selecione a estrategia desejada: "; // estrat�gia
        cin >> input;

        // Limpa o buffer ap�s a leitura de n�meros para evitar problemas no pr�ximo `getline()`
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (!cin || (input != 1 && input != 2)) {
            cout << "    ERRO - selecao invalida!" << endl; // sele��o inv�lida
            cout << "Selecione a estrategia desejada: ";
            cin.clear();  // Limpa a flag de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return input;
    }

    // P�gina de Senha
    std::string passInput() {
        std::string pass{};
        while (true) {
            cout << "Digite a senha (max. 16 caracteres): ";
            std::getline(cin, pass); // L� a linha inteira

            if (pass.size() <= 16 && !pass.empty()) {
                break;
            }
            cout << "ERRO - A senha deve ter no maximo 16 caracteres e nao pode estar vazia!" << endl; // m�ximo
        }
        if (debug) {
            cout << format("        DEBUG - Senha: {}", pass) << endl;
        }

        return pass;
    }

    // Sele��o de arquivo
    std::filesystem::path fileSelection() {
        std::string filePath;
        cout << "Digite o arquivo a ser criptografado: ";
        std::getline(cin, filePath);  // L� o caminho completo do arquivo
        return std::filesystem::path(filePath); // Retorna como um path
    }

    // Erro
    void fileNotFound() {
        cout << "    ERRO - Arquivo nao encontrado!" << endl;
    }

    // Mensagem de arquivo criptografado
    void fileEncrypted() {
        cout << "Arquivo criptografado com sucesso!" << endl;
    }

    // Fun��o para pr�-visualizar o arquivo
    void previewFile(std::ifstream& file, const size_t& size) {
        char* resumo = new char[size] {};
        file.read(resumo, size - 2);

        cout << "O arquivo aberto foi: \n" << resumo << "..." << endl;
		file.seekg(0, ios::beg); // Retorna o ponteiro para o in�cio do arquivo
        delete[] resumo;
    }

}
