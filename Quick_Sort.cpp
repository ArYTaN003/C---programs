#include <iostream>
using namespace std;
int partition(int input[], int start, int end)
{
    int count_Smaller = 0, i = start, j = end;
    for (int k = start; k <= end; k++)
    {
        if (input[start] > input[k])
        {
            count_Smaller++;
        }
    }
    int pi = start + count_Smaller;
    int temp = input[start];
    input[start] = input[pi];
    input[pi] = temp;
    while (i < pi && j > pi)
    {
        if (input[i] < input[pi])
        {
            i++;
        }
        else if (input[j] >= input[pi])
        {
            j--;
        }
        else
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
        }
    }
    return pi;
}
void quickSort(int input[], int start, int end)
{
    // your code goes here
    if (start >= end)
    {
        return;
    }
    int pi = partition(input, start, end);
    quickSort(input, start, pi - 1);
    quickSort(input, pi + 1, end);
}
void quickSort(int input[], int size)
{
    quickSort(input, 0, size - 1);
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, 0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}