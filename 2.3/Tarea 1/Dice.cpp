#include <iostream>
#include "Dice.h"

using namespace std;


Dice::Dice()
{
    srand(time(0));
}


int Dice::roll()
{
    return  (rand() % 6) + 1;
}  

/*
int main(){
    Dice dado;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cout<<dado.roll()<<endl;
    cin.get();
}*/