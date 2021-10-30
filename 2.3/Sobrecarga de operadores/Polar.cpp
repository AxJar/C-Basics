//
// Created by Axel JM on 05/06/2021.
//

#include "Polar.h"
#include <math.h>

Polar::Polar():Polar(0.0,0.0){};

Polar::Polar(double r,double a){
    this->r=r;
    this->a=a;
}

double Polar::getR(){
    return this->r;
}

double Polar::getA(){
    return this->a;
}

Polar Polar::operator*(Polar cp) {
    return Polar(this->r*cp.r,this->a+cp.a);
}

Polar Polar::operator/(Polar cp) {
    return Polar(this->r/cp.r,this->a-cp.a);
}

ostream& operator<<(ostream& os,const Polar& cp) {
    os << "(" << cp.r << "," << cp.a << "r)";
    return os;
}

Rectangular Polar::toRectangular() {
    return Rectangular(this->r*cos(this->a),this->r*sin(this->a));
}
