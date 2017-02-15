//
//  main.cpp
//  Actividad Primer Parcial
//
//  Created by JJ Santos on 2/8/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Videojuego
{
public:
    
    string nombre;
    string developer;
    int noserie;
    int precio;
    int year;
    
    virtual Videojuego* clonar() = 0;
    
    virtual void concepcion()
    {
        cout<< "Videojuego en etapa de Concepto" << endl;
    }
    virtual void diseno()
    {
        cout<< "Videojuego en etapa de Diseno" << endl;
    }
    virtual void planificacion()
    {
        cout<< "Videojuego en etapa de Planificacion" << endl;
    }
    virtual void produccion()
    {
        cout<< "Videojuego en etapa de Produccion" << endl;
    }
    virtual void pruebasDeAceptacion()
    {
        cout<< "Videojuego en etapa de Pruebas de Aceptacion" << endl;
    }
    
    
    
};

template <class SubClase>
class ClonVideojuego : public Videojuego
{
public:
    virtual Videojuego* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};


class Estrategia : public ClonVideojuego<Estrategia>
{
private:
    
    
    
};

class Aventura : public ClonVideojuego<Aventura>
{
private:
    
};

class Aprendizaje : public ClonVideojuego<Aprendizaje>
{
private:
    
};


class VideogameFactory
{
public:
    template<class T>
    static T* construirVideojuego(string nombre, string developer, int noserie, int precio, int year)
    {
        T* vid = new T;
        
        vid->nombre = nombre;
        vid->developer = developer;
        vid->noserie = noserie;
        vid->precio = precio;
        vid->year = year;
        
        vid->concepcion();
        vid->diseno();
        vid->planificacion();
        vid->produccion();
        vid->pruebasDeAceptacion();
        
        
        return vid;
    }
};

//template <class T>
class Almacen {
    
public:
    
    //Vector
    vector<Videojuego* >* arreglo;
    vector<Videojuego* >* eliminados;
    
    //Almacen(){}
    
    void crearInventario()
    {
        arreglo = new vector<Videojuego*>();
        eliminados = new vector<Videojuego*>();
    }
    
    void agregar(Videojuego* v)
    {
        arreglo->push_back(v);
    }
    
    void eliminar(Videojuego* v)
    {
        int index = 0;
        //Buscar la posicion del videojuego
        for (int i=0; i<arreglo->size(); i++)
        {
            if (arreglo->at(i) == v) {
                index = 1;
                break;
            }
        }
        
        eliminados->push_back(arreglo->at(index));
        arreglo->erase(arreglo->begin() + index);
        
        cout << "Elemento borrado" << endl;
    }
    
    void rehacer()
    {
        
        if (eliminados->size() > 0)
        {
            
            arreglo->push_back(eliminados->back());
            eliminados->pop_back();
            
            cout << "Cambios revertidos" << endl;
            
        }
        
    }
    
    void ordenarMenorAMayor()
    {
        
        sort( arreglo->begin(), arreglo->end( ), [ ](Videojuego* a, Videojuego* b )
        {
            return a->precio < b->precio;
        });
    }
    
    void ordenarMayorAMenor()
    {
        sort( arreglo->begin(), arreglo->end( ), [ ](Videojuego* a, Videojuego* b )
        {
            return a->precio > b->precio;
        });
    }
    
    int buscar(string nombre)
    {
        int i;
        //Buscar la posicion del videojuego
        for (i=0; i<arreglo->size(); i++)
        {
            if (arreglo->at(i)->nombre == nombre) {
                break;
                
            }
        }
        return i;
    }
    
    int buscar(int noserie)
    {
        int i;
        //Buscar la posicion del videojuego
        for (i=0; i<arreglo->size(); i++)
        {
            if (arreglo->at(i)->noserie == noserie) {
                break;
                
            }
        }
        return i;
    }
    
    int totalElementos()
    {
        //return arreglo->size() + 1;
        
        return arreglo->size();
    }
    
    void imprimir()
    {
        for (int i=0; i<arreglo->size(); i++)
        {
            cout << arreglo->at(i)->nombre << endl;
        }
    }
    
};



int main() {
    
    
    //Estrategia
    Videojuego* ve1 = VideogameFactory::construirVideojuego<Estrategia>("Age of Empires","Microsoft",13366,399,1997);
    Videojuego* ve2 = ve1->clonar();
    Videojuego* ve3 = VideogameFactory::construirVideojuego<Estrategia>("Fieldrunners","Tech Co",76839,99,2012);
    
    Almacen* aes = new Almacen;
    aes->crearInventario();
    aes->agregar(ve1);
    aes->agregar(ve2);
    aes->eliminar(ve2);
    aes->rehacer();
    aes->agregar(ve3);
    aes->ordenarMenorAMayor();
    aes->ordenarMayorAMenor();
    cout << "Videojuego encontrado en posicion:" << aes->buscar(13366) << endl;
    cout << "Videojuego encontrado en posicion:" << aes->buscar("Fieldrunners") << endl;
    cout << "Total de elementos: " << aes->totalElementos() << endl;
    aes->imprimir();
    
    //Aventura
    Videojuego* va1 = VideogameFactory::construirVideojuego<Aventura>("Tomb Raider","Ubisoft",78273,999,2015);
    Videojuego* va2 = va1->clonar();
    Videojuego* va3 = VideogameFactory::construirVideojuego<Aventura>("Starbound","Enix",49621,299,2014);
    
    Almacen* aav = new Almacen;
    aav->crearInventario();
    aav->agregar(va1);
    aav->agregar(va2);
    aav->eliminar(va2);
    aav->rehacer();
    aav->agregar(va3);
    aav->ordenarMenorAMayor();
    aav->ordenarMayorAMenor();
    cout << "Videojuego encontrado en posicion:" << aav->buscar(78273) << endl;
    cout << "Videojuego encontrado en posicion:" << aav->buscar("Starbound") << endl;
    cout << "Total de elementos: " << aav->totalElementos() << endl;
    aav->imprimir();

    //Aprendizaje
    Videojuego* vap1 = VideogameFactory::construirVideojuego<Aprendizaje>("Duolingo","Inc",34857,199,2014);
    Videojuego* vap2 = vap1->clonar();
    Videojuego* vap3 = VideogameFactory::construirVideojuego<Aprendizaje>("Swift Playgrounds","Apple",36594,15,2016);
    
    Almacen* aap = new Almacen;
    aap->crearInventario();
    aap->agregar(vap1);
    aap->agregar(vap2);
    aap->eliminar(vap2);
    aap->rehacer();
    aap->agregar(vap3);
    aap->ordenarMenorAMayor();
    aap->ordenarMayorAMenor();
    cout << "Videojuego encontrado en posicion:" << aap->buscar(36594) << endl;
    cout << "Videojuego encontrado en posicion:" << aap->buscar("Duolingo") << endl;
    cout << "Total de elementos: " << aap->totalElementos() << endl;
    aap->imprimir();
    
    
    
    return 0;
}
