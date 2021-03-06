
#include <stdio.h>

/*#include <stddef.h>*/

int main(void) {
    /*int*/
	int a = 1;
	short int b = -2;
	long int c = 3L;
    
	unsigned int d = 0xfffU;
	unsigned short int e = 0xffffU;
	unsigned long int f = 2000UL;
	
	/*float*/
	float g = 1.0F;
	double h = -2.7;
	long double i = 5.345L;
	
	/*char (alle immer 1 Byte = 8Bit groß)*/
	char j = '@'; 
	signed char k = 127; /* von -2^7 bis 2^7-1 ist wie der Typ "byte" bei Java*/
	unsigned char l = 0xff; /* in 2er komplement wäre es -1 */
	
	const char* s = "Hallo"; /* muss const sein für c++*/
	
	/*Ausgabe aller 14 Variablen mit
	Adresse, Platzbedarf, Typ, Namen, Wert*/
    
	/* zu a*/
	printf("%p, Platz von a: %lu, ", (void*) &a, (unsigned long) sizeof a);
	printf("Typ von a: int, Name von a: ?, Wert von a: %d\n", a);

    /* zu b*/
    printf("%p, Platz von b: %lu, ", (void*) &b, (unsigned long) sizeof b);
    printf("Typ von b: short int, Name von b: ?, Wert von b: %d\n", b);

    /* zu c*/
    printf("%p, Platz von c: %lu, ", (void*) &c, (unsigned long) sizeof c);
    printf("Typ von c: long int, Name von c: ?, Wert von c: %ld\n", c);

    /* zu d*/
    printf("%p, Platz von d: %lu, ", (void*) &d, (unsigned long) sizeof d);
    printf("Typ von d: unsigned int, Name von d: ?, Wert von d: %d\n", d);

    /*zu e*/
    printf("%p, Platz von e: %lu, ", (void*) &e, (unsigned long) sizeof e);
    printf("Typ von e: unsigned short int, Name von e: ?, Wert von e: %d\n", e);

    /* zu f*/
    printf("%p, Platz von f: %lu, ", (void*) &f, (unsigned long) sizeof f);
    printf("Typ von f: unsigned long int, Name von f: ?, Wert von f: %lu\n", f);

    
    /* zu g*/
    printf("%p, Platz von g: %lu, ", (void*) &g, (unsigned long) sizeof g);
    printf("Typ von g: float, Name von g: ?, Wert von g: %g\n", g);
    
    /* zu h*/
    printf("%p, Platz von h: %lu, ", (void*) &h, (unsigned long) sizeof h);
    printf("Typ von h: double, Name von h: ?, Wert von h: %g\n", h);

    /* zu i*/
    printf("%p, Platz von i: %lu, ", (void*) &i, (unsigned long) sizeof i);
    printf("Typ von i: long double, Name von i: ?, Wert von i: %Lg\n", i);
    /**/

    
    /* zu j*/
    printf("%p, Platz von j: %lu, ", (void*) &j, (unsigned long) sizeof j);
    printf("Typ von j: char, Name von j: ?, Wert von j: %c\n", j);

    /* zu k*/
    printf("%p, Platz von k: %lu, ", (void*) &k, (unsigned long) sizeof k);
    printf("Typ von k: signed char, Name von k: ?, Wert von k: %d\n", k);

    /* zu l*/
    printf("%p, Platz von l: %lu, ", (void*) &l, (unsigned long) sizeof l);
    printf("Typ von l: unsigned char, Name von l: ?, Wert von l: %d\n", l);

    /* zu s*/
    printf("%p, Platz von s: %lu, ", (void*) &s, (unsigned long) sizeof s);
    printf("Typ von s: char*, Name von s: ?, Wert von s: %s\n", s);

    /* zu *s */
    /*printf("%p, Platz von *s: %lu, ", (void*) &*s, (unsigned long) sizeof *s);
    printf("Typ von *s: char[], Name von *s: ?, Wert von *s: %c\n", *s);*/
    
    /*printf("#######%d\n", sizeof(int));
    printf("#######%d\n", sizeof(long) != sizeof(char*));
    printf("#######%d\n", sizeof(char*)); */
    
    /* Abfrage ob ILP32 oder LP64 oder keins von beidem */
    if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(char*) == 4) {
        printf("ILP32-Datenmodell\n");
    } else if (sizeof(int) == 4 && sizeof(long) == 8 && sizeof(char*) == 8) {
        printf("LP64-Datenmodell\n");
    } else {
        printf("es liegt kein ILP32- bzw. LP64-Datenmodell vor.\n");
    }
    
	
	return 0;
}