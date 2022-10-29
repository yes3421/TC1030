#include "Pelicula.h"

Pelicula::Pelicula()
{
    // Nothing
}

Pelicula::Pelicula(
    std::string ID,
    std::string nombre,
    std::chrono::minutes duracion,
    std::string genero,
    unsigned int calificacion) : Video(
        ID,
        nombre,
        duracion,
        genero,
        calificacion)
{
    // Nothing
}

Pelicula::~Pelicula()
{
    // Nothing
}


void Pelicula::imprimir()
{
    constexpr int width = 40;

    std::string ID{"ID: "};
    std::string nombre{"Nombre: "};
    std::string duracion{"Duracion: "};
    std::string genero{"Genero: "};
    std::string calificacion{"Calificacion: "};

    std::cout
    << ID
    << std::setw(width - ID.size())
    << Video::getID()
    << '\n'

    << nombre
    << std::setw(width - nombre.size())
    << Video::getNombre()
    << '\n'

    << duracion
    << std::setw(width - duracion.size())
    << Video::getDuracion().count()
    << '\n'

    << genero
    << std::setw(width - genero.size())
    << Video::getGenero()
    << '\n'

    << calificacion
    << std::setw(width -  calificacion.size())
    << Video::getCalificacion()
    << std::endl;
}

std::ostream& operator<<(std::ostream& output, Pelicula& pelicula)
{
    constexpr int width = 40;

    std::string ID{"ID: "};
    std::string nombre{"Nombre: "};
    std::string duracion{"Duracion: "};
    std::string genero{"Genero: "};
    std::string calificacion{"Calificacion: "};

    output
    << ID
    << std::setw(width - ID.size())
    << pelicula.getID()
    << '\n'

    << nombre
    << std::setw(width - nombre.size())
    << pelicula.getNombre()
    << '\n'

    << duracion
    << std::setw(width - duracion.size())
    << pelicula.getDuracion().count()
    << '\n'

    << genero
    << std::setw(width - genero.size())
    << pelicula.getGenero()
    << '\n'

    << calificacion
    << std::setw(width -  calificacion.size())
    << pelicula.getCalificacion()
    << '\n';
    
    return output;
}
