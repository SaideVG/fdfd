// NodoPublicacion.h
#ifndef NODOPUBLICACION_H
#define NODOPUBLICACION_H

#include <string>

class NodoPublicacion {
public:
    NodoPublicacion(const std::string& correo, const std::string& contenido,
                    const std::string& fecha, const std::string& hora);

    std::string getCorreo() const;
    std::string getContenido() const;
    std::string getFecha() const;
    std::string getHora() const;

    NodoPublicacion* getSiguiente() const;
    NodoPublicacion* getAnterior() const;

    void setSiguiente(NodoPublicacion* siguiente);
    void setAnterior(NodoPublicacion* anterior);

private:
    std::string correo;
    std::string contenido;
    std::string fecha;
    std::string hora;

    NodoPublicacion* siguiente;
    NodoPublicacion* anterior;
};

#endif // NODOPUBLICACION_H
