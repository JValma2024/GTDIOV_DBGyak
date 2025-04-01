#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main() {
    char filename[100];
    char line[MAX];
    FILE *fp;

    printf("Add meg a fajl nevet: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Nem sikerült megnyitni a fajlt");
        return 1;
    }

    printf("Add meg a neved:\n");
    fgets(line, sizeof(line), stdin);
    fputs(line, fp);

    printf("Add meg a Neptun kodod(a '#' karakterrel fejezd be):\n");
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (line[0] == '#' && line[1] == '\n') break;
        fputs(line, fp);
    }

    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Nem sikerult megnyitni a fajlt");
        return 1;
    }

    printf("\nA fajl tartalma nagybetusen:\n");

    while (fgets(line, sizeof(line), fp)) {
        for (int i = 0; line[i] != '\0'; i++) {
            putchar(toupper(line[i]));
        }
    }

    fclose(fp);
    return 0;
}

