#include "matriz.h"

// Implementación de la clase NodoMatriz
NodoMatriz::NodoMatriz(int i, int j) {
    this->i = i;
    this->j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;
}

NodoMatriz::NodoMatriz(int i, int j, bool data) {
    this->data = data;
    this->i = i;
    this->j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;
}

bool NodoMatriz::getData() {
    return data;
}

int NodoMatriz::getI() {
    return i;
}

int NodoMatriz::getJ() {
    return j;
}

NodoMatriz* NodoMatriz::getArriba() {
    return arriba;
}

NodoMatriz* NodoMatriz::getAbajo() {
    return abajo;
}

NodoMatriz* NodoMatriz::getIzq() {
    return izq;
}

NodoMatriz* NodoMatriz::getDcha() {
    return dcha;
}

void NodoMatriz::setData(bool data) {
    this->data = data;
}

void NodoMatriz::setI(int i) {
    this->i = i;
}

void NodoMatriz::setJ(int j) {
    this->j = j;
}

void NodoMatriz::setArriba(NodoMatriz *arriba) {
    this->arriba = arriba;
}

void NodoMatriz::setAbajo(NodoMatriz *abajo) {
    this->abajo = abajo;
}

void NodoMatriz::setIzq(NodoMatriz *izq) {
    this->izq = izq;
}

void NodoMatriz::setDcha(NodoMatriz *dcha) {
    this->dcha = dcha;
}

// Implementación de la clase Matriz
Matriz::Matriz() {
    this->raiz = new NodoMatriz(-1, -1);
    this->alto = 0;
    this->ancho = 0;
}

Matriz::~Matriz() {
    NodoMatriz *temp = raiz;
    NodoMatriz *aux;

    while (temp != nullptr) {
        NodoMatriz *tempFila = temp;
        NodoMatriz *auxFila;

        aux = temp->getAbajo();

        while (tempFila != nullptr) {
            auxFila = tempFila->getDcha();
            delete tempFila;
            tempFila = auxFila;
        }

        temp = aux;
    }
}

void Matriz::insert(int i, int j, bool data) {
    NodoMatriz *nuevo = new NodoMatriz(i, j, data);
    NodoMatriz *columna = buscarColumna(i);
    NodoMatriz *fila = buscarFila(j);

    if (i > this->ancho) { this->ancho = i; }
    if (j > this->alto) { this->alto = j; }

    if (!this->existeNodo(nuevo)) {
        if (columna == nullptr) { columna = insertarEncabezadoColumna(i); }
        if (fila == nullptr) { fila = insertarEncabezadoFila(j); }

        insertarEnColumna(nuevo, fila);
        insertarEnFila(nuevo, columna);
    }
}

void Matriz::graph() {
    std::ofstream outfile("matriz.dot");
    NodoMatriz *aux_fila = raiz;
    NodoMatriz *aux_columna;
    std::string dec_nodo;
    std::string conexion;

    outfile << "digraph G {" << std::endl;
    outfile << "    node[shape=\"box\"]" << std::endl;

    while (aux_fila != nullptr) {
        std::string rank = "{rank=same";
        aux_columna = aux_fila;

        while (aux_columna != nullptr) {
            std::string i_coord = std::to_string(aux_columna->getI() + 1);
            std::string j_coord = std::to_string(aux_columna->getJ() + 1);
            std::string nombre = "Nodo" + i_coord + "_" + j_coord;

            if (aux_columna->getI() == -1 && aux_columna->getJ() == -1) {
                dec_nodo = nombre + "[label = \"raiz\", group = \"" + i_coord + "\"]";
            } else if (aux_columna->getI() == -1) {
                dec_nodo = nombre + "[label = \"" + std::to_string(aux_columna->getJ()) + "\"";
                dec_nodo += ", group = \"" + i_coord + "\"]";
            } else if (aux_columna->getJ() == -1) {
                dec_nodo = nombre + "[label = \"" + std::to_string(aux_columna->getI()) + "\"";
                dec_nodo += ", group = \"" + i_coord + "\"]";
            } else {
                dec_nodo = nombre + "[label = \"" + (aux_columna->getData() ? "T" : "F") + "\"";
                dec_nodo += ", group = \"" + i_coord + "\"]";
            }

            outfile << dec_nodo << std::endl;

            if (aux_columna->getDcha() != nullptr) {
                conexion = nombre + "->Nodo" + std::to_string(aux_columna->getDcha()->getI() + 1);
                conexion += "_" + std::to_string(aux_columna->getDcha()->getJ() + 1);

                outfile << conexion << std::endl;
                outfile << conexion << "[dir = back]" << std::endl;
            }

            if (aux_columna->getAbajo() != nullptr) {
                conexion = nombre + "->Nodo" + std::to_string(aux_columna->getAbajo()->getI() + 1);
                conexion += "_" + std::to_string(aux_columna->getAbajo()->getJ() + 1);

                outfile << conexion << std::endl;
                outfile << conexion << "[dir = back]" << std::endl;
            }

            rank += ";" + nombre;
            aux_columna = aux_columna->getDcha();
        }

        rank += "}";
        outfile << rank << std::endl;

        aux_fila = aux_fila->getAbajo();
    }
    outfile << "}" << std::endl;
    outfile.close();
    int returnCode = system("dot -Tpng ./matriz.dot -o ./matriz.png");

    if (returnCode == 0) { std::cout << "Comando ejecutado exitosamente" << std::endl; }
    else { std::cout << "Ejecucion del comando fallida" << returnCode << std::endl; }
}

