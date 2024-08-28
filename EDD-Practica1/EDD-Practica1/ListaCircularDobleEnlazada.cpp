// ListaCircularDobleEnlazada.cpp
#include "ListaCircularDobleEnlazada.h"
#include <iostream>

ListaCircularDobleEnlazada::ListaCircularDobleEnlazada() : actual(nullptr) {}

ListaCircularDobleEnlazada::~ListaCircularDobleEnlazada() {
    if (actual == nullptr) return;

    NodoPublicacion* inicio = actual;
    NodoPublicacion* siguiente;

    do {
        siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    } while (actual != inicio);
}

void ListaCircularDobleEnlazada::push(const NodoPublicacion& nodo) {
    NodoPublicacion* nuevo = new NodoPublicacion(nodo);

    if (actual == nullptr) {
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        actual = nuevo;
    } else {
        NodoPublicacion* ultimo = actual->getAnterior();

        nuevo->setSiguiente(actual);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        actual->setAnterior(nuevo);
    }
}

void ListaCircularDobleEnlazada::print() const {
    if (actual == nullptr) return;

    NodoPublicacion* temp = actual;

    do {
        std::cout << "Correo: " << temp->getCorreo() << ", Publicación: " << temp->getContenido()
                  << ", Fecha: " << temp->getFecha() << ", Hora: " << temp->getHora() << std::endl;
        temp = temp->getSiguiente();
    } while (temp != actual);
}

void ListaCircularDobleEnlazada::next() {
    if (actual != nullptr) {
        actual = actual->getSiguiente();
    }
}

void ListaCircularDobleEnlazada::previous() {
    if (actual != nullptr) {
        actual = actual->getAnterior();
    }
}
