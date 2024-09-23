#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include "Pages.h"

using namespace std;

static constexpr bool debug{ true };

namespace pages {

    // Função para selecionar a estratégia
    short welcome() {
        short input{};
        cout << "Programa de Criptografia de Arquivos" << endl;
        cout << "=====================================" << endl;
        cout << "Sistemas Operacionais 2 - prof. Modesto" << endl;
        cout << "Encontrados as seguintes estrategias de criptografia:" << endl; // estratégias
        cout << "    1. Cifra de Cesar" << endl;
        cout << "    2. Algoritmo XOR" << endl;
        cout << "Selecione a estrategia desejada: "; // estratégia
        cin >> input;

        // Limpa o buffer após a leitura de números para evitar problemas no próximo `getline()`
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (!cin || (input != 1 && input != 2)) {
            cout << "    ERRO - selecao invalida!" << endl; // seleção inválida
            cout << "Selecione a estrategia desejada: ";
            cin.clear();  // Limpa a flag de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return input;
    }

    // Página de Senha
    std::string passInput() {
        std::string pass{};
        while (true) {
            cout << "Digite a senha (max. 16 caracteres): ";
            std::getline(cin, pass); // Lê a linha inteira

            if (pass.size() <= 16 && !pass.empty()) {
                break;
            }
            cout << "ERRO - A senha deve ter no maximo 16 caracteres e nao pode estar vazia!" << endl; // máximo
        }
        if (debug) {
            cout << format("        DEBUG - Senha: {}", pass) << endl;
        }

        return pass;
    }

    // Seleção de arquivo
    std::filesystem::path fileSelection() {
        std::string filePath;
        cout << "Digite o arquivo a ser criptografado: ";
        std::getline(cin, filePath);  // Lê o caminho completo do arquivo
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

    // Função para pré-visualizar o arquivo
    void previewFile(std::ifstream& file, const size_t& size) {
        char* resumo = new char[size] {};
        file.read(resumo, size - 2);

        cout << "O arquivo aberto foi: \n" << resumo << "..." << endl;
		file.seekg(0, ios::beg); // Retorna o ponteiro para o início do arquivo
        delete[] resumo;
    }

}
