/*
 * funktionsPointer.c
 *
 * Autor: Marcel
 * Erstellt am: 23.10.2015
 */
 
#include <stdio.h> 

static char *Hallo(void)
{
  return "hallo";
}
static char *Ciao(void)
{
  return "ciao";
}



int main( int argc, char **argv )
{
  char *(*GetString)(void);
  GetString = Hallo; /*Pointer wird Funktion uebergeben*/
  printf("%s\n", GetString() );
  GetString = Ciao;
  printf("%s\n", GetString() );
  return 0;
}