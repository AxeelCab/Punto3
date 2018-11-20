#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


// A C Z
// F G

//A   C   F

int main()
{
    char guardado1[50];
    char guardado2[50];
    int g1=0;
    int g2=0;
    char aux[50];
    int leer1=1;
    int leer2=1;
    FILE*archivo;
    archivo=fopen("names1.txt","r");
    FILE*archivo2;
    archivo2=fopen("names2.txt","r");
    FILE*archivo3;
    archivo3=fopen("names3.txt","w");
    while(1)
    {
        if(leer1==1){
            fgets(guardado1,50,archivo);
            fflush(stdin);
            g1=atoi(guardado1);
        }
        if(leer2==1){
            fgets(guardado2,50,archivo2);
            fflush(stdin);
            g2=atoi(guardado2);
        }


        if(strcmp(guardado1,guardado2)<=0){
            fprintf(archivo3,"%s",guardado1);
            printf("%s",guardado1);
            leer1=1;leer2=0;
        }
        if(strcmp(guardado1,guardado2)>0){
            fprintf(archivo3,"%s",guardado2);
            printf("%s",guardado2);
            leer1=0;leer2=1;
        }
        if(feof(archivo))
        {
            printf("\n%s",guardado2);
                while(!feof(archivo2))
                {
                    fgets(guardado2,50,archivo2);
                    printf("%s",guardado2);
                    fprintf(archivo3,"%s",guardado2);
                }
                break;
        }

        if(feof(archivo2))
        {
                while(!feof(archivo))
                {
                    fgets(guardado1,50,archivo);
                    printf("%s",guardado1);
                    fprintf(archivo3,"%s",guardado1);
                }
                break;
        }
    }
    return 0;
}
