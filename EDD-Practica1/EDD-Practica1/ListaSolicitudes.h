// ListaSolicitudes.h
#ifndef LISTASOLICITUDES_H
#define LISTASOLICITUDES_H

#include "NodoSolicitud.h"

class ListaSolicitudes {
public:
    ListaSolicitudes() : cabeza(nullptr) {}

    // Método para imprimir la lista
    void print() const;

    // Métodos para agregar nodos, etc., pueden ir aquí

private:
    NodoSolicitud* cabeza;
};

#endif // LISTASOLICITUDES_H
