//
//  main.cpp
//  Numeros Naturales Perfectos
//
//  Created by JJ Santos on 2/1/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
#include <cctype>

using namespace std;


class ArregloNNP {
    
    
public:
    
    int *arreglo;
    
    ArregloNNP(int n) {
        arreglo = new int[n];
        for (int i=0; i<n; i++)
        {
            arreglo[i] = i + 1;
        }
    }
    
    bool NNP(int n) {
        
        int i=1,count=0;
        while(i<n){
            if(n%i==0)
                count=count+i;
            i++;
        }
        
        if(count==n)
            return true;
        else
            return false;
        
    }
    
    
};






int main()
{
    int size = 500;
    int count = 0;
    ArregloNNP a1(size);
    
    for (int i=0; i<size; i++)
    {
        if (a1.NNP(a1.arreglo[i]) == true)
            cout << "Si" << endl, count ++;
        
        else
            cout << "Error en numero: " << a1.arreglo[i] << " en subindice: " << i << "." << endl;
    }
    
    cout << "Numero total de NNP del 1 al " << size << " : " << count << endl;
    
    return 0;
}



