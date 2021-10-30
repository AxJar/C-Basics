#include <iostream>
#include "Rectangular.h"
#include "Polar.h"
#include <math.h>

using namespace std;

int main(){
    cout<<"Hola mundo Sobrecarga"<<endl;
    Rectangular cr1(2,3),
                cr2(4,5);
    cout<<cr1<<endl;
    cout<<cr2<<endl;

    Rectangular cr3 = cr1+cr2,
                cr4=cr1-cr2;
                /*
                cr5=cr1*cr2,
                cr6=cr1/cr2;
*/
    Polar cp1(10,1.5),
          cp2(-7,2.3),
          /*
          cp3=cp1+cp2,
          cp4=cp1-cp2,
          */
          cp5=cp1*cp2,
          cp6=cp1/cp2;

    cout<<cr1<<endl;
    cout<<cr2<<endl;
    cout<<cr3<<endl;
    cout<<cr4<<endl;
    /*
    cout<<cr5<<endl;
    cout<<cr6<<endl;
*/
    cout<<cp1<<endl;
    cout<<cp2<<endl;
     /*
    cout<<cp3<<endl;
    cout<<cp4<<endl;
      */
    cout<<cp5<<endl;
    cout<<cp6<<endl;
/*
    Rectangular  cr7=cr1+cp1;
    Polar cp7=cp1+cr1;
    cout<<"Combinando"<<endl;
    cout<<cr7<<endl;
    cout<<cp7.toRectangular()<<endl;
    cout<<cp7<<endl;
    cout<<cr7.toPolar()<<endl;


*/
    cin.get();
    return 0;
};
