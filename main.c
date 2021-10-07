#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int pick(unsigned _Start, unsigned _End) {
    srand((unsigned)time(NULL));
    int result = rand() % _End + _Start;

    return result;
}

int main(void) {
    int answer;
    int input;
    int chance = 0;
    char yesno;

start:
    for (int i = 0; i < 20; i++) printf("\n");

    for (int i = 0; i < 20; i++) printf("\t"); printf("  ---------------------------\n");
    for (int i = 0; i < 20; i++) printf("\t"); printf("  |                         |\n");
    for (int i = 0; i < 20; i++) printf("\t"); printf("  |       Random Game       |\n");
    for (int i = 0; i < 20; i++) printf("\t"); printf("  |                         |\n");
    for (int i = 0; i < 20; i++) printf("\t"); printf("  |    Made By Hyunu Jung   |\n");
    for (int i = 0; i < 20; i++) printf("\t"); printf("  |                         |\n");
    for (int i = 0; i < 20; i++) printf("\t"); printf("  ---------------------------\n");

    for (int i = 0; i < 20; i++) printf("\n");

    system("read");
    system("clear");

    printf("Guess my number (1 ~ 100)\n");
    answer = pick(1, 100);

    while (1) {
        scanf("%d", &input);

        if (input == answer) {
            printf("Correct!\n");
            printf("You used %d of chance.\n", chance);

            break;
        }

        else {
            chance++;

            if (input < answer) printf("Your input is smaller then answer.\n");
            else printf("Your input is bigger then answer.\n");
        }

        if (chance == 10) {
            printf("You used all of chance!\n");
            printf("The Answer was %d\n", answer);

            break;
        }
    }

    system("read");
    system("clear");

    getchar();
    printf("Do you want to play again?(y/n) ");
    scanf("%c", &yesno);

    switch (yesno) {
        case 'y':
            printf("GOGO!\n");
            sleep(1);
            answer = pick(1, 100);
            chance = 0;
            goto start;
        case 'n':
            printf("GG! Good Bye!\n");
            sleep(1);
            system("clear");
            return 0;
        default:
            printf("; Wrong Answer!\n");
            sleep(1);
            answer = pick(1, 100);
            chance = 0;
            goto start;
    }

    return 0;
}
