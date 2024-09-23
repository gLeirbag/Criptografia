#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "Pages.h"  
#include "Encryptor.h"
#include "Strategies.h"
#include "CypherStrategy.h"
#include "Utils.h"

int main()
{
	using namespace std;

	// Página principal - Seleção de estratégia
	short selectedStrategy = 0;
	selectedStrategy = pages::welcome();

	// Página de seleção de arquivo
	filesystem::path fpath{ pages::fileSelection() };
	while (!filesystem::exists(fpath)) {
		pages::fileNotFound();
		fpath.assign(pages::fileSelection());
	}

	// Abre o arquivo selecionado anteriormente
	ifstream file{ fpath, ios_base::in };
	if (!file.is_open()) {
		// Se não conseguir abrir o arquivo, dá um erro
		cout << "    ERRO - O arquivo nao pode ser aberto :(" << endl;
		return -1;
	}

	// Preview do arquivo, mostra os primeiros 100 caractéres
	pages::previewFile(file, 100);

	// Página de criação de senha
	const string pass{ pages::passInput() };


	// Instanciando a estratégia selecionada
	CypherStrategy* strategy = nullptr;
	switch (selectedStrategy)
	{
	case 1:
		strategy = new CaesarCypherStrategy();
		break;

	default:
		cout << "    ERRO - Estrategia nao reconhecida" << endl;
		return -1;
	}

	// Encripta o arquivo usando a senha.
	Encryptor encryptor(strategy);
	encryptor.encrypt(aToInt(pass), file);

	// Não esqueça de fechar o arquivo
	file.close();


	return 0;
}