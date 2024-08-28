// NodoPublicacion.cpp
#include "NodoPublicacion.h"

NodoPublicacion::NodoPublicacion(const std::string& correo, const std::string& contenido,
                                 const std::string& fecha, const std::string& hora)
    : correo(correo), contenido(contenido), fecha(fecha), hora(hora), siguiente(nullptr), anterior(nullptr) {}

std::string NodoPublicacion::getCorreo() const { return correo; }
std::string NodoPublicacion::getContenido() const { return contenido; }
std::string NodoPublicacion::getFecha() const { return fecha; }
std::string NodoPublicacion::getHora() const { return hora; }

NodoPublicacion* NodoPublicacion::getSiguiente() const { return siguiente; }
NodoPublicacion* NodoPublicacion::getAnterior() const { return anterior; }

void NodoPublicacion::setSiguiente(NodoPublicacion* siguiente) { this->siguiente = siguiente; }
void NodoPublicacion::setAnterior(NodoPublicacion* anterior) { this->anterior = anterior; }
