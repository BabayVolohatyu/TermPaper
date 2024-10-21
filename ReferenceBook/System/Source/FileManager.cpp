#include <fstream>
#include <filesystem>

#include "../Headers/FileManager.h"
#include "../Headers/Serializable.h"

void FileManager::uploadToFile(const std::string& path, const Serializable& object) {

	std::filesystem::path dirPath = std::filesystem::path(path).parent_path();
	if (!exists(dirPath)) create_directories(dirPath);

	std::ofstream ofs{ path, std::ofstream::out };

	ofs << object;
	ofs.close();
}

void FileManager::downloadFromFile(const std::string& path, Serializable& object){

	std::filesystem::path dirPath = std::filesystem::path(path).parent_path();
	if (!exists(dirPath)) create_directories(dirPath);

	std::ifstream ifs{ path, std::ifstream::in };

	ifs >> object;
	ifs.close();
}
