#pragma once

#include <iostream>

class Serializable;

class FileManager {
private:
	FileManager() = delete;
public:
	static void uploadToFile(const std::string& path, const Serializable& object);

	static void downloadFromFile(const std::string& path, Serializable& object);
};