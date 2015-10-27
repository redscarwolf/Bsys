/*stringsort-optimiert.c*/

#include <stdio.h>
#include <stdlib.h> /*sprintf*/
#include <time.h>
#include <math.h>
#include <string.h>

int main (int argc , char *argv[])
{
    /*Deklarationen*/
    int n;
    int m; /*laenge des vom sprintf benötigten Speicherplatzes fuer den String */
    
    char* s;/*NEU| ein langer String fuer alle Werte*/

    int tmp; /*fuer temporaere Arbeiten*/
    char* stmp;
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

    m = strlen(argv[1]) + 1; /* Die +1 hat mit /0 zu tun*/

    s = (char*) malloc ( m * n * sizeof(char));/*groesse*/
    if (s == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }

    stmp = (char*) malloc (m * sizeof(char));
    if (stmp == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }

    /*String Wuerfeln*/

    for (i = 0; i < n ; ++i)
    {
        tmp = rand() % n;
        sprintf(s + (i * m),"%d",tmp); /*1arg: wo speicher ich rein? 2arg: was schreibe ich rein. 3arg: welche Variable wird bei 2arg rein geschrieben?*/
        printf("%s ", s + (i * m)); /*adresse des Elemnts und !!!!Wert des Elements ausgegeben als String*/

    }
    printf("\n");

    /*Strings sortieren*/
    for (i = n; i > 1; i--)
    {
        for (j = 0; j < i -1; ++j)
        {
            if (strcmp( s + (j*m), s + ( (j+1) * m) ) > 0)
            {
                memcpy(stmp, s + ( (j+1) * m) , m );
                memcpy(s + ( (j+1) * m), s + (j*m), m);
                memcpy(s + (j*m), stmp , m);
            }
        }
    }


    /*initialisierung von buffer*/
    buffer = (char*) malloc (m * n * sizeof(char)); /* m  * 'n-Anzahl'| ist aber worstcase*/
    if (buffer == NULL)
    {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }
        
    /*zusammenbauen*/
    strcpy(buffer,s);
    for (i = 1; i < n ; ++i)
    {
        if (strcmp( s + (i*m), s + ( (i-1) * m) ) == 0)
        {
            strcat(buffer,"*");
        }
        else
        {
            strcat(buffer," ");
            strcat(buffer,s + (i*m));
        }
    }
    printf("%p : %s\n", buffer, buffer);

    /*free*/
    free(s);
    free(stmp);
    free(buffer);
    return 0;
}