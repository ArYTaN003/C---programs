#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
char grid[10][10];
vector<string> words;
void PlaceHorizontally(int ind, int row, int col, vector<bool> &vect)
{
    for (int p = 0; p < words[ind].length(); p++)
    {
        if (grid[row][p + col] == '-')
        {
            vect[p] = true;
            grid[row][p + col] = words[ind][p];
        }
    }
}
bool isValidVertical(int ind, int row, int col)
{
    int c = row + 1;
    while (c < 10 && (grid[c][col] == '-' || grid[c][col] == words[ind][c - row]))
    {
        c++;
    }
    return c - row == words[ind].length();
}
bool isValidHorizontal(int ind, int row, int col)
{
    int c = col + 1;
    while (c < 10 && (grid[row][c] == '-' || grid[row][c] == words[ind][c - col]))
    {
        c++;
    }
    return c - col == words[ind].length();
}
void PlaceVertically(int ind, int row, int col, vector<bool> &vect)
{
    for (int p = 0; p < words[ind].length(); p++)
    {
        if (grid[p + row][col] == '-')
        {
            vect[p] = true;
            grid[p + row][col] = words[ind][p];
        }
    }
}
void restoreVertically(int ind, int row, int col, vector<bool> &vect)
{
    for (int p = 0; p < words[ind].length(); p++)
    {
        if (vect[p])
        {
            grid[p + row][col] = '-';
        }
    }
}
void restoreHorizontally(int ind, int row, int col, vector<bool> &vect)
{
    for (int p = 0; p < words[ind].length(); p++)
    {
        if (vect[p])
        {
            grid[row][p + col] = '-';
        }
    }
}
void solveCrossword(int ind)
{
    if (ind == words.size())
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] == '-' || grid[i][j] == words[ind][0])
            {
                if (isValidHorizontal(ind, i, j))
                {
                    vector<bool> filled(words[ind].length(), false);
                    PlaceHorizontally(ind, i, j, filled);
                    solveCrossword(ind + 1);
                    restoreHorizontally(ind, i, j, filled);
                }
                if (isValidVertical(ind, i, j))
                {
                    vector<bool> filled(words[ind].length(), false);
                    PlaceVertically(ind, i, j, filled);
                    solveCrossword(ind + 1);
                    restoreVertically(ind, i, j, filled);
                }
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> grid[i][j];
        }
    }
    string w;
    cin >> w;
    for (int i = 0; i < w.length(); i++)
    {
        string word = "";
        for (; i < w.length() && (w[i] != '\0' && w[i] != ';'); i++)
        {
            word += w[i];
        }
        words.push_back(word);
    }

    solveCrossword(0);
    // write your code here
    return 0;
}