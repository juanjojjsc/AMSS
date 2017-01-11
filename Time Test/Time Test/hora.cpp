//
//  hora.cpp
//  Time Test
//
//  Created by JJ Santos on 1/11/17.
//  Copyright © 2017 Juanjo Santos. All rights reserved.
//

#include "hora.h"
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

void Clock::getTime() {
    
    
    
    time_t _tm = time(NULL );
   
    struct tm * curtime = localtime ( &_tm );
    timeNow = asctime(curtime);

    
   
    
}


void Clock::test() {
    
    cout << "test method";
    
}

void Clock::printTime() {
    
     
        cout << timeNow;

//        cout << "hola";
}


Clock* Clock::getInstance() {
    
    if (instance != 0)
    {
        return instance;
    } else {
        Clock();
        return instance;
    }
    
    
}

//Inicializar instance
Clock* Clock::instance = 0;

