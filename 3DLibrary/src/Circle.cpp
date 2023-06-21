#include <Ellipse.hpp>
#include <Circle.hpp>
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius) : Ellipse(radius, radius) {
    if (radius < 0) {
        throw std::invalid_argument("Radius of Circle cannot be less than 0");
    }
}

const char* Circle::getName() const {
    return "Circle";
}