//
//  main.cpp
//  Fetching
//
//  Created by Samuel Davis on 21/04/2020.
//  Copyright © 2020 Samuel Davis. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int color = 0x123456;  //RGB(A) values
    
    int red = (color & 0xFF0000) >> 16;
    int green = (color & 0x00FF00) >> 8;
    int blue = (color & 0x0000FF);
    
    cout << hex << red << endl;
    cout << hex << green << endl;
    cout << hex << blue << "\n"<< endl;

    // or do the following...
    
    unsigned char nred = (color & 0xFF0000) >> 16;
    unsigned char ngreen = (color & 0x00FF00) >> 8;
    unsigned char nblue = (color & 0x0000FF);
    
    cout << hex << (int)nred << endl;
    cout << hex << (int)ngreen << endl;
    cout << hex << (int)nblue << "\n" << endl;
    
    // or do the following ...
    
    unsigned char qred = color >> 16;
    unsigned char qgreen = color >> 8;
    unsigned char qblue = color;
    
    cout << hex << (int)qred << endl;
    cout << hex << (int)qgreen << endl;
    cout << hex << (int)qblue << endl;
    
    return 0;
}
