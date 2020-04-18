//
//  Particle.cpp
//  GameDemo
//
//  Created by Samuel Davis on 16/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#include "Particle.hpp"
#include <math.h>
#include <stdlib.h>

Particle::Particle():m_x(0),m_y(0) //constructure inilisation list...
{//constructor    
    m_direction = (2 * M_PI * rand())/RAND_MAX; // calculate angle of particle
    m_speed = (0.0001 * rand())/RAND_MAX; // calculate speed of particle
}

Particle::~Particle()
{//destructor
    
}

void Particle::update(int interval)
{ //calculate how much to move the x and y coordinates by
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);
    
    //move particles propotional to native execution speed of the game loop
    m_x += xspeed * interval;
    m_y += yspeed * interval;

}
