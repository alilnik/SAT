//
//  Polygon.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include "Polygon.hpp"
#include "utils.hpp"

Polygon::Polygon() {
    this->points = new std::vector<Point>();
}

std::vector<Point> * Polygon::getPoints() {
    return points;
}

Polygon::~Polygon() {
    delete points;
}


std::vector<Point> Polygon::getBasePoints() {
    return *points;
}

std::vector<Axis> Polygon::getAxis(Shape & other) {
    std::vector<Axis> result;
    int size = points->size();
    for (int i = 0; i < size; i++) {
        result.push_back(Axis(points->at(i % size), points->at((i + 1) % size)));
    }
    return result;
}

double* Polygon::project(Axis axis) {
    double result[] = {axis.projection(points->at(0)), axis.projection(points->at(0))};
    int size = points->size();
    for (int i = 0; i < size; i++) {
        double projectionFrom = axis.projection(points->at(i % size));
        double projectionTo = axis.projection(points->at((i + 1) % size));
        double top = max(projectionFrom, projectionTo);
        double bot = min(projectionFrom, projectionTo);
        result[0] = min(result[0], bot);
        result[1] = max(result[1], top);
    }
    
    return result;
}

Point Polygon::getCenter() {
    double x = 0, y = 0;
    
    for (int i = 0; i < points->size(); i++) {
        x += points->at(i).getX();
        y += points->at(i).getY();
    }
    
    x /= points->size();
    y /= points->size();
    
    return Point(x, y);
}

bool Polygon::isInside(rect * r) {
    
    for (int i = 0; i < points->size(); i++) {
        if (!r->isInside(points->at(i))) {
            return false;
        }
    }
    return true;
}