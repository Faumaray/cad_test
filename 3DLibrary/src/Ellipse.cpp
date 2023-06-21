#include <Ellipse.hpp>
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(double radiusX, double radiusY) : radiusX_(radiusX), radiusY_(radiusY) {
    if (radiusX_ < 0.0 || radiusY_ < 0.0) {
        throw std::invalid_argument("Radius of Ellipse cannot be less than 0");
    }

};

const char* Ellipse::getName() const {
    return "Ellipse";
}

Point3D Ellipse::calculatePoint(double t) const {
    double x = radiusX_ * std::cos(t);
    double y = radiusY_ * std::sin(t);
    double z = 0.0;
    return Point3D(x, y, z);
}

Vector3D Ellipse::calculateDerivative(double t) const {
    double dx_dt = -radiusX_ * std::sin(t);
    double dy_dt = radiusY_ * std::cos(t);
    double dz_dt = 0.0;
    return Vector3D(dx_dt, dy_dt, dz_dt);
}
