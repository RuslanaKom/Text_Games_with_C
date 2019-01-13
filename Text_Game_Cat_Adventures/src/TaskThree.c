#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct {
	char name[50];
	int energy;
	int toilet;
	int pleasure;
} Cat;

Cat cat;
int randomAction;

void startCat();
void menu();
void sayMeow();
void standAtTheDoor();
void goToToilet();
void eat();
void doNotEat();
void printCatData();
void sharpenNailsAtSofa();
void catchMouse();
void makeUnpredictedAction();

int main(void) {
	time_t t;
	srand((unsigned) time(&t));
	printf("%130s","/ᐠ｡ꞈ｡ᐟ\\  \n");
	printf("%80s","INCREDIBLE ADVENTURES OF MR. CAT\n");
	sleep(1);
	printf("%90s","*********************************************\n");
	printf("%85s","Loose if energy=0   | 	Win	if pleasure=10\n");
	printf("%90s","*********************************************\n");
	sleep(2);
	printf("Hello kitty, you are awsome!\nWhat is your name?\n");
	scanf("%s", cat.name);
	startCat();
	menu();
}

void menu() {
	checkCatParameters();
	printCatData();
	int action;
	printf("0 - Quit  |  ");
	printf("1 - Say Meow  |  ");
	printf("2 - Catch Mouse  |  ");
	printf("3 - Sharpen Nails At Sofa  |  ");
	printf("4 - Make Unpredicted Action\n");

	scanf("%d", &action);

	switch (action) {
	case 0:
		exit(1);
		break;
	case 1:
		sayMeow();
		break;
	case 2:
		catchMouse();
		break;
	case 3:
		sharpenNailsAtSofa();
		break;
	case 4:
		makeUnpredictedAction();
		break;
	default:
		menu();
	}
}

void startCat() {
	cat.energy = 5;
	cat.toilet = 5;
	cat.pleasure = 0;
	menu();
}

void sayMeow() {
	printf("Meow Meow...\n");
	sleep(1);
	int choise;
	randomAction = rand() % 2;
	if (randomAction == 0) {
		printf("Stupid human opens door for you\n");
		sleep(1);
		printf(
				"What do you do?\n 1 - Stand in front of the open door\n 2 - Go outside to the toilet\n Any other key - unpredicted action\n");
		scanf("%d", &choise);
		switch (choise) {
		case 1:
			standAtTheDoor();
			break;
		case 2:
			goToToilet();
			break;
		default:
			makeUnpredictedAction();
		}

	} else {
		printf("Stupid human puts some food to your plate\n");
		sleep(1);
		printf(
				"What do you do?\n 1 - Eat \n 2 - Do not eat \n Any other key - unpredicted action\n");
		scanf("%d", &choise);
		switch (choise) {
		case 1:
			eat();
			break;
		case 2:
			doNotEat();
			break;
		default:
			makeUnpredictedAction();
		}
	}
}

void standAtTheDoor() {
	printf("You stand in front of open door\n");
	sleep(1);
	printf("Stupid human waits...\n");
	sleep(1);
	printf("Stupid human still waits...\n");
	sleep(1);
	printf("Stupid human gets angry and shuts the door..CLUCK \n");
	sleep(1);
	cat.pleasure++;
	cat.toilet++;
	menu();
}

void goToToilet() {
	printf("You go outside and find a sandbox for your toilet\n");
	sleep(1);
	printf("You return home, stupid human did not close the door\n");
	sleep(1);
	cat.toilet = 0;
	cat.energy -= 2;
	menu();
}

void eat() {
	printf("You eat your KittyKat, yummy!\n");
	sleep(1);
	printf("Om-nom-nom\n");
	sleep(1);
	cat.energy += 2;
	cat.pleasure += 2;
	cat.toilet += 2;
	menu();
}

void doNotEat() {
	printf("You turn around and go away from the plate\n");
	sleep(1);
	cat.energy--;
	cat.toilet++;
	menu();
}

