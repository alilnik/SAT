//
//  tests.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 26.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include <iostream>

bool runCollisionTests();
bool runQuadtreeTests();
void runMeasuringTest();

void runTests() {
    
    bool collision = runCollisionTests();
    if (!collision) {
        std::cout << "Collision Tests FAILED!" << std::endl;
    }
    
    bool quadtree = runQuadtreeTests();
    if (!quadtree) {
        std::cout << "Quadtree Tests FAILED!" << std::endl;
    }
    
    runMeasuringTest();
}