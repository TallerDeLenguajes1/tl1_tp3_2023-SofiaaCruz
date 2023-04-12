#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char **nombres, *aux;
    int i, num;

    printf("Indique cuantos nombres desea ingresar >> ");
    scanf("%d", &num);

    fflush(stdin);

    nombres = (char **)malloc(num * sizeof(char *));

    for(i = 0; i < num; i++){

        nombres[i]=(char *)malloc(10 * sizeof(char));
        printf("\nIngrese el nombre N%c %d ",248, i+1);
        gets(nombres[i]);

    }

    printf("\n>>>>Nombres ingresados<<<<");

    for(i = 0; i < num; i++){
        printf("\n%d) ", i+1);
        puts(nombres[i]);
    }

    for(i = 0; i < 5; i++){
        free(nombres[i]);
    }

    free(nombres);

    return 0;
}