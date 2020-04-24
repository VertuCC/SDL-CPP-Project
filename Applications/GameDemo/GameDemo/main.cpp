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
    //time() returns a long which is larger than an unsigned int
    srand(static_cast<unsigned int>(time(NULL)));
    
    Screen screen; //initialise screen object
    
    if (screen.init()==false)
    {
        cout << "Error intialising SDL." << endl;
    }
    
    Swarm swarm;

    while(true)
    {//game loop...
        int elapsed = SDL_GetTicks();  //number of miliseconds since program started
        
        swarm.update(elapsed);
        
        //colour changing algorithm for particles
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
        
        const Particle * const pParticles = swarm.getParticles();
        
        for(int i=0;i<Swarm::NPARTICLES;i++)
        {//draw particles
            Particle particle = pParticles[i];
            
            int x = (particle.m_x +1) * Screen::SCREEN_WIDTH/2;
            int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HIGHT/2;
            
            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.boxBlur();  
        
        screen.update(); //draw particles
        
        if(screen.processEvents() == false)
        {//check for screen close event
            break;
        }
     }
    
    screen.close();
    
    return 0;
}
