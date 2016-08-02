//
//  Sphere.hpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>
#include <vector>
#include "Shape.hpp"
#include "Point.hpp"

class Sphere : public Shape {
private:
    double radious;
    Point center;
public:
    Sphere(Point center, double radious);
    std::vector<Axis> getAxis(Shape & other);
    std::vector<Point> getBasePoints();
    double* project(Axis axis);
    ~Sphere();
    Point getCenter();
    bool isInside(rect * r);
};

#endif /* Sphere_hpp */
