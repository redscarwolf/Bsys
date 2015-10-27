/*stringsort.c*/

#include <stdio.h>
#include <stdlib.h> /*sprintf*/
#include <time.h>
#include <math.h>
#include <string.h>


int main (int argc , char *argv[])
{
    /*Deklarationen*/
    int n;
    char **a; /*Array fuer Zeiger, die wiederum char-Arrays enthalten*/ 
    int m; /*laenge des vom sprintf benötigten Speicherplatzes fuer den String */

    int tmp; /*fuer temporaere Arbeiten*/
    char* stmp;/*fuer temporaere Arbeiten mit Strings*/
    char* buffer;/*fuer gebufferte Stringausgabe*/
    int i; /*itterrierer fuer for außen*/
    int j; /*itterrierer fuer for innen*/
    
    srand((unsigned int) time(NULL)); /*initialisieren des Random*/
    
    /*Check*/
    if ( argc != 2)
    {
        printf("Falscher Aufruf. Es darf nur ein Argument uebergeben werden.");
        return 1;
    }

    

    /*Initialisierung*/
    n = atoi(argv[1]);
    if (n == 0) {/*um eingabe 0 zu verhindern*/
        printf("Falscher Aufruf. Es darf nur ein Argument uebergeben werden.");
        return 1; 
    }
    
    a = (char**) malloc( n * sizeof(char*));
    if (a == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
    }

    m = strlen(argv[1]) + 1; /* Die +1 hat mit /0 zu tun*/

    stmp = (char*) malloc (m * sizeof(char));
    if (stmp == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
    }

    
    /*String Wuerfeln*/

    for (i = 0; i < n ; ++i)
    {
        a[i] = (char*) malloc (m * sizeof(char));
        if (a[i] == NULL)
        {
            printf("Speicherreservierung fehlgeschlagen!\n");
        }

        /*tmp = rand() % ( (int) pow(10,n) );*/ /*pow steht fuer Potenz 10^n | der Rest von rand() bei einer Zahl von n Stellen. Damit ist gewährleistet, dass Random Zahl nicht ueber n Zeichen geht.*/
        tmp = rand() % n;
        sprintf(a[i],"%d",tmp); /*1arg: wo speicher ich rein? 2arg: was schreibe ich rein. 3arg: welche Variable wird bei 2arg rein geschrieben?*/
        printf("%p : %s\n", a[i], a[i]); /*adresse des Elemnts und !!!!Wert des Elements ausgegeben als String*/
        
    }
    

    /*Strings sortieren*/
    for (i = n; i > 1; i--)
        {
            for (j = 0; j < i -1; ++j)
            {
                if (strcmp( a[j], a[j+1] ) > 0)
                {
                    /*Werte tauschen*/
                    /*TODO: Unterschied??? memcpy(stmp, a[j+1], sizeof a[j+1]);*/
                    strcpy(stmp, a[j+1]); /*merke/rette mir Zeiger auf Inhalt von a[j+1] | !!FALSCH!!stmp = a[j+1];!!! keinen Zeiger darauf machen! sondern Werte KOPIEREN*/
                    strcpy(a[j+1],a[j]);
                    /*a[j+1] = a[j];*/ /*Einem Wert einen Wert zuweisen geht nicht!*/
                    strcpy(a[j], stmp);
                }
            }
        }
    
    /*String ausgabe mit EINEM String*/
    /*ohne buffern*/
    printf("\n");
    for (i = 0; i < n ; ++i)
    {
        printf("%p : %s\n", a[i], a[i]);
    }
    printf("\n");
    
    /*zusammenbauen mit strcat*/
    /*initialisierung von buffer*/
    buffer = (char*) malloc (m * n * sizeof(char)); /* m  * 'n-Anzahl'| ist aber worstcase*/
    if (buffer == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
    }
    /*zusammenbauen*/
    strcpy(buffer,a[0]);
    for (i = 1; i < n ; ++i)
    {
        if (strcmp(a[i], a[i-1]) == 0)
        {
            strcat(buffer,"*");
        }
        else
        {
            strcat(buffer," ");
            strcat(buffer,a[i]);
        }
    }
    printf("%p : %s\n", buffer, buffer);

    
    
    /*free-for schleife ueber alle a[i] und free(a)*/
    for (i = 0; i < n; ++i)
    {
        free(a[i]);
    }
    free(a);
    free(stmp);
    free(buffer);
    return 0;
}