#ifndef CATALOGO_H
#define CATALOGO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

#include "Pelicula.h"
#include "Episodio.h"

class Catalogo {
public:
    Catalogo();
    Catalogo(std::vector<Video*> videos);
    ~Catalogo();

    std::vector<Video*> getVideos();
    
    void setVideos(std::vector<Video*> videos);

    void cargarArchivo();
    void desplegarVideo(unsigned int calificacion);
    void desplegarVideo(std::string genero);
    void desplegarEpisodio(
        std::string nombreSerie,
        unsigned int calificacion);
    void desplegarPelicula(unsigned int calificacion);
    void calificarVideo(
        std::string nombre,
        unsigned int calificacion);
private:
    std::vector<Video*> videos;
};

#endif
