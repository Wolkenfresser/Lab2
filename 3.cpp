///Из заданного входного файла считать символы и записать в новый файл только  большие буквы латинского алфавита.
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");    
    std::ifstream inputFile("input.txt"); // Открываем входной файл для чтения
    std::ofstream outputFile("output.txt"); // Открываем выходной файл для записи

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия входного файла\n";
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия выходного файла\n";
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (isupper(ch)) {
            outputFile << ch; // Записываем только большие буквы
        }
    }

    inputFile.close(); // Закрываем входной файл
    outputFile.close(); // Закрываем выходной файл

    std::cout << "Программа успешно завершена\n";

    return 0;
}
