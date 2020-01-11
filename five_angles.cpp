#include <iostream>

#include "five_angles.h"

five_angles::five_angles(std::istream &is)
{
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Input the " << i+1 << " vertex: \n";
        is >> this->points[i];
    }
}

void five_angles::read_file(std::istream &is)//чтение вершин из файла
{
    for (size_t i = 0; i < 5; i++)
        this->points[i].read_file(is);
}

Vertex<double> five_angles::center() const {
    Vertex<double> p;
    for (size_t i = 0; i < 5; i++)
        p = p + points[i];
    p /= 5;
    return p;
}

void five_angles::print(std::ostream &os) const {
    os << points[0] << " " << points[1] << " " << points[2] << " " << points[3] << " " << points[4] <<"\n";
}
void five_angles::help_print(std::ostream &os) const {
    os << "1 " << points[0] << " " << points[1] << " " << points[2] << " " << points[3] << " " << points[4] <<"\n";
}

double five_angles::square() const {
    double s=0;
    s = std::abs(points[0].coord.first*points[1].coord.second+points[1].coord.first*points[2].coord.second+points[2].coord.first*points[3].coord.second+points[3].coord.first*
       points[4].coord.second+points[4].coord.first*points[0].coord.second-points[1].coord.first*points[0].coord.second-
            points[2].coord.first*points[1].coord.second-points[3].coord.first*points[2].coord.second-
       points[4].coord.first*points[3].coord.second-points[0].coord.first*points[4].coord.second)/2;
    return s;
}
