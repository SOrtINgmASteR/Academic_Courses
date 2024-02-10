#include<iostream>
#include<vector>
using namespace std;

//Sieve of Eratosthenes
vector<bool> primes(10000000, true);
vector<int> prime_numbers;
void sieve_of_eratosthenes()
{
    int i, j, n = 10000000;
    primes[0] = false;
    primes[1] = false;
    for(i = 2; i * i < n; i++)
    {
        if(primes[i] == true)
        {
            for(j = i * i; j < n; j+=i)
            {
                primes[j] = false;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        if(primes[i] == true)
        {
            prime_numbers.push_back(i);
        }
    }
}


int main()
{
    sieve_of_eratosthenes();
    for(int i = 0; i < 100 ; i++)
    {
        if(primes[i] == true) cout << i << " ";
    }
    cout << endl;
    int a = prime_numbers.size();
    cout << "Size = " << a << endl;
    cout << "last prime = " << prime_numbers[a - 1] << endl;
    return 0;
}