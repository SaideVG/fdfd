#include "listas.h"

// Implementación de la ListaSimple para solicitudes enviadas
void ListaSolicitudesEnviadas::agregarSolicitud(std::string correoReceptor) {
    NodoSolicitudEnviada* nuevo = new NodoSolicitudEnviada(correoReceptor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void ListaSolicitudesEnviadas::eliminarSolicitud(std::string correoReceptor) {
    NodoSolicitudEnviada* temp = cabeza;
    NodoSolicitudEnviada* anterior = nullptr;

    while (temp != nullptr && temp->correoReceptor != correoReceptor) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (temp != nullptr) {
        if (anterior == nullptr) {
            cabeza = temp->siguiente;
        } else {
            anterior->siguiente = temp->siguiente;
        }
        delete temp;
    }
}

bool ListaSolicitudesEnviadas::existeSolicitud(std::string correoReceptor) {
    NodoSolicitudEnviada* temp = cabeza;
    while (temp != nullptr) {
        if (temp->correoReceptor == correoReceptor) {
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

// Implementación de la Pila para solicitudes recibidas
void PilaSolicitudesRecibidas::push(std::string correoEmisor) {
    NodoSolicitudRecibida* nuevo = new NodoSolicitudRecibida(correoEmisor);
    nuevo->siguiente = cima;
    cima = nuevo;
}

void PilaSolicitudesRecibidas::pop() {
    if (cima != nullptr) {
        NodoSolicitudRecibida* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

std::string PilaSolicitudesRecibidas::top() {
    if (cima != nullptr) {
        return cima->correoEmisor;
    }
    return "";
}

bool PilaSolicitudesRecibidas::estaVacia() {
    return cima == nullptr;
}

bool PilaSolicitudesRecibidas::existeSolicitud(std::string correoEmisor) {
    NodoSolicitudRecibida* temp = cima;
    while (temp != nullptr) {
        if (temp->correoEmisor == correoEmisor) {
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}
