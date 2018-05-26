#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int escribirTexto(char* );
int leerTexto(char*);

int main()
{
    int r;
    int w;
    char txt[50];
    w=escribirTexto("hola a todos\nchao");

    if(w>0)
    {
        printf("guardo con exito\n");
    }
    else
    {
        printf("error");
    }

    r=leerTexto(txt);

    if(r==0)
    {
        printf("error");
    }
    else
    {
        printf("%s",txt);
    }

    return 0;
}
int escribirTexto(char* texto)
{
    FILE* pA;
    int ret=0;

    pA=fopen("archivo.txt","w");

    if(pA!=NULL)
    {
        ///fprintf(pA,"hola");
        fprintf(pA,"%s",texto);
        fclose(pA);
        ret=1;
    }

    return ret;
}

int leerTexto(char* texto)
{
    FILE* pAr;
    char t[100]="";
    int ret=0;

    pAr=fopen("archivo.txt","r");

    if(pAr!=NULL)
    {
        while(!feof(pAr))
        {
            fgets(t,50,pAr);
            strcat(texto,t);
        }
        fclose(pAr);
        ret=1;
    }

    return ret;
}
