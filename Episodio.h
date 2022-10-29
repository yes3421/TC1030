#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>

#include "Video.h"

class Episodio : public Video {
friend std::ostream& operator<<(std::ostream& output, Episodio& episodio);
public:
    Episodio();
    Episodio(
        std::string ID,
        std::string nombre,
        std::chrono::minutes duracion,
        std::string genero,
        unsigned int calificacion,
        std::string nombreSerie,
        unsigned int temporada);
    ~Episodio();

    std::string getNombreSerie();
    unsigned int getTemporada();

    void setNombreSerie(std::string nombreSerie);
    void setTemporada(unsigned int temporada);
    
    void imprimir() override;
private:
    std::string nombreSerie;
    unsigned int temporada;
};

#endif
