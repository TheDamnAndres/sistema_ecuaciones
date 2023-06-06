#include <stdio.h>
#include "functions.h"

void metodoCramer(float coeficientes[3][3], float constantes[3]){

    float deter = calcular_determinante(coeficientes);

    if(deter == 0) {
        printf("Este sistema no tiene solucion unica.");
        return;
    }

    float solucion[3];
    for (int i = 0; i < 3; ++i) {
        float matriz_modificada[3][3];
        remplazar_columna(coeficientes, constantes, matriz_modificada, i);
        solucion[i] = calcular_determinante(matriz_modificada) / deter;
    }

    printf("SOLUCIONES: \n");
    for (int i = 0; i < 3; i++) {
        printf("x%d = %.2f\n", i + 1, solucion[i]);
    }
}

float calcular_determinante(float matriz[3][3]){

    float determinante = 0;

    for(int i = 0 ; i < 3 ; i++ ){
        determinante += matriz[0][i] * (matriz[1][(i + 1) % 3] * matriz[2][(i + 2) % 3] -
                matriz[1][(i + 2) % 3] * matriz[2][(i + 1) % 3]);
                ///obtener determinante por metodo de Sarrus
    }

    return determinante;
}

void remplazar_columna(float coeficientes[3][3], float columna[3],
                       float matrizmodificada[3][3], int index){

    for(int i = 0 ; i < 3 ; i++){
        for (int j = 0; j < 3; ++j) {
            if(j == index)
                matrizmodificada[i][j] = columna[i];
            else
                matrizmodificada[i][j] = coeficientes[i][j];
        }
    }
}

