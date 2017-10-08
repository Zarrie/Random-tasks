#include <iostream>
#include <cmath>

using namespace std;

const long long sieveSize = 200000000;
bool sieve[sieveSize] = {0};

int main ()
{
    for (long i = 2 ; i < sieveSize ; i++)
    {
        if (sieve[i] == 0)
        {
            for (unsigned long long j = i * i ; j < sieveSize ; j += i)
            {
                sieve[j] = 1;
            }
        }
    }

    for (int i = 2 ; i < sieveSize ; i++)
    {
        if (sieve[i] == 0)
        {
           // cout << i << "\n";
        }
    }
return 0;
}


