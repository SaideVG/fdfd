#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "NodoUsuario.h"
#include <iostream>

class ListaSimple {
private:
    NodoUsuario* primero;
    NodoUsuario* ultimo;

public:
    ListaSimple();
    bool estaVacia();
    void insertarInicio(std::string nombre, std::string apellido, std::string fechaNacimiento, std::string correo, std::string contrasena);
    void insertarFinal(std::string nombre, std::string apellido, std::string fechaNacimiento, std::string correo, std::string contrasena);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    bool buscaPorCorreo(std::string correo);
    void eliminarPorCorreo(std::string correo);
    NodoUsuario* visualizarPrimero();
    void visualizarListaDot();
    ~ListaSimple();
};

#endif
