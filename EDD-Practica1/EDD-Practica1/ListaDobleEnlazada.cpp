// ListaDobleEnlazada.cpp
#include "ListaDobleEnlazada.h"
#include <iostream>

ListaDobleEnlazada::ListaDobleEnlazada() : primero(nullptr), ultimo(nullptr) {}

ListaDobleEnlazada::~ListaDobleEnlazada() {
    NodoPublicacion* temp = primero;
    NodoPublicacion* aux;

    while (temp != nullptr) {
        aux = temp->getSiguiente();
        delete temp;
        temp = aux;
    }
}

void ListaDobleEnlazada::push(const NodoPublicacion& nodo) {
    NodoPublicacion* nuevo = new NodoPublicacion(nodo);

    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        nuevo->setSiguiente(primero);
        primero->setAnterior(nuevo);
        primero = nuevo;
    }
}

void ListaDobleEnlazada::append(const NodoPublicacion& nodo) {
    NodoPublicacion* nuevo = new NodoPublicacion(nodo);

    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        ultimo = nuevo;
    }
}


NodoPublicacion* ListaDobleEnlazada::getPrimero() const {
    return primero;
}

void ListaDobleEnlazada::print() const {
    NodoPublicacion* temp = primero;

    while (temp != nullptr) {
        std::cout << "Correo: " << temp->getCorreo() << ", Publicación: " << temp->getContenido()
                  << ", Fecha: " << temp->getFecha() << ", Hora: " << temp->getHora() << std::endl;
        temp = temp->getSiguiente();
    }
}

void ListaDobleEnlazada::remove(int index) {
    if (index < 1) return;

    NodoPublicacion* actual = primero;
    int contador = 1;

    while (actual != nullptr && contador < index) {
        actual = actual->getSiguiente();
        contador++;
    }

    if (actual == nullptr) return;

    if (actual->getAnterior() != nullptr) {
        actual->getAnterior()->setSiguiente(actual->getSiguiente());
    } else {
        primero = actual->getSiguiente();
    }

    if (actual->getSiguiente() != nullptr) {
        actual->getSiguiente()->setAnterior(actual->getAnterior());
    } else {
        ultimo = actual->getAnterior();
    }

    delete actual;
}
