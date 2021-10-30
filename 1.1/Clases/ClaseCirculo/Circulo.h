
// Deja la constante afuera de la clase
const double PI = 3.1416;

// INSTRUCCIONES: 
// Escribe la clase Circulo de acuerdo con 
// los comentarios que se encuentran enseguida


// Nombre de la clase: Circulo
class Circulo{
    // parte pública
    public:
         // método de modificación para radio
        void setRadio(double rad){
            radio = rad;
        }
         // método de acceso para radio
        double getRadio(){
            return radio;
        }
        // método que calcula el área ( PI * radio al cuadrado )
    double calcArea();
         // método que calcula el perímetro ( 2 * PI * radio )
    double calcPerimetro();
    // parte privada
    private:
        // atributo radio
        double radio;
};

// implementa los métodos

double Circulo::calcArea(){
    return PI * (radio * radio);
}

double Circulo::calcPerimetro(){
    return PI * 2 * radio;
}
