//
//  collision.hpp
//  bdmSAT
//
//  Created by Victor Drobny on 02.08.16.
//  Copyright © 2016 Victor Drobny. All rights reserved.
//

#ifndef collision_hpp
#define collision_hpp

#include <stdio.h>
#include "quadtree.hpp"


int collideAll(Quadtree * node);
int collide(Quadtree * node);


#endif /* collision_hpp */
