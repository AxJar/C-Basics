
#include <iostream>
#include <sstream>
#include "TablaHash.h"

using namespace std;

enum Status {
    empty, full, erased
};

struct Node {
    int value;
    Status myState = empty;
};

int HashKaux(int len, string Index, int cant, int tried) {
    string index;
    int index_num;
    if (len % 2 == 0) {
        index = Index[(len / 2) - 1];
        index += Index[(len / 2)];
        stringstream ind(Index);
        ind >> index_num;
        index_num += tried;
        if (index_num > cant) {
            index_num = index_num % cant;
            return index_num;
        }
        else {
            return index_num;
        }
    }else if (len % 2 != 0) {
        Index = Index[(len / 2)];
        stringstream ind(Index);
        ind >> index_num;
        index_num += tried;
        if (index_num > cant) {
            index_num = index_num % cant;
            return index_num;
        }
        else {
            return index_num;
        }
    }
}

int HashK(int value, int cant, int tried) {
    int index = (value * value);
    string ind = to_string(index);
    int length = ind.length();
    index = HashKaux(length, ind, cant, tried);
    return index;
}

void insert(int value, int cant, Node arr[]) {
    int i = 0;

    int index = 0;
    bool full_bool = false;

    while (!full_bool) {
        index = HashK(value, cant, i);
        if (arr[index].myState == empty) {
            full_bool = true;
            arr[index].value = value;
            arr[index].myState = full;
        }
        else {
            i++;
        }
    }
}

void print(int cant, Node arr[]) {
    for (int n = 0; n < cant; n++) { // O (n)
        cout << n << " " << arr[n].value << endl;
    }
}


int main() {

    int arr[] = { 42, 86, 43, 93, 5, 11, 72, 15, 34, 69 };

    int c = 10;
    Node array[10];

    for (int i = 0; i < c; i++) { // O (n)
        array[i].myState = empty;
        array[i].value = 0;
    }

    TablaHash ht(10);

    for (int i : arr) // O (n)
        ht.insertHash(i);
    ht.printC();

    return 0;
}