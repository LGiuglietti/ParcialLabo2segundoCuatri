#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodoArbol
{
    char nombreLibro[30];
    int cantPaginas;
    char genero[20];
    int Puntaje;
    char NombrePersona[20];
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

typedef struct celda
{
    char NombrePersona[20];
    struct nodoListaLibro * listaLibros;
} celda;

typedef struct nodoListaLibro
{
    char nombreLibro[30];
    int cantPaginas;
    char genero[20];
    int Puntaje;
    struct nodoListaLibro* sig;
} nodoListaLibro;
//proto
int altaArreglo(celda Arreglo[],nodoArbol*arbol,int validosArreglo);
nodoListaLibro*crearNodoLista(int Puntaje, int cantPaginas, char nombreLibro[],char genero[]);
nodoListaLibro*insertarNodoEnLista(nodoListaLibro*lista, int Puntaje, int cantPaginas, char nombreLibro[],char genero[]);
int buscarPosEnArreglo(celda Arreglo[],char nombreABuscar[], int posicion);
int contarNodosArbol(nodoArbol*arbol, int validosArbol);
int pasarDeArbolToArreglo(nodoArbol*arbol, celda Arreglo[],int validosArbol,int i,int posicion, int validosArreglo);
///--------------
nodoArbol*crearNodoArbol(int Puntaje,int cantPaginas, char nombreLibro[],char genero[], char NombrePersona[]);
nodoArbol*insertarNodoToArbol(nodoArbol*arbol,nodoArbol*nn);
void mostrarLista(nodoListaLibro*lista);
void mostrarArreglo(celda arreglo[],int validosArreglo);
//fin proto
int main()
{
    celda Arreglo[5];
    nodoArbol*arbol=NULL;
    //-------------------------------------------------------------
    int puntaje=rand()%9+1;
    int cantpaginas=rand()%300+100;
    nodoArbol*nn=crearNodoArbol(puntaje,cantpaginas,"a","a","pepe");
    arbol=insertarNodoToArbol(arbol,nn);
    puntaje=rand()%9+1;
    cantpaginas=rand()%300+100;
    nn=crearNodoArbol(puntaje,cantpaginas,"b","b","julian");
    arbol=insertarNodoToArbol(arbol,nn);
    puntaje=rand()%9+1;
    cantpaginas=rand()%300+100;
    nn=crearNodoArbol(puntaje,cantpaginas,"c","c","lau");
    arbol=insertarNodoToArbol(arbol,nn);
    puntaje=rand()%9+1;
    cantpaginas=rand()%300+100;
    nn=crearNodoArbol(puntaje,cantpaginas,"d","d","pepe");
    arbol=insertarNodoToArbol(arbol,nn);
    puntaje=rand()%9+1;
    cantpaginas=rand()%300+100;
    nn=crearNodoArbol(puntaje,cantpaginas,"e","e","julian");
    arbol=insertarNodoToArbol(arbol,nn);
    puntaje=rand()%9+1;
    cantpaginas=rand()%300+100;
    nn=crearNodoArbol(puntaje,cantpaginas,"f","f","pepe");
    arbol=insertarNodoToArbol(arbol,nn);
    puntaje=rand()%9+1;
    cantpaginas=rand()%300+100;
    nn=crearNodoArbol(puntaje,cantpaginas,"g","g","julian");
    arbol=insertarNodoToArbol(arbol,nn);
    puntaje=rand()%9+1;
    cantpaginas=rand()%300+100;
    nn=crearNodoArbol(puntaje,cantpaginas,"h","h","lau");
    arbol=insertarNodoToArbol(arbol,nn);
    //-----------------------------------------------------------
    int validosArbol=0;
    validosArbol=contarNodosArbol(arbol,validosArbol);
    int validosArreglo=0;
    validosArreglo=pasarDeArbolToArreglo(arbol,Arreglo,validosArbol,0,0,validosArreglo);
    printf("validos%d\n",validosArreglo);
    mostrarArreglo(Arreglo,validosArreglo);
    return 0;
}


nodoArbol*crearNodoArbol(int Puntaje,int cantPaginas, char nombreLibro[],char genero[], char NombrePersona[])
{
    nodoArbol*aux=(nodoArbol*)malloc(sizeof(nodoArbol));
    aux->cantPaginas=cantPaginas;
    aux->Puntaje=Puntaje;
    strcpy(aux->nombreLibro,nombreLibro);
    strcpy(aux->genero,genero);
    strcpy(aux->NombrePersona,NombrePersona);
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}


nodoArbol*insertarNodoToArbol(nodoArbol*arbol,nodoArbol*nn)
{
    if(arbol==NULL)
    {
        arbol=nn;
    }
    else if(arbol->cantPaginas>nn->cantPaginas)
    {
        arbol->izq=insertarNodoToArbol(arbol->izq,nn);
    }
    else
    {
        arbol->der=insertarNodoToArbol(arbol->der,nn);
    }
    return arbol;
}


nodoListaLibro*crearNodoLista(int Puntaje, int cantPaginas, char nombreLibro[],char genero[])
{
    nodoListaLibro*aux=(nodoListaLibro*)malloc(sizeof(nodoListaLibro));
    aux->cantPaginas=cantPaginas;
    aux->Puntaje=Puntaje;
    strcpy(aux->nombreLibro,nombreLibro);
    strcpy(aux->genero,genero);
    aux->sig=NULL;
    return aux;
}


nodoListaLibro*insertarNodoEnLista(nodoListaLibro*lista, int Puntaje, int cantPaginas, char nombreLibro[],char genero[])
{
    nodoListaLibro*aux=crearNodoLista(Puntaje,cantPaginas,nombreLibro,genero);
    if(lista==NULL)
    {
        lista=aux;
    }
    else if(lista->cantPaginas>aux->cantPaginas)
    {
        aux->sig=lista;
        lista=aux;
    }
    else
    {
        nodoListaLibro*seg=lista;
        nodoListaLibro*ante;
        while(seg!=NULL && seg->cantPaginas<aux->cantPaginas)
        {
            ante=seg;
            seg=seg->sig;
        }
        if(seg==NULL)
        {
            ante->sig=aux;
            seg=aux;
        }
        else
        {
            ante->sig=aux;
            aux->sig=seg;
        }
    }
    return lista;
}


int buscarPosEnArreglo(celda Arreglo[],char nombreABuscar[], int posicion)
{
    int i=0;
    posicion=-1;
    while(i<5)
    {
        if(strcmpi(Arreglo[i].NombrePersona,nombreABuscar)==0)
        {
            posicion=i;
        }
        i++;
    }
    return posicion;
}


int contarNodosArbol(nodoArbol*arbol, int validosArbol)
{
    if(arbol!=NULL)
    {
        validosArbol++;
        validosArbol=contarNodosArbol(arbol->izq,validosArbol);
        validosArbol=contarNodosArbol(arbol->der,validosArbol);
    }
    return validosArbol;
}


int pasarDeArbolToArreglo(nodoArbol*arbol, celda Arreglo[],int validosArbol,int i,int posicion, int validosArreglo)
{
    if(arbol!=NULL && i<validosArbol)
    {
        posicion=buscarPosEnArreglo(Arreglo,arbol->NombrePersona,posicion);

        if(posicion==-1)
        {
            validosArreglo=altaArreglo(Arreglo,arbol,validosArreglo);
            posicion=validosArreglo-1;
        }
        Arreglo[posicion].listaLibros=insertarNodoEnLista(Arreglo[posicion].listaLibros,arbol->Puntaje,arbol->cantPaginas,arbol->nombreLibro,arbol->genero);
        i++;
        i=pasarDeArbolToArreglo(arbol->izq,Arreglo,validosArbol,i,posicion,validosArreglo);
        i=pasarDeArbolToArreglo(arbol->der,Arreglo,validosArbol,i,posicion,validosArreglo);
    }
    return i;
}


int altaArreglo(celda Arreglo[],nodoArbol*arbol,int validosArreglo)
{
    strcpy(Arreglo[validosArreglo].NombrePersona,arbol->NombrePersona);
    Arreglo[validosArreglo].listaLibros=NULL;
    validosArreglo++;
    return validosArreglo;
}


void mostrarArreglo(celda arreglo[],int validosArreglo)
{
    int i=0;
    while(i<3)
    {
        puts(arreglo[i].NombrePersona);
        mostrarLista(arreglo[i].listaLibros);
        printf("\n");
        i++;
    }

}


void mostrarLista(nodoListaLibro*lista)
{
    if(lista!=NULL)
    {
        nodoListaLibro*seg=lista;
        while(seg!=NULL)
        {
            printf("\nPuntaje: %d\t",seg->Puntaje);
            printf("cant pags: %d\t",seg->cantPaginas);
            printf("genero: %s\t",seg->genero);
            printf("nombre delibro: %s\t",seg->nombreLibro);

            seg=seg->sig;
        }
        printf("\n\n");
    }
}


















