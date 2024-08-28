#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "ListaSimple.h"
#include "ListaDobleEnlazada.h"
//#include "PilaSolicitudes.h"
#include "ListaSolicitudes.h"
#include "ListaCircularDobleEnlazada.h"
#include "NodoPublicacion.h"

using namespace std;
using json = nlohmann::json;

ListaSimple listaUsuarios;
ListaDobleEnlazada listaPublicaciones;
ListaSolicitudes listaSolicitudesEnviadas;



void cargarUsuariosDesdeJSON();
void cargarSolicitudesDesdeJSON();
void cargarPublicacionesDesdeJSON();
void menuAdministrador();
void menuUsuario(const std::string& correoActual);
void iniciarSesion();
void registroUsuario();
void perfilUsuario();
void mostrarSolicitudes(const std::string& correo);
void mostrarPublicaciones(const std::string& correo);
void menuPublicaciones(const std::string& correo);
void verPublicaciones();
void crearPublicacion();
void eliminarPublicacion(ListaDobleEnlazada& listaPublicaciones);

#define RESET   "\033[0m"
#define RED     "\033[31m"      // Rojo
#define GREEN   "\033[32m"      // Verde
#define YELLOW  "\033[33m"      // Amarillo
#define BLUE    "\033[34m"      // Azul
#define MAGENTA "\033[35m"      // Magenta
#define CYAN    "\033[36m"      // Cian
#define WHITE   "\033[37m"      // Blanco
using namespace std;


int main() {
    int opcion;

    do {
        cout << CYAN << "1. Iniciar sesion\n" << RESET;
        cout << GREEN << "2. Registrarse\n" << RESET;
        cout << YELLOW << "3. Informacion\n" << RESET;
        cout << RED << "4. Salir\n" << RESET;
        cout << BLUE << "Seleccione una opcion: " << RESET;
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << GREEN << "Iniciando sesion...\n" << RESET;
            iniciarSesion();
            break;
        case 2:
            cout << GREEN << "Registrandose...\n" << RESET;
            registroUsuario();
            break;
        case 3:
            cout << MAGENTA << "Aplicacion de Red Social\n" << RESET;
            cout << MAGENTA << "Desarrollado para el curso de Estructuras de Datos.\n" << RESET;
            cout << MAGENTA << "KEVIN MANUEL VELIZ GALVEZ\n" << RESET;
            cout << MAGENTA << "201901441\n" << RESET;
            break;
        case 4:
            cout << RED << "Saliendo de la aplicacion.\n" << RESET;
            break;
        default:
            cout << RED << "Opcion invalida.\n" << RESET;
        }
    } while (opcion != 4);

    return 0;
}

void iniciarSesion() {
    string correo, contrasena;
    cout << "Ingrese su correo: ";
    cin >> correo;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    if (correo == "admin" && contrasena == "admin") {
        menuAdministrador();
    } else {
        NodoUsuario* usuario = listaUsuarios.visualizarPrimero();
        while (usuario != nullptr) {
            if (usuario->getCorreo() == correo && usuario->getContrasena() == contrasena) {
                menuUsuario(correo);  // Pasar el correo al menú de usuario
                return;
            }
            usuario = usuario->getSiguiente();
        }
        cout << "Credenciales incorrectas.\n";
    }
}


void registroUsuario() {
    string nombre, apellido, fecha, correo, contrasena;

    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su apellido: ";
    cin >> apellido;
    cout << "Ingrese su fecha de nacimiento: ";
    cin >> fecha;
    cout << "Ingrese su correo: ";
    cin >> correo;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    if (!listaUsuarios.buscaPorCorreo(correo)) {
        listaUsuarios.insertarFinal(nombre, apellido, fecha, correo, contrasena);
        cout << "Usuario registrado exitosamente.\n";
    } else {
        cout << "El correo ya está registrado.\n";
    }
}

