
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream> // Incluir la biblioteca para cout
using namespace std; // Usar el espacio de nombres std

//MENU DEL JUEGO
void mostrarMenu()
{
    system("cls");
    cout<<"  ___________________________________________________________"<<endl;
    cout<<" |                                                           |"<<endl;
    cout<<" |                      Escalera o Cien                      |"<<endl;
    cout<<" |                                                           |"<<endl;
    cout<<" | [1] - Nuevo juego para un jugador                         |"<<endl;
    cout<<" | [2] - Nuevo juego para un jugador (SIMULADOR)             |"<<endl;
    cout<<" | [3] - Nuevo juego para dos jugadores                      |"<<endl;
    cout<<" | [4] - Nuevo juego para dos jugadores (SIMULADOR           |"<<endl;
    cout<<" | [5] - Mostrar Puntuacion Maxima                           |"<<endl;
    cout<<" | [0] - Salir                                               |"<<endl;
    cout<<" |                                                           |"<<endl;
    cout<<" |  Ingrese la opcion deseada:                               |"<<endl;
    cout<<" |___________________________________________________________|"<<endl;
}

string PedirNombreJugador(int numeroJugador)
{
    string NombreJugador;
    cout<<"Ingrese el nombre del jugador "<<numeroJugador<<" : ";
    cin>>NombreJugador;
    system("cls");
    cout<<" ";
    return NombreJugador;
}

void MostrarPuntuacionMaxima(int PuntuacionMaxima, string NombrePuntuacionMaxima)
{
    system("cls");
    cout<<"---------------------------------------------------------"<<endl;
    cout<<" La puntuacion maxima del juego es: "<<PuntuacionMaxima<<" puntos"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<" El jugador con la puntuacion maxima es: "<<NombrePuntuacionMaxima<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<endl;
    system("pause");
}

//CARGA ALEATORIAMENTE EL VECTOR (LOS 6 DADOS
void cargarVectorAleatorio(int vec[], int tam)
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        vec[i]=rand()%6+1;
    }
    //cout<<"Vector correctamente cargado con numeros aleatorios..."<<endl;
}

//PERMITE CARGAR MANUALMENTE EL VECTOR (LOS 6 DADOS, UNO POR UNO)
void cargarVectorManual(int vec[],int tam )
{
    int i;
    int numero;
    for (i=0; i<tam ; i++ )
    {

        cout<<"Dado "<< i+1 <<": ";
        cin>>numero;

        /* Se evalua que el dado ingresado sea mayor que 1 o menor que 6,
        hasta que no se cumplan esas condiciones no sale del while*/

        while (numero<1||numero>6)
        {
            cout<<"Ingresa un dado valido, entre el uno y el seis."<<endl;
            cout<<"Dado "<< i+1 <<": "<<endl;
            cin>>numero;
        }

        //Una vez que se ingreso un dado valido se carga en el vector
        vec[i] = numero;

    }
    cout<<" "<<endl;
}

//RESETEA EL VECTOR QUE QUIERAS A 0 POR COMPLETO
void ponerVectorEn0(int vec[],int tam )
{
    int i;
    for (i=0; i<tam ; i++ )
    {
        vec[i]=0;
    }

}

//MUESTRA INFO DE RONDA - PUNTAJE TOTAL ETC.
void  mostrarInfoRonda (string nombre, int ronda, int puntajeTotal, int i)
{
cout<< "--------------------------------------------------------------"<<endl;
cout<< " TURNO DE: "<<nombre<<" | RONDA NUMERO: "<<ronda<<" | PUNTAJE TOTAL: "<<puntajeTotal<<" PUNTOS"<<endl;
            cout<< "--------------------------------------------------------------"<<endl;
            cout<< "                Lanzamiento Numero: "<<i+1<<"                    "<<endl;
            cout<< "--------------------------------------------------------------"<<endl;
            cout<<" "<<endl;
}

//MUESTRA INFO POST RONDA - DESPUES DE CADA RONDA
void MostrarInfoPostRonda (int ronda, string nombre, int puntajetotal)
{
        cout<<"|--------------------------------------------------|"<<endl;
        cout<<"| RONDA NUMERO: "<<ronda<<endl;
        cout<<"|--------------------------------------------------|"<<endl;
        cout<<"| NOMBRE DEL JUGADOR: "<<nombre<<endl;
        cout<<"|--------------------------------------------------|"<<endl;
        cout<<"| SU PUNTUACION HASTA EL MOMENTO ES DE: "<<puntajetotal<<" PUNTOS"<<endl;
        cout<<"|--------------------------------------------------|"<<endl;
        system("pause");
        system("cls");
}

