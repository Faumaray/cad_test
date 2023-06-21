#pragma once
#include <Ellipse.hpp>

class Circle : public Ellipse {
public:
    Circle(double radius);
    virtual const char* getName() const override;

    double getRadius() const {return radiusX_;};
};
