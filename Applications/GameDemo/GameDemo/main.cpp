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

using namespace std;
//using std::cout;

int main(int argc, const char * argv[])
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HIGHT = 600;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Failed to initialise SDL" << endl;
        return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
    
    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        cout << "Could not create window: %s\n" << SDL_GetError() << endl;
        return 1;
    }
    
    //game loop...
    bool quit = false;
    SDL_Event event;
    while(!quit)
    {
        //update particles
        //draw particles
        //check for messages/events
        
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
