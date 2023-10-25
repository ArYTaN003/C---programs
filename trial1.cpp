#include <iostream>
#include <cstring>
//#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    vector<string> s={"upgrade","upgrade","upgrade","upgrade","lock","upgrade","lock","upgrade","lock","lock","lock","upgrade","upgrade","upgrade","upgrade","lock","upgrade","lock","upgrade","unlock"};
    vector<vector<int>> num={{8,39},{5,28},{6,33},{9,24},{5,22},{1,3},{5,20},{0,38},{5,14},{6,34},{6,28},{3,23},{4,45},{8,7},{2,18},{3,35},{2,16},{3,21},{1,41},{5,22}};
    vector<bool> out={false,false,false,false,true,false,false,true,true,true,false,true,false,false,false,false,false,false,false,false};
    vector<bool> correctOut={false,false,false,false,true,false,false,true,true,true,false,false,false,false,false,true,false,false,false,false};
    cout << "OPERATION" << "  " << "INPUT" << "  " << "  " << "OUTPUT" << "  " << "CORRECTOUTPUT" <<endl;
    for(int i=0;i<s.size();i++){
        cout << s[i] << "    " << num[i][0] << " " << num[i][1] << "  "<<out[i] << "  " << correctOut[i] <<endl; 
    }
}
//locked =[0,6]
/*

cout << num << " " << temp[i] << endl;
            vector<int> l=descendant_locked(temp.at(i));
            for(int i=0;i<l.size();i++){
                out.push_back(l.at(i));
                cout << "Locked" << l.at(i) << endl;
            }
*/