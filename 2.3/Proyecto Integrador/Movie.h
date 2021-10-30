//
// Created by Axel JM on 09/06/2021.
//

#ifndef PROYECTO_INTEGRADOR_MOVIE_H
#define PROYECTO_INTEGRADOR_MOVIE_H
#include <iostream>
#include <string>
#include "Video.h"

using namespace std;

class Movie: public Video{
public:
    string genre;
    Movie(string id,string name,string duration,string genre,int rating);
    string getId();
    void setRating(int Rating);
    int getRating();
    void show();
    friend ostream &operator<<(ostream &os,Video *v);
};


#endif //PROYECTO_INTEGRADOR_MOVIE_H
