#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int i=0;i<nums.size();i++){
            str.push_back(to_string(nums[i]));
        }
        //sort(str.begin(),str.end(),compare);
        string ary = "";
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-1;j++){
                if(str[j+1]+str[j]>=str[j]+str[j+1]){
                    swap(str[j+1],str[j]);
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            ary+=str[i];
        }
        return ary;
    }
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    //3 30 34 5 9
    cout << largestNumber(nums) << endl;
    return 0;
}