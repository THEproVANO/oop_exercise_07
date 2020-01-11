#include <iostream>

#include "factory.h"

void factory::construct(std::unique_ptr<document> &doc1, std::string figures)
{
    size_t id;
    std::cout << "Input the index for input: ";
    std::cin >> id;
    if(figures == "5")
    {
        std::unique_ptr<figure> new_figure = std::make_unique<five_angles>(five_angles(std::cin));
        doc1->add_figure(std::move(new_figure),id);
    }
    else if(figures == "6")
    {
        std::unique_ptr<figure> new_figure = std::make_unique<six_angles>( six_angles(std::cin));
        doc1->add_figure(std::move(new_figure),id);
    }
    else if(figures == "8")
    {
        std::unique_ptr<figure> new_figure = std::make_unique<eight_angles>( eight_angles(std::cin));
        doc1->add_figure(std::move(new_figure),id);
    }
}
