#ifndef LISTAENVIADAS_H
#define LISTAENVIADAS_H

#include <string>
#include <vector>

// Clase que representa una lista de solicitudes enviadas.
class ListaEnviadas {
public:
    void agregarSolicitud(const std::string& emisor, const std::string& receptor);
    bool existeSolicitud(const std::string& emisor, const std::string& receptor) const;
    void eliminarSolicitud(const std::string& emisor, const std::string& receptor);

private:
    std::vector<std::pair<std::string, std::string>> solicitudes;
};

#endif // LISTAENVIADAS_H
