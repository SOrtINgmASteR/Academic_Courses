#include<iostream>
#include<vector>
using namespace std;

//Bitwise Sieve of Eratosthenes
int primes[100000000];
vector<int> prime_numbers;
int getbit(int n)
{
    int index = n / 32;
    int bit_index = n % 32;
    int mask =  1 << bit_index;
    int bit_value = primes[index] & mask;
    return bit_value;
}
void setbit(int n)
{
    int index = n / 32;
    int bit_index = n % 32;
    int mask = 1 << bit_index;
    primes[index] = primes[index] | mask;
}
int bitwise_sieve()
{
    int i, j, n = 100000000;
    primes[0] = primes[0] | 1 << 0;
    primes[0] = primes[0] | 1 << 1;
    for(i = 2; i * i < n; i++)
    {
        if(getbit(i) == 0)
        {
            for(j = i * i; j < n; j+=i)
            {
                setbit(j);
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        if(getbit(i) == 0)
        {
            prime_numbers.push_back(i);
        }
    }
}

int main()
{
    bitwise_sieve();
    for(int i = 0; i < 100; i++)
    {
        cout << prime_numbers[i] << " ";
    }
    cout << endl;
    int x = prime_numbers.size();
    cout << "Size = " << x << endl;
    cout << "last prime = " << prime_numbers[x - 1] << endl;
    return 0;
}
