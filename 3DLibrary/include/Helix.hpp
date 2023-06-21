#pragma once
#include <Curve.hpp>

class Helix : public Curve {
public:
    Helix(double radius, double step);
    virtual Point3D calculatePoint(double t) const override;
    virtual Vector3D calculateDerivative(double t) const override;
    virtual const char* getName() const override;

    double getStep() const { return step_;};
    double getRadius() const { return radius_;};

private:
    double radius_;
    double step_;
};
