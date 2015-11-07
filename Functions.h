#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

#include "Variables.h"

using namespace std;

/**
*@brief Limpa ecrâ
*/
void clrscr(void);

/**
*@brief Define cor
*/
void setcolor(unsigned int color, unsigned int background_color); // Altera a cor das letras da consola

/**
*@brief Imprime titulo
*/
void impressaoTitulo();

/**
*@ Imprime aviso de saída da aplicação
*/
void exiting();

/**
* @brief Limpa o buffer
*/
void clean_buffer();

/**
* @brief Esconde a password com asteriscos
*/
string hidePass();

#endif /*FUNCTIONS_H_*/