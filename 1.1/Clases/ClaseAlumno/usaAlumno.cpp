#include <iostream>
#include <string>
using namespace std;

#include "Alumno.h"

// agrega el código que se indica en las instrucciones. Atiende a la secuencia. Recuerda que debe ser exacta.

int main () {
    Alumno alumno1;
    alumno1.imprimeAlumno();
    Alumno alumno2 ("A001420000", "Georgina", "ITC" , 18);
    alumno2.imprimeAlumno();
    alumno1.setNombre("Andrea");
    alumno1.setEdad(19);
    alumno1.imprimeAlumno();
    alumno2.cumpleanios();
    alumno2.imprimeAlumno();
    return 0;
}

    // Declara una variable alumno1 con el contstructor default
    // Imprime los valores de alumno1 usando imprimeAlumno
    // Declara una variable alumno2 con el constructor con parámetros e inicializa con "A001420000", "Georgina", "ITC" y 18
    // Completa con una llamada al método imprimeAlumno con el objeto alumno2
    // Usa el método modificador para cambiar el nombre del alumno1 por "Andrea¨ y su edad por 19.
    // Muestra el objeto alumno1
    // Usa el método cumpleanios con el objeto alumno2
    // Usa el método para imprimir el objeto alumno2