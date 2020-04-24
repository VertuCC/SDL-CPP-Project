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
    
private:
    double m_speed;
    double m_direction;
    
private:
    void init();
    
public:
    Particle(); //constructor
    virtual ~Particle(); //keyword virtual ensures that the correct destructor is called.
    void update(int interval);
};

#endif /* Particle_hpp */
