using namespace std;
#include <iostream>
#include "libro.h"

//COMPLETA este programa principal, escribe las funciones que hagan falta...

// 1. ESCRIBE la función que carga información de una determinada cantidad de libros al arreglo con datos que proporciona el usuario.

//    Se pide al usuario título y numero de páginas por cada libro del arreglo (pidelos en ese orden).
//    El título del libro manéjalo por simplicidad de una sola palabra por ejemplo: Dracula
//    No pongas ningún mensaje al usuario para recibir los datos

void cargaInfoLibros(Libro Libros[], int cantLibros{
    for (int i=0; i<cantLibros; i++){
        string title;
		int numPags;

		cin>>title;
		cin>>numPags;

		libros[i].setTitulo(title);
		libros[i].setPaginas(numPags)
    }
}

// 2. ESCRIBE la función que recorre el arreglo, busca un determinado titulo y si lo encuentra, 
//    actualiza las paginas leidas de ese libro

bool buscaLibro(Libro Libros[], int cantLibros string LibroABuscar, int pags) {
    for (int i=0; i<cantLibros; i++){
        string title = libros[i].getTitulo();
        if (title == LibroABuscar){
            libros[i].registraAvance(pags)
        }
    }
    return false;
}

// 3. COMPLETA la función que muestra los libros de la biblioteca que han sigo cargados.
void muestraBiblioteca(Libro list[], int c){
    cout << "------------------------------"<<endl; //No la quites
    for(int i = 0; i<c; i++){
        list[i].imprime();
       //Escribe la instrucción para imprimir la información del libro, usando el método correspondiente de Libro.
        cout << "------------------------------"<<endl; //No la quites
    }
}

int main(){
    // 4. CREA un arreglo de objetos tipo Libro, llamado biblioteca con 10 localidades
    Libro biblioteca[10];
    //Variables que te van a servir para tus opciones del programa principal
    int cantLibros, paginas;
    char opcion;
    string titulo;
    //cout << "¿Cuántos libros vas a ingresar? "; déja esta instrucción como comentario
    // 5. ESCRIBE la instrucción para recibir la cantidad de libros
    cin >> cantLibros;
    // 6. LLAMA/INVOCA a la función para cargar los libros
    cargaInfoLibros(paginas,titulo);
    do {
        //cout << "a) Incrementar paginas leidas b) Mostrar biblioteca c) Terminar" << endl; ***Déja esta linea como comentario
        cin >> opcion;
        switch (opcion) {
            case 'a':
                //En esta opción se registran las páginas leidas de un libro en particular
                //cout << "Titulo del libro a actualizar: ";***Déja esta linea como comentario
                // 7. ESCRIBE la instrucción para recibir el titulo del libro
                cin >> titulo;
               //cout << "Paginas leidas: "; ***Deja esta linea como comentario
                // 8. ESCRIBE la instrucción para recibir la cantidad de páginas leidas
                cin >> paginas;
                // 9. LLAMA/INVOCA a la función correspondiente que creaste en este archivo
                buscaLibro(biblioteca,cantLibros, titulo,paginas);
                break;
            case 'b':
                // En esta opción se deben mostrar los libros de la biblioteca que han sido cargados.
                // 10. ESCRIBE lo necesario para realizar la acción mencionada en el renglón anterior
                muestraBiblioteca(biblioteca,cantLibros);
                break;
            case 'c':
                cout << "Escogiste salir del menu." << endl; //No modifiques esto
                break;
            default:
                cout << "Error, opcion incorrecta" << endl;// No modifiques esto
        }
    } while (opcion != 'c');
    
    return 0;

}