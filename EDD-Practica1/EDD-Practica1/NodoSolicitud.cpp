#include "NodoSolicitud.h"

class ListaSolicitudes {
private:
    NodoSolicitud* primero;
    NodoSolicitud* ultimo;

public:
    ListaSolicitudes();
    ~ListaSolicitudes();

    void append(std::string data);
    void print(); // Para mostrar las solicitudes enviadas
};

