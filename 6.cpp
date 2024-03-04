///Дан файл f, компоненты которого являются целыми числами. Получить в файле g все компоненты файла f являющиеся чётными числами.
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");  
    std::ifstream inputFile("f.txt");
    std::ofstream outputFile("g.txt");

    if (!inputFile) {
        std::cerr << "Не удается открыть файл f.txt\n";
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Не удается создать файл g.txt\n";
        return 1;
    }

    int number;
    while (inputFile >> number) {
        if (number % 2 == 0) {
            outputFile << number << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
