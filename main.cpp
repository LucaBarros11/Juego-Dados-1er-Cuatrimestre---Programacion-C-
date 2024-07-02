#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "funciones.h"
#include "modosjuego.h"

int main() {
    srand(time(NULL));
    const int TAM = 6;
    int NumeroPartidas = 0;
    int PuntuacionMaxima = 0;
    string NombrePuntuacionMaxima = "Ningun jugador";
    int opcion = 1;
    int dados[TAM] = {1, 2, 3, 4, 5, 6};

    while (opcion != 0) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                NumeroPartidas++;
                crearPartidaUnJugador(NumeroPartidas, PuntuacionMaxima, NombrePuntuacionMaxima);
                system("cls");
                break;
            case 2:
                NumeroPartidas++;
                crearPartidaUnJugadorSIMULADOR(NumeroPartidas, PuntuacionMaxima, NombrePuntuacionMaxima);
                system("cls");
                break;
            case 3:
                NumeroPartidas++;
                NuevoJuegoParaDosJugadores(NumeroPartidas, PuntuacionMaxima, NombrePuntuacionMaxima);
                system("cls");
                break;
            case 4:
                NumeroPartidas++;
                NuevoJuegoParaDosJugadoresSIMULADOR(NumeroPartidas, PuntuacionMaxima, NombrePuntuacionMaxima);
                system("cls");
                break;
            case 5:
                MostrarPuntuacionMaxima(PuntuacionMaxima, NombrePuntuacionMaxima);
                system("cls");
                break;
            case 0:
                system("cls");
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                system("cls");
                cout << "Ingresa una opcion correcta." << endl;
                system("pause");
                break;
        }
    }

    return 0;
}
