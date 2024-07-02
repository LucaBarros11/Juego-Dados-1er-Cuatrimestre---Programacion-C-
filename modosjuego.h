#ifndef MODOSJUEGO_H_INCLUDED
#define MODOSJUEGO_H_INCLUDED


//FUNCION PARTIDA UN JUGADOR ALEATORIA
void crearPartidaUnJugador(int NumeroPartidas, int& PuntuacionMaxima, string& NombrePuntuacionMaxima)
{
   const int tam=6;
    const int tamtirada=3;
    int NumeroRonda=1;
    int PuntajeTotal=0;
    int dados[tam]= {};
    int SumadeVector=0;
    int tiradas[3]= {};
    int numeroRepetido;
    bool PodesContinuar=true; //Lo vamos a usar para poder salis del while / juego cuando pasen determinadas cosas
    string nombreJugador;
    system("cls");
    cout << "Creando partida para un jugador..." << endl;
    system("pause");
    system("cls");

    //PEDIMOS EL NOMBRE DEL JUGADOR
    nombreJugador=PedirNombreJugador(1);

    //WHILE TOTAL DE PARTIDA QUE CONTROLA CUANDO SE ALCANZAN LOS 100 PUNTOS
    while (PuntajeTotal<100 && PodesContinuar==true)
    {
        //FOR PARA LAS 3 TIRADAS POR RONDA
        for (int i=0; i<tamtirada && PodesContinuar==true;i++)
        {
            mostrarInfoRonda(nombreJugador, NumeroRonda, PuntajeTotal, i);//MUESTRA INFO DE RONDA, N° DE TIRADA, NOMBRE, PUNTAJE TOTAL EN CADA TIRADA
            cargarVectorAleatorio(dados,tam);//CARGA EL VECTOR ALEATORIAMENTE
            mostrarVector(dados,tam);//MUESTRA EL VECTOR (LOS DADOS)

            if (CompruebaSexteto(dados, tam, numeroRepetido)==true)//IF QUE COMPRUEBA SI EN LA TIRADA HUBO SEXTETO
            {
                cout<<endl;
                //SI EL SEXTETO ES DE 6 (GUARDA 0 EN LA TIRADA, RESETEA A 0 PUNTAJE TOTAL, PONE EL VECTOR DE TIRADAS EN 0
                if (numeroRepetido==6){
                PuntajeTotal = 0;
                ponerVectorEn0(tiradas,tamtirada);
                cout << "MALA SUERTE, SEXTETO DE 6, PUNTAJE RESETEADO A 0!" << endl;
                } else {
                //SI EL SEXTETO FUE DE OTRO NUMERO DISTINTO DE 6 LO MULTIPLICA POR 10 Y LO GUARDA EN LA TIRADA
                cout << "BUENA SUERTE! OBTUVISTE UN SEXTETO DE: ["<<numeroRepetido<<"]"<< endl;
                tiradas[i]=numeroRepetido*10;
                }

            }
         // SI NO HUBO SEXTETO COMPRUEBA SI HAY ESCALERA
            else if (ComprobarEscalera(dados,tam) == true){
                cout<<endl;
                cout<<"HAY ESCALERA, GANASTE LA PARTIDA!"<<endl;
                PuntajeTotal+=100;
                tiradas[i]=0;
                PodesContinuar=false;
            } else {
                    //si no hubo sexteto ni escalera esto guarda en cada tirada la suma de los dados, para despues de la tercera analizar cual es la mas grande.
                    tiradas[i] = SumarElementosVector(dados, tam);
              }

                system("pause");
                system("cls");
        }

        //ACA TERMINAN LAS 3 TIRADAS Y SE LIMPIA PANTALLA PARA COMENZAR LA SIGUIENTE RONDA

        if (PuntajeTotal<100)
        {
           //MOSTRAMOS EL RESULTADO DE LAS 3 TIRADAS
            cout<<"--------------------------------------------"<<endl;
            cout<<" Tiradas: "; mostrarVector(tiradas,tamtirada);
            cout<<"--------------------------------------------"<<endl;

            //CALCULARMAXIMAPUNTUACION RECIBE EL VECTOR Y SE QUEDA CON LA TIRADA MAS ALTA PARA GUARDARLA EN MAXPUNTUACION
            int maxPuntuacion=CalcularMaximaPuntuacion(tiradas[0],tiradas[1],tiradas[2]);

            //SUMAMOS LA MAXPUNTUACION AL PUNTAJE TOTAL DE LA PARTIDA
            PuntajeTotal+=maxPuntuacion;
            cout<<" Mayor puntuacion: ["<<maxPuntuacion<<"]"<<endl;
            cout<<"--------------------------------------------"<<endl;
            system("pause");
            system("cls");

            //MOSTRAMOS INFO POST RONDA, NOMBRE DE JUGADOR Y COMO ES SU PUNTAJE HASTA EL MOMENTO ANTES DE COMENZAR LA SIGUIENTE
            if (PuntajeTotal<100){
            MostrarInfoPostRonda(NumeroRonda,nombreJugador,PuntajeTotal);
            NumeroRonda++;
            }
        }
    }

    //ACA TERMINA LA PARTIDA Y MUESTRA EL CARTEL QUE DICE EL GANADOR, SU PUNTAJE FINAL Y EN CUANTAS RONDAS LO OBTUVO
    MostrarCartelVictoria (nombreJugador, PuntajeTotal, NumeroRonda);
    system("pause");

    //EVALUAMOS PUNTAJE MAXIMO PARA COMPARARLOS CON LAS DEMAS PARTIDAS
        if (NumeroPartidas==1){
        PuntuacionMaxima=PuntajeTotal;
        NombrePuntuacionMaxima=nombreJugador;
        } else if (PuntajeTotal>PuntuacionMaxima){
        PuntuacionMaxima=PuntajeTotal;
        NombrePuntuacionMaxima=nombreJugador;
        }

}

