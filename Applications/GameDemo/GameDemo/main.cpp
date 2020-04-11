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
        //update particles
        //draw particles
        //check for messages/events
        
        if(screen.processEvents() == false)
        {
            break;
        }
     }
    
    screen.close();
    
    return 0;
}
