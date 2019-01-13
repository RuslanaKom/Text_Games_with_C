#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[50];
	char description[255];
} Animal;

FILE *file;
Animal animal;
Animal animalArray[100];

void calculateDataBase();
void writeNewAnimal(char fileName[], int kiekis);
int guessFromFile(char fileName[], int kiekis);

const char nam_malonumas1[] = "files/naminiaimalonumas.bin";
const char nam_ukis2[] = "files/naminiaiukis.bin";
const char lauk_plesrus3[] = "files/laukiniaiplesrus.bin";
const char lauk_kanopiniai4[] = "files/laukiniaikanopiniai.bin";
const char lauk_kiti5[] = "files/laukiniaikiti.bin";

int kiekis1 = 0;
int kiekis2 = 0;
int kiekis3 = 0;
int kiekis4 = 0;
int kiekis5 = 0;

char answer[5] = { 0 };
int guessed = 0;
int i, j;

int main(void) {

	calculateDataBase();
	//writeNewAnimal(lauk_kiti5, kiekis5);


	printf("Sugalvokite žinduolį gyvenantį Lietuvoje\n");
	printf("Ar jis naminis?\n");
	scanf("%s", answer);

	if (strcmp(answer, "taip") == 0) {
		printf("Ar jis laikomas dėl malonumo?\n");
		scanf("%s", answer);
		if (strcmp(answer, "taip") == 0) {
			guessFromFile(nam_malonumas1, kiekis1);
		} else {
			guessFromFile(nam_ukis2, kiekis2);
		}
	}

	else {
		printf("Ar tai plėšrūnas?\n");
		scanf("%s", answer);
		if (strcmp(answer, "taip") == 0) {
			guessFromFile(lauk_plesrus3, kiekis3);
		} else {
			printf("Ar jis turi kanopus?\n");
			scanf("%s", answer);
			if (strcmp(answer, "taip") == 0) {
				guessFromFile(lauk_kanopiniai4, kiekis4);
			} else {
				guessFromFile(lauk_kiti5, kiekis5);
			}
		}
	}
}

void calculateDataBase() {
	Animal animalToCount;

	file = fopen(nam_malonumas1, "rb");
	while (!feof(file)) {
		fread(&animalToCount, sizeof(Animal), 1, file);
		kiekis1++;
	}
	fclose(file);

	file = fopen(nam_ukis2, "rb");
	while (!feof(file)) {
		fread(&animalToCount, sizeof(Animal), 1, file);
		kiekis2++;
	}
	fclose(file);
	file = fopen(lauk_plesrus3, "rb");
	while (!feof(file)) {
		fread(&animalToCount, sizeof(Animal), 1, file);
		kiekis3++;
	}
	fclose(file);
	file = fopen(lauk_kanopiniai4, "rb");
	while (!feof(file)) {
		fread(&animalToCount, sizeof(Animal), 1, file);
		kiekis4++;
	}
	fclose(file);
	file = fopen(lauk_kiti5, "rb");
	while (!feof(file)) {
		fread(&animalToCount, sizeof(Animal), 1, file);
		kiekis5++;
	}
	fclose(file);
}

void writeNewAnimal(char fileName[], int kiekis) {
	Animal animalToWrite;
	file = fopen(fileName, "a+b");
	if (!file) {
		printf("Unable to open file!");
		exit(0);
	}
	animalToWrite.id = kiekis;
	printf("\nPasiduodu!\nKokį žinduolį sugalvojote?\n");
	scanf(" %[^\n]", animalToWrite.name);
	printf("\nTrumpai jį aprašykite?\n");
	scanf(" %[^\n]", animalToWrite.description);
	fwrite(&animalToWrite, sizeof(Animal), 1, file);
	fclose(file);
}

int guessFromFile(char fileName[], int kiekis) {

	file = fopen(fileName, "rb");
	for (j = 0; j < kiekis; j++) {
		fread(&animalArray[j], sizeof(Animal), 1, file);
	}
	for (i = 0; i < kiekis - 1; i++) {
		printf("Ar jis %s?\n", animalArray[i].description);
		scanf("%s", answer);
		if (strcmp(answer, "taip") == 0) {
			printf("Tai %s?\n", animalArray[i].name);
			scanf("%s", answer);
			if (strcmp(answer, "taip") == 0) {
				guessed = 1;
				break;
			}
		}
	}
	if (guessed) {
		printf("Kompiuteris laimėjo!\n");
		return 0;
	} else {
		writeNewAnimal(fileName, kiekis);
		return 0;
	}
}

