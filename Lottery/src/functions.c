#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "structs.h"
#include "globalVariables.h"

void menu() {
	int action;
	printf("\nSelect your action:\n");
	printf("0 - Quit\n");
	printf("1 - Get some money\n");
	printf("2 - Byu tickets\n");
	printf("3 - Check tickets\n");
	printf("4 - See statistics\n");

	scanf("%d", &action);

	switch (action) {
	case 0:
		break;
	case 1:
		getMoney();
		break;
	case 2:
		buyTickets();
		break;
	case 3:
		checkTickets();
		break;
	case 4:
		seeStatistics();
		break;
	default: menu();
	}
}

void getMoney() {
	printf("You are working hard now...\n");
	sleep(1);
	printf("Working day is not over yet!\n");
	sleep(1);
	printf("Still at work...\n");
	sleep(1);
	printf("Your boss says :\"Here is you money!\"\n");
	money = (rand() % 100)+10;
	printf("You have now %d Eur\n", money);
	menu();
}

Ticket generateTicket() {
	int i, j;
	int prizes[] = { 1, 2, 5, 10, 20, 30, 40, 50};
	LOOP: if (ticketId < numberOfTicketsInSeries) {
		Ticket ticket;
		ticket.win = false;
		ticket.prize = 0;
		ticket.id = ++ticketId;

		for (i = 0; i < 5; i++) {
			for (j = 0; j < 2; j++) {
				ticket.columns[i][j] = prizes[rand() % 8];
			}
			if (ticket.columns[i][0] == ticket.columns[i][1]) {
				ticket.win = true;

				switch (ticket.columns[i][0]) {
				case 50:
					if (prizeCounter.p50 < prizeCounter.p50Max) {
						prizeCounter.p50++;
					} else {
						ticketId--;
						goto LOOP;
					}
					break;
				case 40:
					if (prizeCounter.p40 < prizeCounter.p40Max) {
						prizeCounter.p40++;
					} else {
						ticketId--;
						goto LOOP;
					}
					break;
				case 30:
					if (prizeCounter.p30 < prizeCounter.p30Max) {
						prizeCounter.p30++;
					} else {
						ticketId--;
						goto LOOP;
					}
					break;
				case 20:
					if (prizeCounter.p20 < prizeCounter.p20Max) {
						prizeCounter.p20++;
					} else {
						ticketId--;
						goto LOOP;
					}
					break;
				case 10:
					if (prizeCounter.p10 < prizeCounter.p10Max) {
						prizeCounter.p10++;
					} else {
						ticketId--;
						goto LOOP;
					}
					break;
				case 5:
					if (prizeCounter.p5 < prizeCounter.p5Max) {
						prizeCounter.p5++;
					} else {
						ticketId--;
						goto LOOP;
					}
					break;
				case 2:
					if (prizeCounter.p2 < prizeCounter.p2Max) {
						prizeCounter.p2++;
					} else {
						ticketId--;
						goto LOOP;
					}
					break;
				case 1:
					if (prizeCounter.p1 < prizeCounter.p1Max) {
						prizeCounter.p1++;
					} else {
						ticketId--;
						goto LOOP;
					}
					break;
				}
				ticket.prize += ticket.columns[i][0];
			}
		}
		money += ticket.prize;
		return ticket;
	} else {
		printf(
				"no more tickets available in this series, starting new series\n");
		printSeriesResults();
		ticketId = 0;
		setPrizeCounter();
		goto LOOP;
	}
}

void setPrizeCounter() {
	prizeCounter.p50 = 0;
	prizeCounter.p40 = 0;
	prizeCounter.p30 = 0;
	prizeCounter.p20 = 0;
	prizeCounter.p10 = 0;
	prizeCounter.p5 = 0;
	prizeCounter.p2 = 0;
	prizeCounter.p1 = 0;
	prizeCounter.p50Max = 1;  //2;
	prizeCounter.p40Max = 1; //35;
	prizeCounter.p30Max = 2; //400;
	prizeCounter.p20Max = 2; //4000;
	prizeCounter.p10Max = 3; //12000;
	prizeCounter.p5Max = 4; //31500;
	prizeCounter.p2Max = 5; //120000;
	prizeCounter.p1Max = 10; //273000;
}

void buyTickets() {
	int numberOfTickets;
	printf("You have now %d Eur\n", money);
	printf("How many tickets do you want to buy? (1 ticket - 2 Euro)\n");
	scanf("%d", &numberOfTickets);

	if (money >= numberOfTickets * ticketPrice) {
		money -= numberOfTickets * ticketPrice;
		numberOfTicketsBought += numberOfTickets;
		printf("You bought %d tickets, good luck\n", numberOfTickets);
	} else {
		printf("You are too poor for this\n");
	}
	menu();
}

