#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"
struct
{
    char name[20];
    int score;
} typedef player;

void registerplayer(player p)
{
    FILE *f = fopen("leader board.txt", "a");
    fwrite(&p.name, sizeof(char)*20, 1, f);
    fwrite(&p.score, sizeof(int), 1, f);
    fclose(f);
}

void seeScores()
{
    FILE *f;
    char *l;
    f = fopen("leader board.txt", "r");
    fgets(l, 99, f);
    printf("%s", l);
    while (l != NULL)
    {
        printf("%s", l);
        fgets(l, 99, f);
    }
    fclose(f);
}
void menu()
{
    int x;
    player p;
    do
    {
        printf("play(1) or see scores(2) ?");
        scanf("%d", &x);
    } while (x > 2 || x < 1);

    switch (x)
    {
    case 1:
        printf("your name ?");
        scanf("%s", p.name);
        p.score = play();
        registerplayer(p);
        break;
    case 2:
        seeScores();
        break;
    default:
        break;
    }
}
int main()
{
    menu();
    return 0;
}
