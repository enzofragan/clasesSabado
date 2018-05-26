#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char texto[50]="los pelos verdes de agustin, ponte la gorra";

    f=fopen("miHTML.html","w");

    /**fprintf(f,"<html><body><h1>");
    fprintf(f,"%s",texto);
    fprintf(f,"</h1></body></html>");*/

    fprintf(f,"<html><body><h1>%s</h1></body></html>",texto);

    fclose(f);
    return 0;
}