void menuAdministrador() {
    int opcion;

    do {
        cout << "1. Carga de usuarios\n";
        cout << "2. Carga de relaciones\n";
        cout << "3. Carga de publicaciones\n";
        cout << "4. Gestionar usuarios\n";
        cout << "5. Reportes\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cargarUsuariosDesdeJSON();
            break;
        case 2:
            cargarSolicitudesDesdeJSON();
            break;
        case 3:
            cargarPublicacionesDesdeJSON();
            break;
        case 4:
            cout << "Funcionalidad en desarrollo.\n";
            break;
        case 5:
            cout << "Funcionalidad en desarrollo.\n";
            break;
        case 6:
            cout << "Saliendo del módulo administrador.\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 6);
}

void menuUsuario(const std::string& correoActual) {
    int opcion;

    do {
        cout << "1. Perfil\n";
        cout << "2. Solicitudes\n";
        cout << "3. Publicaciones\n";
        cout << "4. Reportes\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            perfilUsuario();
            break;
        case 2:
            mostrarSolicitudes(correoActual);
            break;
        case 3:
            menuPublicaciones(correoActual);
            break;
        case 4:
            
            break;
        case 5:
            cout << "Saliendo del módulo usuario.\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 5);
}

void cargarUsuariosDesdeJSON() {
    string path;
    cout << "Ingrese el path del archivo JSON: ";
    cin >> path;

    ifstream archivo(path);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << path << endl;
        return;
    }

    json j;
    archivo >> j;

    for (const auto& item : j) {
        string nombre = item["nombres"].get<string>();
        string apellido = item["apellidos"].get<string>();
        string fecha = item["fecha_de_nacimiento"].get<string>();
        string correo = item["correo"].get<string>();
        string contrasena = item["contrasenia"].get<string>();

        if (!listaUsuarios.buscaPorCorreo(correo)) {
            listaUsuarios.insertarFinal(nombre, apellido, fecha, correo, contrasena);

        std::cout << "Nombre: " << nombre << ", Apellido: " << apellido
        << ", Fecha de Nacimiento: " << fecha << ", Correo: " << correo << std::endl;
        } else {
            cout << "Ya existe un usuario con este correo.\n";
        }
    }

    archivo.close();
    cout << "Usuarios cargados exitosamente.\n";
}


void cargarSolicitudesDesdeJSON() {
    string path;
    cout << "Ingrese el path del archivo JSON: ";
    cin >> path;

    ifstream archivo(path);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << path << endl;
        return;
    }

    json j;
    archivo >> j;

    for (const auto& item : j) {
        string emisor = item["emisor"].get<string>();
        string receptor = item["receptor"].get<string>();
        string estado = item["estado"].get<string>();

        // Mostrar la información cargada
        cout << "Emisor: " << emisor 
             << ", Receptor: " << receptor 
             << ", Estado: " << estado 
             << endl;
    }

    archivo.close();
    cout << "Solicitudes cargadas y mostradas exitosamente.\n";
}


void cargarPublicacionesDesdeJSON() {
    std::string path;
    std::cout << "Ingrese el path del archivo JSON de publicaciones: ";
    std::cin >> path;

    std::ifstream archivo(path);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo: " << path << std::endl;
        return;
    }

    json j;
    archivo >> j;

    std::cout << "Publicaciones cargadas desde el archivo JSON:" << std::endl;

    for (const auto& item : j) {
        std::string correo = item["correo"].get<std::string>();
        std::string contenido = item["contenido"].get<std::string>();
        std::string fecha = item["fecha"].get<std::string>();
        std::string hora = item["hora"].get<std::string>();

        // Crear un nuevo NodoPublicacion
        NodoPublicacion nuevaPublicacion(correo, contenido, fecha, hora);

        // Añadir la publicación a la lista
        listaPublicaciones.append(nuevaPublicacion);

        std::cout << "Correo: " << correo << ", Publicación: " << contenido 
                  << ", Fecha: " << fecha << ", Hora: " << hora << std::endl;
    }

    archivo.close();
    std::cout << "Carga de publicaciones completada." << std::endl;
}

void perfilUsuario() {
    // Obtener el correo del usuario actual
    string correoActual;
    cout << "Ingrese su correo para ver su perfil: ";
    cin >> correoActual;

    NodoUsuario* usuario = listaUsuarios.visualizarPrimero();
    while (usuario != nullptr) {
        if (usuario->getCorreo() == correoActual) {
            // Mostrar información del perfil
            cout << "Nombre: " << usuario->getNombre() << endl;
            cout << "Apellido: " << usuario->getApellido() << endl;
            cout << "Fecha de Nacimiento: " << usuario->getFechaNacimiento() << endl;
            cout << "Correo: " << usuario->getCorreo() << endl;
            // Mostrar publicaciones y solicitudes
            
            
            return;
        }
        usuario = usuario->getSiguiente();
    }
    cout << "Usuario no encontrado.\n";
}

