#ifndef REGISTERENTRY_H
#define REGISTERENTRY_H

//Inclusión de las Librerías y Clases
#include <iostream>
#include <string>

//Ajuste a estandar
using namespace std;

class RegisterEntry {
private:
  // Ip en forma decimal
  unsigned long long ip;

  // String que contiene la ip
  string stringIp;
  
public:
  
  //Constructor la lista de registros, recibe como parámetro un string constante referenciado.
  explicit RegisterEntry(const string &textRegistry); //Complejidad Computacional: O(1).

  //Constructor defawult.
  RegisterEntry(); //Complejidad Computacional: O(1)

  //Función para leer la ip, recibe como parámetro un string constante referenciado y retorno un unsigned long long.
  static unsigned long long ipReader(const string &stringIp); //Complejidad Computacional: O(n)

  //Función para recibir la ip no recibe parámetros, va hacia constante, retorna un unsigned long long.
  unsigned long long int getIp() const; //Complejidad Computacional: O(1)

  //Función para definir la ip recibe un unsigned long long y no tiene valor de retorno.
  void setIp(unsigned long long int ip); //Complejidad Computacional: O(1)

  //Función para recibir la ip no recibe parámetros, va hacia constante, retorna una constante.
  const string &getStringIp() const; //Complejidad Computacional: O(1)

  //Función para definir la ip en forma de string, recibe un string constante refernciado y no tiene valor de retorno.
  void setStringIp(const string &stringIp); //Complejidad Computacional: O(1)
 
  //Función escribir la ip en el archivo recibe un ostream referenciado y una register entry constante referenciado y retorna un ostream.
  friend ostream &operator<<(ostream &os, const RegisterEntry &entry); //Complejidad Computacional: O(1)
};

#endif 