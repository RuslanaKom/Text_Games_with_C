
#include <stdbool.h>

typedef struct {
	int id;
	int columns[5][2];
	bool win;
	int prize;
} Ticket;

typedef struct {
	int p50;
	int p40;
	int p30;
	int p20;
	int p10;
	int p5;
	int p2;
	int p1;
	int p50Max;
	int p40Max;
	int p30Max;
	int p20Max;
	int p10Max;
	int p5Max;
	int p2Max;
	int p1Max;
} PrizeCounter;



