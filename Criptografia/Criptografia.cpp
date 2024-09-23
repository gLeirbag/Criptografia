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

	// P�gina principal - Sele��o de estrat�gia
	short selectedStrategy = 0;
	selectedStrategy = pages::welcome();

	// P�gina de sele��o de arquivo
	filesystem::path fpath{ pages::fileSelection() };
	while (!filesystem::exists(fpath)) {
		pages::fileNotFound();
		fpath.assign(pages::fileSelection());
	}

	// Abre o arquivo selecionado anteriormente
	ifstream file{ fpath, ios_base::in };
	if (!file.is_open()) {
		// Se n�o conseguir abrir o arquivo, d� um erro
		cout << "    ERRO - O arquivo nao pode ser aberto :(" << endl;
		return -1;
	}

	// Preview do arquivo, mostra os primeiros 100 caract�res
	pages::previewFile(file, 100);

	// P�gina de cria��o de senha
	const string pass{ pages::passInput() };


	// Instanciando a estrat�gia selecionada
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

	// N�o esque�a de fechar o arquivo
	file.close();


	return 0;
}