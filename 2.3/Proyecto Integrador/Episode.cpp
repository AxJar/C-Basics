//
// Created by Axel JM on 09/06/2021.
//
#include "Episode.h"


using namespace std;

Episode::Episode(string id, string name, string duration, string genre, int rating, int season): Video(id,name,duration,genre,rating) {
    this->id = id;
    this->name = name;
    this->duration = duration;
    this->genre = genre;
    this->rating = rating;
    this->season = season;
}

string Episode::getSid(){
    return  id;
}

int Episode::getRating() {
    return rating;
}

void  Episode::setGenre(string genre) {
    this-> genre = genre;
}

void Episode::setRating(int rating) {
    this->rating = rating;
}

void Episode::show() {
    cout << "Id episodio: " << eId << endl;
    cout << "Nombre: " << name << endl;
    cout << "Duración: " << duration << endl;
    cout << "Calificación: " << rating << endl;
    cout << "Genero de la serie: " << genre << endl;
    cout << "Temporada: " << season << endl;
    cout << endl;
}