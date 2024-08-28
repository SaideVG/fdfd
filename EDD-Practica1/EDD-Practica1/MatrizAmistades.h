#ifndef MATRIZAMISTADES_H
#define MATRIZAMISTADES_H

#include <string>
#include <vector>

// Clase que representa una matriz de amistades.
class MatrizAmistades {
public:
    void insertarAmistad(const std::string& amigo1, const std::string& amigo2);
    void print() const;

private:
    std::vector<std::pair<std::string, std::string>> amistades;
};

#endif // MATRIZAMISTADES_H
