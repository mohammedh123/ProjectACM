// Solution to problem 10042
// by: Mohammed Hossain
// Language: C++

#include <iostream>
#include <bitset>

using namespace std;

class P10042
{
    //sqrt(10^9) is 31622.77; make an array of size 31633 to see if there are any primes
    //10^9
    static bitset<1000000000> primes;

    static void PopulatePrimes()
    {
        static int sqrtN = 31622;

        for(int i = 2; i < sqrtN; i++) {
            for(int j = i*2; j < sqrtN; j += i)
                primes.set(j);
        }
    }
public:
    static void Solve()
    {
    }
};

bitset<1000000000> P10042::primes;

int main()
{    
    P10042::Solve();
}