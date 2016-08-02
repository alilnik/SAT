//
//  utils.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include "utils.hpp"
#include <vector>

using std::vector;

double min(double a, double b) {
    return a > b ? b : a;
}

double max(double a, double b) {
    return a > b ? a : b;
}

