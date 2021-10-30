// Escribe la clase Alumno de acuerdo con los comentarios
// Incluye las librerias requeridas
// Utiliza el espacio de trabajo estándar
// implementa los métodos
#include <iostream>
#include <string>
using namespace std;
// Clase Alumno
class Alumno{
    public:
    //constructores
        Alumno();
        Alumno(string, string, string, int);
    //getters
        string getMatricula() const;
        string getNombre() const;
        string getCarrera() const;
        int getEdad() const;
    
    //setters
        void setMatricula(string);
        void setNombre(string);
        void setCarrera(string);
        void setEdad(int);
        void imprimeAlumno();
        int cumpleanios();
    private:
        string matricula;
        string nombre;
        string carrera;
        int edad;
    
};
Alumno :: Alumno(){
    matricula = "";
    nombre = "";
    carrera = "";
    edad =0;
}
Alumno::Alumno(string _matricula, string _nombre, string _carrera, int _edad){
    matricula = _matricula;
    nombre = _nombre;
    carrera = _carrera;
    edad = _edad;
}
string Alumno::getMatricula() const{
    return matricula;
}
string Alumno::getNombre() const{
    return nombre;
}
string Alumno::getCarrera() const{
    return carrera;
}
int Alumno::getEdad() const{
    return edad;
}

void Alumno :: setMatricula(string _matricula){
    matricula = _matricula;
}
void Alumno :: setNombre(string _nombre){
    nombre = _nombre;
}
void Alumno :: setCarrera(string _carrera){
    carrera = _carrera;
}
void Alumno :: setEdad(int _edad){
    edad = _edad;
}
void Alumno::imprimeAlumno(){
    cout<<"["<< matricula<< " - "<<  nombre<< " - " << carrera<< " - "<<  edad<< "]"<<endl;
}
int Alumno::cumpleanios(){
    edad++;
    return edad;
}
