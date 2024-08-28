#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <fstream>

class NodoMatriz {
private:
    int i, j;
    bool data;
    NodoMatriz *arriba, *abajo;
    NodoMatriz *izq, *dcha;

public:
    NodoMatriz(int i, int j);
    NodoMatriz(int i, int j, bool data);

    void setI(int i);
    void setJ(int j);
    void setData(bool data);
    void setArriba(NodoMatriz *arriba);
    void setAbajo(NodoMatriz *abajo);
    void setIzq(NodoMatriz *izq);
    void setDcha(NodoMatriz *dcha);

    int getI();
    int getJ();
    bool getData();
    NodoMatriz* getArriba();
    NodoMatriz* getAbajo();
    NodoMatriz* getIzq();
    NodoMatriz* getDcha();
};

class Matriz {
private:
    NodoMatriz *raiz;
    int ancho;
    int alto;

    NodoMatriz* buscarColumna(int i);
    NodoMatriz* buscarFila(int j);
    void insertarEnFila(NodoMatriz *nuevo, NodoMatriz *encabezadoColumna);
    void insertarEnColumna(NodoMatriz *nuevo, NodoMatriz *encabezadoFila);
    NodoMatriz* insertarEncabezadoFila(int j);
    NodoMatriz* insertarEncabezadoColumna(int i);
    void imprimirEncabezadosColumna();
    NodoMatriz* obtenerNodo(int i, int j);

public:
    Matriz();
    ~Matriz();

    void insert(int i, int j, bool data);
    bool existeNodo(NodoMatriz *nuevo);
    void print();
    void graph();
};

#endif
