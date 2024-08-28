// ListaCircularDobleEnlazada.h
#ifndef LISTACIRCULARDOBLEENLAZADA_H
#define LISTACIRCULARDOBLEENLAZADA_H

#include "NodoPublicacion.h"

class ListaCircularDobleEnlazada {
public:
    ListaCircularDobleEnlazada();
    ~ListaCircularDobleEnlazada();

    void push(const NodoPublicacion& nodo);
    void print() const;
    void next();
    void previous();

private:
    NodoPublicacion* actual;
};

#endif // LISTACIRCULARDOBLEENLAZADA_H
