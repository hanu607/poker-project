#include "enum.h"
#include "player.h"
#include "table.h"
#include <iostream>
#include <time.h>

std::pair<int, int> parseCard()
{
    char i, j;
    int n, s;
    while (std::cin >> i >> j)
    {
        if ('2' <= i && i <= '9')
            n = i - '0';
        else if (i == 'T')
            n = T;
        else if (i == 'J')
            n = J;
        else if (i == 'Q')
            n = Q;
        else if (i == 'K')
            n = K;
        else if (i == 'A')
            n = A;
        else
            continue;
        if (j == 's')
            s = SPADE;
        else if (j == 'h')
            s = HEART;
        else if (j == 'c')
            s = CLUB;
        else if (j == 'd')
            s = DIAMOND;
        else
            continue;
        break;
    }
    return {s, n};
}

int main()
{
    Table T;
    std::cout << "P1: ";
    T.insertHand(0, parseCard());
    T.insertHand(0, parseCard());
    std::cout << "P2: ";
    T.insertHand(1, parseCard());
    T.insertHand(1, parseCard());
    std::cout << "Board: ";
    int n;
    std::cin >> n;
    while (n--)
        T.insertCommunity(parseCard());

    clock_t start, end;
    start = clock();
    int *res = Bruteforce(T);
    end = clock();
    for (int i = 0; i < 3; i++)
        std::cout << res[i] << ' ';
    std::cout << '\n';
    printf("%f %%\n", 100 * (double)res[2] / (double)(res[0] + res[1] + res[2]));
    double t = (double)(end - start);
    std::cout << t;
}

/*
TO DO:

Major:
Update a function caculating odds.
Implement the user prompt.
Improve perfromance.

More:
Modify Showdown function in Table for multiple players.
Modify bruteforce to work with the player without hand.

Options:
Convert enums to enum classes.
Convert if-else to switch-case for better performance.
Comment whole codes.
*/
