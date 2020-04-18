//
//  Swarm.cpp
//  GameDemo
//
//  Created by Samuel Davis on 16/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#include "Swarm.hpp"

Swarm::Swarm(): lastTime(0)  //constructor inilisation list
{
    m_pParticles = new Particle[NPARTICLES]; 
}

Swarm::~Swarm()
{
    delete [] m_pParticles;
}

void Swarm::update(int elasped)
{
    int interval = elasped - lastTime;
    
    for(int i=0;i<Swarm::NPARTICLES;i++)
    {
        m_pParticles[i].update(interval);
    }
    
    lastTime = elasped;
}
