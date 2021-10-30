//PROGRAMA:Programa que abre una bitácora desordenada; la guarda ordenada, y permite al usuario ver los hechos entre dos días que él decida por medio de su interacción con la consola.
//PROGRAMADORES: León Emiliano García Pérez (A00573074), Leonardo Luna Flores (A01633305), Axel Jarquín Morga(A01636324).
//FECHA DE ENTREGA: SEP 15, 2021.

//Innclusión de librerías.

#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
#include <stdlib.h>
#include <fstream>

//Ajuste a estandar

using namespace std;

//Función que permite dar un espacio en la consola, cambiando de línea. No recibe parámetros y no tiene valor de retorno.
void espacio(){
  cout << endl;
}

//Función que sepera los tokens de un string, recibiendo como parámetro el string y retornando una vector de strings, que contiene cada separación del string.
vector<string> espaciadoTokensPlus (string linea){

  //Tokenizado I, en función del " ".

  vector<string> tokens1;
  stringstream check1(linea);
  string intermedio1;

  while(getline(check1,intermedio1, ' ')){
    tokens1.push_back(intermedio1);
  }

  //Tokenizado II, en función del ":".

  string hora = tokens1[2];
  vector<string> tokens2;
  stringstream check2(hora);
  string intermedio2;

  while(getline(check2,intermedio2, ':')){
    tokens2.push_back(intermedio2);
  }

  vector<string> tokensFinal;
  tokensFinal.push_back(tokens1[0]);
  tokensFinal.push_back(tokens1[1]);

  for (int i = 0 ; i < tokens2.size() ; i++)
    tokensFinal.push_back(tokens2[i]);

  for (int i = 3 ; i < tokens1.size() ; i++)
    tokensFinal.push_back(tokens1[i]);
  
  return tokensFinal;
}

//Función que muestra el contenido de un vector de strings, donde recibe como parámetro dicho vector y no tiene valor de retorno.
void muestraVector(vector<string> vect){
  
  for (int i = 0 ; i < vect.size() ; i++){
    if (i == 2 || i == 3){
      cout << vect[i];
      cout << ":";
    }
    else{
      cout << vect[i];
      cout << " ";
    }
  }
  cout<<endl;
}

//Función que muestra el contenido de un vector de vectores de strings, donde recibe como parámetro dicha matriz y no tiene valor de retorno.
void muestraMatriz(vector<vector<string>> matriz){

  espacio();
  cout<<"XXXXXXXXXXXXXXX BITACORA XXXXXXXXXXXXXXX"<<endl;
  espacio();

  for (int i = 0 ; i < matriz.size(); i++)
    muestraVector(matriz[i]);  
}

//Función que abre un archivo de texto con el formato anticipado, sin recibir parámetros, lo guarda en un vector de vectores de string.
vector<vector<string>> lecturaUltra(){
  
  fstream prueba("bitacora.txt", ios::in);
  string line;

  vector<vector<string>> res;

  if (prueba.is_open()){
    getline(prueba,line);
    while(prueba){
      vector<string> vect = espaciadoTokensPlus(line);
      res.push_back(vect);
      getline(prueba,line);
    }
    prueba.close();
  }
  return res;
}

