//
// Created by Axel JM on 09/06/2021.
//

#ifndef PROYECTO_INTEGRADOR_SERIE_H
#define PROYECTO_INTEGRADOR_SERIE_H
#include "Video.h"
#include <istream>
#include <string>
#include <iostream>

using namespace std;

class Serie {
protected:
    string id;
    string name;
    string duration;
    string genre;
    string se;
    int episode;

public:
    Serie(string id, string name,string duration, string genre,string se, int episode);
    string getId();
    string getGenre();
    void setNombre(string name);
    void show();
    friend ostream &operator<<(ostream &os,Serie *s);
};


#endif //PROYECTO_INTEGRADOR_SERIE_H
