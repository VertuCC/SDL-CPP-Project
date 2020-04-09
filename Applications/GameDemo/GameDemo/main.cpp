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
        return 2;
    }
    
    // Textures, Renderers & Buffers: lecture 63
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HIGHT);
    
    if(renderer == NULL)
    {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }
    
    if (texture == NULL) {
        cout << "Could not create texture" << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }
    
    //Need area of memory to hold all the pixels in the window,relating to RGBA = 8+8+8+8 = 32
    Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HIGHT];  //Will this return NULL or raise an exception if memory allocation fails?
    
    //Set a block of memory with a particular value.
    //Write some pixel information in the buffer.  This will change what is displayed in the window.
    memset(buffer, 0, SCREEN_WIDTH*SCREEN_HIGHT*sizeof(Uint32));  //the value 255 (0xFF) will produce a white screen.
                                                                    //NB: One byte specifies one pixel.
    
    
    for (int i=0; i<SCREEN_WIDTH*SCREEN_HIGHT; i++)
    {
        buffer[i] = 0x00FF80FF;  //Bit shfting colours: RGBA
    }
    
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32)); //pitch is the amount of mememory allocated to one row of pixels
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    
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
    
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
