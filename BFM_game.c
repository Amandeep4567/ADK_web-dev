#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int bearMosquitoFish(char user, char comp)
{
    if (user == comp)
    {
        return 0;
    }

    if (user == 'b' && comp == 'f')
    {
        return 1;
    }
    else if (user == 'f' && comp == 'b')
    {
        return -1;
    }
    if (user == 'f' && comp == 'm')
    {
        return 1;
    }
    else if (user == 'm' && comp == 'f')
    {
        return -1;
    }
    if (user == 'b' && comp == 'm')
    {
        return -1;
    }
    else if (user == 'm' && comp == 'b')
    {
        return 1;
    }
}
int main()
{
    char user, comp;
    int result;
    srand(time(0));
    int ucount = 0, ccount = 0;
    for (int k = 0; k < 3; k++)
    {
        int cuser = 0, ccomp = 0;
        printf("\n***************LEVEL %d****************\n", k + 1);
        for (int z = 0; z < 3; z++)
        {
            int number = rand() % 100 + 1;
            if (number <= 33)
            {
                comp = 'f';
            }
            else if (number > 33 && number < 66)
            {
                comp = 'm';
            }
            else
            {
                comp = 'b';
            }
            printf("ROUND %d : Select b for bear, m for mosquito and f for fish.\n", z + 1);
            scanf("%c", &user);
            if (user == 'm' || user == 'b' || user == 'f')
            {
                result = bearMosquitoFish(user, comp);
            }
            else
            {
                printf("Invalid Input. Try Again...\n");
                printf("ROUND %d : Select b for bear, m for mosquito and f for fish.\n", z + 1);
                scanf(" %c", &user);
                if (user == 'm' || user == 'b' || user == 'f')
                {
                    result = bearMosquitoFish(user, comp);
                }
            }

            if (result == 0)
            {
                printf("****Game Draw!****\n");
            }
            else if (result == 1)
            {
                printf("****You Win!****\n");
                cuser++;
            }
            else
            {
                printf("****You Lose!****\n");
                ccomp++;
            }
            printf("You choose %c and computer choose %c !\n\n", user, comp);
            getchar();
        }
        printf("User won %d matches while Comp won %d matches\n", cuser, ccomp);
        ucount = ucount + cuser;
        ccount = ccount + ccomp;
    }
    if (ucount > ccount)
    {
        printf("\n*************User WON!**************\n");
        printf("USER won %d matches while COMP won %d matches\n", ucount, ccount);
    }
    else if (ccount > ucount)
    {
        printf("\n*************Comp WON!****************\n");
        printf("COMP won %d matches while USER won %d matches\n", ccount, ucount);
    }
    else
    {
        printf("\n*************Game DRAW!***************");
    }

    return 0;
}