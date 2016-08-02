//
//  Polygon.hpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#ifndef Polygon_hpp
#define Polygon_hpp

#include <vector>
#include <stdio.h>
#include "Shape.hpp"
#include "Point.hpp"

class Polygon : public Shape {
private:
    std::vector<Point> *points;
public:
    Polygon();
    std::vector<Point> * getPoints();
    std::vector<Point> getBasePoints();
    std::vector<Axis> getAxis(Shape & other);
    double* project(Axis axis);
    ~Polygon();
    Point getCenter();
    bool isInside(rect * r);
};

#endif /* Polygon_hpp */
