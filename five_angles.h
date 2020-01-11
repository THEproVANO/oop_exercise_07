#ifndef D_FIVE_ANGLES_H_
#define D_FIVE_ANGLES_H_

#include <iostream>
#include "figure.h"

struct five_angles : figure
{
    virtual ~five_angles() override {};
    five_angles(std::istream &is);
    five_angles() = default;
    Vertex<double> center() const override;
    void print(std::ostream &os) const override;
    void help_print(std::ostream &os) const override;
    void read_file(std::istream &is) override;
    double square() const override;
private:
    Vertex<double> points[5];
};

#endif
