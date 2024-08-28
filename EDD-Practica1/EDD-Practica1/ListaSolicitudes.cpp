// ListaSolicitudes.cpp
#include "ListaSolicitudes.h"
#include <iostream>

void ListaSolicitudes::print() const {
    NodoSolicitud* temp = cabeza;
    while (temp != nullptr) {
        std::cout << "Emisor: " << temp->getEmisor()
                  << ", Receptor: " << temp->getReceptor()
                  << ", Estado: " << temp->getEstado() << std::endl;
        temp = temp->getSiguiente();
    }
}
