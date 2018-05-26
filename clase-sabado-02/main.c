#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[50];
    int estado;
}ePersona;

int main()
{
    ePersona listaPesonas[4] = {{1,"juan",1},{2,"maria",0},{3,"jose",1},{0,"",0}};
    ePersona lectura[4];
    int i;
    for(i=0;i<3;i++)
    {
        lectura[i].estado=0;
    }
    int cont=0;
    FILE* f;

    f=fopen("miArchivo.dat","wb");

    for(i=0;i<4;i++)///para guardar los que tiene estado 1
    {
        if(listaPesonas[i].estado==1)///alta uno por uno
        {
            ///fwrite(&listaPesonas[i],sizeof(ePersona),1,f);///&cuando es un solo valor de estructura
            cont++;
        }
    }

    fwrite(&cont,sizeof(int),1,f);

    for(i=0;i<4;i++)///para guardar los que tiene estado 1
    {
        if(listaPesonas[i].estado==1)///alta uno por uno
        {
            fwrite(&listaPesonas[i],sizeof(ePersona),1,f);///&cuando es un solo valor de estructura
        }
    }

    fclose(f);


   f=fopen("miArchivo.dat","rb");

    fread(&cont,sizeof(int),1,f);

    fread(lectura,sizeof(ePersona),cont,f);

    fclose(f);

    for(i=0;i<4;i++)
    {
        if(lectura[i].estado==1)///mostrar uno por uno con estado 1
        {
            printf("%d---%s\n",lectura[i].id,lectura[i].nombre);
        }
    }
    return 0;
}
