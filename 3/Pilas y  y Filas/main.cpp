//https://www.journaldev.com/35189/priority-queue-in-c-plus-plus
//https://stackoverflow.com/questions/51828816/why-do-we-need-to-add-a-vector-as-an-argument-in-priority-queue-declaration
//https://en.cppreference.com/w/cpp/container/priority_queue

#include <iostream>
#include <string>
#include <queue>
#include "Triangulo.h"

//yo lo personas, UDS lo van a hacer con areas de triagulos what?
//quiero que esto me lo hagan bonito, me lo van a separar en archivos .h y .cpp


using namespace std;


class CompareClassT {
public:
    bool operator() (Triangulo a, Triangulo b) {
        if (a.getEdad() > b.getEdad())
            return true;
        return false;
    }
};



void print_pqueue(priority_queue<int, vector<int>, CompareClass> pq) {

    priority_queue<int, vector<int>, CompareClass> copy_q = pq;
    cout << "Priority Queue : ";
    while (!copy_q.empty()) {
        cout << copy_q.top() << " ";
        copy_q.pop();
    }
    cout << "\n";
}

void print_pqueueP(priority_queue<Triangulo, vector<Triangulo>, CompareClassP> pq) {

    priority_queue<Triangulo, vector<Triangulo>, CompareClassP> copy_q = pq;
    cout << "Priority Queue : ";
    while (!copy_q.empty()) {
        cout << copy_q.top() << " ";
        copy_q.pop();
    }
    cout << "\n";
}

int main() {

    priority_queue<Triangulo, vector<Triangulo>, CompareClassP> queue_Persona;


    queue_Persona.push(Triangulo("goku",40));
    queue_Persona.push(Triangulo("vegeta", 39));
    queue_Persona.push(Triangulo("bulma", 30));


    //receta de cocina,si yo quiero cambiar en un prq el orden preestablecido
    priority_queue<int, vector<int>, CompareClass> queue_int;  //esto no lo hice yo, es de las librerias

    cout << "Is the Queue empty now? : " << (queue_int.empty() ? "Yes" : "No") << endl;

    cout << "Adding some elements...\n";
    queue_int.push(6000);
    queue_int.push(500);
    queue_int.push(400);
    queue_int.push(5000);

    cout << "Number of elements : " << queue_int.size() << endl;
    cout << "Top element : " << queue_int.top() << endl << endl;

    print_pqueue(queue_int);

    cout << "Popping element from the top...\n\n";
    queue_int.pop();
    print_pqueue(queue_int);

    return 0;
}