void MostrarInfoPostRonda2jugadores (int ronda, string nombre1, int puntaje1, string nombre2, int puntaje2)
{
        cout<<"|--------------------------------------------------|"<<endl;
        cout<<"| RONDA NUMERO: "<<ronda<<endl;
        cout<<"|--------------------------------------------------|"<<endl;
        cout<<"| PROXIMO TURNO: "<<nombre1<<endl;
        cout<<"|--------------------------------------------------|"<<endl;
        cout<<"| PUNTAJE "<<nombre1<<" : "<<puntaje1<<" PUNTOS"<<endl;
        cout<<"|--------------------------------------------------|"<<endl;
        cout<<"| PUNTAJE "<<nombre2<<" : "<<puntaje2<<" PUNTOS"<<endl;
        cout<<"|--------------------------------------------------|"<<endl;
        system("pause");
        system("cls");
}

//MUESTRA EL CARTEL CUANDO ALGUIEN GANA LA PARTIDA
void MostrarCartelVictoria (string nombre, int puntaje, int rondas)
{
    cout<<" "<<endl;
    cout<<"            "<<nombre<<" GANO LA PARTIDA !         "<<endl;
    cout<<"|-------------------------------------------------|"<<endl;
    cout<<"|  El puntaje final obtenido fue de: "<<puntaje<<" puntos   |"<<endl;
    cout<<"|                                                 |"<<endl;
    cout<<"|        Numero de rondas totales: "<<rondas<<"              |"<<endl;
    cout<<"|-------------------------------------------------|"<<endl;
    cout<<" "<<endl;
    //system("pause");
}

//MUESTRA LOS 6 DADOS
void mostrarVector(int vec[],int tam)
{
    int i;
    for (i=0; i<tam ; i++)
    {
        cout<<"   ["<<vec[i]<<"]   ";
    }
    cout<<" "<<endl;
}

//SUMA LOS ELEMENTOS DEL VECTOR (LOS DADOS) Y MUESTRA EL RESULTADO
int SumarElementosVector(int vec[],int tam)
{
    int i;
    int SumadeVector=0;
    for (i=0; i<tam; i++)
    {
        SumadeVector=SumadeVector+vec[i];
    }
    cout<<endl;
    cout<<" -----------------"<<endl;
    cout<<"| Resultado: ["<<SumadeVector<<"] |"<<endl;
    cout<<" -----------------"<<endl;
    cout<<endl;
    return SumadeVector;
    //system("pause");
}

//EVALUA LAS TIRADAS Y CALCULA CUAL FUE LA MAS ALTA, LA RETORNA COMO MAXPUNTUACION
int CalcularMaximaPuntuacion(int tirada1, int tirada2,int tirada3)
{
    int maxPuntuacion = tirada1;
    if (tirada2 > maxPuntuacion)
    {
        maxPuntuacion = tirada2;
    }
    if (tirada3 > maxPuntuacion)
    {
        maxPuntuacion = tirada3;
    }
    return maxPuntuacion;
}

//COMPRUEBA SI HAY O NO SEXTETO EN LA TIRADA
bool CompruebaSexteto(int dados[], int tam, int& numeroRepetido)
{
    int i;
    int haySexteto=true;
    numeroRepetido=dados[0];

    for (i=1; i<tam; i++)
    {
        if(dados[i]!=numeroRepetido)
        {
            return false;
        }
    }
    return true;
}

//COMPRUEBA SI HAY O NO ESCALERA EN LA TIRADA
bool ComprobarEscalera(int dados[], int tam)
{
 bool HayEscalera=true;
 //DECLARAMOS UN VECTOR EN 0 PARA LLENARLO CON LOS NUMEROS QUE NOS SALIERON
 int vecEn0[tam]={};
 int num;

 //ACUMULAMOS EN EL VECEN0 DEPENDE EL NUMERO, SI SALE UN 1 ACUMULO EN EL 0 (NUM-1) Y ASI CON TODOS
 for (int i=0;i<tam;i++){
    num=dados[i];
    vecEn0[num-1]++;
 }

 //NOS FIJAMOS QUE EL VECTOR HAYA QUEDADO EN TODAS LAS POSICIONES EN 1
 for (int i=0;i<tam;i++)
 {
     if (vecEn0[i]!=1){
      HayEscalera=false;  //SI ALGUNA POSICION NO ES 1 PONEMOS HAYESCALERA EN FALSE
      return HayEscalera;  //Y RETORNAMOS AVISANDO QUE NO HAY ESCALERA
     }
 }
 return HayEscalera; //SI EN TODAS LAS POSICIONES FUE 1 Y NUNCA ENTRO AL IF RETORNAMOS EL HAYESCALERA EN TRUE COMO ESTABA PUESTO AL PRINCIPIO
}

#endif // FUNCIONES_H_INCLUDED
