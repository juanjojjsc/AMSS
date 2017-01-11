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

string Clock::getTime() {
    
    
    
    time_t _tm = time(NULL );
    
    struct tm * curtime = localtime ( &_tm );
    return asctime(curtime);
    
    
    
    
}
