/**
@progName Puzzle
@author Alejandro Hernández López
 A00822926
@date 11-01-18
 Version 1.0
 @desc El Puzzle de 15 fichas es un juego que consiste de 15 fichas numeradas del 1 al 15 que se encuentran dentro de un marco cuadrado que tiene espacio para 16 fichas. Una de las posiciones está vacía y las fichas se pueden desplazar de una posición a otra sin ser sacadas del marco. El objetivo del juego es acomodar las fichas en alguna posición predefinida.
*/

//@desc HOLAAAAAA
// @funcName HOLAAA
#include <iostream>
using namespace std;

/**
@funcName matrizDeJuego
@desc Saca en la consola una matriz 4x4, que es el tablero del Puzzle.
@param Tiene una matriz llamada tablero como parametro de 4x4
@return No retorna.
 */
void matrizDeJuego(int tablero[4][4])
{
    for(int i = 0; i < 4; i++ )
    {
        for(int j = 0; j < 4; j++ )
        {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}



/**
@funcName moverFicha
@desc Si hay un '0' a un lado de la ficha que se ingreso, las cambiara de lugar y mostrara un mensaje diciendo que se ha cambiado la ficha.
@param Tiene una matriz llamada tablero como parametro de 4x4 y un integer llamado 'ficha' que es la ficha que se va a cambiar de lugar
@return No retorna.
 */
void moverFicha(int tablero[4][4], int ficha)
{
    for(int i = 0; i < 4; i++ )
    {
        for(int j = 0; j < 4; j++ )
        {
            if (tablero[i][j] == ficha)
            {
                if(tablero[i-1][j] == 0)
                {
                    tablero[i][j] = 0;
                    tablero[i-1][j] = ficha;
                    i = 4;
                    cout << "Posición cambiada" << endl;
                }
                else if(tablero[i][j-1] == 0)
                {
                    tablero[i][j] = 0;
                    tablero[i][j-1] = ficha;
                    i = 4;
                    cout << "Posición cambiada" << endl;
               
                }
                else if(tablero[i+1][j] == 0)
                {
                    tablero[i][j] = 0;
                    tablero[i+1][j] = ficha;
                    i = 4;
                    cout << "Posición cambiada" << endl;
                    
                }
                else if(tablero[i][j+1] == 0)
                {
                    tablero[i][j] = 0;
                    tablero[i][j+1] = ficha;
                    i = 4;
                    cout << "Posición cambiada" << endl;
                    
                }
                else if(ficha == 0)
                {
                    
                    i = 4;
                    cout << "Termina el juego" << endl;
                }
                else
                {
                    cout << "Debe estar junto a la ficha \"0\"" << endl;
                    i = 4;
                }
                
            }
        }
    }
}



/**
@funcName main
@desc Llama a todas las funciones anteriores
@param Sin parametros
@return No retorna.
 */

// @funcName HOLAAAAAAAAA
int main() {
    
    int tablero[4][4] =
    {{0,4,7,2},
    {3,10,1,9},
    {5,8,12,15},
    {6,11,13,14},
    };
    int fichaMover;
    do
    {
    matrizDeJuego(tablero);
    cout << "Numero" << endl;
    cin >> fichaMover;
    moverFicha(tablero,fichaMover);
    }while(fichaMover != 0);
    
    return 0;
}
