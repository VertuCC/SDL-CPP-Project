//
//  Screen.hpp
//  GameDemo
//
//  Created by Samuel Davis on 11/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Screen
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HIGHT = 600;
    
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;
    
public:
    Screen();
    bool init();
    void update();
    void setPixel(int x, int y, Uint8 red,Uint8 green, Uint8 blue);
    bool processEvents();
    void close();
    void boxBlur();
};

#endif /* Screen_hpp */
