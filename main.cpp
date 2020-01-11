#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <memory>
#include <fstream>
#include "figure.h"
#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"
#include "document.h"
#include "factory.h"

void PrintMenu()
{
    std::cout << "Save elements in file: 1" << std::endl;
    std::cout << "Load elements from file: 2" << std::endl;
    std::cout << "Add element: 3" << std::endl;
    std::cout << "Remove element: 4" << std::endl;
    std::cout << "Output elements: 5" << std::endl;
    std::cout << "Undo last operation: 6" << std::endl;
    std::cout << "Exit program: 0" << std::endl;
}

int main()
{
    std::cout << "Laba 07\n";
    std::string command;
    factory fact;
    std::unique_ptr<document> doc1;
    doc1 = std::make_unique<document>();
    while(command != "0")
    {
        PrintMenu();
        std::cin >> command;
        if(command=="1")
        {
            std::cout << "Input the path to file for saving: ";
            std::string path;
            std::cin >> path;
            std::ofstream os(path);
            doc1->save(os);
            os.close();//закрытие файла
        }
        else if(command=="2")
        {
            std::cout << "Input the path to file for loading: ";
            std::string path;
            std::cin >> path;
            std::ifstream is(path);
            if(is)
                doc1->load(is);
            else
                std::cout << "No such file\n";
            is.close();//закрытие файла
        }
        else if(command=="3")
        {
            std::string figures;
            std::cout << "Input the number of figure for adding: \n";
            std::cout << "Pentagon: 5\n";
            std::cout << "Hexagon: 6\n";
            std::cout << "Octagon: 8\n";
            std::cin >> figures;
            if (figures != "5" && figures != "6" && figures != "8")
            {
                std::cout << "Wrong input!\n";
                break;
            }
            fact.construct(doc1,figures);
        }
        else if(command=="4")
        {
            std::cout << "Input the index for deleating: ";
            size_t id;
            std::cin >> id;
            doc1->remove_figure(id);
        }
        else if(command== "5")
            doc1->show(std::cout);
        else if(command == "6")
            doc1->undo();
        std::cout << "\n\n\n";
    }
    return 0;
}
