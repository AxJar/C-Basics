//
// Created by Axel JM on 07/06/2021.
//

#ifndef PROYECTO_INTEGRADOR_VIDEO_H
#define PROYECTO_INTEGRADOR_VIDEO_H
#include <string>
#include <iostream>

using namespace std;

class Video {
protected:
    string id;
    string name;
    string duration;
    string genre;
    int rating;
public:
    Video(string id,string name, string duration, string genre,int rating);
    virtual string getId();
    virtual string getName();
    virtual string getDuration();
    virtual string getGenre();
    virtual int getRating();
    virtual void show() = 0;
    void setRating(int rating);
    void setGenre(string genre);
    friend ostream &operator<<(ostream &os, Video *v);
    bool operator >=(double wRating);
    bool operator <=(double bRating);


};


#endif //PROYECTO_INTEGRADOR_VIDEO_H
