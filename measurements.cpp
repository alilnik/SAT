//
//  measurements.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 26.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "quadtree.hpp"
#include "Sphere.hpp"
#include "Polygon.hpp"


double inline r() {
    return 1.0 * rand() / RAND_MAX;
}

void testWithoutQuadtree() {
    int sizes[]{100, 1000, 10000};
    srand(2);
    std::cout << "=======================" << std::endl << "Collision detection time without quadtree: " << std::endl;
    
    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        std::cout << "Size " << sizes[i] << ": ";
        Shape ** shapes = new Shape*[sizes[i]];
        for (int j = 0; j < sizes[i]; j++) {
            shapes[j] = new Sphere(Point(r(), r()), r());
        }
        clock_t begin = clock();
        for (int j = 0; j < sizes[i]; j++) {
            for (int k = 0; ++k < sizes[i]; k++) {
                shapes[j]->isColide(*shapes[k]);
            }
        }
    
        clock_t end = clock();
        double timeInSeconds = double(end - begin) / CLOCKS_PER_SEC;
        std::cout << timeInSeconds << " sec" << std::endl;
    }
    std::cout << "=======================" << std::endl;
}

void testWithQuadtree() {
    int sizes[]{100, 1000, 10000, 100000, 1000000};
    srand(2);
    std::cout << "=======================" << std::endl << "Collision detection time with quadtree: " << std::endl;
    
    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        std::cout << "Size " << sizes[i] << ": ";
        Quadtree qt;
        qt.setBounds(new rect(0, 0, 1, 1));
        
        clock_t qtBegin = clock();
        for (int j = 0; j < sizes[i]; j++) {
            qt.insert(new Sphere(Point(r(), r()), r()));
        }
        clock_t qtEnd = clock();
        double qtTimeInSeconds = double(qtEnd - qtBegin) / CLOCKS_PER_SEC;
        
        
        
        vector<Quadtree *> leafNodes = qt.getLeafNodes();
        clock_t begin = clock();
        for (int j = 0; j < leafNodes.size(); j++) {
            auto shapes = leafNodes.at(j)->getElements();
            for (int k = 0; k < shapes->size(); k++) {
                for (int l = k; ++l < shapes->size(); l++) {
                    shapes->at(k)->isColide(*shapes->at(l));
                }
            }
        }
        clock_t end = clock();
        double timeInSeconds = double(end - begin) / CLOCKS_PER_SEC;
        
        std::cout << timeInSeconds << " sec, " << "Quadtree making - " << qtTimeInSeconds << " sec" << std::endl;
    }
    std::cout << "=======================" << std::endl;
}

void runMeasuringTest() {
    //testWithoutQuadtree();
    testWithQuadtree();
}