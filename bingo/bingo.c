/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
*/

int main ()
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

int main2 ()
{
    int iSecret, iGuess;

    /* initialize random seed: */
    //~ srand (time(NULL));
    srand (1);

    int myTime = time(NULL);
    printf ("myTime: %d\n", myTime);
    
    /* generate secret number between 1 and 10: */
    iSecret = rand() % 10 + 1;
    printf ("iSecret: %d\n", iSecret);


    //~ do {
    //~ printf ("Guess the number (1 to 10): ");
    //~ scanf ("%d",&iGuess);
    //~ if (iSecret<iGuess) puts ("The secret number is lower");
    //~ else if (iSecret>iGuess) puts ("The secret number is higher");
    //~ } while (iSecret!=iGuess);
    //~ 
    //~ puts ("Congratulations!");
    return 0;
}
