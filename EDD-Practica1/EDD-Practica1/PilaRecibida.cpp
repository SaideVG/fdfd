/*

#include "PilaRecibidas.h"
#include <algorithm>
#include <stack>

void PilaRecibidas::agregarSolicitud(const std::string& emisor, const std::string& receptor) {
    solicitudes.emplace(emisor, receptor);
}

bool PilaRecibidas::existeSolicitud(const std::string& receptor, const std::string& emisor) const {
    std::stack<std::pair<std::string, std::string>> temp = solicitudes;
    while (!temp.empty()) {
        if (temp.top() == std::make_pair(emisor, receptor)) {
            return true;
        }
        temp.pop();
    }
    return false;
}

bool PilaRecibidas::eliminarSolicitud(const std::string& receptor, const std::string& emisor) {
    std::stack<std::pair<std::string, std::string>> temp;
    bool encontrado = false;

    while (!solicitudes.empty()) {
        if (solicitudes.top() == std::make_pair(emisor, receptor)) {
            encontrado = true;
            solicitudes.pop();
            break;
        }
        temp.push(solicitudes.top());
        solicitudes.pop();
    }

    while (!temp.empty()) {
        solicitudes.push(temp.top());
        temp.pop();
    }

    return encontrado;
}
*/