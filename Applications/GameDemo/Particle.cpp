//
//  Particle.cpp
//  GameDemo
//
//  Created by Samuel Davis on 16/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#include "Particle.hpp"
#include <stdlib.h>

Particle::Particle()
{
    m_x = ((2.0 * rand())/RAND_MAX) - 1;
    m_y = ((2.0 * rand())/RAND_MAX) - 1;
}

Particle::~Particle()
{
    
}
