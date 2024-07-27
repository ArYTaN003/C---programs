#include<bits/stdc++.h>
using namespace std;

// input : disk1 alag map /  file1 -> data
// lakshay
// disk 3     3 maps
// disk2 file x
// disk n 
// DiskName/FileName
class FileSystem{
    map<string,Disk*> disks;
    public:
    void create(string DiskName){
        disks[DiskName] = new Disk(DiskName,4);
    }
    void write(string path){
        int n = path.length();
        string diskName = "";
        string fileName = "";
        int i;
        for(i=0;i<n && path[i]!='/';i++);
        diskName = path.substr(0,i);
        fileName = path.substr(i+1);
        if(disks.count(diskName)){
            disks[diskName]->write(fileName);
        }else{
            // Exception 
        } 
    }
    string read(string path){
        int n = path.length();
        string diskName = "";
        string fileName = "";
        int i;
        for(i=0;i<n && path[i]!='/';i++);
        diskName = path.substr(0,i);
        fileName = path.substr(i+1);
        if(disks.count(diskName)){
            return disks[diskName]->read(fileName);
        }else{
            // Exception
        }
    }
    void append(string path){
        int n = path.length();
        string diskName = "";
        string fileName = "";
        int i;
        for(i=0;i<n && path[i]!='/';i++);
        diskName = path.substr(0,i);
        fileName = path.substr(i+1);
        if(disks.count(diskName)){
            return disks[diskName]->append(fileName);
        }else{
            // Exception
        }
    }
};
//GOOD BOY ARYAN :-)


class Disk:private FileSystem{
    string DiskName;
    map<string,File*> files;
    int MaxSize,CurrSize;
    public:
    Disk(string name,int maxsize){
        DiskName = name;
        MaxSize = maxsize;
        CurrSize=0;
    }
    void write(string FileName){

    }
    ~Disk(){
    }
};

class File:private Disk{

};

int main(){
    disk1
    return 0;
}