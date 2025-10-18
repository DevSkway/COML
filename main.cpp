#include <iostream>
#include <string>
#include <unordered_map>

std::string get_extension(const std::string &filename) {
	size_t pos = filename.find_last_of('.');
	if (pos == std::string::npos) return "";
	return filename.substr(pos);
}

int main(int argc, char **argv) {
	const std::string YAML = "YAML";
	const std::string TOML = "TOML";
	const std::string JSON = "JSON";

	std::unordered_map<std::string, std::string> FILE_EXTENSIONS = {
		{".yaml", YAML}, {".yml", YAML},
		{".toml", TOML}, {".tml", TOML},
		{".json", JSON}, {".jsonl", JSON}, {".jsonml", JSON}
	};

	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];

		if (arg == "-f" || arg == "--file") {
			if (i + 1 < argc) {
				std::string filename = argv[++i];
				std::string ext = get_extension(filename);

				auto it = FILE_EXTENSIONS.find(ext);
				if (it == FILE_EXTENSIONS.end()) {
					std::cerr << "ERRO: Extensão de arquivo inválida (" << ext << ")\n";
					return 1;
				}
				if (ex)
			} else {
				std::cerr << "ERRO: Missing file name after param " << arg << "\n";
				return 1;
			}
		}
	}
	return 0;
}
