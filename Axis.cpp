//
//  Axis.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include "Axis.hpp"

Axis::Axis(Point from, Point to, bool isParallel) {
    if (from.getX() == to.getX()) {
        this->dir = Point(1, 0);
    } else if (from.getY() == to.getY()) {
        this->dir = Point(0, 1);
    } else {
        this->dir = Point(to.getY() - from.getY(), from.getX() - to.getX());
        this->dir.normalize();
    }
    
    if (isParallel) {
        this->dir = Point(dir.getY(), -dir.getX());
    }
}

double Axis::projection(Point p) {
    return dir * p;
}