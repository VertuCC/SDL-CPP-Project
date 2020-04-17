//
//  Swarm.hpp
//  GameDemo
//
//  Created by Samuel Davis on 16/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp
#include "Particle.hpp"
#include <stdio.h>

class Swarm
{
public:
    const static int NPARTICLES = 1000;
    
private:
    Particle * m_pParticles; //m because it's a instance variable, p because it's a pointer

public:
    Swarm();
    virtual ~Swarm();  //this virtual method could be overidding
    void update();
    
    const Particle *const getParticles() {return m_pParticles;};
};
#endif /* Swarm_hpp */
