//
//  main.cpp
//  Time Test
//
//  Created by JJ Santos on 1/11/17.
//  Copyright © 2017 Juanjo Santos. All rights reserved.
//

#include <iostream>
#include "hora.h"

int main() {
    
    
    //Queremos que solo haya una instancia en memoria de Clock
    //Usamos static
    
    Clock* r1 = Clock::getInstance();
    r1->getTime();
    r1->printTime();
    r1->test();
    
    return 0;
}