//FUNCION PARTIDA UN JUGADOR MANUAL (SIMULADOR CORRECCION)
void crearPartidaUnJugadorSIMULADOR(int NumeroPartidas, int& PuntuacionMaxima, string& NombrePuntuacionMaxima)
{
    const int tam=6;
    const int tamtirada=3;
    int NumeroRonda=1;
    int PuntajeTotal=0;
    int dados[tam]= {};
    int SumadeVector=0;
    int tiradas[3]= {};
    int numeroRepetido;
    bool PodesContinuar=true; //Lo vamos a usar para poder salis del while / juego cuando pasen determinadas cosas
    string nombreJugador;

    system("cls");
    cout << "Creando partida para un jugador(SIMULADOR)..." << endl;
    system("pause");
    system("cls");

    //PEDIMOS EL NOMBRE DEL JUGADOR
    nombreJugador=PedirNombreJugador(1);

    //WHILE TOTAL DE PARTIDA QUE CONTROLA CUANDO SE ALCANZAN LOS 100 PUNTOS
    while (PuntajeTotal<100 && PodesContinuar==true)
    {
        //FOR PARA LAS 3 TIRADAS POR RONDA
        for (int i=0; i<tamtirada && PodesContinuar==true;i++)
        {
            mostrarInfoRonda(nombreJugador, NumeroRonda, PuntajeTotal, i);//MUESTRA INFO DE RONDA, N° DE TIRADA, NOMBRE, PUNTAJE TOTAL EN CADA TIRADA
            cargarVectorManual(dados,tam);//CARGA EL VECTOR MANUALMENTE (PIDE QUE INGRESES LOS DADOS)
            mostrarVector(dados,tam);//MUESTRA EL VECTOR (LOS DADOS)

            if (CompruebaSexteto(dados, tam, numeroRepetido)==true)//IF QUE COMPRUEBA SI EN LA TIRADA HUBO SEXTETO
            {
                cout<<endl;
                //SI EL SEXTETO ES DE 6 (GUARDA 0 EN LA TIRADA, RESETEA A 0 PUNTAJE TOTAL, PONE EL VECTOR DE TIRADAS EN 0
                if (numeroRepetido==6){
                PuntajeTotal = 0;
                ponerVectorEn0(tiradas,tamtirada);
                cout << "MALA SUERTE, SEXTETO DE 6, PUNTAJE RESETEADO A 0!" << endl;
                } else {
                //SI EL SEXTETO FUE DE OTRO NUMERO DISTINTO DE 6 LO MULTIPLICA POR 10 Y LO GUARDA EN LA TIRADA
                cout << "BUENA SUERTE! OBTUVISTE UN SEXTETO DE ["<<numeroRepetido<<"]" << endl;
                tiradas[i]=numeroRepetido*10;
                }
            }

            // SI NO HUBO SEXTETO COMPRUEBA SI HAY ESCALERA
            else if (ComprobarEscalera(dados,tam) == true){
                cout<<endl;
                cout<<"HAY ESCALERA, GANASTE LA PARTIDA!"<<endl;
                PuntajeTotal+=100;
                tiradas[i]=0;
                PodesContinuar=false;
            } else {
                    //si no hubo sexteto ni escalera esto guarda en cada tirada la suma de los dados, para despues de la tercera analizar cual es la mas grande.
                    tiradas[i] = SumarElementosVector(dados, tam);
              }
            system("pause");
            system("cls");
        }

        //ACA TERMINAN LAS 3 TIRADAS Y SE LIMPIA PANTALLA PARA COMENZAR LA SIGUIENTE RONDA

        if (PuntajeTotal<100)
        {
            //MOSTRAMOS EL RESULTADO DE LAS 3 TIRADAS
            cout<<"--------------------------------------------"<<endl;
            cout<<" Tiradas: "; mostrarVector(tiradas,tamtirada);
            cout<<"--------------------------------------------"<<endl;

            //CALCULARMAXIMAPUNTUACION RECIBE EL VECTOR Y SE QUEDA CON LA TIRADA MAS ALTA PARA GUARDARLA EN MAXPUNTUACION
            int maxPuntuacion=CalcularMaximaPuntuacion(tiradas[0],tiradas[1],tiradas[2]);

            //SUMAMOS LA MAXPUNTUACION AL PUNTAJE TOTAL DE LA PARTIDA
            PuntajeTotal+=maxPuntuacion;
            cout<<" Mayor puntuacion: ["<<maxPuntuacion<<"]"<<endl;
            cout<<"--------------------------------------------"<<endl;
            system("pause");
            system("cls");

            //MOSTRAMOS INFO POST RONDA, NOMBRE DE JUGADOR Y COMO ES SU PUNTAJE HASTA EL MOMENTO ANTES DE COMENZAR LA SIGUIENTE
            if (PuntajeTotal<100){
            MostrarInfoPostRonda(NumeroRonda,nombreJugador,PuntajeTotal);
            NumeroRonda++;
            }
        }
    }

    //ACA TERMINA LA PARTIDA Y MUESTRA EL CARTEL QUE DICE EL GANADOR, SU PUNTAJE FINAL Y EN CUANTAS RONDAS LO OBTUVO
    MostrarCartelVictoria (nombreJugador, PuntajeTotal, NumeroRonda);
    system("pause");

    //EVALUAMOS PUNTAJE MAXIMO PARA COMPARARLOS CON LAS DEMAS PARTIDAS
        if (NumeroPartidas==1){
        PuntuacionMaxima=PuntajeTotal;
        NombrePuntuacionMaxima=nombreJugador;
        } else if (PuntajeTotal>PuntuacionMaxima){
        PuntuacionMaxima=PuntajeTotal;
        NombrePuntuacionMaxima=nombreJugador;
        }
}

