//
//  Axis.hpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#ifndef Axis_hpp
#define Axis_hpp

#include <stdio.h>
#include "Point.hpp"


class Axis {
private:
    Point dir;
public:
    Axis(Point dir): dir(dir) {}
    Axis(Point from, Point to, bool isParallel = false); //Axis that parallel to normal of line between from and dir
    
    double projection(Point p);
};

#endif /* Axis_hpp */
