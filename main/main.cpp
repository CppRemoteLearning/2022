#include "../store/Store.h"
#include "../read_write/fileOperations.h"
#include <iostream>

int main() {
    // Product p1 = Product("Ciocan", 10.25, 12);
    // Product p2 = Product("Surubeltina", 5.65, 3);
    // Product p3 = Product("Boloboc", 7.85, 10);
    // Product p4 = Product("Topor", 15.55, 4);
    // Product p5 = Product("Lopata", 12.35, 6);

    // std::cout << p2.toString() << p4.toString();

    // std::vector<Product> products1;
    // products1.push_back(p1);
    // products1.push_back(p2);
    // products1.push_back(p5);
    // products1.push_back(p4);

    // Store s1 = Store("Store1", products1);

    // std::cout << s1.toString();

    std::string filePath = "/home/alexandrei11/2022/read_write/in.txt";
    std::string fileContents = FileOperations::readStringFromFile(filePath); // Read

    std::cout << "Am citit din fisier urmatoarele produse: \n" << fileContents << "\n";
    
    fileContents += "Ruleta 9.25 18\nFileOut FileOut FileOut";

    filePath = "/home/alexandrei11/2022/read_write/out.txt";
    FileOperations::writeStringToFile(fileContents, filePath); // Write

    std::cout << "Am scris in fisier urmatoarele produse: \n" << fileContents << "\n";

    return 0;
}