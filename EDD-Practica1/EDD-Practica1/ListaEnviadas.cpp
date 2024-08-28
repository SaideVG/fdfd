#include "ListaEnviadas.h"
#include <algorithm>

void ListaEnviadas::agregarSolicitud(const std::string& emisor, const std::string& receptor) {
    solicitudes.emplace_back(emisor, receptor);
}

bool ListaEnviadas::existeSolicitud(const std::string& emisor, const std::string& receptor) const {
    return std::find(solicitudes.begin(), solicitudes.end(), std::make_pair(emisor, receptor)) != solicitudes.end();
}

void ListaEnviadas::eliminarSolicitud(const std::string& emisor, const std::string& receptor) {
    solicitudes.erase(std::remove(solicitudes.begin(), solicitudes.end(), std::make_pair(emisor, receptor)), solicitudes.end());
}
