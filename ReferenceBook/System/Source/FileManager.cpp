#include <fstream>

#include "../Headers/FileManager.h"
#include "../Headers/Serializable.h"

void FileManager::uploadToFile(const std::string& path, const Serializable& object) {
	std::ofstream ofs{ path, std::ofstream::out };
	ofs << object;
	ofs.close();
}

void FileManager::downloadFromFile(const std::string& path, Serializable& object){
	std::ifstream ifs{ path, std::ifstream::in };
	ifs >> object;
	ifs.close();
}
