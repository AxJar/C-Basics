//
// Created by Axel JM on 08/06/2021.
//

#ifndef EXAMEN_MULTIMEDIO_H
#define EXAMEN_MULTIMEDIO_H
#include <string>
#include <iostream>

using namespace std;

class Multimedio {
protected:
    string nombre;
    int duracion;
public:
    Multimedio(string nombre, int duracion){
        this ->nombre = nombre;
        this->duracion = duracion;
    };
    Multimedio():Multimedio("Sin nombre",0.0) {};
    virtual int getSize() = 0;


};




#endif //EXAMEN_MULTIMEDIO_H
