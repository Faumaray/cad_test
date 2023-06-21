#pragma once
#include <Curve.hpp>

class Ellipse : public Curve {
public:
    Ellipse(double radiusX, double radiusY);
    virtual Point3D calculatePoint(double t) const override;
    virtual Vector3D calculateDerivative(double t) const override;
    virtual const char* getName() const override;

    double getRadiusX() const { return radiusX_; };
    double getRadiusY() const { return radiusY_; };

protected:
    double radiusX_;
    double radiusY_;
};
