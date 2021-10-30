
#include <iostream>
#include <conio.h>
using namespace std;

class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona(string,int);
		void mostrarP();
};

class Estudiante : public Persona{
	private:
		string codigo;
		float notaMedia;
	public:
		Estudiante(string,int,string,float);
		void mostrarE();
};

class Universitario : public Estudiante{
	private:
		string carrera;
	public:
		Universitario(string,int,string,float,string);
		void mostrarU();
};

class Empleado : public Persona{
	private:
		string empleo;
		float sueldo;
	public:
		Empleado(string,int,string,float);
		void mostrarEM();
};

Persona::Persona(string _nombre, int _edad) {
	nombre = _nombre;
	edad = _edad;
}

Estudiante::Estudiante(string _nombre, int _edad, string _codigo, float _notaMedia) : Persona(_nombre, _edad) {
	codigo = _codigo;
	notaMedia = _notaMedia;
}

Universitario::Universitario(string _nombre, int _edad, string _codigo, float _notaMedia, string _carrera) : Estudiante(_nombre, _edad, _codigo, _notaMedia) {
	carrera = _carrera;
}

Empleado::Empleado(string _nombre, int _edad, string _empleo, float _sueldo) : Persona(_nombre, _edad) {
	empleo = _empleo;
	sueldo = _sueldo;
}

void Persona::mostrarP() {
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
}

void Estudiante::mostrarE() {
	mostrarP();
	cout << "Codigo: " << codigo << endl;
	cout << "Nota Media: " << notaMedia << endl;
}

void Universitario::mostrarU() {
	mostrarE();
	cout << "Carrera: " << carrera << endl;
}

void Empleado::mostrarEM() {
	mostrarP();
	cout << "Empleo: " << empleo << endl;
	cout << "Sueldo: " << sueldo << "$" << endl;
}

int main() {
	Universitario uni1("Pepico Parker",25,"76G2",7.3,"Arquitectura");
	Empleado emp1("Juan Julian",46,"Jardinero",900);
	
	uni1.mostrarU();
	cout << endl;
	emp1.mostrarEM();
	
	cout << "\nPresione cualquier tecla para salir del programa." << endl;
	getch();
	return 0;
}