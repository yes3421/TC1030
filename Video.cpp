#include "Video.h"

Video::Video()
{
    std::chrono::minutes defaultDuracion{0};

    this->ID;
    this->nombre;
    this->duracion = defaultDuracion;
    this->genero;
    this->calificacion = 0;
}

Video::Video(
    std::string ID,
    std::string nombre,
    std::chrono::minutes duracion,
    std::string genero,
    unsigned int calificacion)
{
    setID(ID);
    setNombre(nombre);
    setDuracion(duracion);
    setGenero(genero);
    setCalificacion(calificacion);
}

Video::~Video()
{
    // Nothing
}

std::string Video::getID()
{
    return ID;
}

std::string Video::getNombre()
{
    return nombre;
}

std::chrono::minutes Video::getDuracion()
{
    return duracion;
}

std::string Video::getGenero()
{
    return genero;
}

unsigned int Video::getCalificacion()
{
    return calificacion;
}

void Video::setID(std::string ID)
{
    this->ID = ID;
}

void Video::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

void Video::setDuracion(std::chrono::minutes duracion)
{
    this->duracion = duracion;
}

void Video::setGenero(std::string genero)
{
    this->genero = genero;
}

void Video::setCalificacion(unsigned int calificacion)
{
    if (calificacion < 0 || calificacion > 5)
        throw std::invalid_argument("Calificacion no valida.");
    this->calificacion = calificacion;
}

/* void Video::imprimir()
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
    << this->ID
    << '\n'

    << nombre
    << std::setw(width - nombre.size())
    << this->nombre
    << '\n'

    << duracion
    << std::setw(width - duracion.size())
    << this->duracion.count()
    << '\n'

    << genero
    << std::setw(width - genero.size())
    << this->genero
    << '\n'

    << calificacion
    << std::setw(width -  calificacion.size())
    << this->calificacion
    << std::endl;
} */
