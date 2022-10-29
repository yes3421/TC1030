#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <stdexcept>

class Video {
public:
    Video();
    Video(
        std::string ID,
        std::string nombre,
        std::chrono::minutes duracion,
        std::string genero,
        unsigned int calificacion);
    ~Video();

    std::string getID();
    std::string getNombre();
    std::chrono::minutes getDuracion();
    std::string getGenero();
    unsigned int getCalificacion();

    void setID(std::string ID);
    void setNombre(std::string nombre);
    void setDuracion(std::chrono::minutes duracion);
    void setGenero(std::string genero);
    void setCalificacion(unsigned int calificacion);

    virtual void imprimir() = 0;
private:
    std::string ID;
    std::string nombre;
    std::chrono::minutes duracion;
    std::string genero;
    unsigned int calificacion;
};

#endif
