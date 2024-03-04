///Организовать файл целых чисел. Найти сумму элементов файла, номера которых кратны трем
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");    
    std::ifstream file("numbers.txt");
    if (!file) {
        std::cerr << "Ошибка открытия файла.";
        return 1;
    }

    int number, sum = 0, index = 1;
    while (file >> number) {
        if (index % 3 == 0) {
            sum += number;
        }
        index++;
    }

    file.close();

    std::cout << "Сумма элементов файла, номера которых кратны трем: " << sum << std::endl;

    return 0;
}