//JUEGO PARA DOS JUGADORES ALEATORIA
void NuevoJuegoParaDosJugadores(int NumeroPartidas, int &PuntuacionMaxima, string &NombrePuntuacionMaxima) {

    const int tam = 6;
    const int tamtirada = 3;
    int dados[tam];
    int tiradas[tamtirada];
    int PuntajeTotal_1 = 0;
    int PuntajeTotal_2 = 0;
    int NumeroRonda = 1;
    int numeroRepetido;
    bool PodesContinuar = true;
    string nombreJugador1, nombreJugador2;

    system("cls");
    cout << "Creando partida para dos jugadores..." << endl;
    system("pause");
    system("cls");

    nombreJugador1 = PedirNombreJugador(1);
    nombreJugador2 = PedirNombreJugador(2);

    while ((PuntajeTotal_1 < 100 && PuntajeTotal_2 < 100) && PodesContinuar) {

        // TURNO JUGADOR 1 - FOR CON LAS 3 TIRADAS
        for (int i = 0; i < tamtirada && PodesContinuar; i++) {
            mostrarInfoRonda(nombreJugador1, NumeroRonda, PuntajeTotal_1, i); // Muestra info de ronda
            cargarVectorAleatorio(dados, tam); // Carga el vector aleatoriamente
            mostrarVector(dados, tam); // Muestra el vector (los dados)

            if (CompruebaSexteto(dados, tam, numeroRepetido)) { // If que comprueba si en la tirada hubo sexteto
                cout << endl;
                if (numeroRepetido == 6) {
                    PuntajeTotal_1 = 0;
                    ponerVectorEn0(tiradas, tamtirada);
                    cout << "MALA SUERTE, SEXTETO DE 6, PUNTAJE RESETEADO A 0!" << endl;
                } else {
                    cout << "BUENA SUERTE! OBTUVISTE UN SEXTETO DE: [" << numeroRepetido << "]" << endl;
                    tiradas[i] = numeroRepetido * 10;
                }
            } else if (ComprobarEscalera(dados, tam)) {
                cout << endl;
                cout << "HAY ESCALERA, GANASTE LA PARTIDA!" << endl;
                PuntajeTotal_1 += 100;
                tiradas[i] = 0;
                PodesContinuar = false;
            } else {
                tiradas[i] = SumarElementosVector(dados, tam);
            }

            system("pause");
            system("cls");
        }

        if (PuntajeTotal_1 < 100 && PodesContinuar) {
            cout << "--------------------------------------------" << endl;
            cout << " Tiradas: ";
            mostrarVector(tiradas, tamtirada);
            cout << "--------------------------------------------" << endl;

            int maxPuntuacion = CalcularMaximaPuntuacion(tiradas[0], tiradas[1], tiradas[2]);
            PuntajeTotal_1 += maxPuntuacion;
            cout << " Mayor puntuacion: [" << maxPuntuacion << "]" << endl;
            cout << "--------------------------------------------" << endl;
            system("pause");
            system("cls");

        }

        // TURNO DEL JUGADOR 2
        for (int i = 0; i < tamtirada && PodesContinuar; i++) {
            mostrarInfoRonda(nombreJugador2, NumeroRonda, PuntajeTotal_2, i); // Muestra info de ronda
            cargarVectorAleatorio(dados, tam); // Carga el vector aleatoriamente
            mostrarVector(dados, tam); // Muestra el vector (los dados)

            if (CompruebaSexteto(dados, tam, numeroRepetido)) { // If que comprueba si en la tirada hubo sexteto
                cout << endl;
                if (numeroRepetido == 6) {
                    PuntajeTotal_2 = 0;
                    ponerVectorEn0(tiradas, tamtirada);
                    cout << "MALA SUERTE, SEXTETO DE 6, PUNTAJE RESETEADO A 0!" << endl;
                } else {
                    cout << "BUENA SUERTE! OBTUVISTE UN SEXTETO DE: [" << numeroRepetido << "]" << endl;
                    tiradas[i] = numeroRepetido * 10;
                }
            } else if (ComprobarEscalera(dados, tam)) {
                cout << endl;
                cout << "HAY ESCALERA, GANASTE LA PARTIDA!" << endl;
                PuntajeTotal_2 += 100;
                tiradas[i] = 0;
                PodesContinuar = false;
            } else {
                tiradas[i] = SumarElementosVector(dados, tam);
            }

            system("pause");
            system("cls");
        }

        if (PuntajeTotal_2 < 100 && PodesContinuar) {
            cout << "--------------------------------------------" << endl;
            cout << " Tiradas: ";
            mostrarVector(tiradas, tamtirada);
            cout << "--------------------------------------------" << endl;

            int maxPuntuacion = CalcularMaximaPuntuacion(tiradas[0], tiradas[1], tiradas[2]);
            PuntajeTotal_2 += maxPuntuacion;
            cout << " Mayor puntuacion: [" << maxPuntuacion << "]" << endl;
            cout << "--------------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        if (PuntajeTotal_1<100&&PuntajeTotal_2<100 & PodesContinuar==true){
        MostrarInfoPostRonda2jugadores (NumeroRonda, nombreJugador1, PuntajeTotal_1, nombreJugador2, PuntajeTotal_2);
        NumeroRonda++;}

    }

    //DETERMINAMOS EL GANADOR

    string nombreGanador;
    int puntajeGanador;
    if (PuntajeTotal_1 > PuntajeTotal_2) {
        nombreGanador = nombreJugador1;
        puntajeGanador = PuntajeTotal_1;
    } else {
        nombreGanador = nombreJugador2;
        puntajeGanador = PuntajeTotal_2;
    }

    MostrarCartelVictoria(nombreGanador, puntajeGanador, NumeroRonda);

    cout<<"---------------------------------------------------"<<endl;
    cout<<"PUNTAJE FINAL DE: |"<<nombreJugador1<<"| : "<<PuntajeTotal_1<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"PUNTAJE FINAL DE: |"<<nombreJugador2<<"| : "<<PuntajeTotal_2<<endl;
    cout<<"---------------------------------------------------"<<endl;
    system("pause");

    // EVALUAMOS EL PUNTAJE PARA VER SI ES MAS GRANDE QUE EL MAXIMO GENERAL Y PISARLO

    if (NumeroPartidas == 1) {
        PuntuacionMaxima = puntajeGanador;
        NombrePuntuacionMaxima = nombreGanador;
    } else if (puntajeGanador > PuntuacionMaxima) {
        PuntuacionMaxima = puntajeGanador;
        NombrePuntuacionMaxima = nombreGanador;
    }
}

