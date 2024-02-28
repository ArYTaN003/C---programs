#include <bits/stdc++.h>
using namespace std;

string rearrange_string(string s) {
    int n = s.length();
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }
    vector<pair<int, int>> freq;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            freq.push_back({i, count[i]});
        }
    }
    sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });
    string res(n, '0');
    int index = 0;
    for (auto& [f, cnt] : freq) {
    for (int i = index; i < n; i += 2) {
        if (cnt > 0) {
            res[i] = char(f + 'a');
            int cnt_copy = cnt; // create a copy of cnt
            cnt_copy--; // decrement the copy
            cnt = cnt_copy; // update the original cnt
            index++;
        }
    }
    if (index == n && cnt > 0) {
        return "impossible";
    }
}
    return res;
}
int main(){
    string s = "aaba";
    cout << rearrange_string(s) << endl;
}