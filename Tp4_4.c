#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};


struct Producto
{
    int ProductoID;
    int Cantidad; 
    char *TipoProducto;
    float PrecioUnitario;
};

typedef struct Producto prod;


struct Cliente
{
    int ClienteID;
    char NombreCliente[10];
    int CantidadProductosAPedir;
    struct Producto *Productos; 
};

typedef struct Cliente client;

void cargar_clientes (client* datosC, int numClientes);
void cargar_productos(prod *productos, int numProd);
float total_productos (prod *productos, int numProd);
void mostrar_cargados (client *datosC, int numClientes);
void mostrar_prod (prod *productos, int numProd);

int main(){

    client* datosC;
    int numClientes;
    srand(time(NULL));

    printf("Ingrese la cantidad de clientes >> ");
    scanf("%d", &numClientes);

    while(numClientes > 5){
        printf("\nSolo puede visitar hasta 5 clientes, por favor ingrese un numero menor de clientes >> ");
        scanf("%d", &numClientes);
    }
    
    fflush(stdin);
    datosC = (client*)malloc(sizeof(client) * numClientes);

    cargar_clientes(datosC, numClientes);
    mostrar_cargados(datosC, numClientes);

    for(int i=0; i < numClientes; i++){
        free(datosC->Productos);
    }
    free(datosC);

    getchar();
    return 0;
}

void cargar_clientes (client* datosC, int numClientes){

    for(int i=0; i< numClientes; i++){

        printf("\n\n>>>>Cliente N%c %d<<<<", 248, i+1);
        datosC->ClienteID = i+1;
        printf("\nIngrese el nombre del clinete >> ");
        gets(datosC->NombreCliente);
        datosC->CantidadProductosAPedir = rand()%5+1;
        datosC->Productos = (prod*)malloc(sizeof(prod) * datosC->CantidadProductosAPedir);
        cargar_productos(datosC->Productos, datosC->CantidadProductosAPedir);

        datosC++;
        fflush(stdin);

    }


}

void cargar_productos(prod *productos, int numProd){

    for(int i=0; i < numProd; i++){
        productos->ProductoID = i+1;
        productos->Cantidad = rand()%10+1;
        productos->TipoProducto= TiposProductos[(int)rand()%5];
        productos->PrecioUnitario = ((float)rand()/RAND_MAX) * 91+10;
        productos++;
    }
}

float total_productos (prod *productos, int numProd){
    float total;
    for(int i=0; i < numProd; i++){
        total += productos->PrecioUnitario * productos->Cantidad;
        productos++;
    }
    return total;
}

void mostrar_cargados (client *datosC, int numClientes){

    for(int i=0; i<numClientes; i++){
        printf("\n\n>>>>Cliente N%c %d<<<<", 248, datosC->ClienteID);
        printf("\nNombre: ");
        puts(datosC->NombreCliente);
        printf("\nCantidad de productos: %d", datosC->CantidadProductosAPedir);
        mostrar_prod(datosC->Productos, datosC->CantidadProductosAPedir);
        printf("\n\tTotal a pagar: %.2f", total_productos(datosC->Productos, datosC->CantidadProductosAPedir));
         datosC++;
    }
}

void mostrar_prod (prod *productos, int numProd){

    for(int i=0; i<numProd; i++){

        printf("\n\n>>Producto N%c %d<<", 248, productos->ProductoID);
        printf("\nCantidad: %d", productos->Cantidad);
        printf("\nTipo de producto: ");
        puts(productos->TipoProducto);
        printf("Precio unitario: %.2f", productos->PrecioUnitario);
        productos++;
    }
}




