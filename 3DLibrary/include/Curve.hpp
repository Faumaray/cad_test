#pragma once

struct Point3D {
    double x;
    double y;
    double z;

    Point3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {};
};

struct Vector3D {
    double dx;
    double dy;
    double dz;

    Vector3D(double _dx, double _dy, double _dz) : dx(_dx), dy(_dy), dz(_dz) {};
};

class Curve {
public:
    virtual const char* getName() const = 0;
    virtual Point3D calculatePoint(double t) const = 0;
    virtual Vector3D calculateDerivative(double t) const = 0;
    virtual ~Curve() = 0;
};