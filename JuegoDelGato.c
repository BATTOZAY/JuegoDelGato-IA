// EDWAR GONZALEZ 2IL131 INTELIGENCIA ARTIFICIAL
// JUEGO: X 0
 
#include <stdio.h>
#include <stdlib.h>

// Prototipo de la Función para modificar la matriz en cada movimientos

void movimientos (char matriz[3][3], char player1, char player2);

// Imprimir resultados
void impresion (char matriz[3][3], char jugador1, char jugador2);

// Imprimir resultados
int comprobador (int posicion, int rastro[8]);

//FUNCIÓN PRINCIPAL
int main () {
    
   //BLOQUE DE VARIABLES

   //declaro la matriz, con valores inciales para que los jugadores se guién.
      char matriz [3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
      
      char player1, player2;

   //BLOQUE DE INSTRUCCIONES

      // entrada del carácter que usará el jugador #1

      printf("\n---------HOLA, BIENVENIDO AL JUEGO GATO---------\n\n");
      printf("\nJugador #1 ingresa la ficha que quieres utilizar ( x u o ): ");
         scanf ("%c", &player1);

      // if para determinar caracter del player 2
         if( player1 == 'x' )
            player2 = 'o';
         else
            player2 = 'x';
            
      system("cls");
      // llamo las funciones
      impresion (matriz, player1, player2);
      movimientos (matriz, player1, player2);

}

//---------------------------------------------------------------------------------------


//Función para modificar la matriz en cada movimientos
void movimientos (char matriz[3][3], char player1, char player2)
   {
      //variables
      int fila, columna, x, control = 0, posicion, r;
      int rastro[8]={0};
      
      //INSTRUCCIONES

      //for de 9 repeteciones
         for ( x = 1; x <= 9; x++ )
            {
               // ENTRADA DE POSICIÓN
                     do{
                           while( control == 0)
                              {
                                 if( (x % 2) != 0 )
                                    printf("\n\n           Es tu turno jugador #1");
                                 else
                                    printf("\n\n           Es tu turno jugador #2");  

                                 // entrada de la posicion
                                 printf("\n  Ingresa el # de la posicion que deseas: ");
                                    scanf ("%d", &posicion);
                                 // comprobamos si la posición existe
                                 if( posicion >= 1 && posicion <= 9 )
                                    control = 1;
                                 else
	                                 {
	                                 	printf("\n    ______________________________________\n");
	                                    printf("\n     Posicion inexistente, vuelve a elegir\n");
	                                    printf("\n    ______________________________________\n");
									 }
                              }
                     // comprobamos si la posción está ocupada y imprimimos si lo está
							if( comprobador (posicion, rastro) == 1)
								{
									printf("\n   ______________________________________\n");
									printf("\n    La posicion esta ocupada intenta otra\n");
									printf("\n   ______________________________________\n");
									control = 0;
								}
								
                        }while( comprobador (posicion, rastro) != 0 ); //COMPROBAMOS SI ESA POSICIÓN ESTÁ OCUPADA
                
            //ingreso una posición ocupada
               rastro [x-1] = posicion;
              
            //decido cual es la posición en la matriz

            switch(posicion) //donde opción es la variable a comparar
               {
                  case 1: fila = 0; columna = 0;
                           break;

                  case 2: fila = 0; columna = 1;
                           break;

                  case 3: fila = 0; columna = 2;
                           break;

                  case 4: fila = 1; columna = 0;
                           break;

                  case 5: fila = 1; columna = 1;
                           break;
                  case 6: fila = 1; columna = 2;
                           break;

                  case 7: fila = 2; columna = 0;
                           break;

                  case 8: fila = 2; columna = 1;
                           break;

                  case 9: fila = 2; columna = 2;
                           break;
               }

               // ELECCIÓN DE CARACTER A INTRODUCIR
              
               if( (x % 2) != 0 ) // veo si la interacción es par para saber cual es el jugador
                  matriz[fila][columna] = player1;
               else
                  matriz[fila][columna] = player2;
               system("cls"); 
               //impresion de la matriz
               impresion (matriz, player1, player2);
               control = 0;

                // QUIÉN GANA ?, LUEGO DE X>=3 
               if (x >= 3)
                  {
                     // GANA X ?
                     if(matriz[0][0] == player1 && matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2]
                     || matriz[1][0] == player1 && matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2]
                     || matriz[2][0] == player1 && matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2]
                     
                     || matriz[0][0] == player1 && matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0]
                     || matriz[0][1] == player1 && matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1]
                     || matriz[0][2] == player1 && matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2]
                     
                     || matriz[0][0] == player1 && matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]
                     || matriz[0][2] == player1 && matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0])
                     {
                        printf("\n\n           ==========================\n");
                        printf("\n             El Jugador 1 Ha Ganado\n");
                        printf("\n           ==========================\n");
                        x = 9;
			            }
                     
                     // GANA 0 ?
                     if(matriz[0][0] == player2 && matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2]
                     || matriz[1][0] == player2 && matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2]
                     || matriz[2][0] == player2 && matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2]
                     
                     || matriz[0][0] == player2 && matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0]
                     || matriz[0][1] == player2 && matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1]
                     || matriz[0][2] == player2 && matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2]
                     
                     || matriz[0][0] == player2 && matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]
                     || matriz[0][2] == player2 && matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0])
                     {
                        printf("\n\n           ==========================\n");
                        printf("\n             El Jugador 2 Ha Ganado\n");
                        printf("\n           ==========================\n");
                        x = 9;
                     }
                  }
            
            }

   }


//----------------------------------------------------------------------------------------


//FUNCIÓN PARA LA IMPRESIÓN
void impresion (char matriz[3][3], char jugador1, char jugador2 )
   {
      //variables
      int fila, columna;
       // 2 for para imprimir la matriz y sus actulizaciones
      printf("\n---------HOLA, BIENVENIDO AL JUEGO GATO---------\n\n");
      printf("\n          Jugador #1: %c jugador #3: %c", jugador1, jugador2);
      printf("\n                _____________\n");
      //impresion de la matriz
      for ( fila = 0; fila < 3; fila++ )
         {
            for ( columna = 0; columna < 3; columna++ )
            {
               if ( columna == 0 )
                  
                  printf("                | %C ", matriz[fila][columna]);
               else 
                  printf("| %C ", matriz[fila][columna]);
                  
               //salto de linea
               if( columna == 2 )
               printf("|\n");

            }
            printf("                _____________\n");
           
         }
         printf("\n\n");
   }

//------------------------------------------------------------------------------
//FUNCIÓN PARA COMPROBAR SI LA POSICIÓN ESTÁ OCUPADA
   int comprobador (int posicion, int rastro[8])
      {
         //VARIABLES
         int r, valor = 0;
         //FOR PARA VER SI ESTÁ OCUPADA
         for (r = 0; r < 8; r++ )
                  {
                  		if(valor == 0)
                           {
                              if (posicion == rastro [r])
                                          valor = 1;   
                                    else
                                       valor = 0;
                           }
    					      else
    						      r = 7;
                  }
            //RETORNO VALOR
            return valor;
      }
