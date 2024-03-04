///Дано 2 файла вещественных чисел а.txt и b.txt. Найти произведение отрицательных элементов двух файлов
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file1("a.txt");
    ifstream file2("b.txt");

    float num1;
    float num2;
    double product = 1.0;

    if (file1.is_open() && file2.is_open()) {
        while (file1 >> num1 && file2 >> num2) {
            if (num1 < 0 && num2 < 0) {
                product *= num1 * num2;
            }
        }

        file1.close();
        file2.close();

        cout << "Произведение отрицательных элементов двух файлов: " << product << endl;
    }
    else {
        cout << "Не удалось открыть один из файлов." << endl;
    }

    return 0;
}
