#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int a;
    char b[50];///los vectores son punteros
}eDato;

int set_a(eDato* , int);
int set_b(eDato* , char*);

int get_a(eDato* );
char* get_b(eDato* );

int main()
{
    eDato dato;
    eDato* d;

    d=&dato;

    set_a(d,1800);

    set_b(d,"hola");

    printf("%d--%s",get_a(d),get_b(d));

    return 0;
}
int set_a(eDato* dato, int valor)///seteo
{
    int ret=0;
    if(dato!=NULL && valor >1500)
    {
        dato->a=valor;
        ret=1;
    }
    else
    {
        dato->a=1500;
    }

    return ret;
}

int set_b(eDato* dato, char* valor)
{
    int ret=0;
    if(dato!=NULL && valor!=NULL)
    {
        strcpy(dato->b,valor);
        ret=1;
    }

    return ret;
}
int get_a(eDato* dato)
{
    int valor=-1;
    if(dato!=NULL)
    {
        valor = dato->a;
    }

    return valor;
}

char* get_b(eDato* dato)
{
    char* valor;
    if(dato!=NULL)
    {
        valor=dato->b;
    }
    return valor;
}
