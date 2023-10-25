#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_map<string,int> myMap;
    //insert uses the inbuilt pair class
    pair<string,int> p("abc",3);
    myMap.insert(p);
    myMap["abc"]=4;
    myMap.insert(p);
    //another way to insert
    myMap["a"]=1;
    //find or access
    cout << myMap["abc"] << endl;
    cout << myMap.at("a") << endl;
    //The difference between at() and [] is that if the key value is not present in the map , at() will give an error wehreas []
    //will insert the key value with default value 0, and give 0.
    // To check if a key is present or not.
    if(myMap.count("ghi")>0){
        cout << "Present" << endl;
    }
    else{
        cout << "Not Present" << endl;
    }
    //size
    cout << myMap.size() << endl;
    //delete
    myMap.erase("abc");
    cout << myMap.size() << endl;
}