//
//  Swarm.cpp
//  GameDemo
//
//  Created by Samuel Davis on 16/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#include "Swarm.hpp"

Swarm::Swarm()
{
    m_pParticles = new Particle[NPARTICLES]; 
}

Swarm::~Swarm()
{
    delete [] m_pParticles;
}

void Swarm::update()
{
    for(int i=0;i<Swarm::NPARTICLES;i++)
    {
        m_pParticles[i].update();
    }
}
