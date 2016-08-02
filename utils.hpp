//
//  utils.hpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include "Point.hpp"
#include <vector>


double min(double a, double b);
double max(double a, double b);

class rect {
public:
    double left;
    double right;
    double up;
    double down;
public:
    rect(double left, double down, double right, double up)
    : left(left), up(up), right(right), down(down) {}
    
    Point center() {
        return Point(left / 2 + right / 2, up / 2 + down / 2);
    }
    
    bool isInside(Point p) {
        return p.getX() >= left && p.getX() <= right && p.getY() >= down && p.getY() <= up;
    }
};

#endif /* utils_hpp */
