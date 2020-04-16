//
//  main.cpp
//  GameDemo
//
//  Created by Samuel Davis on 01/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.hpp"
#include "Swarm.hpp"
#include <stdlib.h>

using namespace std;
//using std::cout;

int main(int argc, const char * argv[])
{
    srand(time(NULL)); //seeds the random number generator
    
    Screen screen;
    
    if (screen.init()==false)
    {
        cout << "Error intialising SDL." << endl;
    }
    
    Swarm swarm;
    

    while(true)//game loop...
    {
        int elapsed = SDL_GetTicks();  //number of miliseconds since program started
        //colour changing algorithm
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
        
        const Particle * const pParticles = swarm.getParticles();
        
        for(int i=0;i<Swarm::NPARTICLES;i++)
        {
            Particle particle = pParticles[i];
            
            int x = (particle.m_x +1) * Screen::SCREEN_WIDTH/2;
            int y = (particle.m_y +1) * Screen::SCREEN_HIGHT/2;
            
            screen.setPixel(x, y, red, green, blue);
        }
        
        //draw particles
        screen.update();
        
        //check for screen close event
        if(screen.processEvents() == false)
        {
            break;
        }
     }
    
    screen.close();
    
    return 0;
}
