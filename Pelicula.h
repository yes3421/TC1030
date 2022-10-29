#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <string>
#include <chrono>

#include "Video.h"

class Pelicula : public Video {
friend std::ostream& operator<<(std::ostream& output, Pelicula& pelicula);
public:
    Pelicula();
    Pelicula(
        std::string ID,
        std::string nombre,
        std::chrono::minutes duracion,
        std::string genero,
        unsigned int calificacion);
    ~Pelicula();
    
    void imprimir() override;
private:
};

#endif
