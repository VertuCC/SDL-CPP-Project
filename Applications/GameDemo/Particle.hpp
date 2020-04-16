//
//  Particle.hpp
//  GameDemo
//
//  Created by Samuel Davis on 16/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

struct Particle
{
    double m_x; //m to indicate that it's a member variable
    double m_y;
    
public:
    Particle();
    virtual ~Particle();
};

#endif /* Particle_hpp */
