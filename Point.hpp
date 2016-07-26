//
//  Point.hpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <cmath>

class Point {
private:
    double x, y;
public:
    Point(): x(0), y(0) {}
    Point(double x, double y): x(x), y(y) {}
    
    double getX() {
        return x;
    }
    
    double getY() {
        return y;
    }
    
    double getLen() {
        return sqrt(x * x + y * y);
    }
    
    void normalize() {
        double len = getLen();
        x /= len;
        y /= len;
    }
    
    double operator* (Point p) {
        return x * p.getX() + y * p.getY();
    }
    
    Point operator* (double a) {
        return Point(x * a, y * a);
    }
    
    Point operator+ (Point b) {
        return Point(x + b.getX(), y + b.getY());
    }
    
};

#endif /* Point_hpp */
