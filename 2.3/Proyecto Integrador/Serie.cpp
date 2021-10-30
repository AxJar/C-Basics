//
// Created by Axel JM on 09/06/2021.
//

#include "Serie.h"

Serie::Serie(string id, string name,string duration,string genre,string se,int episode) {
    this -> id = id;
    this -> name = name;
    this-> duration =duration;
    this -> genre = genre;
    this -> se = se;
    this -> episode = episode;
}

void Serie::setNombre(string name) {
    this -> name = name;
}

string Serie::getId() {
    return id;
}

string Serie::getGenre() {
    return genre;
}

void Serie::show() {
    cout << "Id: " << id << endl;
    cout << "Nombre: " << name << endl;
    cout << "Duracion: " << duration << endl;
    cout << "Genero: " << genre << endl;
    cout << "Serie: " << se << endl;
    cout << "Episodio: " << episode << endl;
}

ostream &operator<<(ostream &os,Serie *s){
    char c[256];
    int n;
    cout << "Id: " << s->id << endl;
    cout << "Nombre: " << s->name << endl;
    cout << "Duracion: " << s->duration << endl;
    cout << "Genero: " << s->genre << endl;
    cout << "Serie: " << s->se << endl;
    cout << "Episodio: " << s->episode << endl;

    return os;
}