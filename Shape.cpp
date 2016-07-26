//
//  Shape.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include "Shape.hpp"


bool Shape::isColide(Shape & other) {
    std::vector<Axis> axises, aAxis = getAxis(other), bAxis = other.getAxis(*this);
    
    axises.insert(std::end(axises), std::begin(aAxis), std::end(aAxis));
    axises.insert(std::end(axises), std::begin(bAxis), std::end(bAxis));
    
    for (int i = 0; i < axises.size(); i++) {
        double projectionA[2];
        double projectionB[2];
        double * tmp;
        
        tmp = project(axises.at(i));
        projectionA[0] = tmp[0];
        projectionA[1] = tmp[1];
        
        tmp = other.project(axises.at(i));
        projectionB[0] = tmp[0];
        projectionB[1] = tmp[1];
        
        if (projectionA[0] > projectionB[1] || projectionA[1] < projectionB[0])
            return false;
    }
    
    return true;
}