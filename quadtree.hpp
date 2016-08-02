//
//  quadtree.hpp
//  bdmSAT
//
//  Created by Victor Drobny on 17.07.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#ifndef quadtree_hpp
#define quadtree_hpp

#include <stdio.h>
#include <vector>

#include "Shape.hpp"
#include "utils.hpp"

using std::vector;

int const MAX_OBJECTS = 5;
int const FOUR = 4;

class Quadtree {
private:
    Quadtree *nodes;
    Quadtree *parent;
    vector<Shape *> * shapes;
    rect * bounds;
    
    int getIndex(Point p) {
        double x = p.getX();
        double y = p.getY();
        if (x > bounds->center().getX()) {
            if (y > bounds->center().getY()) {
                return 1;
            } else {
                return 4;
            }
        } else {
            if (y > bounds->center().getY()) {
                return 2;
            } else {
                return 3;
            }
        }
    }
    
public:
    Quadtree()
    {
        nodes = nullptr;
        parent = nullptr;
        shapes = new vector<Shape *>();
        bounds = new rect(-1, -1, 1, 1);
    }
    
    ~Quadtree()
    {
        if (nodes != nullptr)
            delete[] nodes;
        nodes = nullptr;
        delete shapes;
        delete bounds;
    }
    
    void clear() {
        shapes->clear();
        delete[] nodes;
        nodes = nullptr;
    }
    
    void setBounds(rect * bounds) {
        this->bounds = bounds;
    }
    
    void insert(Shape * shape) {
        if (nodes == nullptr) {
            if (shapes->size() >= MAX_OBJECTS) {
                split();
                nodes[getIndex(shape->getCenter()) - 1].insert(shape);
            } else {
                shapes->push_back(shape);
            }
        } else {
            int idx = getIndex(shape->getCenter()) - 1;
            if (shape->isInside(nodes[idx].bounds)) {
                nodes[idx].insert(shape);
            } else {
                shapes->push_back(shape);
            }
        }
    }
    
    void split() {
        double x0, y0, x1, y1, x2, y2;
        x0 = bounds->left;
        y0 = bounds->down;
        x2 = bounds->right;
        y2 = bounds->up;
        x1 = (x0 + x2) / 2;
        y1 = (y0 + y2) / 2;
        nodes = new Quadtree[FOUR];
        nodes[3].setBounds(new rect(x1, y0, x2, y1));
        nodes[2].setBounds(new rect(x0, y0, x1, y1));
        nodes[1].setBounds(new rect(x0, y1, x1, y2));
        nodes[0].setBounds(new rect(x1, y1, x2, y2));
        
        vector<Shape *> * oldShapes = shapes;
        shapes = new vector<Shape *>();
        for (int i = 0; i < oldShapes->size(); i++) {
            //int ind = getIndex(shapes->at(i)->getCenter()) - 1;
            //nodes[ind].insert(shapes->at(i));
            insert(oldShapes->at(i));
        }
        delete oldShapes;
        //shapes->clear();
    }
    
    vector<Shape *> getNeighbours(Shape shape) {
        if (nodes == nullptr) {
            if(std::find(shapes->begin(), shapes->end(), &shape) != shapes->end()) {
                /* v contains x */
                vector<Shape*> result;
                std::copy (shapes->begin(), shapes->end(), result.begin() );
                return result;
            } else {
                return vector<Shape*>();
            }
        } else {
            return nodes[getIndex(shape.getCenter()) - 1].getNeighbours(shape);
        }
    }
    
    
    /* return elements if it is leaf node, otherwise nullptr */
    vector<Shape *> * getElements() {
        return shapes;
    }
    
    vector<Quadtree *> getLeafNodes() {
        vector<Quadtree *> result;
        if (nodes == nullptr) {
            result.push_back(this);
        } else {
            auto leafnodes0 = nodes[0].getLeafNodes();
            auto leafnodes1 = nodes[1].getLeafNodes();
            auto leafnodes2 = nodes[2].getLeafNodes();
            auto leafnodes3 = nodes[3].getLeafNodes();
            for (int i = 0; i < leafnodes0.size(); i++) {
                result.push_back(leafnodes0.at(i));
            }
            for (int i = 0; i < leafnodes1.size(); i++) {
                result.push_back(leafnodes1.at(i));
            }
            for (int i = 0; i < leafnodes2.size(); i++) {
                result.push_back(leafnodes2.at(i));
            }
            for (int i = 0; i < leafnodes3.size(); i++) {
                result.push_back(leafnodes3.at(i));
            }
        }
        
        
        return result;
    }
    
    int size() {
        int result = 0;
        result += shapes->size();
        if (nodes != nullptr) {
            result += nodes[0].size() + nodes[1].size() + nodes[2].size() + nodes[3].size();
        }
        return result;
    }
    
    Quadtree * getParentNode() {
        return parent;
    }
    
    vector<Quadtree *> getAllNodes() {
        vector<Quadtree *> result;
        result.push_back(this);
        if (nodes == nullptr) {
            
        } else {
            auto leafnodes0 = nodes[0].getAllNodes();
            auto leafnodes1 = nodes[1].getAllNodes();
            auto leafnodes2 = nodes[2].getAllNodes();
            auto leafnodes3 = nodes[3].getAllNodes();
            for (int i = 0; i < leafnodes0.size(); i++) {
                result.push_back(leafnodes0.at(i));
            }
            for (int i = 0; i < leafnodes1.size(); i++) {
                result.push_back(leafnodes1.at(i));
            }
            for (int i = 0; i < leafnodes2.size(); i++) {
                result.push_back(leafnodes2.at(i));
            }
            for (int i = 0; i < leafnodes3.size(); i++) {
                result.push_back(leafnodes3.at(i));
            }
        }
        
        
        return result;
    }

};

#endif /* quadtree_hpp */
