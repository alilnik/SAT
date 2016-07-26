//
//  Sphere.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include "Sphere.hpp"


Sphere::Sphere(Point center, double radious) {
    this->center = center;
    this->radious = radious;
}

Sphere::~Sphere() {
    
}

std::vector<Axis> Sphere::getAxis(Shape & other) {
    std::vector<Axis> result;
    int size = other.getBasePoints().size();
    for (int i = 0; i < size; i++) {
        Point from = center;
        Point to = other.getBasePoints().at(i % size);
        result.push_back(Axis(from, to, true));
    }
    return result;
}

std::vector<Point> Sphere::getBasePoints() {
    std::vector<Point> result;
    result.push_back(center);
    return result;
}

double* Sphere::project(Axis axis) {
    double result[] = {0, 0};
    double projection = axis.projection(center);
    result[0] = projection - radious;
    result[1] = projection + radious;
    return result;
}

Point Sphere::getCenter() {
    return center;
}