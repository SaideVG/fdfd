/*#include "solicitudes.h"
#include <iostream>
#include <stdexcept> // Para std::runtime_error
#include <string>

void enviarSolicitud(ListaEnviadas& listaEnviadas, PilaRecibidas& pilaRecibidas, const std::string& correoEmisor, const std::string& correoReceptor) {
    // Verifica si ya existe una solicitud pendiente
    if (listaEnviadas.existeSolicitud(correoEmisor, correoReceptor)) {
        std::cout << "Ya se ha enviado una solicitud de amistad a este usuario.\n";
        return;
    }

    if (pilaRecibidas.existeSolicitud(correoReceptor, correoEmisor)) {
        std::cout << "Ya tienes una solicitud pendiente de este usuario.\n";
        return;
    }

    // Crear y agregar la solicitud a la lista de enviadas
    listaEnviadas.agregarSolicitud(correoEmisor, correoReceptor);
    // Crear y agregar la solicitud a la pila de recibidas
    pilaRecibidas.agregarSolicitud(correoEmisor, correoReceptor);
    std::cout << "Solicitud de amistad enviada a " << correoReceptor << ".\n";
}

void aceptarSolicitud(ListaEnviadas& listaEnviadas, PilaRecibidas& pilaRecibidas, MatrizAmistades& matrizAmistades, const std::string& correoEmisor, const std::string& correoReceptor) {
    // Verifica y elimina la solicitud de la pila de recibidas
    if (!pilaRecibidas.eliminarSolicitud(correoReceptor, correoEmisor)) {
        std::cout << "No se encontró una solicitud de amistad para aceptar.\n";
        return;
    }

    // Elimina la solicitud de la lista de enviadas
    listaEnviadas.eliminarSolicitud(correoEmisor, correoReceptor);

    // Añadir la amistad a la matriz de amistades
    matrizAmistades.insertarAmistad(correoEmisor, correoReceptor);
    std::cout << "Solicitud de amistad aceptada. Ahora eres amigo de " << correoReceptor << ".\n";
}

void rechazarSolicitud(PilaRecibidas& pilaRecibidas, const std::string& correoEmisor) {
    // Rechaza la solicitud de amistad
    if (!pilaRecibidas.eliminarSolicitud(correoEmisor)) {
        std::cout << "No se encontró una solicitud de amistad para rechazar.\n";
        return;
    }
    std::cout << "Solicitud de amistad rechazada.\n";
}*/