//JUEGO PARA DOS JUGADORES SIMULADORES MANUAL (SIMULADOR CORRECCION)
void NuevoJuegoParaDosJugadoresSIMULADOR(int NumeroPartidas, int &PuntuacionMaxima, string &NombrePuntuacionMaxima) {

    const int tam = 6;
    const int tamtirada = 3;
    int dados[tam];
    int tiradas[tamtirada];
    int PuntajeTotal_1 = 0;
    int PuntajeTotal_2 = 0;
    int NumeroRonda = 1;
    int numeroRepetido;
    bool PodesContinuar = true;
    string nombreJugador1, nombreJugador2;

    system("cls");
    cout << "Creando partida para dos jugadores (SIMULADOR)..." << endl;
    system("pause");
    system("cls");

    nombreJugador1 = PedirNombreJugador(1);
    nombreJugador2 = PedirNombreJugador(2);

    while ((PuntajeTotal_1 < 100 && PuntajeTotal_2 < 100) && PodesContinuar) {

        // TURNO JUGADOR 1 - FOR CON SUS 3 TIRADAS
        for (int i = 0; i < tamtirada && PodesContinuar; i++) {
            mostrarInfoRonda(nombreJugador1, NumeroRonda, PuntajeTotal_1, i); // Muestra info de ronda
            cargarVectorManual(dados, tam); // Carga el vector Manual
            mostrarVector(dados, tam); // Muestra el vector (los dados)

            if (CompruebaSexteto(dados, tam, numeroRepetido)) { // If que comprueba si en la tirada hubo sexteto
                cout << endl;
                if (numeroRepetido == 6) {
                    PuntajeTotal_1 = 0;
                    ponerVectorEn0(tiradas, tamtirada);
                    cout << "MALA SUERTE, SEXTETO DE 6, PUNTAJE RESETEADO A 0!" << endl;
                } else {
                    cout << "BUENA SUERTE! OBTUVISTE UN SEXTETO DE: [" << numeroRepetido << "]" << endl;
                    tiradas[i] = numeroRepetido * 10;
                }
            } else if (ComprobarEscalera(dados, tam)) {
                cout << endl;
                cout << "HAY ESCALERA, GANASTE LA PARTIDA!" << endl;
                PuntajeTotal_1 += 100;
                tiradas[i] = 0;
                PodesContinuar = false;
            } else {
                tiradas[i] = SumarElementosVector(dados, tam);
            }

            system("pause");
            system("cls");
        }

        if (PuntajeTotal_1 < 100 && PodesContinuar) {
            cout << "--------------------------------------------" << endl;
            cout << " Tiradas: ";
            mostrarVector(tiradas, tamtirada);
            cout << "--------------------------------------------" << endl;

            int maxPuntuacion = CalcularMaximaPuntuacion(tiradas[0], tiradas[1], tiradas[2]);
            PuntajeTotal_1 += maxPuntuacion;
            cout << " Mayor puntuacion: [" << maxPuntuacion << "]" << endl;
            cout << "--------------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        // TURNO DEL JUGADOR 2 - FOR CON SUS 3 TIRADAS

        for (int i = 0; i < tamtirada && PodesContinuar; i++) {
            mostrarInfoRonda(nombreJugador2, NumeroRonda, PuntajeTotal_2, i); // Muestra info de ronda
            cargarVectorManual(dados, tam); // Carga el vector aleatoriamente
            mostrarVector(dados, tam); // Muestra el vector (los dados)

            if (CompruebaSexteto(dados, tam, numeroRepetido)) { // If que comprueba si en la tirada hubo sexteto
                cout << endl;
                if (numeroRepetido == 6) {
                    PuntajeTotal_2 = 0;
                    ponerVectorEn0(tiradas, tamtirada);
                    cout << "MALA SUERTE, SEXTETO DE 6, PUNTAJE RESETEADO A 0!" << endl;
                } else {
                    cout << "BUENA SUERTE! OBTUVISTE UN SEXTETO DE: [" << numeroRepetido << "]" << endl;
                    tiradas[i] = numeroRepetido * 10;
                }
            } else if (ComprobarEscalera(dados, tam)) {
                cout << endl;
                cout << "HAY ESCALERA, GANASTE LA PARTIDA!" << endl;
                PuntajeTotal_2 += 100;
                tiradas[i] = 0;
                PodesContinuar = false;
            } else {
                tiradas[i] = SumarElementosVector(dados, tam);
            }

            system("pause");
            system("cls");
        }

        if (PuntajeTotal_2 < 100 && PodesContinuar) {
            cout << "--------------------------------------------" << endl;
            cout << " Tiradas: ";
            mostrarVector(tiradas, tamtirada);
            cout << "--------------------------------------------" << endl;

            int maxPuntuacion = CalcularMaximaPuntuacion(tiradas[0], tiradas[1], tiradas[2]);
            PuntajeTotal_2 += maxPuntuacion;
            cout << " Mayor puntuacion: [" << maxPuntuacion << "]" << endl;
            cout << "--------------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        if (PuntajeTotal_1<100&&PuntajeTotal_2<100 & PodesContinuar==true){
        MostrarInfoPostRonda2jugadores (NumeroRonda, nombreJugador1, PuntajeTotal_1, nombreJugador2, PuntajeTotal_2);
        NumeroRonda++;}

    }

    //DETERMINAMOS EL GANADOR DE LA PARTIDA

    string nombreGanador;
    int puntajeGanador;
    if (PuntajeTotal_1 > PuntajeTotal_2) {
        nombreGanador = nombreJugador1;
        puntajeGanador = PuntajeTotal_1;
    } else {
        nombreGanador = nombreJugador2;
        puntajeGanador = PuntajeTotal_2;
    }

    MostrarCartelVictoria(nombreGanador, puntajeGanador, NumeroRonda);
    cout<<"---------------------------------------------------"<<endl;
    cout<<"PUNTAJE FINAL DE | "<<nombreJugador1<<" | : "<<PuntajeTotal_1<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"PUNTAJE FINAL DE | "<<nombreJugador2<<" | : "<<PuntajeTotal_2<<endl;
    cout<<"---------------------------------------------------"<<endl;

    system("pause");


    // Evaluamos puntaje máximo para compararlos con las demás partidas
    if (NumeroPartidas == 1) {
        PuntuacionMaxima = puntajeGanador;
        NombrePuntuacionMaxima = nombreGanador;
    } else if (puntajeGanador > PuntuacionMaxima) {
        PuntuacionMaxima = puntajeGanador;
        NombrePuntuacionMaxima = nombreGanador;
    }
}



#endif // FUNCIONES_H_INCLUDED