void checkTickets() {
	if (numberOfTicketsBought > 0) {
		int i, j, k;
		for (i = 0; i < numberOfTicketsBought; i++) {
			Ticket ticket = generateTicket();
			printf("Checking ticket ID:%d\n", ticket.id);
			for (j = 0; j < 5; j++) {
				for (k = 0; k < 2; k++) {
					printf("%d ", ticket.columns[j][k]);
				}
				printf("\n");
			}
			printf("Ticket ID %d -wins %d Eur\n", ticket.id, ticket.prize);
			printf("\n--------\n");
			generateHTML(ticket);
		}
	} else {
		printf("You don't have any tickets, go  buy one\n");
	}
	numberOfTicketsBought = 0;
	menu();
}

void calculateTotalWins() {
	int sum = prizeCounter.p1 * 1 + prizeCounter.p2 * 2 + prizeCounter.p5 * 5
			+ prizeCounter.p10 * 10 + prizeCounter.p20 * 20
			+ prizeCounter.p30 * 30 + prizeCounter.p40 * 40
			+ prizeCounter.p50 * 50;
	int total = prizeCounter.p1Max * 1 + prizeCounter.p2Max * 2 + prizeCounter.p5Max * 5
				+ prizeCounter.p10Max * 10 + prizeCounter.p20Max * 20
				+ prizeCounter.p30Max * 30 + prizeCounter.p40Max * 40
				+ prizeCounter.p50Max * 50;
	printf("Possible to win maximum %d Eur\n", total);
	printf("Totally won at this point of time:%d Eur\n", sum);
}

void printSeriesResults() {
	printf(" 1st prizes total possible %d - won: %d \n",prizeCounter.p50Max, prizeCounter.p50);
	printf(" 2nd prizes total possible %d - won: %d \n",prizeCounter.p40Max,prizeCounter.p40);
	printf(" 3rd prizes total possible %d - won: %d \n",prizeCounter.p30Max, prizeCounter.p30);
	printf(" 4th prizes total possible %d - won: %d \n",prizeCounter.p20Max, prizeCounter.p20);
	printf(" 5th prizes total possible %d - won: %d \n",prizeCounter.p10Max, prizeCounter.p10);
	printf(" 6th prizes total possible %d - won: %d \n",prizeCounter.p5Max, prizeCounter.p5);
	printf(" 7th prizes total possible %d - won: %d \n",prizeCounter.p2Max, prizeCounter.p2);
	printf(" 8th prizes total possible %d - won: %d \n",prizeCounter.p1Max, prizeCounter.p1);
}

void seeStatistics() {
	calculateTotalWins();
	printSeriesResults();
	menu();
}

void generateHTML(Ticket ticket) {
	/*generate file name*/
	int i, j;
	char filename[10] = { 0 };
	char idAsString[4] = { 0 };
	sprintf(idAsString, "%d", ticket.id);

	strcat(filename, idAsString);
	strcat(filename, ".html");

	/*open file*/
	if ((ticketHTML = fopen(filename, "w")) == NULL) {
		printf("Error opening file");
		exit(1);
	}

	/*write to file*/
	fprintf(ticketHTML,
			"<!DOCTYPE html>\r\n <html>\r\n <head> \r\n <title> %d </title> \r\n <style> table,th, td {border: solid thin green; border-collapse:collapse;font-size:80%} </style>\r\n </head> \r\n <body> \r\n",
			ticket.id);
	fprintf(ticketHTML, "\r <h1> EURO ŠANSAS <\h1> \r\n");

	fprintf(ticketHTML, "\r <img src=\"laimek.jpeg\" width=\"35%\">");

	fprintf(ticketHTML, "\r <table>\r\n");
	fprintf(ticketHTML, "<tr>");
	for (i = 0; i < 5; i++) {
		fprintf(ticketHTML, "<th> %d žaidimas </th>", i + 1);
	}
	fprintf(ticketHTML, "</tr>");

	for (j = 0; j < 2; j++) {
		fprintf(ticketHTML, "<tr>");
		for (i = 0; i < 5; i++) {
			fprintf(ticketHTML, "<td> %d </td>", ticket.columns[i][j]);
		}
		fprintf(ticketHTML, "</tr>");
	}

	fprintf(ticketHTML, "</table>\r\n");

	if (ticket.win) {
		fprintf(ticketHTML, "\r <h2> Jūs laimėjote %d Eur <\h2> \r\n",
				ticket.prize);
	} else {
		fprintf(ticketHTML, "\r <h2> Jūsų bilietas nieko nelaimėjo <\h2> \r\n");
	}
	fprintf(ticketHTML, "</body> \r\n </html>");
	fclose(ticketHTML);
}
