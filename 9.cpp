///Создать двухмерный массив целого типа размерностью 5×5. Ввестизначения для этого массива в StringGrid и записать в бинарный файлэлементы этого массива по столбцам. Переписать бинарный файл так,чтобы значения элементов каждого столбца были увеличены в два раза.Распечатать этот массив до и после изменения данных в файле.
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");
    const int rows = 5;
    const int cols = 5;
    int array[rows][cols];

    // Ввод значений в двумерный массив
    std::cout << "Введите значения для двумерного массива 5x5:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> array[i][j];
        }
    }

    // Запись в бинарный файл по столбцам
    std::ofstream outFile("data.bin", std::ios::binary);
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            outFile.write(reinterpret_cast<char*>(&array[i][j]), sizeof(int));
        }
    }
    outFile.close();

    // Вывод массива до изменения данных в файле
    std::cout << "Массив до изменения данных в файле:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Увеличение значений элементов каждого столбца в два раза
    std::ifstream inFile("data.bin", std::ios::binary);
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            int value;
            inFile.read(reinterpret_cast<char*>(&value), sizeof(int));
            value *= 2;
            array[i][j] = value;
        }
    }
    inFile.close();

    // Вывод массива после изменения данных в файле
    std::cout << "Массив после изменения данных в файле:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
