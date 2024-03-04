///создать текстовый файл с произвольной информацией. Организовать просмотр содержимого файла. Организовать чтение и обработку данных из файла всоответствии с индивидуальным заданием. Сохранить полученные результаты в новый текстовый файл.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
    int storagePeriod;
    string type;
    string releaseDate;
    int expirationDate;
};

void createFile(const string& fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        file << "Name;Price;Storage Period;Type;Release Date;Expiration Date\n";
        file.close();
        cout << "File " << fileName << " created successfully." << endl;
    }
    else {
        cout << "Error creating file " << fileName << endl;
    }
}

void addProductToFile(const string& fileName, const Product& product) {
    ofstream file(fileName, ios::app);
    if (file.is_open()) {
        file << product.name << ";" << product.price << ";" << product.storagePeriod << ";"
            << product.type << ";" << product.releaseDate << ";" << product.expirationDate << "\n";
        file.close();
        cout << "Product added to file " << fileName << " successfully." << endl;
    }
    else {
        cout << "Error adding product to file " << fileName << endl;
    }
}

void printFileContent(const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Error opening file " << fileName << endl;
    }
}

int main() {
    const string fileName = "products.txt";

    createFile(fileName);

    Product product1 = { "Apple", 1.5, 7, "Fruit", "2022-10-01", 10 };
    Product product2 = { "Milk", 2.0, 14, "Dairy", "2022-09-25", 7 };

    addProductToFile(fileName, product1);
    addProductToFile(fileName, product2);

    cout << "Content of file " << fileName << ":" << endl;
    printFileContent(fileName);

    // Reading and processing data from file

    // Saving results to new file
    const string newFileName = "processed_products.txt";
    // code for reading and processing data from file
    // code for saving results to new file

    return 0;
}
