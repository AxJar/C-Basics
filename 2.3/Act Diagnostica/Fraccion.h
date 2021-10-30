#ifndef FRACCION_H
#define FRACCION_H

class Fraccion{
    private:
        int numerador;
        int denominador;
    public:
        //constructores
        Fraccion();
        Fraccion(int num, int den);
        //getters
        int getNum();
        int getDen(); 
        //setters
        void setNum(int num);
        void setDen(int den);
        
        int reducirFraacciones();
        int sumaFracciones();
        int multiplicaFraciones();
        void imprime();
};

#endif
