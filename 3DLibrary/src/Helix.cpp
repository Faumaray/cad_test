#include <Helix.hpp>
#include <cmath>
#include <numbers>
#include <stdexcept>

Helix::Helix(double radius, double step) : radius_(radius), step_(step) {
    if(radius_ < 0){
        throw std::invalid_argument("Radius of Helix cannot be less than 0");
    }

};

const char* Helix::getName() const {
    return "Helix";
}

Point3D Helix::calculatePoint(double t) const {
    double x = radius_ * std::cos(t);
    double y = radius_ * std::sin(t);
    double z = step_ * t / (2.0 * std::numbers::pi);
    return Point3D(x, y, z);
}

Vector3D Helix::calculateDerivative(double t) const {
    double dx_dt = -radius_ * std::sin(t);
    double dy_dt = radius_ * std::cos(t);
    double dz_dt = step_ / (2.0 * std::numbers::pi);
    #ifdef Vector3DStruct
    return Vector3D(dx_dt, dy_dt, dz_dt);
    #else
    return Vector3D{dx_dt, dy_dt, dz_dt};
    #endif
}
