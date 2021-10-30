#ifndef CTABANC_H
#define CTABANC_H

class CtaBanc{
    private:
        string nombre;
        double saldo;
    public:
        CtaBanc();
        CtaBanc(string nom, double sal);
        // Metodos de acceso
        string getNombre();
        double getSaldo();
        // Metodos de modificacion
        void setNombre(string nombre);
        void setSaldo(double saldo);

        // Otros metodos 
        void deposita(double cant);
        bool retira(double cant);
        void muestra();
};

#endif