//
// Created by Axel JM on 07/06/2021.
//

#include "Video.h"

using namespace std;


Video::Video(string id, string name, string duration, string genre, int rating)
{
    this->id = id;
    this->name = name;
    this->duration = duration;
    this->genre = genre;
    this->rating = rating;
}

void Video::setRating(int rating) {
    this-> rating = rating;
}

void Video::setGenre(string genre) {
    this -> genre = genre;
}

string Video::getId() {
    return id;
}

string Video::getName() {
    return name;
}

string Video::getDuration() {
    return duration;
}

string Video::getGenre() {
    return genre;
}

int Video::getRating() {
    return rating;
}

void Video::show() {

}


bool Video::operator>=(double wRating) {
    if (this -> rating >=wRating){
        return true;
    }
    return false;
}