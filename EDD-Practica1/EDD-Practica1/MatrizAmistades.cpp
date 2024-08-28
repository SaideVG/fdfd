#include "MatrizAmistades.h"
#include <iostream>

void MatrizAmistades::insertarAmistad(const std::string& amigo1, const std::string& amigo2) {
    amistades.emplace_back(amigo1, amigo2);
}

void MatrizAmistades::print() const {
    for (const auto& amistad : amistades) {
        std::cout << amistad.first << " - " << amistad.second << std::endl;
    }
}
