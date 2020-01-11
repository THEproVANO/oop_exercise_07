#include <iostream>

#include "eight_angles.h"

eight_angles::eight_angles(std::istream &is)//метод ввода вершин восьмиугольника
{
    for (size_t i = 0; i < 8; i++)
    {
        std::cout << "Input the " << i+1 << " vertex: \n";
        is >> this->points[i];
    }
}

void eight_angles::read_file(std::istream &is)//чтение вершин из файла
{
    for (size_t i = 0; i < 8; i++)
        this->points[i].read_file(is);
}

Vertex<double> eight_angles::center() const //метод подсчёта центра фигуры
{
    Vertex<double> p;
    for (size_t i = 0; i < 8; i++)
        p = p + points[i];
    p/=8;
    return p;
}

void eight_angles::print(std::ostream &os) const {//метод вывода в консоль
    os << points[0] << " " << points[1] << " " << points[2] << " " << points[3] << " " << points[4] << " " << points[5] << " " << points[6]
    << " " << points[7]<<"\n";
}
void eight_angles::help_print(std::ostream &os) const {//метод вывода в файл
    os <<"3 " << points[0] << " " << points[1] << " " << points[2] << " " << points[3] << " "
      << points[4] << " " << points[5] << " " << points[6]
       << " " << points[7]<<"\n";
}

double eight_angles::square() const {//метод подсчёта площади фигуры
    double s=0;
    s = std::abs(points[0].coord.first*points[1].coord.second+points[1].coord.first*points[2].coord.second+points[2].coord.first*
       points[3].coord.second+points[3].coord.first*points[4].coord.second+points[4].coord.first*points[5].coord.second+
       points[5].coord.first*points[6].coord.second+points[6].coord.first*points[7].coord.second+
            points[7].coord.first*points[0].coord.second-points[1].coord.first*points[0].coord.second-points[2].coord.first*
       points[1].coord.second-points[3].coord.first*points[2].coord.second-points[4].coord.first*points[3].coord.second-
       points[5].coord.first*points[4].coord.second-points[6].coord.first*points[5].coord.second
            -points[7].coord.first*points[6].coord.second-points[0].coord.first*points[7].coord.second)/2;
    return s;
}
