#include "Episodio.h"

Episodio::Episodio()
{
    this->temporada = 1;
}

Episodio::Episodio(
    std::string ID,
    std::string nombre,
    std::chrono::minutes duracion,
    std::string genero,
    unsigned int calificacion,
    std::string nombreSerie,
    unsigned int temporada) : Video(
        ID,
        nombre,
        duracion,
        genero,
        calificacion)
{
    setNombreSerie(nombreSerie);
    setTemporada(temporada);
}

Episodio::~Episodio()
{
    // Nothing
}

std::string Episodio::getNombreSerie()
{
    return nombreSerie;
}

unsigned int Episodio::getTemporada()
{
    return temporada;
}

void Episodio::setNombreSerie(std::string nombreSerie)
{
    this->nombreSerie = nombreSerie;
}

void Episodio::setTemporada(unsigned int temporada)
{
    this->temporada = temporada;
}

void Episodio::imprimir()
{
    constexpr int width = 40;

    std::string ID{"ID: "};
    std::string nombre{"Nombre: "};
    std::string duracion{"Duracion: "};
    std::string genero{"Genero: "};
    std::string calificacion{"Calificacion: "};
    std::string nombreSerie{"Serie: "};
    std::string temporada{"Temporada: "};

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
    << '\n'

    << nombreSerie
    << std::setw(width - nombreSerie.size())
    << this->nombreSerie
    << '\n'

    << temporada
    << std::setw(width - temporada.size())
    << this->temporada
    << std::endl;
}

std::ostream& operator<<(std::ostream& output, Episodio& episodio)
{
    constexpr int width = 40;

    std::string ID{"ID: "};
    std::string nombre{"Nombre: "};
    std::string duracion{"Duracion: "};
    std::string genero{"Genero: "};
    std::string calificacion{"Calificacion: "};
    std::string nombreSerie{"Serie: "};
    std::string temporada{"Temporada: "};

    output
    << ID
    << std::setw(width - ID.size())
    << episodio.getID()
    << '\n'

    << nombre
    << std::setw(width - nombre.size())
    << episodio.getNombre()
    << '\n'

    << duracion
    << std::setw(width - duracion.size())
    << episodio.getDuracion().count()
    << '\n'

    << genero
    << std::setw(width - genero.size())
    << episodio.getGenero()
    << '\n'

    << calificacion
    << std::setw(width -  calificacion.size())
    << episodio.getCalificacion()
    << '\n'

    << nombreSerie
    << std::setw(width - nombreSerie.size())
    << episodio.nombreSerie
    << '\n'

    << temporada
    << std::setw(width - temporada.size())
    << episodio.temporada
    << '\n';

    return output;
}
