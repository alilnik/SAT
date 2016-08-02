//
//  Shape.hpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <vector>
#include "Axis.hpp"
#include "utils.hpp"

class Shape {
public:
    virtual ~Shape(){}
    virtual std::vector<Axis> getAxis(Shape & other) = 0;
    virtual std::vector<Point> getBasePoints() = 0;
    virtual double* project(Axis axis) = 0;
    bool isColide(Shape & other);
    virtual Point getCenter() = 0;
    virtual bool isInside(rect * r) = 0;
};

#endif /* Shape_hpp */
