#pragma once

namespace pages {
	short welcome();
	std::string passInput();
	std::filesystem::path fileSelection();
	void fileNotFound();
	void fileEncrypted();
	void previewFile(std::ifstream&, const size_t& size);
}
