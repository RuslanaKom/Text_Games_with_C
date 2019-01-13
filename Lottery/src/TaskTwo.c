#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "functions.h"

int main(void) {
	time_t t;
	srand((unsigned) time(&t));
	setPrizeCounter();
 printf("Loterija EURO ŠANSAS\n");
 printf("Loterijos biliete yra 10 atspausdintų skaičių - 5 stulpeliai po du skaičius kiekiviename.\n");
 printf("Jei stulpelyje yra du vienodi skaičiai - žaidėjas laimi sumą, atitinkančią sutampančius skaičius.\n");
 printf("Galimi laimėjimai: 1,2,5,10,20,30,40,50 EUR.\nJei skaičiai sutampa keliuose bilieto stulpeliuose - laimėjimai sumuojami.\n");

	menu();

}

