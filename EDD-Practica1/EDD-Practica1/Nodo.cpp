#include "Nodo.h"

//Constructores
Nodo::Nodo() {
    data = 0;
    sig = nullptr;
}

Nodo::Nodo(int data) {
    this->data = data;
    sig = nullptr;
}

//Getter y setters
int Nodo::getData() {
    return data;
}

Nodo* Nodo::getSig() {
    return sig;
}

void Nodo::setData(int data) {
    this->data = data;
}

void Nodo::setSig(Nodo* sig) {
    this->sig = sig;
}
