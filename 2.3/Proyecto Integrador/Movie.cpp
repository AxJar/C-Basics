//
// Created by Axel JM on 09/06/2021.
//

#include "Movie.h"

using namespace std;

Movie::Movie(string id, string name, string duration, string genre, int rating): Video(id,name,duration,genre,rating) {
    this->id = id;
    this->name = name;
    this->duration = duration;
    this->genre = genre;
    this->rating = rating;
}

string Movie::getId() {
    return id;
}
void Movie::setRating(int Rating) {
    this ->rating = rating;

}
int Movie::getRating() {
    return rating;
}

void Movie::show() {
    cout << "Id: " << id << endl;
    cout << "Nombre: " << name << endl;
    cout << "Género: " << genre << endl;
    cout << "Duración: " << duration << endl;
    cout << "Calificación: " << rating << endl;
    cout << endl;
}

ostream &operator<<(ostream &os, Video *v){
    char c[256];
    int n;
    os << "Id: " << v->id << endl;
    os << "Nombre: " << v->name << endl;
    os << "Género: " << v->genre << endl;
    os << "Duración: " << v->duration << endl;
    os << "Calificacion: " << v->rating << endl;

    return os;
}