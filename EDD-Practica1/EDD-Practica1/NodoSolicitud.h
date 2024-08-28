// NodoSolicitud.h
#ifndef NODOSOLICITUD_H
#define NODOSOLICITUD_H

#include <string>

class NodoSolicitud {
public:
    NodoSolicitud(const std::string& emisor, const std::string& receptor, const std::string& estado)
        : emisor(emisor), receptor(receptor), estado(estado), siguiente(nullptr) {}

    // Métodos para obtener los datos
    std::string getEmisor() const { return emisor; }
    std::string getReceptor() const { return receptor; }
    std::string getEstado() const { return estado; }
    NodoSolicitud* getSiguiente() const { return siguiente; }
    void setSiguiente(NodoSolicitud* sig) { siguiente = sig; }

private:
    std::string emisor;
    std::string receptor;
    std::string estado;
    NodoSolicitud* siguiente;
};

#endif // NODOSOLICITUD_H
