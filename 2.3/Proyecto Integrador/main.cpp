
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include "Video.h"
#include "Movie.h"
#include "Serie.h"
#include "Episode.h"

using namespace std;

int readData(vector<Video *> &v, vector<Serie *> &s) {
    ifstream videosFile;
    char type;
    string id, name, genre, duration, se;
    int i = 0, rating,episode;
    try {
        if (videosFile) {
            videosFile.open("formatoArchivo.txt");
            string line;
            while (getline(videosFile, line)) {
                stringstream ss(line);
                string data;
                vector<string> datos;
                while (getline(ss, data, ',')) {
                    datos.push_back(data);
                }
                type = datos[0].at(0);
                id = datos[1];
                name = datos[2];
                duration = datos[3];
                rating = (rand() % 5) + 1;
                if (type == 'p') {
                    v.push_back(new Movie(id, name, duration, genre, rating));
                } else if (type == 'c') {
                    genre = datos[4];
                    se = datos[5];
                    episode = stod(datos[6]);
                    s.push_back(new Serie(id, name, duration, genre, se, episode));
                }
            }
        } else {
            throw invalid_argument("Error de lectura del archivo");
        }
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}

string ratingVideos(vector<Video *> v, vector<Serie *> s, string g) {
    string idS;
    for (int i = 0; i < s.size(); i++) {
        if (s[i]->getGenre() == g) {
            idS = s[i]->getId();
            for (int j = 0; j < v.size(); j++) {
                if (v[j]->getId() == idS) {
                    v[j]->setGenre(g);
                }
            }
        }
    }
    double wRating, bRating;
    string wR, bR;
    bool f = true;
    while (f) {
        int cont = 1;
        cout << "Ingrese el minimo de la calificacion: ";
        cin >> wR;
        cout << "Ingrese el maximo de la calificacion: ";
        cin >> bR;
        try {
            wRating = stod(wR);
            bRating = stod(bR);
            f = false;
        }
        catch (invalid_argument &e) {
            cout << "Error. " << e.what() << endl;
        }
    }
    cout <<endl;
    int cont = 1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getRating() >= wRating && v[i]->getRating() <= bRating && v[i]->getGenre() == g) {
            cout << cont << ")" << endl;
            v[i]->show();
            cont++;
        }
    }
    return "";
}

string showEpisodes(vector<Video *> v, string idS, vector<Serie *> s, string g) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getId() == idS) {
            v[i]->setGenre(g);
        }
    }
    double wRating, bRating;
    string wR, bR;
    bool f = true;
    while (f) {
        cout << "Ingrese el minimo de la calificacion: ";
        cin >> wR;
        cout << "Ingrese el maximo de la calificacion: ";
        cin >> bR;
        try {
            wRating = stod(wR);
            bRating = stod(bR);
            f = false;
        }
        catch (invalid_argument &e) {
            cout << "Error. " << e.what() << endl;
        }
        int cont = 1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->getRating() >= wRating && v[i]->getRating() <= bRating && v[i]->getId() == idS) {
                cout << cont << ")" << endl;
                v[i]->show();
                cont++;
            }
        }
    }
    return idS;
}

string ratingMovie(vector<Video *> v, double wRating, double bRating){
        int cont = 1;
        for (int i = 0; i <=7 ; i++){
            if (v[i]->getRating() >=wRating && v[i]->getRating() <= bRating){
                cout << cont << ")" << endl;
                cout << v[i];
                cont++;
            }
        }
        return "";
}

string ratingVideo(vector<Video *> v){
    int num;
    double newRating;
    for (int i = 0; i < v.size(); i++){
        cout << i + 1 << ")" << endl;
        v[i]->show();
    }
    string n;
    bool f = true;
    while (f){
        cout << "Ingrese el numero del video que desea calificar: ";
        cin >> n;
        try{
            num = stoi(n);
            f = false;
        }
        catch (invalid_argument &e){
            cout << "Error. " << e.what() << endl;
        }
    }
    cout << "Selecciono el video: " << v[num - 1]->getName() << ". Con calificacion de: " << v[num - 1]->getRating() << endl;
    cout << "Ingrese la califcacion nueva: ";
    cin >> newRating;
    v[num - 1]->setRating(newRating);
    return "";
}

int main(){
    int option;
    while(option != 6){
        cout <<"\t\t\t\t */*/*/*/*/*/ MENU */*/*/*/*/*/ \n";
        cout << endl;
        cout << "\t 1.- Cargar archivos de datos" << endl;
        cout << "\t 2.- Mostrar los videos en general con un cierto rango de calificacion de un cierto genero" << endl;
        cout << "\t 3.- Mostrar los episodios de una determinada serie con un rango de calificacion determinada" << endl;
        cout << "\t 4.- Mostrar las peliculas con cierto rango de calificacion" << endl;
        cout << "\t 5.- Calificar un video" << endl;
        cout << "\t 6.- Salir" << endl;
        cout << "\t ** Ingresa una opcion del menu: "<<endl;
        cin >> option;
        vector<Video *> v;
        vector<Serie *> s;
        int n;
        double wRating, bRating;
        string num,idS,g,wR,bR;
        bool f;
        switch (option) {
            case 1:
                readData(v,s);
                break;
            case 2:
                cout << "drama" << endl;
                cout << "accion" << endl;
                cout << "misterio" << endl;
                cout << "Ingrese el genero de los videos que desea ver: ";
                cin >> g;
                ratingVideos(v, s, g);
                break;
            case 3:
                for (int i = 0; i < s.size(); i++){
                    cout << i + 1 << ")" << endl;
                    cout << s[i];
                }
                cout << endl;
                f = true;
                while (f){
                    cout << "Ingresa el numero de la serie: ";
                    cin >> num;
                    try{
                        n = stoi(num);
                        f = false;
                    }
                    catch (invalid_argument &e){
                        cout << "Error. " << e.what() << endl;
                    }
                }
                idS = s[n - 1]->getId();
                g = s[n - 1]->getGenre();
                showEpisodes(v, idS, s, g);
                break;
            case 4:
                f = true;
                while (f){
                    cout << "Introduzca el minimo de calificacion: ";
                    cin >> wR;
                    cout << "Introduzca el maximo de  calificacion: ";
                    cin >> bR;
                    try{
                        wRating = stod(wR);
                        bRating = stod(bR);
                        f = false;
                    }
                    catch (invalid_argument &e){
                        cout << "Error. " << e.what() << endl;
                    }
                }
                ratingMovie(v, wRating, bRating);
                break;
            case 5:
                ratingVideo(v);
            case 6:
                cout<<"¡Gracias por usar nuestra plataforma de streaming!";
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;

        };
    };
    return 0;
}
