#include<string>
using namespace std;
template<typename v>
class Mapnode{
    public:
    string key;
    v val;
    Mapnode* next;
    Mapnode(string key,v val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
    ~Mapnode(){
        delete next;
    }
}; 
template<typename v>
class Map{
    Mapnode<v>** buckets;
    int size;
    int bucketNum;
    public:
    Map(){
        count=0;
        bucketNum=5;
        buckets=new Mapnode<v>*[5];
        for(int i=0;i<bucketNum;i++){
            buckets[i]=NULL;
        }
    }
    ~Map(){
        for(int i=0;i<bucketNum;i++){
            delete buckets[i];
        }
        delete []buckets;
    }
    private:
    int getIndex(string key){
        int hashCode=0;
        int coeff=1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode+=key[i]*coeff;
            hashCode=hashCode%bucketNum;
            coeff*=37; //We can use any other Prime Number instead of  37
            coeff=coeff%bucketNum;
        }
        return hashCode%bucketNum;
    }
    void rehash(){
        Mapnode<v> **temp=buckets;
        buckets=new Mapnode<v>*[2*bucketNum];
        for(int i=0;i<bucketNum*2;i++){
            buckets[i]=NULL;
        }
        int oldBucket=bucketNum;
        bucketNum*=2;
        count=0;
        for(int i=0;i<oldBucket;i++){
            Mapnode<v> *head=temp[i];
            while(head!=NULL){
                string key=head->key;
                v val=head->val;
                insert(key,val);
                head=head->next;
            }
        }
        for(int i=0;i<oldBucket;i++){
            Mapnode<v> *head=temp[i];
            delete head;
        }
        delete []temp;
    }
    public:
    void insert(string key,v val){
        int bucketIndex=getIndex(key);
        Mapnode<v> *head=bukcets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->val=val;
                return ;
            }
            head=head->next;
        }
        head=buckets[bucketIndex];
        Mapnode<v> *node=new Mapnode<v>(key,val);
        node->next=head;
        buckets[bucketIndex]=node;
        count++;
        double loadfactor= (count*1.0)/bucketNum;
        if(loadfactor>0.7){
            rehash();
        }
    }
    int size(){
        return count;
    }
    v remove(string key){
        int bucketIndex=getIndex(key);
        Mapnode<v> *head=buckets[bucketIndex];
        Mapnode<v> *prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[bucketIndex]=prev;
                }else{
                    prev->next=head->next;
                }
                v val=head->val;
                head->next=NULL;
                delete head;
                count--;
                return val;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
    v getValue(string key){
        int bukcetIndex=getIndex(key);
        Mapnode<v>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->val;
            }
            head=head->next;
        }
        return 0;
    }
};