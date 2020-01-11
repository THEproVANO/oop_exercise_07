#ifndef D_EIGHT_ANGLES_H_
#define D_EIGHT_ANGLES_H_

#include <iostream>
#include "figure.h"

struct eight_angles : figure
{
    virtual ~eight_angles() override {};
    eight_angles(std::istream &is);
    eight_angles() = default;
    Vertex<double> center() const override;
    void print(std::ostream &os) const override;
    void help_print(std::ostream &os) const override;
    void read_file(std::istream &is) override;
    double square() const override;
private:
    Vertex<double> points[8];
};

#endif
