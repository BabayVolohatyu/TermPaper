#include <fstream>
#include <filesystem>

#include "../Headers/FileManager.h"
#include "../Headers/Serializable.h"

void FileManager::uploadToFile(const std::string &path, const Serializable &object) {
    //Отримуємо шлях до файлу без назви файлу
    std::filesystem::path dirPath = std::filesystem::path(path).parent_path();
    //якщо такого не існує, то створюємо його
    if (!exists(dirPath) && !dirPath.empty()) create_directories(dirPath);

    std::ofstream ofs{path, std::ofstream::out};

    ofs << object;
    ofs.close();
}

void FileManager::downloadFromFile(const std::string &path, Serializable &object) {
    //Отримуємо шлях до файлу без назви файлу
    std::filesystem::path dirPath = std::filesystem::path(path).parent_path();
    //якщо такого не існує, то створюємо його
    if (!exists(dirPath) && !dirPath.empty()) create_directories(dirPath);

    std::ifstream ifs{path, std::ifstream::in};

    ifs >> object;
    ifs.close();
}
