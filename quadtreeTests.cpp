//
//  quadtreeTests.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 26.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include <iostream>
#include "quadtree.hpp"
#include "Shape.hpp"
#include "Sphere.hpp"


bool quadtreeTest1() {
    Quadtree qt;
    qt.setBounds(new rect(0, 0, 1, 1));
    return qt.getLeafNodes().size() == 1;
}

bool quadtreeTest2() {
    Quadtree qt;
    qt.setBounds(new rect(0, 0, 1, 1));
    Shape *s = new Sphere(Point(0, 0), 1);
    qt.insert(s);
    bool result = qt.getElements()->size() == 1;
    delete s;
    return result;
}

bool quadtreeTest3() {
    Quadtree qt;
    qt.setBounds(new rect(0, 0, 1, 1));
    Shape *s = new Sphere(Point(0, 0), 1);
    qt.insert(s);
    qt.clear();
    bool result = qt.getElements()->size() == 0;
    delete s;
    return result;
}

bool quadtreeTest4() {
    Quadtree qt;
    qt.setBounds(new rect(0, 0, 1, 1));
    Sphere s[] {Sphere(Point(0, 0), 1), Sphere(Point(0.11, 0.11), 1),
        Sphere(Point(0.55, 0.1), 1), Sphere(Point(0.99, 0.99), 1), Sphere(Point(0, 0.99), 1), Sphere(Point(0, 0.98), 1)};
    for (int i = 0; i < 6; i++) {
        qt.insert(s + i);
    }
    bool result = qt.getLeafNodes().size() == 4;
    
    return result;
}

bool quadtreeTest5() {
    Quadtree qt;
    qt.setBounds(new rect(0, 0, 1, 1));
    Sphere s[] {Sphere(Point(0, 0), 1), Sphere(Point(0.11, 0.11), 1),
        Sphere(Point(0.55, 0.1), 1), Sphere(Point(0.99, 0.99), 1), Sphere(Point(0, 0.99), 1), Sphere(Point(0, 0.98), 1)};
    for (int i = 0; i < 6; i++) {
        qt.insert(s + i);
    }
    qt.clear();
    bool result = qt.getLeafNodes().size() == 1;
    
    return result;
}

typedef bool (*BoolFunctionWithNoParameter) ();

bool runQuadtreeTests() {
    bool result = true;
    BoolFunctionWithNoParameter tests[] = {quadtreeTest1, quadtreeTest2, quadtreeTest3, quadtreeTest4, quadtreeTest5};
    std::cout << "Quadtree tests:" << std::endl << "=======================" << std::endl;
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