#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

//SE RECOMIENDA EJECUTAR EL PROGRAMA EN MAC DEBIDO A PROBLEMAS DE INCOMPATIBILIDAD DE WINDOWS CON LOS SÍMBOLOS

// Declaración de variables
int playerScore = 0;
int dealerScore = 0;
int hand = 21;
int normas;
int carta;
int cartas[4][13]; // 4 palos, 13 cartas por palo
int valorAS;
string palos[4] = {"♥", "♦", "♣", "♠"};
string baraja[13] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
int scores[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

void clearScreen()
{ // Funcion para limpiar la terminal
    system("clear");
}
void instrucciones()
{
    cout << "\nI N S T R U C C I O N E S\n1) Objetivo del juego: El objetivo es tener una mano mejor que la del crupier, quedándote lo más cerca posible de 21 sin pasarte.\n2) Cartas: Se juega con 1 o más barajas de 52 cartas, con valores entre 1 y 11 puntos. \n3) Inicio del juego: Los jugadores reciben 2 cartas y juegan por turnos. \n4) Opciones de juego: Puedes pedir (solicitar otra carta), doblar (doblar tu apuesta inicial y recibir una sola carta adicional), dividir (si tienes dos cartas del mismo valor, puedes dividirlas en dos manos separadas) o plantarte (no recibir más cartas).\n5) Blackjack: Si obtienes exactamente 21 puntos en la repartición, eso se llama un blackjack.\n6) Ganar el juego: Si tu mano está más cerca de 21 que la del crupier, superas al repartidor y ganas.\nRecuerda, las reglas específicas pueden variar dependiendo del casino o de la versión del juego que estés jugando.\n\n\n";
}

int valorAs(string usuario)
{
    if (usuario == "Dealer")
    {
        if (dealerScore + 11 > hand)
        {
            return 1;
        }
        else
        {
            return 11;
        }
    }
    else
    {
        cout << "* PREGUNTA AL JUGADOR: *\n¿Quiere el Jugador que el AS valga 1 o 11? \n";
        cin >> valorAS;
        if (valorAS == 11)
        {
            return 11;
        }
        else if (valorAS == 1)
        {
            return 1;
        }
    }

    return 0;
}

int repartirCarta(string usuario)
{
    int valor = 0;
    int palo = rand() % 4; // Seleccionar un palo y una carta aleatoriamente
    do
    {
        carta = rand() % 13;
    } while (cartas[palo][carta] == -1); // Check de que la carta no ha sido ya seleccionada

    cartas[palo][carta] = -1; // Marca la carta como seleccionada

    if (carta == 0)
    { // Situación en caso de salir un AS
        valor = valorAs(usuario);
    }
    else
    {
        valor = scores[carta];
    }
    cout << "\n\nCarta para " << usuario << ": "  // ésta es la carta que se reparte
        << baraja[carta] << " " << palos[palo] << "\n";


    //implementar aquí las cartas de poker
    if ((baraja[carta] == "2" || baraja[carta] == "3" || baraja[carta] == "4" || baraja[carta] == "5" || baraja[carta] == "6" || baraja[carta] == "7" || baraja[carta] == "8" || baraja[carta] == "9")){
        cout<< "╭-------╮ \n"
            << "|"<< baraja[carta]<<"      | \n"
            << "|"<< palos[palo]<<"      | \n"
            << "|       | \n"
            << "|      "<<palos[palo]<<"| \n"
            << "|      "<< baraja[carta]<<"| \n"
            << "╰-------╯ \n";
    } else if (baraja[carta] == "As" ) {
        cout<< "╭-------╮ \n"
            << "|       | \n"
            << "|   A   | \n"
            << "|       | \n"
            << "|   "<<"\033[31m"<< palos[palo] << "\033[0m" << "   | \n"
            << "|       | \n"
            << "╰-------╯ \n";
    } else if (baraja[carta] == "10"){
        cout<< "╭-------╮ \n"
            << "|"<<baraja[carta]<<"     | \n"
            << "|"<<"\033[31m"<<palos[palo]<<"\033[0m" <<"      | \n"
            << "|       | \n"
            << "|      "<<"\033[31m"<< palos[palo] << "\033[0m" << "| \n"
            << "|     "<< baraja[carta]<<"| \n"
            << "╰-------╯ \n";
    } else {
        cout<< "╭-------╮ \n"
            << "|"<<baraja[carta]<<"      | \n"
            << "|"<<"\033[31m"<<palos[palo]<<"\033[0m" <<"      | \n"
            << "|       | \n"
            << "|      "<<"\033[31m"<<palos[palo]<< "\033[0m" << "| \n"
            << "|      "<<baraja[carta]<<"| \n"
            << "╰-------╯ \n";
    }

    return valor;
}

int main()
{
    clearScreen();
    srand(time(NULL)); // Inicialización de la función Random

    string player;

    string bienvenida = "♡ ♢ ♤ ♧  B I E N V E N I D O  ♡ ♢ ♤ ♧ \n\n";
    for (char c : bienvenida)
    {
        cout << c;
        cout.flush();                                     // Asegura que el carácter se imprime inmediatamente
        this_thread::sleep_for(chrono::milliseconds(40)); // Pausa de 100 milisegundos
    }

    cout << "Conoce las normas del BlackJack? \n"
        << "1. SI\n2. NO\n";
    cin >> normas;

    if (normas == 2)
    {
        instrucciones();
        string empezar = "♡ ♢ ♤ ♧  E M P I E Z A   L A   P A R T I D A  ♡ ♢ ♤ ♧ \n\n";
        for (char c : empezar)
        {
            cout << c;
            cout.flush();                                     // Asegura que el carácter se imprime inmediatamente
            this_thread::sleep_for(chrono::milliseconds(40)); // Pausa de 100 milisegundos
        }
    }
    else if (normas == 1)
    {
        clearScreen();
        string empezar = "♡ ♢ ♤ ♧  E M P I E Z A   L A   P A R T I D A  ♡ ♢ ♤ ♧ \n\n";
        for (char c : empezar)
        {
            cout << c;
            cout.flush();                                     // Asegura que el carácter se imprime inmediatamente
            this_thread::sleep_for(chrono::milliseconds(40)); // Pausa de 100 milisegundos
        }
    }
    else
    {
        cout << "Introduzca un número correcto por favor.";
    }

    // nombre usuario
    cout << "Introduce tu nombre de usuario:\n\n";
    cin >> player;

    for (int i = 0; i < 4; i++)
    { // Doble bucle for para inicializa todas las cartas a 1
        for (int j = 0; j < 13; j++)
        {
            cartas[i][j] = 1;
        }
    }
    while(true){
        
        //Se reparten las cartas para el jugador
        cout << "\n** TURNO DEL JUGADOR **";
        this_thread::sleep_for(chrono::seconds(1));
        for (size_t i = 0; i < 2; i++) //Bucle para repartir las dos cartas iniciales del jugador
        {
            playerScore += repartirCarta(player);
            cout << player << " Score: " << playerScore << "\n\n"; //Score del jugador
            this_thread::sleep_for(chrono::seconds(1));
        }

        this_thread::sleep_for(chrono::seconds(1));

        //Se reparte la carta para el coupier
        cout << "\n\n** TURNO DEL CROUPIER **";
        this_thread::sleep_for(chrono::seconds(1));
        dealerScore += repartirCarta("Dealer");

        //SCORES
        //Player score
        cout << "\n\nACTUAL SCORES: \n\n";
        cout << player << " Score: " << playerScore << "\n\n"; //Score del jugador
        this_thread::sleep_for(chrono::seconds(1));

        //Dealer Score
        cout << "Dealer Score: " << dealerScore << "\n\n";
        this_thread::sleep_for(chrono::seconds(1));



        //preguntar si player quiere otra carta
        bool otherCarta = true;
        while (otherCarta)
        {
            cout << player << " quiere otra carta?\n1. Si\n2. No\n";
            int opc = 0;
            cin >> opc;
            if (opc == 1)
            {
                playerScore += repartirCarta(player);
                cout << player << " Score: " << playerScore << "\n\n";

                if (playerScore > hand)
                {
                    otherCarta = false;
                }
            }
            else
            {
                otherCarta = false;
            }
        }

        if(playerScore == hand){ //COMPROBACIÓN DE LA PUNTUACIÓN ACTUAL
            exit(0);
        }
        if (playerScore <= hand)
        {
            while (dealerScore < playerScore && dealerScore <= 21)
            {
                dealerScore += repartirCarta("Dealer");

                cout << "Dealer Score: " << dealerScore << "\n\n";
            }

            if (dealerScore > hand)
            {
                cout << player << " ha ganado\n\n";
            }
            else if (playerScore > dealerScore)
            {
                cout << player << " ha ganado\n\n";
            }
            else if (playerScore == dealerScore)
            {
                cout << "\nEMPATE\n";
            }
            else
            {
                cout << player << " ha perdido";
            }
        }
        else
        {
            cout << player << " ha perdido\n\n";
        }

        cout << "\n";
        int seguir;
        this_thread::sleep_for(chrono::seconds(1));
        string empezar = "♡ ♢ ♤ ♧  ¿QUIERES JUGAR OTRA PARTIDA?  ♡ ♢ ♤ ♧ \n\n";
            for (char c : empezar)
            {
                cout << c;
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(40)); 
            }
        cout << "1.SI\n2.NO\n";
        cin >> seguir;
        if (seguir == 2) {
            break;
        } else {
            playerScore = 0;
            dealerScore = 0;
        }
        
    }

    return 0;
}