#ifndef NODO_USUARIO_H
#define NODO_USUARIO_H

#include <string>

class NodoUsuario {
private:
    std::string nombre;
    std::string apellido;
    std::string fechaNacimiento;
    std::string correo;
    std::string contrasena;
    NodoUsuario* siguiente;

public:
    NodoUsuario(std::string nombre, std::string apellido, std::string fechaNacimiento, std::string correo, std::string contrasena);

    NodoUsuario* getSiguiente();
    void setSiguiente(NodoUsuario* siguiente);

    std::string getNombre();
    std::string getApellido();
    std::string getFechaNacimiento();
    std::string getCorreo();
    std::string getContrasena();

    ~NodoUsuario();
};

#endif
