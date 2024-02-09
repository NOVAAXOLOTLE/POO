// Ejercicio_Diagnostico

#include <iostream>
#include <stdlib.h>

using namespace std;

class Transport {
private:
    int capacity;
    string security;
    string motor;
    int velocity;
public:
    Transport(int, string, string, int);
    virtual void mostrar();
};

class Terrestrian : public Transport {
private:
    int nTires;
public:
    Terrestrian(int, string, string, int, int);
    void mostrar();
};

class Aerial : public Transport {
private:
    int cost;
public:
    Aerial(int, string, string, int, int);
    void mostrar();
};

class Maritime : public Transport {
private:
    string efficiency;
public:
    Maritime(int, string, string, int, string);
    void mostrar();
};

// definitions of class Maritime
Maritime::Maritime(int _capacity, string _security, string _motor, int _velocity, string _efficiency) : Transport(_capacity, _security, _motor, _velocity) {
    efficiency = _efficiency;
}

void Maritime::mostrar() {
    Transport::mostrar();
    cout << "Eficiencia del transporte: " << efficiency << endl;
}

// definitions of class Aerial
Aerial::Aerial(int _capacity, string _security, string _motor, int _velocity, int _cost) : Transport(_capacity, _security, _motor, _velocity) {
    cost = _cost;
}

void Aerial::mostrar() {
    Transport::mostrar();
    cout << "Costo promedio: " << cost << endl;
}

// definitions of class Terrestrians
Terrestrian::Terrestrian(int _capacity, string _security, string _motor, int _velocity, int _nTires) : Transport(_capacity, _security, _motor, _velocity) {
    nTires = _nTires;
}

void Terrestrian::mostrar() {
    Transport::mostrar();
    cout << "Número de ruedas: " << nTires << endl;
}

// definitions of class Transport
Transport::Transport(int _capacity, string _security, string _motor, int _velocity) {
    capacity = _capacity;
    security = _security;
    motor = _motor;
    velocity = _velocity;
}

void Transport::mostrar() {
    cout << "Capacidad de pasajeros: " << capacity << endl;
    cout << "Seguridad del transporte: " << security << endl;
    cout << "Tipo de motor: " << motor << endl;
    cout << "Velocidad del transporte: " << velocity << "km/h" << endl;
}

int main()
{
    Transport* vector[3];

    vector[0] = new Terrestrian(4, "poca", "motor de gasolina", 120, 4);
    vector[1] = new Aerial(70, "alta", "turbofan", 800, 700);
    vector[2] = new Maritime(6700, "media", "motor diesel cuatro tiempos", 37, "alta en grandes cargas");

    vector[0]->mostrar();
    cout << "\n";
    vector[1]->mostrar();
    cout << "\n";
    vector[2]->mostrar();
    cout << "\n";

    system("pause");
    return 0;
}
