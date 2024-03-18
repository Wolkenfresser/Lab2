/*Создать бинарный файл, компонентами которого является структура,содержащая следующие поля:
− название турпоездки;
− стоимость путевки;
− количество групп отправления;
− количество в группе от одной организации (массив, не менее чем
из 5 групп)
− общая стоимость путевки для каждой группы (массив, не менее
чем для 5 групп).
Переписать бинарный файл так, чтобы стоимость путевки была бы снижена на 5% для группы, состоящей из 10 человек от одной организации.*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TourPackage {
    string name;
    float cost;
    int departureGroupsCount;
    int groupSize[5];
    float groupCost[5];
};

int main() {
    TourPackage package;
    
    // Создание бинарного файла и запись данных
    ofstream outFile("tour_packages.bin", ios::out | ios::binary);
    
    package.name = "Отпуск в горах";
    package.cost = 1000.0;
    package.departureGroupsCount = 5;
    
    for (int i = 0; i < 5; ++i) {
        package.groupSize[i] = 10;
        package.groupCost[i] = 1000.0;
    }
    
    outFile.write((char*)&package, sizeof(package));
    outFile.close();
    
    // Изменение стоимости путевки для группы из 10 человек
    ifstream inFile("tour_packages.bin", ios::in | ios::binary);
    ofstream tempFile("temp.bin", ios::out | ios::binary);
    
    while (inFile.read((char*)&package, sizeof(package))) {
        for (int i = 0; i < 5; ++i) {
            if (package.groupSize[i] == 10) {
                package.groupCost[i] *= 0.95; // Снижение стоимости на 5%
            }
        }
        
        tempFile.write((char*)&package, sizeof(package));
    }
    
    inFile.close();
    tempFile.close();
    
    remove("tour_packages.bin");
    rename("temp.bin", "tour_packages.bin");
    
    return 0;
}