void catchMouse() {
	printf("You see the mouse, you stay still\n");
	sleep(1);
	printf("You move slowly...\n");
	sleep(1);
	printf("You jump!\n");
	sleep(1);
	randomAction = rand() % 2;
	if (randomAction == 0) {
		printf("You are the best! Mouse is in your teeth\n");
		sleep(1);
		printf("Om-nom-nom\n");
		sleep(1);
		cat.energy++;
		cat.pleasure++;
		cat.toilet += 2;
		menu();
	} else {
		printf("Oh this mouse was very fast and lucky, it escaped\n");
		sleep(1);
		printf("Don't worry, you are still the best creature in galaxy\n");
		sleep(1);
		cat.energy -= 2;
		cat.pleasure--;
		cat.toilet++;
		menu();
	}
}

void sharpenNailsAtSofa() {
	printf("You approach a human's favourite sofa\n");
	sleep(1);
	printf("You start sharpening you nails....");
	sleep(1);
	printf("scrum...srcum...scrum\n");
	sleep(1);
	randomAction = rand() % 2;
	if (randomAction == 0) {
		printf("Oh no! Stupid human sees you doing this!\n");
		sleep(1);
		printf("You try to escape, but he catches you and shouts at you\n");
		sleep(1);
		printf("Stupid human! He ruined your pleasure\n");
		sleep(1);
		cat.pleasure -= 2;
		cat.energy--;
		cat.toilet++;
		menu();
	} else {
		printf("Stupid human did not see you this time \n");
		sleep(1);
		printf("Oh that's the pleasure!\n");
		sleep(1);
		cat.pleasure += 2;
		cat.energy--;
		cat.toilet++;
		menu();
	}
}

void checkCatParameters() {
	if (cat.energy > 10) {
		cat.energy = 10;
	}
	if (cat.energy <= 0) {
		cat.energy = 0;
		printf("\n /ᐠ –ꞈ–ᐟ\\ \n");
		printf("Your energy is low, you need to sleep\n");
		printf("You loose\n");
		printf(" /ᐠ –ꞈ–ᐟ\\ \n");
		sleep(1);
		printCatData();
		exit(1);
	}

	if (cat.toilet >= 10) {
		printf("\nYou want to toilet and cannot wait anymore\n");
		sleep(1);
		printf("You make a wet place on the carpet\n");
		sleep(1);
		printf("Stupid human shouts at you!\n");
		cat.toilet = 0;
		cat.pleasure -= 2;
	}
	if (cat.toilet < 0) {
		cat.toilet = 0;
	}

	if (cat.pleasure < 0) {
		cat.pleasure = 0;
	}
	if (cat.pleasure >= 10) {
		cat.pleasure = 10;
		printf("\n(=^ ◡ ^=)\n");
		printf("You have reached your satisfaction, %s!\n", cat.name);
		sleep(1);
		printf("You are happy now, you win!\n");
		printf("purrr  (=^ ◡ ^=)  purrr \n");
		sleep(1);
		printCatData();
		exit(1);
	}
}

void printCatData() {
	printf("___________________________\n");
	printf("/ᐠ｡ꞈ｡ᐟ\\ %20s\n", cat.name);
	printf("Energy: %17d\n", cat.energy);
	printf("Toilet: %17d\n", cat.toilet);
	printf("Pleasure: %15d\n", cat.pleasure);
	printf("___________________________\n");
}

void makeUnpredictedAction() {
	randomAction = rand() % 4;
	if (randomAction == 0) {
		printf("You jump high and run away \n");
		sleep(1);
		cat.energy -= 2;
		cat.toilet++;
		menu();
	} else if (randomAction == 1) {
		printf("Oh KittyGod,  your tail need washing right now!\n");
		sleep(1);
		printf("You lick your tail\n");
		sleep(1);
		cat.energy--;
		cat.pleasure++;
		cat.toilet++;
		menu();

	} else if (randomAction == 2) {
		printf("What a lovely piece of paper, catch catch!\n");
		sleep(1);
		printf("You play with paper\n");
		sleep(1);
		cat.energy--;
		cat.pleasure++;
		cat.toilet++;
		menu();
	} else {
		printf("You bite stupid human's leg\n");
		sleep(1);
		printf("Stupid human shouts at you \n");
		sleep(1);
		cat.energy--;
		cat.pleasure--;
		cat.toilet++;
		menu();
	}
}
