/*
Double Hashing就直接加入「第二個Hash Function」
來影響「次數i」，定義為：

    h(k,i) = (h1(k)+i*h2(k))%m

並且要求，h2(k)一定要與m互質。

幾種常見的h2(k)選擇：

    第一種：m=2P，h2(k)的值域(range)為奇數(odd number)，h2(k)=2n+1。

    第二種：m是質數，h2(k)的值域(range)介於1?m?1，0<h2(k)<m?1。

    第三種：m是質數，h2(k)=R?k，R也是質數，並且R<m。


*/

#include <iostream>
#include <string>

using namespace std;

class HashOpenAddress{
public:
    struct dict{
        int key;
        string value;
        dict(){
            key = 0;
            value = "";
        }
        dict(int Key, string Value){
            key = Key;
            value = Value;
        }
    };

    int size, count;
    dict *table;
    HashOpenAddress(){
        size = 0;
        count = 0;
        table = 0;
    }
    HashOpenAddress(int m){
        size = m;
        count = 0;
        table = new dict[size];//*
    }
    int DoubleHashing(int key, int i){
        return ((key%size+i*DoubleFunction(key))%size);
    }
    int DoubleFunction(int key){
        int q = 8;              // q is prime && gcd(q,size)=1
        return(q-key%q);

    }
    void Insert(int key, string value){
        bool flag = false; 
        int count = 0; 

        while(flag != true && count<=size ){
            int index = DoubleHashing(key,count);
            if(table[index].value==""){
                table[index].value = value;
                table[index].key = key;
                flag = true;
                cout << "successful: "<<count<<"times"<<endl;
                break;
            }
            else{
                count++;
            }

        }
        if(count==size+1){
            cout << "Hash Table is full"<<endl;
        }

    }
    void Delete(int key){
        int i =0;
        bool flag = false;

        while(flag != true && i<=size ){
            int index = DoubleHashing(key,i);
            if(table[index].key==key){
                table[index].key = 0;
                table[index].value = "";
                break;
            }
            else{
                i++;
            }

        }
    }
    string Search(int key){
        int i = 0;
        bool flag = false;

        while(flag != true && i!=size ){
            int index = DoubleHashing(key,i);
            if(table[index].key==key){
                return table[index].value;
            }
            else{
                i++;
            }

        }
        return "...not found\n";

    }
    void Display(){
        for (int i = 0; i < size; i++) {
            cout << "slot#" << i << ": (" << table[i].key
                 << "," << table[i].value << ")" << endl;
        }
        cout << endl;
    }
};
int main(){

    HashOpenAddress hash(13);          // probing sequence:
    hash.Insert(33, "blue");          // 1,2,4,7,3,0,6,5 -> 1
    hash.Insert(10, "yellow");        // 2,3,5,0,4,1,7,6 -> 2
    hash.Insert(77, "red");           // 5,6,0,3,7,4,2,1 -> 5
    hash.Insert(2, "white");          // 2,3,5,0,4,1,7,6 -> 3
    hash.Display();
    hash.Insert(8, "black");          // 0,1,3,6,2,7,5,4 -> 0
    hash.Display();
    hash.Insert(47, "gray");          // 7,0,2,5,1,6,4,3 -> 7
    hash.Display();
    hash.Insert(90, "purple");        // 2,3,5,0,4,1,7,6 -> 4
    hash.Display();
    hash.Insert(1, "deep purple");    // 4,5,7,2,6,3,1,0 -> 6
    hash.Display();
    hash.Insert(15, "green");         // hash table overflow
    hash.Display();

    hash.Insert(12, "12");
    hash.Display();
    hash.Insert(76, "76");
    hash.Display();
    hash.Insert(24, "24");
    hash.Display();
    hash.Insert(13, "13");
    hash.Display();
    hash.Insert(5, "5");
    hash.Display();
    hash.Insert(88, "88");
    hash.Display();
    hash.Insert(61, "61");
    hash.Display();




    cout << "number#90 is " << hash.Search(90) << "\n\n";

    hash.Delete(90);
    hash.Display();
    cout << "after deleting (90,purple):\n";
    cout << "number#90 is " << hash.Search(90) << "\n";

    hash.Insert(12, "orange");        // 4,5,7,2,6,3,1,0 -> 4
    hash.Display();

    system("pause");
    return 0;
}