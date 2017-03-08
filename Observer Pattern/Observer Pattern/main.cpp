//
//  main.cpp
//  Observer Pattern
//
//  Created by JJ Santos on 3/8/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Subject {
    vector < class Observer * > views;
    string value;
    string name;
public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(string val) {
        value = val;
        notify();
    }
    void setName(string n) {
        name = n;
    }
    string getVal() {
        return value;
    }
    string getName() {
        return name;
    }
    void notify();
};

class Observer {
    Subject *model;
    string name;
    
public:
    Observer(string n, Subject *mod) {
        model = mod;
        name = n;
        model->attach(this);
    }
    
    void setName(string n) {
        name = n;
    }
    string getName() {
        return name;
    }

    void update() {
        string n = getSubject()->getName();
        string v = getSubject()->getVal();
        cout << getName() << " - Tweet de " << n << ": " << v << '\n';
    }
protected:
    Subject *getSubject() {
        return model;
    }
    
};

void Subject::notify() {
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}


int main() {
    
    Subject s1;
    Subject s2;
    
    s1.setName("Donald Trump");
    s2.setName("EPN");
    
    Observer o1("Reforma", &s1);
    Observer o2("Televisa", &s2);
    
    s1.setVal("I will build a GREAT wall.");
    s2.setVal("Mexico will not pay for the wall.");
    
    
}
