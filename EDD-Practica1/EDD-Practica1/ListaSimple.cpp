#include "ListaSimple.h"

ListaSimple::ListaSimple() {
    primero = ultimo = nullptr;
}

bool ListaSimple::estaVacia() {
    return (primero == nullptr) && (ultimo == nullptr);
}

bool ListaSimple::buscaPorCorreo(std::string correo) {
    NodoUsuario* actual = primero;
    while (actual != nullptr) {
        if (actual->getCorreo() == correo) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

void ListaSimple::insertarInicio(std::string nombre, std::string apellido, std::string fechaNacimiento, std::string correo, std::string contrasena) {
    NodoUsuario* nuevo = new NodoUsuario(nombre, apellido, fechaNacimiento, correo, contrasena);
    if (estaVacia()) {
        primero = ultimo = nuevo;
    } else {
        nuevo->setSiguiente(primero);
        primero = nuevo;
    }
}

void ListaSimple::insertarFinal(std::string nombre, std::string apellido, std::string fechaNacimiento, std::string correo, std::string contrasena) {
    NodoUsuario* nuevo = new NodoUsuario(nombre, apellido, fechaNacimiento, correo, contrasena);
    if (estaVacia()) {
        primero = ultimo = nuevo;
    } else {
        ultimo->setSiguiente(nuevo);
        ultimo = nuevo;
    }
}

void ListaSimple::eliminarInicio() {
    if (estaVacia()) {
        std::cout << "La lista está vacía" << std::endl;
    } else {
        if (primero == ultimo) {
            delete primero;
            primero = ultimo = nullptr;
        } else {
            NodoUsuario* segundo = primero->getSiguiente();
            delete primero;
            primero = segundo;
        }
    }
}

void ListaSimple::eliminarFinal() {
    if (estaVacia()) {
        std::cout << "La lista está vacía" << std::endl;
    } else {
        NodoUsuario* temporal = primero;
        if (primero == ultimo) {
            delete primero;
            primero = ultimo = nullptr;
        } else {
            while (temporal != nullptr) {
                if (temporal->getSiguiente() == ultimo) {
                    delete ultimo;
                    temporal->setSiguiente(nullptr);
                    ultimo = temporal;
                }
                temporal = temporal->getSiguiente();
            }
        }
    }
}

void ListaSimple::eliminarPorCorreo(std::string correo) {
    if (estaVacia()) {
        std::cout << "La lista está vacía. No se puede eliminar ningún nodo.\n";
        return;
    }

    NodoUsuario* actual = primero;
    NodoUsuario* anterior = nullptr;

    if (actual != nullptr && actual->getCorreo() == correo) {
        primero = actual->getSiguiente();
        delete actual;
        std::cout << "Nodo con correo " << correo << " eliminado.\n";
        return;
    }

    while (actual != nullptr && actual->getCorreo() != correo) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == nullptr) {
        std::cout << "Nodo con correo " << correo << " no encontrado.\n";
        return;
    }

    anterior->setSiguiente(actual->getSiguiente());
    delete actual;
    std::cout << "Nodo con correo " << correo << " eliminado.\n";
}

NodoUsuario* ListaSimple::visualizarPrimero() {
    if (estaVacia()) {
        std::cout << "La lista está vacía" << std::endl;
        return nullptr;
    } else {
        return primero;
    }
}

void ListaSimple::visualizarLista() {
    NodoUsuario* actual = primero;
    while (actual != nullptr) {
        std::cout << actual->getNombre() << " " << actual->getApellido() << " (" << actual->getCorreo() << ")\n";
        actual = actual->getSiguiente();
    }
}

ListaSimple::~ListaSimple() {
    while (!estaVacia()) {
        eliminarInicio();
    }
}
