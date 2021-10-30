//
// Created by Axel JM on 09/06/2021.
//

#ifndef PROYECTO_INTEGRADOR_EPISODE_H
#define PROYECTO_INTEGRADOR_EPISODE_H
#include <iostream>
#include <string>
#include "Video.h"
#include "Serie.h"

using namespace std;

class Episode: public Video{
private:
    int season;
    string eId;
public:
    Episode(string id, string name, string duration, string genre, int rating, int season);
    string getSid();
    int getRating();
    void setGenre(string genre);
    void setRating(int rating);
    void show();
};


#endif //PROYECTO_INTEGRADOR_EPISODE_H
