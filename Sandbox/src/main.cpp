#include <Circle.hpp>
#include <Ellipse.hpp>
#include <Helix.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <numbers>

int main() {
    std::vector<Curve*> curves;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> radiusDist(1.0, 10.0);
    std::uniform_real_distribution<double> stepDist(0.1, 1.0);

    for (int i = 0; i < 5; ++i) {
        double radius = radiusDist(gen);
        double step = stepDist(gen);

        if (i % 3 == 0) {
            curves.push_back(new Circle(radius));
        } else if (i % 3 == 1) {
            curves.push_back(new Ellipse(radius, radius * 0.7));
        } else {
            curves.push_back(new Helix(radius, step));
        }
    }

    double t = std::numbers::pi / 4.0;

    for (const Curve* curve : curves) {
        Point3D point = curve->calculatePoint(t);
        Vector3D derivative = curve->calculateDerivative(t);
        std::cout << curve->getName() << "\n";
        std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")\n";
        #ifdef Vector3DStruct
        std::cout << "Derivative: (" << derivative.dx << ", " << derivative.dy << ", " << derivative.dz << ")\n" << std::endl;
        #else
        std::cout << "Derivative: (" << derivative[0] << ", " << derivative[1] << ", " << derivative[3] << ")\n" << std::endl;
        #endif
    }

    std::vector<Circle*> circles;

    for (Curve* curve : curves) {
        if (Circle* circle = dynamic_cast<Circle*>(curve)) {
            circles.push_back(circle);
        }
    }

    std::sort(circles.begin(), circles.end(),
              [](const Circle* circle1, const Circle* circle2) {
                  return circle1->getRadius() < circle2->getRadius();
              });


    double sumOfRadii = std::accumulate(circles.begin(), circles.end(), 0.0,
        [](double accumulator, Circle* circle) {
            return accumulator + circle->getRadius();
    });

    std::cout << "Sum of radii: " << sumOfRadii << std::endl;

    return 0;
}
