#include "NodoUsuario.h"

NodoUsuario::NodoUsuario(std::string nombre, std::string apellido, std::string fechaNacimiento, std::string correo, std::string contrasena) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->fechaNacimiento = fechaNacimiento;
    this->correo = correo;
    this->contrasena = contrasena;
    this->siguiente = nullptr;
}

NodoUsuario* NodoUsuario::getSiguiente() {
    return this->siguiente;
}

void NodoUsuario::setSiguiente(NodoUsuario* siguiente) {
    this->siguiente = siguiente;
}

std::string NodoUsuario::getNombre() {
    return this->nombre;
}

std::string NodoUsuario::getApellido() {
    return this->apellido;
}

std::string NodoUsuario::getFechaNacimiento() {
    return this->fechaNacimiento;
}

std::string NodoUsuario::getCorreo() {
    return this->correo;
}

std::string NodoUsuario::getContrasena() {
    return this->contrasena;
}

NodoUsuario::~NodoUsuario() {
    // Destructor
}
