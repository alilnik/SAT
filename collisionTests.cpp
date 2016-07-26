//
//  collisionTests.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 26.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Shape.hpp"
#include "Sphere.hpp"
#include "Polygon.hpp"


bool collisionTest1() {
    Shape *s = new Sphere(Point(1, 1), sqrt(2) / 2);
    Shape *s2 = new Sphere(Point(2, 2), sqrt(2.1) / 2);
    bool result = s->isColide(*s2) == true;
    delete s;
    delete s2;
    return result;
}

bool collisionTest2() {
    Shape *s = new Sphere(Point(1, 1), sqrt(2) / 2);
    Shape *s2 = new Sphere(Point(2, 2), sqrt(1.9) / 2);
    bool result = s->isColide(*s2) == false;
    delete s;
    delete s2;
    return result;
}

bool collisionTest3() {
    Shape *s = new Sphere(Point(2, 0), 1.1);
    Polygon *s2 = new Polygon();
    
    s2->getPoints()->push_back(Point(0, 0));
    s2->getPoints()->push_back(Point(0, 1));
    s2->getPoints()->push_back(Point(1, 1));
    s2->getPoints()->push_back(Point(1, 0));
    
    
    bool result = s->isColide(*s2) == true;
    delete s;
    delete s2;
    return result;
}

bool collisionTest4() {
    Shape *s = new Sphere(Point(2, 0), 0.9);
    Polygon *s2 = new Polygon();
    
    s2->getPoints()->push_back(Point(0, 0));
    s2->getPoints()->push_back(Point(0, 1));
    s2->getPoints()->push_back(Point(1, 1));
    s2->getPoints()->push_back(Point(1, 0));
    
    
    bool result = s->isColide(*s2) == false;
    delete s;
    delete s2;
    return result;
}

bool collisionTest5() {
    Polygon *s = new Polygon();
    Polygon *s2 = new Polygon();
    
    s->getPoints()->push_back(Point(1.1, 0.5));
    s->getPoints()->push_back(Point(2, 1));
    s->getPoints()->push_back(Point(2, 0));
    
    s2->getPoints()->push_back(Point(0, 0));
    s2->getPoints()->push_back(Point(0, 1));
    s2->getPoints()->push_back(Point(1, 1));
    s2->getPoints()->push_back(Point(1, 0));
    
    
    bool result = s->isColide(*s2) == false;
    delete s;
    delete s2;
    return result;
}

bool collisionTest6() {
    Polygon *s = new Polygon();
    Polygon *s2 = new Polygon();
    
    s->getPoints()->push_back(Point(0.9, 0.5));
    s->getPoints()->push_back(Point(2, 1));
    s->getPoints()->push_back(Point(2, 0));
    
    s2->getPoints()->push_back(Point(0, 0));
    s2->getPoints()->push_back(Point(0, 1));
    s2->getPoints()->push_back(Point(1, 1));
    s2->getPoints()->push_back(Point(1, 0));
    
    
    bool result = s->isColide(*s2) == true;
    delete s;
    delete s2;
    return result;
}



typedef bool (*BoolFunctionWithNoParameter) ();

bool runCollisionTests() {
    bool result = true;
    BoolFunctionWithNoParameter tests[] = {collisionTest1, collisionTest2, collisionTest3, collisionTest4, collisionTest5, collisionTest6};
    std::cout << "Collision tests:" << std::endl << "=======================" << std::endl;
    for (int i = 0; i < 1.0 * sizeof(tests) / sizeof(BoolFunctionWithNoParameter); i++) {
        bool testResult = tests[i]();
        if (testResult) {
            std::cout << i + 1 << "-th test PASSED!" << std::endl;
        } else {
            std::cout << i + 1 << "-th test FAILED!" << std::endl;
        }
        result &= testResult;
    }
    std::cout << "=======================" << std::endl;
    return result;
}