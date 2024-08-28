#ifndef NODO_DOBLE_H
#define NODO_DOBLE_H

class NodoDoble {
private:
    int data;
    NodoDoble* prev;
    NodoDoble* next;

public:
    NodoDoble(int data);

    int getData();
    NodoDoble* getPrev();
    NodoDoble* getNext();

    void setData(int valor);
    void setPrev(NodoDoble* prev);
    void setNext(NodoDoble* next);
};

#endif
