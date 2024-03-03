#include <iostream>
using namespace std;
bool check(int temp)
{
    int c = temp;
    while (c)
    {
        if (c % 10 == 1 || c % 10 == 3 || c % 10 == 5 || c % 10 == 7 || c % 10 == 9)
            return false;
        c /= 10;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int temp = 0;
    while (n)
    {
        if (check(temp))
            n--;
        temp++;
    }
    cout << temp - 1 << endl;
    return 0;
}