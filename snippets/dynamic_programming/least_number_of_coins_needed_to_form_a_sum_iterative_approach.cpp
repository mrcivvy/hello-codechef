#include <bits/stdc++.h>
using namespace std;
#define INF 2147483646
#define MAX 10000


/*
 * Problem:
 * Given a set of coins, find the least number of coins required to 
 * form a sum N using iterative dynamic programming approach.
 * 
 * Note:
 * The iterative form of a recursive dynamic algorithm generally has
 * better constant factors in its time complexity which makes it a 
 * slightly faster solution and easier to implement. However, it is
 * easier to come up with a recursive dynamic programming solution first
 * and then convert it to an iterative solution.
 */


int value[MAX];
int coins[3] = {1, 3, 4};

int construction()
{
    value[0] = 0;
    for(int x = 1; x <= MAX; x++)
    {
        value[x] = INF;
        for(int c = 0; c < 3; c++)
        {
            if(x - coins[c] >= 0)
            {
                value[x] = min(value[x], value[x-coins[c]] + 1);
            }
        }
    }
}

int number_of_coins(int x)
{
    if(x < 0) return INF;
    return value[x];
}

int main()
{
    construction();
    cout << "Value is -1, number of coins: " << number_of_coins(-1) << endl;
    cout << "Value is 0, number of coins: " << number_of_coins(0) << endl;
    cout << "Value is 1, number of coins: " << number_of_coins(1) << endl;
    cout << "value is 2, number of coins: " << number_of_coins(2) << endl;
    cout << "value is 3, number of coins: " << number_of_coins(3) << endl;
    cout << "Value is 10, number of coins: " << number_of_coins(10) << endl;
    cout << "Value is 20, number of coins: " << number_of_coins(20) << endl;
    cout << "Value is " << MAX << ", number of coins: " << number_of_coins(MAX) << endl;

    return 0;
}