//Funcion que ordena la matriz de vectores de manera descendente en priorizando mes y despues dia, recibe como parametro un vector de vectores de string, y no tiene valor de retorno.
void ordenaFinal(vector<vector<string>>& matriz){ ////////////////////////////////////////////////////////////////////DOCUMENTACIÓN: Complejidad computacional O(372n)

  vector<vector<string>> nuevo;
  vector<string> mes={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dic"};
  vector<string> dia={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};

  for (int a = 0; a < mes.size(); a++) //DOCUMENTACIÓN: Sucede 12 veces
    for (int b = 0; b < dia.size(); b++) //DOCUMENTACIÓN: Sucede 31 veces
        for (int c = 0; c < matriz.size(); c++) //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.
            if (matriz[c][0] == mes[a] && matriz[c][1] == dia[b])
                nuevo.push_back(matriz[c]);

  matriz = nuevo; 
}

// Se declara un mapeo para transformar lo leido de meses en string a int, para poder compararlos con mayor facilidad.
unordered_map<string, int>  monthsMap;

//Función que asigna los valores del mapeo anterior, no recibe parámetros y no tiene valor de retorno.
void sorteo_mes(){
  monthsMap["Jan"] = 1;
  monthsMap["Feb"] = 2;
  monthsMap["Mar"] = 3;
  monthsMap["Apr"] = 4;
  monthsMap["May"] = 5;
  monthsMap["Jun"] = 6;
  monthsMap["Jul"] = 7;
  monthsMap["Aug"] = 8;
  monthsMap["Sep"] = 9;
  monthsMap["Oct"] = 10;
  monthsMap["Nov"] = 11;
  monthsMap["Dec"] = 12;
}

// Se declara un mapeo para transformar lo leido de dias en string a int, para poder compararlos con mayor facilidad.
unordered_map<string, int>  daysMap;

//Función que asigna los valores del mapeo anterior, no recibe parámetros y no tiene valor de retorno.
void sorteo_dia(){
  daysMap["01"] = 1;
  daysMap["02"] = 2;
  daysMap["03"] = 3;
  daysMap["04"] = 4;
  daysMap["05"] = 5;
  daysMap["06"] = 6;
  daysMap["07"] = 7;
  daysMap["08"] = 8;
  daysMap["09"] = 9;
  daysMap["10"] = 10;
  daysMap["11"] = 11;
  daysMap["12"] = 12;
  daysMap["13"] = 13;
  daysMap["14"] = 14;
  daysMap["15"] = 15;
  daysMap["16"] = 16;
  daysMap["17"] = 17;
  daysMap["18"] = 18;
  daysMap["19"] = 19;
  daysMap["20"] = 20;
  daysMap["21"] = 21;
  daysMap["22"] = 22;
  daysMap["23"] = 23;
  daysMap["24"] = 24;
  daysMap["25"] = 25;
  daysMap["26"] = 26;
  daysMap["27"] = 27;
  daysMap["28"] = 28;
  daysMap["29"] = 29;
  daysMap["30"] = 30;
  daysMap["31"] = 31;
}

//Funcion que realiza la busqueda de fechas, recibe como parametros un vector de vectores de string, y 4 strings individuales correspondientes a mes y dia iniciales y finales; no tiene valor de retorno.
void muestraBusqueda(vector<vector<string>> matriz, string m1, string d1, string m2, string d2){ ////////////////////////DOCUMENTACIÓN: Complejidad computacional O(3n^2)
  
  sorteo_dia();
  sorteo_mes();
  int mes1 = monthsMap[m1]; 
  int mes2 = monthsMap[m2]; 
  int dia1 = daysMap[d1];
  int dia2 = daysMap[d2];

  //Análisis primer mes. //DOCUMENTACIÓN: Sucede por primera vez respecto a la matriz (vector<vector<string>>) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.

  espacio();
  cout<<"XXXXXXXXXXXXXXX RESULTADO DE BUSQUEDA XXXXXXXXXXXXXXX"<<endl;
  espacio();

    for (int a = 0; a < matriz.size(); a++) //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
      if (m1 == m2){
        if (matriz[a][0] == m1 && daysMap[matriz[a][1]] >= dia1 && daysMap[matriz[a][1]] <= dia2)
          muestraVector(matriz[a]); //DOCUMENTACIÓN: Sucede n veces INTERNAMENTE respecto a la matriz (vector<vector<string>>)
      }
      else if (m1 != m2 && matriz[a][0] == m1 && daysMap[matriz[a][1]] >= dia1)
          muestraVector(matriz[a]);
      
  //Analis en caso de haber meses intermedios. //DOCUMENTACIÓN: Sucede por segunda vez respecto a la matriz (vector<vector<string>>) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.

  for (int k = 0; k < matriz.size(); k++) //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
    if(monthsMap[matriz[k][0]] > mes1 && monthsMap[matriz[k][0]] < mes2)
      muestraVector(matriz[k]); //DOCUMENTACIÓN: Sucede n veces INTERNAMENTE respecto a la matriz (vector<vector<string>>)

  //Análisis último de mes. //DOCUMENTACIÓN: Sucede por tercera vez respecto a la matriz (vector<vector<string>>) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.

    for (int p = 0;p < matriz.size(); p++) //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
      if (matriz[p][0] != m1)
        if (matriz[p][0] == m2 && daysMap[matriz[p][1]] <= dia2)
          muestraVector(matriz[p]); //DOCUMENTACIÓN: Sucede n veces INTERNAMENTE respecto a la matriz (vector<vector<string>>)

  espacio();
  
cout<<"RESULTADOS ENCONTRADOS DE "<< m1 << " " << d1 <<" - "<< m2 << " " <<d2 <<endl;

}

// Funcion para guardar matriz dentro de un archivo de texto, recibe como parametro un vector de vectores string y no tiene valor de retorno.
void guardaMatriz(vector<vector<string>> matriz){ 

  string nombreArchivo="bitacoraOrdenada.txt";
  ofstream archivo;

  archivo.open(nombreArchivo.c_str(),fstream::out);

  for (int i = 0 ; i < matriz.size() ; i++){
    //Inicia Adaptación de Muestra Vector a Guarda Vector
    for (int j = 0 ; j < matriz[i].size() ; j++){
      if (j == 2 || j == 3){
        archivo << matriz[i][j];
        archivo << ":";
      }
      else{
        archivo << matriz[i][j];
        archivo << " ";

      }
    }

  if(i == matriz.size() - 1)
    archivo << "";
  else
    archivo << endl;
  //Termina Adaptación de Muestra Vector a Guarda Vector
  }
  archivo.close();
}

//Función que guarda ls Búsqueda de la Matriz, dentro de un Archivo de Texto, recibe como parametros un vector de vectores de string, y 4 strings individuales correspondientes a mes y dia iniciales y finales; no tiene valor de retorno. //DOCUMENTACIÓN: Complejidad computacional O(3n^2)
void guardaBusqueda(vector<vector<string>> matriz, string m1, string d1, string m2, string d2){

  sorteo_dia();
  sorteo_mes();
  int mes1 = monthsMap[m1]; 
  int mes2 = monthsMap[m2]; 
  int dia1 = daysMap[d1];
  int dia2 = daysMap[d2];

  string nombretxt="busquedaOrdenada.txt";
  ofstream busquedaOrdenada;
  busquedaOrdenada.open(nombretxt.c_str(),fstream::out);

  //Análisis primer mes. //DOCUMENTACIÓN: Sucede por primera vez respecto a la matriz (vector<vector<string>>) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.

    for (int a = 0; a < matriz.size(); a++){ //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
      if (m1 == m2){
        if (matriz[a][0] == m1 && daysMap[matriz[a][1]] >= dia1 && daysMap[matriz[a][1]] <= dia2){
          //Inicia Adaptación de Muestra Vector a Guarda Vector

          for (int j = 0 ; j < matriz[a].size() ; j++){ //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
            if (j == 2 || j == 3){
              busquedaOrdenada << matriz[a][j];
              busquedaOrdenada << ":";
            }
            else{
              busquedaOrdenada << matriz[a][j];
              busquedaOrdenada << " ";
            }
          }
          if(a < matriz.size() - 1)
            busquedaOrdenada << endl;
          else if (a == matriz.size() - 1)
            busquedaOrdenada << "";

          //Termina Adaptación de Muestra Vector a Guarda Vector
        }
      }
    else if (m1 != m2 && matriz[a][0] == m1 && daysMap[matriz[a][1]] >= dia1){
          //Inicia Adaptación de Muestra Vector a Guarda Vector

          for (int j = 0 ; j < matriz[a].size() ; j++){ //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
            if (j == 2 || j == 3){
              busquedaOrdenada << matriz[a][j];
              busquedaOrdenada << ":";
            }
            else{
              busquedaOrdenada << matriz[a][j];
              busquedaOrdenada << " ";
            }
          }
          busquedaOrdenada << endl;

          //Termina Adaptación de Muestra Vector a Guarda Vector
    }
  }
      
  //Analis en caso de haber meses intermedios. //DOCUMENTACIÓN: Sucede por segunda vez respecto a la matriz (vector<vector<string>>) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora. 

  for (int k = 0; k < matriz.size(); k++){ //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
    if(monthsMap[matriz[k][0]] > mes1 && monthsMap[matriz[k][0]] < mes2){
          ////Inicia Adaptación de Muestra Vector a Guarda Vector

          for (int j = 0 ; j < matriz[k].size() ; j++){ //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
            if (j == 2 || j == 3){
              busquedaOrdenada << matriz[k][j];
              busquedaOrdenada << ":";
            }
            else{
              busquedaOrdenada << matriz[k][j];
              busquedaOrdenada << " ";
            }
          }
          busquedaOrdenada << endl;

        //Termina Adaptación de Muestra Vector a Guarda Vector
    }
  }

  //Análisis último de mes. //DOCUMENTACIÓN: Sucede por tercera vez respecto a la matriz (vector<vector<string>>) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.

    for (int p = 0;p < matriz.size(); p++){ //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
      if (matriz[p][0] != m1){
        if (matriz[p][0] == m2 && daysMap[matriz[p][1]] <= dia2){
          //Inicia Adaptación de Muestra Vector a Guarda Vector

          for (int j = 0 ; j < matriz[p].size() ; j++){ //DOCUMENTACIÓN: Sucede n veces respecto a la matriz (vector<vector<string>>)
            if (j == 2 || j == 3){
              busquedaOrdenada << matriz[p][j];
              busquedaOrdenada << ":";
            }
            else{
              busquedaOrdenada << matriz[p][j];
              busquedaOrdenada << " ";
            }
          }

          if(p < matriz.size() - 1)
            busquedaOrdenada << endl;
          else if (p == matriz.size() - 1)
            busquedaOrdenada << "";

          //Terminada Adaptación de Muestra Vector a Guarda Vector
        }
      }
    }
  
  busquedaOrdenada.close();

  espacio();
  cout<<"BUSQUEDA ALMACENADA DE "<< m1 << " " << d1 <<" - "<< m2 << " " <<d2 <<endl;
  
}

//Main ejecutable del Programa en C++
int main(){

  //INICIO DE PROGRAMA    

  //Crear matriz.
  vector<vector<string>> matriz;

  //Leer archivo de texto.
  matriz = lecturaUltra();

  // Ordenar matriz por Mes y Dia.
  ordenaFinal(matriz); //DOCUMENTACIÓN: Complejidad computacional O(372n) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.

  // Mostrar matriz ordenada.
  muestraMatriz(matriz);

  // Guardar matriz ordenada en archivo de texto.
  guardaMatriz(matriz);

  espacio(); 
  // Declaracion de inputs del usuario.
  string mesInicio;
  string diaInicio;
  string mesFin;
  string diaFin;

  //Main inicial donde el usuario interactua ingresando fechas deseadas.
  cout << "INREGSE SU BUSQUEDA: "<<endl;

  cout << "Ingrese mes de inicio: Ejemplo (Jan, Feb, Mar... etc): ";
  cin >> mesInicio;
  cout << "\nIngrese dia de inicio: Ejemplo (01, 02, 03... 30, 31): ";
  cin >> diaInicio;
  cout << "\nIngrese mes de fin: Ejemplo (Jan, Feb, Mar... etc): ";
  cin >> mesFin;
  cout << "\nIngrese dia de fin: Ejemplo (01, 02, 03... 30, 31): ";
  cin >> diaFin;

  // Se realiza la busqueda y se despliega.
  muestraBusqueda(matriz, mesInicio, diaInicio, mesFin, diaFin); //DOCUMENTACIÓN: Complejidad computacional O(3n^2) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.

  // Se almacena la búsqueda realizada.

  guardaBusqueda(matriz, mesInicio, diaInicio, mesFin, diaFin); //DOCUMENTACIÓN: Complejidad computacional O(3n^2) / Considerando n como el número de vectores de string que contiene el vector matriz, siendo un vector de string resultado de una línea de bitácora.

  //FIN DE PROGRAMA 
}