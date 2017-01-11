//
//  hora.h
//  Time Test
//
//  Created by JJ Santos on 1/11/17.
//  Copyright © 2017 Juanjo Santos. All rights reserved.
//

#include <iostream>
#include <string>
#pragma once

using namespace std;

class Clock {
    
private:
    
    char* timeNow = "sada";
    //Constructor privado para que solo haya una instancia
    Clock(){instance=this;
            timeNow="ss";}
    
    
    
    static Clock* instance;
    
    
    
public:
    
    void test();
    
    static Clock* getInstance();
    
    void getTime();
    
    void printTime();
    
};
