#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define F 5
#define C 12

void cargarMatriz (int prod[F][C]);
void mostrarMatriz (int prod[F][C]);
void calcularProm (int prod[F][C]);
void maximoMinimoValor (int prod[F][C]);

int main(){

    int prod[F][C];

    srand(time(NULL));

    cargarMatriz(prod);
    mostrarMatriz(prod);
    calcularProm(prod);
    maximoMinimoValor(prod);

    getchar();
    return 0;
}

void cargarMatriz (int prod[F][C]){
    int i, j;

    for(i = 0; i < F; i++){
        for(j = 0; j < C; j++){

            prod[i][j]=rand()%(40000 + 1) + 10000;
        }
    }
}

void mostrarMatriz (int prod[F][C]){

    int i, j;

    for (i = 0; i < F; i++){
        for (j = 0; j < C; j++){
            printf(" %d ", prod[i][j]);
        }
        printf("\n");
    }
}

void calcularProm (int prod[F][C]){
    int aux=0;
    for (int i=0; i < F; i++){
        for (int j=0; j < C; j++){
            aux += prod[i][j];
        }
        aux/=C;
        printf("\nEl promedio de ganancia del a%co %d es: %d",164,i+1, aux);
    }

}

void maximoMinimoValor (int prod[F][C]){

    int i, j, aux = prod[0][0], a, b, aux2 = prod[0][0], c, d;

    for(i = 0; i < F; i++){
        for(j = 0; j < C; j++){
            if(aux < prod[i][j]){
                aux=prod[i][j];
                a=i;
                b=j;
            }

            if(aux2 > prod[i][j]){
                aux2=prod[i][j];
                c=i;
                d=j;
            }
        }
    }

    printf("\n\nEl maximo valor es %d en el a%co %d y mes %d", aux, 164, a+1, b+1);
    printf("\n\nEl minimo valor es %d en el a%co %d y mes %d", aux2, 164, c+1, d+1);
}
