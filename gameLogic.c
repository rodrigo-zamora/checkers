#include <stdio.h>
#include <stdlib.h>
#include "gameLogic.h"
/*
void seleccionarFicha(){
    if(game.turno = negras)
        if normal
            isPossible(game, currentX, currentY, currentX+1, currentY+1);
            isPossible(game, currentX, currentY, currentX+1, currentY-1);
        else
            isPossible(game, currentX, currentY, currentX+1, currentY+1);
            isPossible(game, currentX, currentY, currentX+1, currentY-1);
            isPossible(game, currentX, currentY, currentX-1, currentY+1);
            isPossible(game, currentX, currentY, currentX-1, currentY-1);
    else if blancas
        if normal
            isPossible(game, currentX, currentY, currentX+1, currentY+1);
            isPossible(game, currentX, currentY, currentX+1, currentY-1);
        else
            isPossible(game, currentX, currentY, currentX+1, currentY+1);
            isPossible(game, currentX, currentY, currentX+1, currentY-1);
            isPossible(game, currentX, currentY, currentX-1, currentY+1);
            isPossible(game, currentX, currentY, currentX-1, currentY-1);
}
*/
// revisar todos los posibles movimientos y ver si son válidos. regresa 1 si es válido y 0 si no
int isPossible(gameStructRef game, int currentX, int currentY, int possibleX, int possibleY)
{
    
    // revisar si la posición está vacía
    if(game->board[possibleX][possibleY]->type == 0){ // 0 = nothing ; 1 = normal ; 2 = king
        return 1;
    } else {
        // revisar si a la posición donde se desea mover, hay otra ficha del equipo contrario
        // 0 = nothing; 1 = black; 2 = white
        if(game->board[possibleX][possibleY]->playerHolder != game->board[currentX][currentY]->playerHolder){
            //
            // comer ficha [agregar código] - jaime
            //
        } else {
            // el movimiento no es válido
            return 0;
        }
    }
}

// considerando que el movimiento si es válido
void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY)
{
    // asignar al nuevo lugar la ficha
    game->board[newX][newY]->playerHolder = game->board[currentX][currentY]->playerHolder;
    game->board[newX][newY]->type = game->board[currentX][currentY]->type;

    // poner la ficha antigua vacia
    game->board[currentX][currentY]->playerHolder = 0;
    game->board[currentX][currentY]->type = 0;
}