//gcc bingo.c -o bingo.o -std=c99 && ./bingo.o

/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <limits.h>
#include <sys/auxv.h>

/*
time: 1451391347.15
< Welcome to Bingo!$
<
Welcome to round 1, the difficulty will be 5.
The computer has chosen these numbers:
+----+----+----+----+----+
|  0 | 28 | 26 |  9 | 14 |
+----+----+----+----+----+
| 10 | 11 | 15 | 22 | 30 |
+----+----+----+----+----+
|  7 | 12 |  1 | 21 | 16 |
+----+----+----+----+----+
| 31 |  6 |  4 | 17 |  5 |
+----+----+----+----+----+
| 18 |  8 | 23 | 13 | 24 |
+----+----+----+----+----+
*
*   5 -> 31
*   9 -> 511
*       (2^N) - 1
*/

int main4 ()
{
    //~ printf("UINT_MAX: %u", UINT_MAX);
    time_t start = time(NULL);
    for (unsigned int seed = 0; seed < UINT_MAX; seed++)
    {
        srand(seed);
        if ((time(NULL) - start) > 10)
        {
            printf("seed: %u\n", seed);
            break;
        }
    }
}


/*
+------------+------------+------------+------------+------------+
|          2 |          6 |         32 |          0 |        797 |
+------------+------------+------------+------------+------------+
|         22 |         64 |         12 |    6291493 |  573480960 |
+------------+------------+------------+------------+------------+
| 2299920512 |  574955520 | 1623195650 | 2315807072 |       2304 |
+------------+------------+------------+------------+------------+
|          0 |          0 | 1351221248 |     524560 | 3254846464 |
+------------+------------+------------+------------+------------+
| 2283798804 | 2747531298 |  101359704 |    9044110 | 1073742848 |
+------------+------------+------------+------------+------------+
* 
*/
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main5 ()
{
    unsigned int numbers[] = {2, 6, 32, 0, 797,
                              22, 64, 12, 6291493, 573480960,
                              2299920512, 574955520, 1623195650, 2315807072, 2304,
                              0, 0, 1351221248, 524560, 3254846464,
                              2283798804, 2747531298, 101359704, 9044110, 1073742848};

    int sum = 0;
    for(int i=0; i<NELEMS(numbers);i++)
    {
        //~ printf("i: %d\n", i);
        sum += numbers[i];
    }
}

int main3 ()
{
    int myTime = 1451391347;
    int delta = 6000;
    for (int theTime = myTime - delta; theTime < myTime + delta; theTime++)
    {
        //~ printf("theTime: %d\n", theTime);
        srand (theTime);

        int iSecret = rand() % 31 + 0;
        //~ printf ("iSecret: %d\n", iSecret);

        if (iSecret == 0)
        {
            //~ printf ("iSecret: %d\n", iSecret);
            //~ printf("YEAH!!!");
            iSecret = rand() % 31 + 0;
            //~ printf ("iSecret2: %d\n", iSecret);
            if (iSecret == 28)
            {
                iSecret = rand() % 31 + 0;
                printf ("iSecret2: %d\n", iSecret);
            }
        }
    }
}

int main ()
{
    int iSecret, iGuess;

    /* initialize random seed: */
    //~ srand (time(NULL));
    srand (1);

    int myTime = time(NULL);
    printf ("myTime: %d\n", myTime);

    iSecret = rand();
    printf ("iSecret: %d\n", iSecret);
    return 0;
    
    //iSecret = rand() % 10 + 1;
    //printf ("iSecret: %d\n", iSecret);

    ////unsigned long getauxval(unsigned long type);
    //char[16] = (char *)getauxval(AT_RANDOM);
    //printf("axv: %lu\n", *axv);

    ////~ do {
    ////~ printf ("Guess the number (1 to 10): ");
    ////~ scanf ("%d",&iGuess);
    ////~ if (iSecret<iGuess) puts ("The secret number is lower");
    ////~ else if (iSecret>iGuess) puts ("The secret number is higher");
    ////~ } while (iSecret!=iGuess);
    ////~ 
    ////~ puts ("Congratulations!");

    //int foo = 10;
    //printf("foo: %d", foo);
    //foo = foo << 1;
    //printf("foo: %d", foo);
    
    //return 0;
}
