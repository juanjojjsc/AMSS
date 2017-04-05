#include <iostream>
#include <vector>
#include <ctime>




using namespace std;

class Dominio{
    
public:
    string ip;
    vector<string> url;
    void setIP(string i){ip = i;}
    string getIP(){return ip;}
    void pushURL(string ur){url.push_back(ur);}
};

class DNS
{
    DNS *next;
    
public:
    DNS()
    {
        next = 0;
    }
    
    void setNext(DNS *n)
    {
        next = n;
    }
    
    void add(DNS *n)
    {
        if (next)
            next->add(n);
        else
            next = n;
    }
    
    \
    virtual void handle(string m)
    {
        next->handle(m);
    }
};


class ServidorA: public DNS
{
public:
    Dominio a;
    ServidorA(){
        a.setIP("192.16.4.5");
        a.pushURL("www.google.com");
        a.pushURL("www.amazon.com");
    }
    /*virtual*/ void handle(string m)
    {
        if (m=="www.google.com" || m=="www.amazon.com") {
            cout << "Server A handled " << m << "  ";
        }
        else
            cout << "Server A passed " << m << "  ";
        DNS::handle(m);
        
        
    }
};

class ServidorB: public DNS
{
public:
    Dominio b;
    ServidorB(){
        b.setIP("198.144.8.7");
        b.pushURL("www.yahoo.com");
        b.pushURL("www.forbes.com");
    }
    /*virtual*/void handle(string m)
    {
        if (m=="www.yahoo.com" || m=="www.forbes.com") {
            cout << "Server B handled " << m << "  ";
        }
        else
            cout << "Server B passed " << m << "  ";
        DNS::handle(m);
        
    }
};

class ServidorC: public DNS
{
public:
    Dominio c;
    ServidorC(){
        c.setIP("157.35.34.7");
        c.pushURL("www.facebook.com");
        c.pushURL("www.mitec.itesm.com");
    }
    /*virtual*/void handle(string m)
    {
        if (m=="www.facebook.com" || m=="www.mitec.itesm.com") {
            cout << "Server C handled " << m << "  ";
        }
        else
            cout << "Server C passed " << m << "  ";
        DNS::handle(m);
       
    }
};

class ServidorD: public DNS
{
public:
    Dominio d;
    ServidorD(){
        d.setIP("146.12.20.3");
        d.pushURL("www.miscursos.tec.com");
        d.pushURL("www.fifa.com");
    }
    /*virtual*/void handle(string m)
    {
        if (m=="www.miscursos.tec.com" || m=="www.fifa.com") {
            cout << "Server D handled " << m << "  ";
        }
        else
            cout << "Server D passed " << m << "  ";
        DNS::handle(m);
        
    }
};

class ServidorE: public DNS
{
public:
    Dominio e;
    ServidorE(){
        e.setIP("124.70.20.100");
        e.pushURL("www.nfl.com");
        e.pushURL("www.espn.com");
    }
    /*virtual*/void handle(string m)
    {
        if (m=="www.nfl.com" || m=="www.espn.com") {
            cout << "Server E handled " << m << "  ";
        }
        else
            cout << "Server E passed " << m << "  ";
        DNS::handle(m); 
        
    }
};

int main()
{
    // srand(time(0));
    ServidorA s1;
    ServidorB s2;
    ServidorC s3;
    ServidorD s4;
    ServidorE s5;
    s1.add(&s2);
    s1.add(&s3);
    s1.add(&s4);
    s1.add(&s5);
    
    
    
    
    s5.setNext(&s1);
    
    string pag[5];
    pag[0]="www.facebook.com";
    pag[1]="www.google.com";
    pag[2]="www.yahoo.com";
    pag[3]="www.amazon.com";
    pag[4]="www.nfl.com";
    
    for (int i = 0; i < 6; i++)
    {
        s1.handle(pag[i]);
        cout << '\n';
    }
}
