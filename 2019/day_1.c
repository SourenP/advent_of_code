#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WEIGHTS_SIZE 2024
#define LINE_SIZE 10

int fuel_sum() {
    int weights[WEIGHTS_SIZE];

    // Read in weights from stdin
    char line[LINE_SIZE];
    int count = 0;
    while (fgets(line, LINE_SIZE, stdin) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        sscanf(line, "%d", &weights[count++]);
    }

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += (weights[i] / 3) - 2;
    }
    return sum;
}

int main(void) {
    printf("Sum of fuel requirements: %d\n", fuel_sum());
}
