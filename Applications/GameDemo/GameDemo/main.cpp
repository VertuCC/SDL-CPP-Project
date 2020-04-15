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
//#include <math.h>
#include "Screen.hpp"

using namespace std;
//using std::cout;

int main(int argc, const char * argv[])
{
    Screen screen;
    
    if (screen.init()==false)
    {
        cout << "Error intialising SDL." << endl;
    }
    
    //game loop...

    while(true)
    {
        
        int elapsed = SDL_GetTicks();  //number of miliseconds since program started
        //colour changing algorithm
        unsigned char green = (unsigned char)((1 + cos(elapsed * 0.0001)) * 128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
        
        //update particles
        for(int y=0; y < Screen::SCREEN_HIGHT; y++)
        {
            for(int x=0; x < Screen::SCREEN_WIDTH; x++)
            {
                screen.setPixel(x, y, red, green, blue);
            }
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
