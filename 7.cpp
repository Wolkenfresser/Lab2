///В первом файле хранится k матриц размерности m × n, во втором - l матриц размерности m × n. Те матрицы из первого файла, сумма элементов главной диагонали которых равна 5, перенести в конец второго файла. Вывести на экран содержимое первого и второго файлов.
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int k, l, m, n;
    cout << "Введите количество матриц в первом файле: ";
    cin >> k;
    cout << "Введите количество матриц во втором файле: ";
    cin >> l;
    cout << "Введите размерность матриц (m x n): ";
    cin >> m >> n;

    // Открытие файлов для чтения и записи
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");
    ofstream tempFile("temp.txt");
    ofstream file2Append("file2.txt", ios::app);

    // Чтение матриц из первого файла
    for (int i = 0; i < k; i++) {
        vector<vector<int>> matrix(m, vector<int>(n));
        int sumDiagonal = 0;

        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                file1 >> matrix[j][l];
                if (j == l) {
                    sumDiagonal += matrix[j][l];
                }
            }
        }

        if (sumDiagonal == 5) {
            // Запись матрицы в конец второго файла
            for (int j = 0; j < m; j++) {
                for (int l = 0; l < n; l++) {
                    file2Append << matrix[j][l] << " ";
                }
                file2Append << endl;
            }
        }
        else {
            // Запись матрицы во временный файл
            for (int j = 0; j < m; j++) {
                for (int l = 0; l < n; l++) {
                    tempFile << matrix[j][l] << " ";
                }
                tempFile << endl;
            }
        }
    }

    // Вывод содержимого первого файла
    cout << "Содержимое первого файла:" << endl;
    file1.clear();
    file1.seekg(0, ios::beg);
    char ch;
    while (file1.get(ch)) {
        cout << ch;
    }
    cout << " " << endl;
    // Вывод содержимого второго файла
    cout << "Содержимое второго файла:" << endl;
    file2.clear();
    file2.seekg(0, ios::beg);
    while (file2.get(ch)) {
        cout << ch;
    }

    // Закрытие файлов
    file1.close();
    file2.close();
    tempFile.close();
    file2Append.close();

    // Удаление временного файла и переименование его во второй файл
    remove("file2.txt");
    rename("temp.txt", "file2.txt");

    return 0;
}
