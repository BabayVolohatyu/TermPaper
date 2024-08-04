#include <fstream>

#include "FileManager.h"
#include "Serializable.h"

void FileManager::uploadToFile(const std::string& path, const Serializable& object) {
	std::ofstream of{ path, std::ofstream::out };
	of << object;
	of.close();
}