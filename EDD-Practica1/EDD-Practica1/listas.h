#ifndef LISTAS_H
#define LISTAS_H

#include <iostream>
#include <string>

// Nodo para la lista de solicitudes enviadas
struct NodoSolicitudEnviada {
    std::string correoReceptor;
    NodoSolicitudEnviada* siguiente;

    NodoSolicitudEnviada(std::string correo) : correoReceptor(correo), siguiente(nullptr) {}
};

// Lista simple para las solicitudes enviadas
class ListaSolicitudesEnviadas {
private:
    NodoSolicitudEnviada* cabeza;

public:
    ListaSolicitudesEnviadas() : cabeza(nullptr) {}

    void agregarSolicitud(std::string correoReceptor);
    void eliminarSolicitud(std::string correoReceptor);
    bool existeSolicitud(std::string correoReceptor);
};

// Nodo para la pila de solicitudes recibidas
struct NodoSolicitudRecibida {
    std::string correoEmisor;
    NodoSolicitudRecibida* siguiente;

    NodoSolicitudRecibida(std::string correo) : correoEmisor(correo), siguiente(nullptr) {}
};

// Pila para las solicitudes recibidas
class PilaSolicitudesRecibidas {
private:
    NodoSolicitudRecibida* cima;

public:
    PilaSolicitudesRecibidas() : cima(nullptr) {}

    void push(std::string correoEmisor);
    void pop();
    std::string top();
    bool estaVacia();
    bool existeSolicitud(std::string correoEmisor);
};

#endif
