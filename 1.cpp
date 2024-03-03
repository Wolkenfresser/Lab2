///Дан файл вещественных чисел a.txt Найти количество положительных элементов и произведение элементов меньших 1 и больших 0
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("a.txt");
    
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }
    
    double num;
    int countPositives = 0;
    double product = 1;
    
    while (file >> num) {
        if (num > 0) {
            countPositives++;
        }
        
        if (num < 1 && num > 0) {
            product *= num;
        }
    }
    
    file.close();
    
    std::cout << "Количество положительных элементов: " << countPositives << std::endl;
    std::cout << "Произведение элементов меньших 1 и больших 0: " << product << std::endl;
    
    return 0;
}
