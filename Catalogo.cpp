#include "Catalogo.h"

Catalogo::Catalogo()
{
    // Nothing
}

Catalogo::Catalogo(std::vector<Video*> videos)
{
    setVideos(videos);
}

Catalogo::~Catalogo()
{
    // Nothing
}

std::vector<Video*> Catalogo::getVideos()
{
    return videos;
}

void Catalogo::setVideos(std::vector<Video*> videos)
{
    this->videos = videos;
}

void Catalogo::cargarArchivo()
{
    char tipoVideo;

    std::string ID;
    std::string nombre;
    int duracion;
    std::string genero;
    unsigned int calificacion;

    std::string nombreSerie;
    unsigned int temporada;

    std::ifstream archivo;

    archivo.open("Videos.txt");

    if (archivo.is_open()) {
        while (archivo >> tipoVideo) {
            if (tipoVideo == 'P') {
                archivo
                >> ID
                >> nombre
                >> duracion
                >> genero
                >> calificacion;

                std::chrono::minutes duracionChrono1(duracion);

                videos.push_back(new Pelicula(
                    ID,
                    nombre,
                    duracionChrono1,
                    genero,
                    calificacion));
            }
            else {
                archivo
                >> ID
                >> nombre
                >> duracion
                >> genero
                >> calificacion
                >> nombreSerie
                >> temporada;

                std::chrono::minutes duracionChrono2(duracion);

                videos.push_back(new Episodio(
                    ID,
                    nombre,
                    duracionChrono2,
                    genero,
                    calificacion,
                    nombreSerie,
                    temporada));
            }
        }

        archivo.close();

    }
}

void Catalogo::desplegarVideo(unsigned int calificacion)
{
    for (const auto& video : videos) {
        if (video->getCalificacion() == calificacion) {
            video->imprimir();
            std::cout << std::endl;
        }
    }
}

void Catalogo::desplegarVideo(std::string genero)
{
    for (const auto& video : videos)
        if (video->getGenero() == genero) {
            video->imprimir();
            std::cout << std::endl;
        }
}

void Catalogo::desplegarEpisodio(
    std::string nombreSerie,
    unsigned int calificacion)
{
    for (auto& video : videos) {
        Episodio* episodioPtr = dynamic_cast<Episodio*>(video);
        if (episodioPtr)
            if (episodioPtr->getNombreSerie() == nombreSerie && episodioPtr->getCalificacion() == calificacion) {
                episodioPtr->imprimir();
                std::cout << std::endl;
            }
    }
}

void Catalogo::desplegarPelicula(unsigned int calificacion)
{
    for (auto& video : videos) {
        Pelicula* peliculaPtr = dynamic_cast<Pelicula*>(video);
        if (peliculaPtr)
            if (peliculaPtr->getCalificacion() == calificacion) {
                std::cout << *peliculaPtr << std::endl;
            }
    }
}

void Catalogo::calificarVideo(
    std::string nombre,
    unsigned int calificacion)
{
    for (auto& video : videos)
        if (video->getNombre() == nombre)
            video->setCalificacion(calificacion);
}
