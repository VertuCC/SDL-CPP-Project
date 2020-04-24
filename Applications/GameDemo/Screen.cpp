//
//  Screen.cpp
//  GameDemo
//
//  Created by Samuel Davis on 11/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#include "Screen.hpp"

Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL){
    //constructor
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
    
    //allocate area of memory for display relating to RGBA = 8+8+8+8 = 32
    //initialise buffer to store screen pixels.
    m_buffer1 = new Uint32[SCREEN_WIDTH*SCREEN_HIGHT];
    m_buffer2 = new Uint32[SCREEN_WIDTH*SCREEN_HIGHT];
    
    //memset will set a block of memory with a particular value.
    //clears buffers upon initialisation.
    memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HIGHT*sizeof(Uint32));
    memset(m_buffer2, 0, SCREEN_WIDTH*SCREEN_HIGHT*sizeof(Uint32));
    
    return true;
}


void Screen::boxBlur()
{//implementation of the boxBlur algorithm
    Uint32 *temp = m_buffer1;
    m_buffer1 = m_buffer2;
    m_buffer2 = temp;
    
    for(int y=0; y < SCREEN_HIGHT; y++)
    {
        for(int x=0; x < SCREEN_WIDTH; x++)
        {
            /*
             * 0 0 0 (-1)
             * 0 1 0 (0)
             * 0 0 0 (+1)
             *
             */
            
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;
            
            for(int row = -1; row <= 1; row++)
            {
                for(int col = -1; col <= 1; col++)
                {
                    int currentX = x + col;
                    int currentY = y + row;
                    
                    if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HIGHT)
                    {
                        Uint32 color = m_buffer2[currentY * SCREEN_WIDTH + currentX];
                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;
                        
                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
            }
            
            Uint8 red = redTotal/9;
            Uint8 green = greenTotal/9;
            Uint8 blue = blueTotal/9;
            
            setPixel(x, y, red, green, blue);
        }
    }
}


void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
    
    if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HIGHT)
    {//ensure that pixels are plotted within screen dimensions
        return;
    }
    
    Uint32 color = 0;
    
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    
    m_buffer1[(y * SCREEN_WIDTH) + x] = color;  //drawing buffer
}


void Screen::update()
{
    //Drawing code ...
    SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32)); //pitch is the amount of mememory allocated to one row of pixels
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
    delete [] m_buffer1;
    delete [] m_buffer2;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
