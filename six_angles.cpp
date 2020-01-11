#include <iostream>

#include "six_angles.h"

six_angles::six_angles(std::istream &is)
{
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << "Input the " << i+1 << " vertex: \n";
        is >> this->points[i];
    }
}

void six_angles::read_file(std::istream &is)//чтение вершин из файла
{
    for (size_t i = 0; i < 6; i++)
        this->points[i].read_file(is);
}

Vertex<double> six_angles::center() const {
    Vertex<double> p;
    for (size_t i = 0; i < 6; i++)
        p = p + points[i];
    p/=6;
    return p;
}

void six_angles::print(std::ostream &os) const {
    os << points[0] << " " << points[1] << " " << points[2] << " " << points[3] << " " << points[4] << " " << points[5] <<"\n";
}
void six_angles::help_print(std::ostream &os) const {
    os <<"2 " << points[0] << " " << points[1] << " " << points[2] << " " << points[3] << " " << points[4] << " " << points[5] <<"\n";
}

double six_angles::square() const {
    double s=0;
    s = std::abs(points[0].coord.first*points[1].coord.second+points[1].coord.first*points[2].coord.second+points[2].coord.first
            *points[3].coord.second+points[3].coord.first*points[4].coord.second+points[4].coord.first*points[5].coord.second
            +points[5].coord.first*points[0].coord.second-points[1].coord.first*points[0].coord.second-
       points[2].coord.first*points[1].coord.second-points[3].coord.first*points[2].coord.second
            -points[4].coord.first*points[3].coord.second-points[5].coord.first*points[4].coord.second-points[0].coord.first*points[5].coord.second)/2;
    return s;
}
