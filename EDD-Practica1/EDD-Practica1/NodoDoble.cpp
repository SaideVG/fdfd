#include "NodoDoble.h"

// Constructor
NodoDoble::NodoDoble(int data) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
}

// Getters
int NodoDoble::getData() {
    return data;
}

NodoDoble* NodoDoble::getPrev() {
    return prev;
}

NodoDoble* NodoDoble::getNext() {
    return next;
}

// Setters
void NodoDoble::setData(int data) {
    this->data = data;
}

void NodoDoble::setPrev(NodoDoble* prev) {
    this->prev = prev;
}

void NodoDoble::setNext(NodoDoble* next) {
    this->next = next;
}
