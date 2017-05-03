//
//  main.cpp
//  Actividad Primer Parcial
//
//  Created by JJ Santos on 3/5/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;


class Visitor;

class ElementoVideojuego
{
public:
    
    string tipo;
    
    virtual ElementoVideojuego* clonar() = 0;
    
    virtual void concepcionElemento()
    {
        cout<< "Elemento en creacion" << endl;
    }
    
    virtual void accept(Visitor*,ElementoVideojuego*) = 0;
    
    
};


template <class SubClase>
class ClonVideojuego : public ElementoVideojuego
{
public:
    virtual ElementoVideojuego* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
   
};


class Spacecraft : public ClonVideojuego<Spacecraft>
{
public:
    void construir()
    {
        cout << "Construyendo elemento de tipo: " << tipo << endl;
    }
    void accept(Visitor*,ElementoVideojuego*);
};

class Asteroid : public ClonVideojuego<Asteroid>
{
public:
    void construir()
    {
        cout << "Construyendo elemento de tipo: " << tipo << endl;
    }
    void accept(Visitor*,ElementoVideojuego*);
};

class Planet : public ClonVideojuego<Planet>
{
public:
    void construir()
    {
        cout << "Construyendo elemento de tipo: " << tipo << endl;
    }
    void accept(Visitor*,ElementoVideojuego*);
};


class VideogameFactory
{
    
    VideogameFactory() {
        instance = this;
    }
    static VideogameFactory* instance;
    
public:
    template<class T>
    static T* construirElemento(string tipo)
    {
        T* vid = new T;
        
        vid->tipo = tipo;
        vid->concepcionElemento();
        vid->construir();
        
        
        
        return vid;
    }
    
    static VideogameFactory* getInstance() {
        if (instance==0) {
            return new VideogameFactory;
        } else {
            return instance;
        }
    }
};
VideogameFactory* VideogameFactory::instance=0;



class Visitor
{
public:
    virtual void visit(Spacecraft*,ElementoVideojuego*) = 0;
    virtual void visit(Asteroid*,ElementoVideojuego*) = 0;
    virtual void visit(Planet*,ElementoVideojuego*) = 0;
};

class ColisionVisitor : public Visitor
{
    ColisionVisitor()
    {
        instance = this;
    }
    static ColisionVisitor* instance;
public:
    
    static ColisionVisitor* getInstance()
    {
        if(instance == 0)
        {
            return new ColisionVisitor;
        }
        else
            return instance;
    }
    
    void visit(Spacecraft* s, ElementoVideojuego* e)
    {
        cout <<  s->tipo << " collides with " <<  e->tipo << endl;
    }
    void visit(Asteroid* a, ElementoVideojuego* e)
    {
        cout <<  a->tipo << " collides with " <<  e->tipo << endl;
    }
    void visit(Planet* p, ElementoVideojuego* e)
    {
        cout <<  p->tipo << " collides with " <<  e->tipo << endl;
    }
};
ColisionVisitor* ColisionVisitor::instance = 0;



void Spacecraft::accept(Visitor* v, ElementoVideojuego* m)
{
    v->visit(this,m);
}

void Asteroid::accept(Visitor* v, ElementoVideojuego* m)
{
    v->visit(this,m);
}

void Planet::accept(Visitor* v, ElementoVideojuego* m)
{
    v->visit(this,m);
}



int main() {
    
    ColisionVisitor* c = ColisionVisitor::getInstance();
    
    ElementoVideojuego* ev1 = VideogameFactory::getInstance()->construirElemento<Spacecraft>("Planet exploration ship");
    ElementoVideojuego* ev2 = VideogameFactory::getInstance()->construirElemento<Spacecraft>("Colonization ship");
    ElementoVideojuego* ev3 = VideogameFactory::getInstance()->construirElemento<Spacecraft>("Planet observation ship");
    
    ElementoVideojuego* cl1 = ev1->clonar();
    ElementoVideojuego* cl2 = ev2->clonar();
    ElementoVideojuego* cl3 = ev3->clonar();
    
    ElementoVideojuego* ev4 = VideogameFactory::getInstance()->construirElemento<Asteroid>("Stony meteorite");
    ElementoVideojuego* ev5 = VideogameFactory::getInstance()->construirElemento<Asteroid>("Iron meteorite");
    
    ElementoVideojuego* cl4 = ev4->clonar();
    ElementoVideojuego* cl5 = ev5->clonar();
    
    ElementoVideojuego* ev6 = VideogameFactory::getInstance()->construirElemento<Asteroid>("Desert Planet");
    ElementoVideojuego* ev7 = VideogameFactory::getInstance()->construirElemento<Asteroid>("Earth Analog");
    
    ElementoVideojuego* cl6 = ev6->clonar();
    ElementoVideojuego* cl7 = ev7->clonar();
    
    
    
    
    
    ev1->accept(c, ev2);
    ev1->accept(c, ev3);
    ev1->accept(c, ev4);
    ev1->accept(c, ev5);
    ev1->accept(c, ev6);
    ev1->accept(c, ev7);
    
    
    ev2->accept(c, ev1);
    ev2->accept(c, ev3);
    ev2->accept(c, ev4);
    ev2->accept(c, ev5);
    ev2->accept(c, ev6);
    ev2->accept(c, ev7);
    
    
    ev3->accept(c, ev1);
    ev3->accept(c, ev2);
    ev3->accept(c, ev4);
    ev3->accept(c, ev5);
    ev3->accept(c, ev6);
    ev3->accept(c, ev7);
    
    

    
    
    return 0;
}
