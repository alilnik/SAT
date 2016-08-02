//
//  collision.cpp
//  bdmSAT
//
//  Created by Victor Drobny on 02.08.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#include "collision.hpp"
#include <vector>

using std::vector;

void collideAll(Quadtree * node) {
    vector<Quadtree *> nodes = node->getAllNodes();
    for (int j = 0; j < nodes.size(); j++) {
        collide(nodes.at(j));
    }
    
}

void collide(Quadtree * node) {
    auto shapes = node->getElements();
    for (int k = 0; k < shapes->size(); k++) {
        for (int l = k; ++l < shapes->size(); l++) {
            shapes->at(k)->isColide(*shapes->at(l));
        }
    }
    Quadtree * parent = node;
    while ((parent = node->getParentNode()) != nullptr) {
        auto parentShapes = parent->getElements();
        for (int k = 0; k < shapes->size(); k++) {
            for (int l = 0; l < parentShapes->size(); l++) {
                shapes->at(k)->isColide(*parentShapes->at(l));
            }
        }
        
    }

}