#include <iostream>
using namespace std;
int main()
{
    string s = "";
    cin >> s;
    int lower = 0, upper = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            lower++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            upper++;
        }
    }
    //cout << lower <<" " << upper << endl;
    for (int i = 0; i < s.length(); i++)
    {
        if (lower < upper)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] -= 32;
            }
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
            }
        }
    }
    cout<< s << endl;
}