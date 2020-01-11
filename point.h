#pragma once
#include <iostream>

template <class T>
struct Vertex
{
    using m_Vertex = std::pair<T,T>;
    m_Vertex coord;
    void read_file(std::istream& is);
};

template <class T>
void Vertex<T>::read_file(std::istream& is)
{
    is >> this->coord.first >> this->coord.second;
}

template <class T>
std::istream& operator>> (std::istream& is, Vertex<T>& p){
    std::cout << "Coordinate 'x': ";
    is >> p.coord.first;
    std::cout << "Coordinate 'y': ";
    is >> p.coord.second;
    return is;
}

template <class T>
std::ostream& operator<< (std::ostream& os, const Vertex<T>& p){
    os << "[" << p.coord.first << "; " << p.coord.second << "]";
    return os;
}

template<class T>
Vertex<T> operator+(const Vertex<T>& A, const Vertex<T>& B) {
    Vertex<T> res;
    res.coord.first = A.coord.first + B.coord.first;
    res.coord.second = A.coord.second + B.coord.second;
    return res;
}

template<class T>
Vertex<T> operator/=(Vertex<T>& res, const int& number) {
    res.coord.first = res.coord.first / number;
    res.coord.second = res.coord.second / number;
    return res;
}
