// RandomNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

constexpr auto GREEN = "\033[32m";

int main()
{
    cout << GREEN;
    int randomNumberDistribution[20]{};
    srand(time(NULL));
    cout << "how many random numbers?";
    int iterations = 0, countNumbers=0;
    cin >> iterations;

    for (int i = 0; i < iterations; i++) {
        countNumbers++;

        auto randomInt = rand() % 20 + 1;
        randomNumberDistribution[randomInt - 1]++;
    }
    
    cout <<endl<< "generated " << countNumbers << " random numbers:"<<endl;


    for (int i = 0;i < sizeof(randomNumberDistribution)/sizeof(int);i++) {
        cout << "Number " << i+1<<": "<< randomNumberDistribution[i]<< " times ("<< 100*randomNumberDistribution[i]/ (float)countNumbers<<"%)"<< endl;
    }
}

/*


Create a large number of random numbers between 1 and 20!
Count how often every number appears
Compare this to the ideal distribution
(i.e. display probability of every number or something like that)
maybe, show the average, absolute discrepancy off the expected value
Number 2: 189 times (4.975%)
Number 3: 191 times (5.025%)
...
Maximum Offet: Number 4 (0.004%)
Minimum Offet: Number 7 (0.0%)
Average Offet: 0.002%

*/
