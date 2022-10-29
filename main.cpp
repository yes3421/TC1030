#include "Catalogo.h"

int main()
{
    Catalogo catalogo;

    catalogo.cargarArchivo();

    int opcion;
    int calificacion;
    std::string genero;
    std::string nombreSerie;
    std::string nombre;

    do {
        std::cout
        << "[1] Mostrar videos por calificacion" << '\n'
        << "[2] Mostrar videos por genero" << '\n'
        << "[3] Mostrar episodios por serie y calificacion" << '\n'
        << "[4] Mostrar peliculas por calificacion" << '\n'
        << "[5] Calificar un video" << '\n'
        << "[0] Salir" << '\n'
        << ">>> ";

        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Ingrese la calificacion: ";
            std::cin >> calificacion;
            catalogo.desplegarVideo(calificacion);
            break;
        case 2:
            std::cout << "Ingrese el genero: ";
            std::cin >> genero;
            catalogo.desplegarVideo(genero);
            break;
        case 3:
            std::cout << "Ingrese el nombre de la serie: ";
            std::cin >> nombreSerie;
            std::cout << "Ingrese la calificacion: ";
            std::cin >> calificacion;
            catalogo.desplegarEpisodio(nombreSerie, calificacion);
            break;
        case 4:
            std::cout << "Ingrese la calificacion: ";
            std::cin >> calificacion;
            catalogo.desplegarPelicula(calificacion);
            break;
        case 5:
            std::cout << "Ingrese el nombre del video: ";
            std::cin >> nombre;
            while (true) {
                std::cout << "Ingrese la calificacion: ";
                std::cin >> calificacion;
                try {
                    catalogo.calificarVideo(nombre, calificacion);
                    std::cout << std::endl;
                    break;
                }
                catch (std::invalid_argument& excep) {
                    std::cout << "Ocurrio una excepcion: " << excep.what() << std::endl;
                }
            }
            break;
        default:
            break;
        }
    
    } while (opcion != 0);

    return 0;

}
