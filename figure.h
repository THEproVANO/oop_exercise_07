#ifndef D_FIGURE_H_
#define D_FIGURE_H_

#include <iostream>

#include "point.h"

struct figure
{
    virtual Vertex<double> center() const = 0;
    virtual void print(std::ostream &os) const = 0;
    virtual void help_print(std::ostream &os) const = 0;
    virtual void read_file(std::istream &is) = 0;
    virtual double square() const = 0;
    virtual ~figure() {};
};
#endif
