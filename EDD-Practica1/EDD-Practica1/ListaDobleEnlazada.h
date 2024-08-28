// ListaDobleEnlazada.h
#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H

#include "NodoPublicacion.h"

class ListaDobleEnlazada {
public:
    ListaDobleEnlazada();
    ~ListaDobleEnlazada();

    void push(const NodoPublicacion& nodo);
    void append(const NodoPublicacion& nodo);
    void remove(int index);
    NodoPublicacion* getPrimero() const;  // Método añadido
    void print() const;

private:
    NodoPublicacion* primero;
    NodoPublicacion* ultimo;
};

#endif // LISTADOBLEENLAZADA_H
