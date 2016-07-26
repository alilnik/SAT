//
//  main.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 11.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Shape.hpp"
#include "Sphere.hpp"
#include "Polygon.hpp"
#include "Axis.hpp"
#include "quadtree.hpp"

void runTests();

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*Shape *s = new Sphere(Point(1, 1), sqrt(2) / 2);
    Shape *s2 = new Sphere(Point(2, 2), sqrt(2.1) / 2);
    Polygon *p = new Polygon();
    
    p->getPoints()->push_back(Point(0, 0));
    p->getPoints()->push_back(Point(1, 1));
    p->getPoints()->push_back(Point(2, 0));
    
    Axis a(Point(0, 0), Point(-1, 1));
    
    Quadtree tree;
    tree.setBounds(new rect(0, 0, 1, 1));
    
    for (int i = 0; i < 6; i++) {
        tree.insert(new Sphere(Point(0.11 * i, 0.11 * i), 1));
    }
    
    std::cout << "Hello, World!\n";
    std::cout << s->isColide(*s2) << std::endl;*/
    
    runTests();
    return 0;
}
