//
// Created by Axel JM on 05/06/2021.
//

#include "Rectangular.h"
#include <math.h>
#include "Rectangular.h"
#include "Polar.h"


Rectangular::Rectangular():Rectangular(0.0,0.0){}

Rectangular::Rectangular(double x, double y){
    this->x=x;
    this->y=y;
}

double Rectangular::getX(){
    return this->x;
}

double Rectangular::getY(){
    return this->y;
}

//Rectangular Rectangular::suma(Rectangular cr) {
//    return Rectangular(this-> x + cr.x,this -> y + cr.y);
//    Rectangular res;
//    res.x = this-> x + cr.x;
//    res.y = this -> y + cr.y;
//    return res;
//}

Rectangular Rectangular::operator+(Rectangular cr) {
    return Rectangular(this-> x + cr.x,this -> y + cr.y);
//    Rectangular res;
//    res.x = this-> x + cr.x;
//    res.y = this -> y + cr.y;
//    return res;
}

Rectangular Rectangular::operator+(Polar cp) {
    return *this + cp.toRectangular();
}

Rectangular Rectangular::operator-(Rectangular cr) {
    return Rectangular(this-> x - cr.x,this -> y - cr.y);
//    Rectangular res;
//    res.x = this-> x - cr.x;
//    res.y = this -> y - cr.y;
//    return res;
}

Rectangular Rectangular::operator*(Rectangular cr) {
    Polar cp1 = this->toPolar(),
          cp2 =cr.toPolar();
    return (cp1*cp2).toRectangular();
}

/*
Rectangular Rectangular::operator/(Rectangular cr) {
    return Rectangular(this->x - cr.x, this->y - cr.y);
}
*/

//Funcion amiga , por eso no hay Rectangular::
// Esta funcion sirve para saber que hay dentro del objeto
ostream& operator<<(ostream& os,const Rectangular& cr){
    os <<"("<<cr.x<<","<<cr.y<<")";
    return os;
}

Polar Rectangular::toPolar() {
    double r = sqrt(this->x*this->x+this->y*this->y); //Pitagoras
    double a = atan2(this->y,this->x); //angulo
    return Polar(r,a);
}