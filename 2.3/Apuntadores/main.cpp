
#include<iostream>
#include <vector>
using namespace std; 

void swap (int& first, int& second) { 
    int temp = first; 
    first = second; 
    second = temp; 
} 

int& fun() { 
    static int x = 10; 
    return x; 
} 

int fun2(int &x) { 
    return x; 
} 

int main() { 
    int x = 10; 
    int& ref = x; 
    ref = 20; 
    cout << "x = " << x << endl ; 
    cin.get();
    x = 30; 
    cout << "ref = " << ref << endl ; 
    cin.get();

    int a = 2, b = 3; 
    swap( a, b ); 
    cout << a << " " << b<<endl;  
    cin.get();

    vector<int> vect{ 10, 20, 30, 40 };  
    for (int& x : vect){
            x = x + 5; 
    }

    for (int x : vect){
        cout << x << " ";  
    }
    cout<<endl;
    cin.get();

    fun() = 30; 
    cout << fun();
    cin.get();
    return 0; 
}
