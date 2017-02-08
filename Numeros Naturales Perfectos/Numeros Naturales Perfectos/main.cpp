//
//  main.cpp
//  Numeros Naturales Perfectos
//
//  Created by JJ Santos on 2/1/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <array>

using namespace std;


class ArregloNNP;



class Proxy
{
    
private:
    
    ArregloNNP& arr;
    int index;
    
public:
    
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
    
    Proxy(ArregloNNP& arr, int index) : arr(arr), index(index){}
    
    Proxy operator = (int value);
    friend ostream& operator <<(ostream&, Proxy&&);
    
    
};


class ArregloNNP {
    
private:
    
    int *arreglo;
    int size;
    
    
public:
    //make friends to access attributes from other classes
    friend class Proxy;
    
    ArregloNNP(int size) : size(size)
    {
        arreglo = new int[size+1]; //Reservamos memoria extra
    }
    
    //Sobrecarga de operador
    Proxy operator [](int index)
    {
        if(index<0 || index >= size)
        {
            cout << "Error: No hay indices negativos" << endl;
             return Proxy(*this, size);
        }
        return Proxy(*this, index);
    }
    friend ostream& operator<<(ostream& os, Proxy&& p);
    
    
    
    
};


Proxy Proxy::operator=(int value)
{
    if (NNP(value)) {
        arr.arreglo[index] = value;
        cout << "Si es" << endl;
    }
    else
        cout << "Error: No es numero natural perfecto" << endl;
    return *this;
}


ostream& operator <<(ostream& os, Proxy&& p)
{
    os << p.arr.arreglo[p.index];
    return os;
}

int main()
{
    
    
    ArregloNNP a1(1);

    a1[0]=6;
    a1[5]=2;
    a1[-1]=5;
    
    cout << a1[1];
    
    return 0;
}