void mostrarPublicaciones(const std::string& correo) {
    // Cargar publicaciones desde JSON
    string path;
    cout << "Ingrese el path del archivo JSON de publicaciones: ";
    cin >> path;

    ifstream archivo(path);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << path << endl;
        return;
    }

    json j;
    archivo >> j;
    archivo.close();

    cout << "Publicaciones de " << correo << ":" << endl;
    for (const auto& item : j) {
        string correoPublicacion = item["correo"].get<string>();
        if (correoPublicacion == correo) {
            cout << "Contenido: " << item["contenido"].get<string>() << endl;
            cout << "Fecha: " << item["fecha"].get<string>() << endl;
            cout << "Hora: " << item["hora"].get<string>() << endl;
            cout << "------------------------" << endl;
        }
    }
}

void mostrarSolicitudes(const std::string& correo) {
    // Cargar solicitudes desde JSON
    string path;
    cout << "Ingrese el path del archivo JSON de solicitudes: ";
    cin >> path;

    ifstream archivo(path);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << path << endl;
        return;
    }

    json j;
    archivo >> j;
    archivo.close();

    cout << "Solicitudes para " << correo << ":" << endl;
    for (const auto& item : j) {
        string emisor = item["emisor"].get<string>();
        string receptor = item["receptor"].get<string>();
        string estado = item["estado"].get<string>();

        if (receptor == correo && estado == "ACEPTADA") {
            cout << "Solicitud de amistad de: " << emisor << endl;
        }
        if (emisor == correo && estado == "ACEPTADA") {
            cout << "Solicitud de amistad enviada a: " << receptor << endl;
        }
    }
}


void menuPublicaciones(const std::string& correoActual) {
    int opcion;

    do {
        cout << "1. Ver publicaciones  \n";
        cout << "2. crear publicaciones \n";
        cout << "3. Eliminar Publicacion  \n";
        cout << "4. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

       switch (opcion) {
        case 1: {
            // Mostrar publicaciones
            ListaCircularDobleEnlazada feed;
            NodoPublicacion* temp = listaPublicaciones.getPrimero(); // Obtén el primer nodo

            while (temp != nullptr) {
                feed.push(*temp); // Añadir publicaciones al feed
                temp = temp->getSiguiente();
            }

            feed.print(); // Mostrar feed
            break;
        }
        case 2: {
            // Crear publicación
            std::string correo, contenido, fecha, hora;
            std::cout << "Ingrese el correo del usuario: ";
            std::cin.ignore(); // Limpiar el buffer
            std::getline(std::cin, correo);
            std::cout << "Ingrese el contenido de la publicación: ";
            std::getline(std::cin, contenido);
            std::cout << "Ingrese la fecha (YYYY-MM-DD): ";
            std::getline(std::cin, fecha);
            std::cout << "Ingrese la hora (HH:MM): ";
            std::getline(std::cin, hora);

            NodoPublicacion nuevaPublicacion(correo, contenido, fecha, hora);
            listaPublicaciones.append(nuevaPublicacion);
            std::cout << "Publicación creada exitosamente." << std::endl;
            break;
        }
        case 3: {
            eliminarPublicacion(listaPublicaciones);
            break;
        }
        case 4:
            std::cout << "Saliendo del menú de publicaciones.\n";
            break;
        default:
            std::cout << "Opción inválida.\n";
        }
    } while (opcion != 4);
}

void eliminarPublicacion(ListaDobleEnlazada& listaPublicaciones) {
    // Mostrar publicaciones numeradas
    listaPublicaciones.print();

    // Pedir al usuario el número de la publicación a eliminar
    int num;
    std::cout << "Ingrese el número de la publicación a eliminar: ";
    std::cin >> num;

    // Eliminar la publicación
    listaPublicaciones.remove(num);

    std::cout << "Publicación eliminada. Aquí está la lista actualizada:" << std::endl;
    listaPublicaciones.print();
}
