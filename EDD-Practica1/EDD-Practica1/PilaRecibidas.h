/*
#include <string>
#include <stack>

#ifndef PILARECIBIDAS_H
#define PILARECIBIDAS_H

// Clase que representa una pila de solicitudes recibidas.
class PilaRecibidas {
public:
    void agregarSolicitud(const std::string& emisor, const std::string& receptor);
    bool existeSolicitud(const std::string& receptor, const std::string& emisor) const;
    bool eliminarSolicitud(const std::string& correoEmisor, const std::string& correoReceptor);

private:
    std::stack<std::pair<std::string, std::string>> solicitudes;
};

#endif */// PILARECIBIDAS_H

