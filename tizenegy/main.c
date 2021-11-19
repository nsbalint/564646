#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void randomkarakter(char array[], char random[10]);
bool ismetlodes(char random[]);
char karakter();
int szamolas (char input, char random[]);

int main()
{
    char abc[] = {'A','B','C','D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    char random [10];
    randomkarakter(abc, random);
    for (int i=0; i < 10; i++)
    {
        printf("%c", random[i]);
    }
    printf("\n");
    if(!ismetlodes(random))
    {
        printf("Ilyenkor nincs ismetlodes!\n");
    }
    else
    {
        printf("Van ismetlodes!\n");
    }

    printf("Adj nekem egy karaktert:");
    char input;
    input = karakter();
    printf("%c a tombben %d alkalommal szerepel.", input, szamolas(input, random));

    return 0;
}


void randomkarakter(char array[], char random[10])
{
    srand(time(0));
    {
        for (int i=0; i < 10; i++)
        {
            int a =rand() % 26;
            random[i] = array[a];
        }
    }
}
bool ismetlodes(char random[])
{
    int i=1;
    bool found;

    char first = random[0];
    do
    {
        if(first == random[i])
        {
            found = true;
        }
        i++;
    }
    while (!found|| i < 10);
    return found;
}

char karakter()
{
    char characterc;
    bool ok;
    do
    {
        ok = true;
        if(scanf("%c", &characterc) !=1)
        {
            while(getchar() != '\n');
        }
    }
    while (!ok);
    return characterc;

}
int szamolas (char input, char random[])
{
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if(random[i] == input)
        {
            count++;
        }
    }
    return count;
}

