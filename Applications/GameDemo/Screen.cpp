//
//  Screen.cpp
//  GameDemo
//
//  Created by Samuel Davis on 11/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#include "Screen.hpp"

Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL){
    
}

bool Screen::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        //use SDL_GetError() to obtain error code
        return false;
    }
    
    m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
    
    // Check that the window was successfully created
    if (m_window == NULL)
    {
        // In the case that the window could not be made...
        return false;
    }
    
    // Textures, Renderers & Buffers: lecture 63
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HIGHT);
    
    if(m_renderer == NULL)
    {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    
    if (m_texture == NULL)
    {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    
    //Need area of memory to hold all the pixels in the window,relating to RGBA = 8+8+8+8 = 32
    m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HIGHT];  //Will this return NULL or raise an exception if memory allocation fails?
    
    //Set a block of memory with a particular value.
    //Write some pixel information to the buffer.  This will change what is displayed in the window.
    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HIGHT*sizeof(Uint32));  //the value 255 (0xFF) will produce a white screen.
                                                                    //NB: One byte specifies one pixel.
    
    return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
 //   Uint32 *m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HIGHT];
    Uint32 color = 0;
    
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    
    m_buffer[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::update()
{
    //Drawing code ...
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32)); //pitch is the amount of mememory allocated to one row of pixels
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

bool Screen::processEvents()
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {//Closes screen
        if(event.type == SDL_QUIT)
        {
            return false;
        }
    }
    return true;
}

void Screen::close()
{
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}