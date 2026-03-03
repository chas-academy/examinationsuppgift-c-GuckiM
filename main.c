//Write your code in this file

#include <stdio.h>

struct Student {
    char name[11];
    int points[13];
    double average;
};

void formatName(char *s) {

    // Make first letter upprcase
    if (s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;

    // Make the rest lowercase
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }

}

int main () {

    struct Student s[5];
    double totalSum = 0;

    // Input. Stores the input in the Student struct array. Calculates the average and formats names.
    for (int i = 0; i < 5; i++) {
        scanf("%s", s[i].name);
        double studentSum = 0;
        for (int v = 0; v < 13; v++) {
            scanf("%d", &s[i].points[v]);
            studentSum += s[i].points[v];
        }
        s[i].average = studentSum / 13.0; 
        totalSum += s[i].average;
        formatName(s[i].name);
    }

    double totalAverage = totalSum / 5.0;

    // Finding the best student
    int bestId = 0;
    for (int i = 0; i < 5; i++) {
        if (s[i].average > s[bestId].average) {
            bestId = i;
        }
    }

    printf("%s\n", s[bestId].name);

    // Find the students with below average scores
    for (int i = 0; i < 5; i++) {
        if (s[i].average < totalAverage) {
            printf("%s\n", s[i].name);
        }
    }


    return 0;
}