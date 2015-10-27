/*
 * inparam.c
 *
 * Beispiel-Programm Eingabe-Parameter
 *
 * Autor: H.Drachenfels
 * Erstellt am: 7.5.2015
 */

#include <stdio.h>

struct date
{
    int day;
    const char *month;
    int year;
};

typedef struct date date;

void print_int(int n);
void print_string(const char *s);
void print_int_array(int size, const int a[]);
void print_date(const date *d);
void print_int_array_array(int n, const int xy[][2]);
void print_int_matrix(int n, int m, const int *xy);
void print_int_array_pointer(int n, int m, const int * const *xy);

int main(void)
{
    int n = 10;
    const char* s = "Hallo"; /* C++ verlangt const */
    int a[2] = {10, 11};
    date d = {25, "Februar", 2011};
    int aa[3][2] = {{10, 11}, {20, 21}, {30, 31}};
    int *ap[3];
    ap[0] = aa[0];
    ap[1] = aa[1];
    ap[2] = aa[2];

    print_int(n);
    print_string(s);
    print_int_array(2, a);
    print_date(&d);
    print_int_array_array(3, (const int(*)[2]) aa); /* gcc will cast */
    print_int_matrix(3, 2, &aa[0][0]);
    print_int_array_pointer(3, 2, (const int*const*) ap); /* gcc will cast */

    return 0;
}


void print_int(int n)
{
    printf("%d\n", n);
    n = 0; /* ok, lokale Variable */
}


void print_string(const char *s)
{
    printf("%s\n", s);
    /* s[0] = '\0'; Fehler, Zeiger auf konstante Zeichenkette */
    s = NULL; /* ok, lokale Variable */
}


void print_int_array(int size, const int a[])
{
    int i;

    for (i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    /* a[0] = 0; Fehler, Zeiger auf konstantes Feld */
    a = NULL; /* ok, lokale Variable */
}


void print_date(const date *d)
{
    printf("%d. %s %d\n", d->day, d->month, d->year);
    /* d->day = 0; Fehler, Zeiger auf konstanten Wert */
}


void print_int_array_array(int n, const int xy[][2])
{
    int i, j;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            printf("%d ", xy[i][j]);
        }
    }

    printf("\n");

    /* xy[0][0] = 0; Fehler, Zeiger auf konstantes Feld */
    /* xy[0] = 0; Fehler, Zeiger auf zweidimensionales Feld */
    xy = NULL; /* ok, lokale Variable */
}


void print_int_matrix(int n, int m, const int *xy)
{
    int i, j;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            printf("%d ", xy[i * m + j]);
        }
    }

    printf("\n");
}


void print_int_array_pointer(int n, int m, const int * const *xy)
{
    int i, j;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            printf("%d ", xy[i][j]);
        }
    }

    printf("\n");

    /* xy[0][0] = 0; Fehler, Zeiger auf konst. Zeiger auf konst. Feld */
    /* xy[0] = 0; Fehler, Zeiger auf konstanten Zeiger */
    xy = NULL; /* ok, lokale Variable */
}

