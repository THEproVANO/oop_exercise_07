#ifndef D_SIX_ANGLES_H_
#define D_SIX_ANGLES_H_

#include <iostream>
#include "figure.h"


struct six_angles : figure
{
    virtual ~six_angles() override {};
    six_angles(std::istream &is);
    six_angles() = default;
    Vertex<double> center() const override;
    void print(std::ostream &os) const override;
    void help_print(std::ostream &os) const override;
    void read_file(std::istream &is) override;
    double square() const override;
private:
    Vertex<double> points[6];
};

#endif
