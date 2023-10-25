/*

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, 
as 1 is the minimum count of numbers required to represent N as sum of squares.
*/
#include <cmath>
#include<iostream>
using namespace std;
int minCount(int n)
{
    // Write your code here
    int *minc = new int[n + 1];
    minc[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        minc[i] = i;
        for (int j = 1; i - j * j >= 0; j++)
        {
            if (minc[i - j * j] < minc[i])
            {
                minc[i] = minc[i - j * j];
            }
        }
        minc[i] += 1;
    }
    int res = minc[n];
    delete[] minc;
    return res;
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}