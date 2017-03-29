//
//  main.cpp
//  Entrega Parcial 2
//
//  Created by JJ Santos on 3/29/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
using namespace std;



class Visitor;




class Printer{
protected:
    string tipo;
public:
    string getTipo(){return tipo;}
    virtual void accept(Visitor*)=0;
    
};



class Laser : public Printer
{
public:
    Laser(){
        tipo = "Laser";
    }
    static int countLaser;
    void accept(Visitor*);
};
int Laser::countLaser=0;

class Inyeccion : public Printer
{
public:
    Inyeccion(){
        tipo = "Inyeccion";
    }
    static int countInyeccion;
    void accept(Visitor*);
};
int Inyeccion::countInyeccion=0;

class PDF : public Printer
{
public:
    PDF(){
        tipo = "PDF";
    }
    static int countPDF;
    void accept(Visitor*);
};
int PDF::countPDF=0;

class Postscript : public Printer
{
public:
    Postscript(){
        tipo = "Postscript";
    }
    static int countPostscript;
    void accept(Visitor*);
};
int Postscript::countPostscript=0;








class Document{
protected:
    string tipo;
public:
    string getTipo(){return tipo;}
    void printOn(Printer* p)
    {
        cout << "Imprimiendo documento " << tipo << " en impresora " << p->getTipo() << endl;
    }
    virtual void visit(Laser*)=0;
    virtual void visit(Inyeccion*)=0;
    virtual void visit(PDF*)=0;
    virtual void visit(Postscript*)=0;
    
};

class Texto : public Document
{
public:
    Texto(){
        tipo = "Texto";
    }
    static int countTexto;
    
};
int Texto::countTexto=0;

class Formato : public Document
{
public:
    Formato(){
        tipo = "Formato";
    }
    static int countFormato;
    
};
int Formato::countFormato=0;

class Imagenes : public Document
{
public:
    Imagenes(){
        tipo = "Imagenes";
    }
    static int countImagenes;
    
};
int Imagenes::countImagenes=0;





class CountVisitor : public Printer
{
public:
    void visit(Laser* l)
    {
        cout << Laser::countLaser;
    }
    void visit(Inyeccion* i)
    {
        cout << Inyeccion::countInyeccion;
    }
    void visit(PDF* p)
    {
        cout << PDF::countPDF;
    }
    void visit(Postscript* po)
    {
        cout << Postscript::countPostscript;
    }
};



class AddVisitor : public Printer
{
public:
    void visit(Laser* l)
    {
        Laser::countLaser++;
    }
    void visit(Inyeccion* i)
    {
        Inyeccion::countInyeccion++;
    }
    void visit(PDF* p)
    {
        PDF::countPDF++;
    }
    void visit(Postscript* po)
    {
        Postscript::countPostscript++;
    }
};








class Main
{
public:
    
    void printAllDocuments(Document** d, int countDocs, Printer** p, int countPrinters)
    {
        for(int i=0; i<countDocs; i++)
        {
            for(int j=0; j<countPrinters; j++)
            {
                d[i]->printOn(p[i]);
            }
        }
    }
    
};



int main()
{
    
    
    
    
    Laser* p1;
    Inyeccion* p2;
    PDF* p3;
    Postscript* p4;
    
    Texto* d1;
    Formato* d2;
    Imagenes* d3;
    
    //p1->accept(d1*);
    
    
    Main examen;
    //examen.printAllDocuments(<#Document **d#>, <#int countDocs#>, <#Printer **p#>, <#int countPrinters#>)
    
    
    
    return 0;
}
