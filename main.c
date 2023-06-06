#include <stdio.h>
#include "functions.h"

int main() {

    float coeficientes[3][3] = {{1, 1, 1},
                                {-5, -1, 2},
                                {1, -1, -3}};
    float constantes[3] = {6, 5, -10};

    metodoCramer(coeficientes, constantes);

    return 0;
}
