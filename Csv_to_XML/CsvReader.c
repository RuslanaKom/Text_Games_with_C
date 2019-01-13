#include <stdio.h>
#include <string.h>

int countTags(char firstLine[]);

/* when starting the program enter input and output file names */

int main(int agrc, char *argv[]) {

	/*get filenames as parameters*/

	FILE *input;
	FILE * output;

	if ((input = fopen(argv[1], "r")) == NULL) {
		printf("Error opening file");
		exit(1);
	}

	if ((input = fopen(argv[2], "w")) == NULL) {
		printf("Error opening file");
		exit(1);
	}

	/*if lazy use hardcoded filenames*/
//	FILE * input = fopen("files/doctors.csv", "r");
//	FILE * output = fopen("files/xml.xml", "w");
//	FILE * input = fopen("files/DAKRPDiplomaiPagalDiplomoTipaKaita.csv", "r");
//	FILE * output = fopen("files/xml.xml", "w");

	char firstLine[255] = { 0 };
	char otherLine[2000] = { 0 };
	int numberOfTags = 0;
	int i = 0, z = 0, n = 0;

	/*read first line, get rid of '\n'*/
	fgets(firstLine, sizeof(firstLine), input);
	n = strlen(firstLine) - 1;
	char tagLine[n + 1];
	for (i = 0; i < n; i++) {
		tagLine[i] = 0;
	}
	strncpy(tagLine, firstLine, n);
	tagLine[n] = '\0';

	/*count number of tags */
	numberOfTags = countTags(tagLine);

	/*make arrays of pointers for tags and data */
	char * tags[numberOfTags];
	char * data[numberOfTags];

	/*get array of tags from first line*/
	z = 0;
	tags[z] = strtok(tagLine, ",");
	while (z < numberOfTags - 1) {
		z++;
		tags[z] = strtok(NULL, ",");
	}

	/*read data, write to xml file*/
	int lineCount = 0;
	for (i = 0; i < sizeof(otherLine); i++) {
		otherLine[i] = 0;
	}
	while ((fgets(otherLine, sizeof(otherLine), input)) != NULL) {
		lineCount++;
		/* get data from other lines*/
		n = strlen(otherLine) - 1;
		char dataLine[n + 1];
		for (i = 0; i < n; i++) {
			dataLine[i] = 0;
		}
		strncpy(dataLine, otherLine, n);
		dataLine[n] = '\0';

		/* get array of data from other lines*/
		z = 0;
		data[z] = strtok(dataLine, ",");
		while (z < numberOfTags - 1) {
			z++;
			data[z] = strtok(NULL, ",");
			if (data[z] == NULL) {
				data[z] = "-";
			}
		}

		/*write to file*/
		fputs("<object>\n", output);
		for (i = 0; i < numberOfTags; i++) {
			fputs("<", output);
			fputs(tags[i], output);
			fputs(">", output);
			fputs(data[i], output);
			fputs("</", output);
			fputs(tags[i], output);
			fputs(">\n", output);
		}
		fputs("</object>\n", output);
		printf("Logging: writing data line %d to file %s\n", lineCount,
				argv[2]);
	}
	fclose(input);
	fclose(output);
	printf("Logging: output file %s is ready\n", argv[2]);
	return 1;
}

int countTags(char firstLine[]) {
	int i;
	int number = 0;
	for (i = 0; i < strlen(firstLine); i++) {
		if (firstLine[i] == ',') {
			number++;
		}
	}
	return number + 1;
}