NodoMatriz* Matriz::insertarEncabezadoFila(int j) {
    NodoMatriz *nuevoEncabezadoFila = new NodoMatriz(-1, j);
    this->insertarEnFila(nuevoEncabezadoFila, this->raiz);
    return nuevoEncabezadoFila;
}

NodoMatriz* Matriz::insertarEncabezadoColumna(int i) {
    NodoMatriz *nuevoEncabezadoColumna = new NodoMatriz(i, -1);
    this->insertarEnColumna(nuevoEncabezadoColumna, this->raiz);
    return nuevoEncabezadoColumna;
}

void Matriz::insertarEnFila(NodoMatriz *nuevo, NodoMatriz *encabezadoColumna) {
    NodoMatriz *temp = encabezadoColumna;

    while (temp->getDcha() != nullptr) {
        if (temp->getDcha()->getJ() > nuevo->getJ()) {
            break;
        }
        temp = temp->getDcha();
    }

    nuevo->setDcha(temp->getDcha());
    if (temp->getDcha() != nullptr) { temp->getDcha()->setIzq(nuevo); }

    temp->setDcha(nuevo);
    nuevo->setIzq(temp);
}

void Matriz::insertarEnColumna(NodoMatriz *nuevo, NodoMatriz *encabezadoFila) {
    NodoMatriz *temp = encabezadoFila;

    while (temp->getAbajo() != nullptr) {
        if (temp->getAbajo()->getI() > nuevo->getI()) {
            break;
        }
        temp = temp->getAbajo();
    }

    nuevo->setAbajo(temp->getAbajo());
    if (temp->getAbajo() != nullptr) { temp->getAbajo()->setArriba(nuevo); }

    temp->setAbajo(nuevo);
    nuevo->setArriba(temp);
}

bool Matriz::existeNodo(NodoMatriz *nuevo) {
    NodoMatriz *columna = buscarColumna(nuevo->getI());
    NodoMatriz *temp = columna;

    if (temp != nullptr) {
        while (temp != nullptr) {
            if (temp->getJ() == nuevo->getJ()) {
                return true;
            }
            temp = temp->getDcha();
        }
    }
    return false;
}

NodoMatriz* Matriz::buscarColumna(int i) {
    NodoMatriz *temp = this->raiz;

    while (temp != nullptr) {
        if (temp->getI() == i) {
            return temp;
        }
        temp = temp->getAbajo();
    }

    return nullptr;
}

NodoMatriz* Matriz::buscarFila(int j) {
    NodoMatriz *temp = this->raiz;

    while (temp != nullptr) {
        if (temp->getJ() == j) {
            return temp;
        }
        temp = temp->getDcha();
    }

    return nullptr;
}

NodoMatriz* Matriz::obtenerNodo(int i, int j) {
    NodoMatriz *columna = buscarColumna(i);
    NodoMatriz *temp = columna;

    while (temp != nullptr) {
        if (temp->getJ() == j) {
            return temp;
        }
        temp = temp->getDcha();
    }

    return nullptr;
}

void Matriz::print() {
    NodoMatriz *temp_fila = this->raiz->getAbajo();
    NodoMatriz *temp_columna;

    while (temp_fila != nullptr) {
        temp_columna = temp_fila->getDcha();
        while (temp_columna != nullptr) {
            std::cout << "i: " << temp_columna->getI() << " j: " << temp_columna->getJ() << " data: " << temp_columna->getData() << std::endl;
            temp_columna = temp_columna->getDcha();
        }
        temp_fila = temp_fila->getAbajo();
    }
}
