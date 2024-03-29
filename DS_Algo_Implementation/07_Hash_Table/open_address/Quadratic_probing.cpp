//Open Addressing使用的Hash Function有兩個參數，一個是資料的Key，另一個是Probing的「次數」
/*
    h(k,i) = hash fuction
    h'(k) = division method k%m, means the start point of probing
    i = the time of probing


linear probing: h(k,i) = (h'(k)+i)%m = ((k%m)+i)%m

Quadratic probing: h(k,i) = (h'(k)+c1*i+c2*i^2)%m 
                    (1): c1 = c2 = 0.5, m = 2^p
                    (2): h(k,i) = (h'(k)-(-1)(i/2)^2)%m
                    ()
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
    int QuadraticProbing(int key, int i){
        //c1 = c2 = 0.5, m = 2^p
        return(int(((key%size)+0.5*i+0.5*i*i))%size);

    }
    void Insert(int key, string value){
        bool flag = false; 
        int i = 0;

        while(flag != true && i!=size ){
            int index = QuadraticProbing(key,i);
            if(table[index].value==""){
                table[index].value = value;
                table[index].key = key;
                flag = true;
                break;
            }
            else{
                i++;
            }

        }
        if(i==size){
            cout << "Hash Table is full"<<endl;
        }

    }
    void Delete(int key){
        int i =0;
        bool flag = false;

        while(flag != true && i!=size ){
            int index = QuadraticProbing(key,i);
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
            int index = QuadraticProbing(key,i);
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

    HashOpenAddress hash(7);          // probing sequence:
    hash.Insert(33, "blue");          // 1,2,4,7,3,0,6,5 -> 1
    hash.Insert(10, "yellow");        // 2,3,5,0,4,1,7,6 -> 2
    hash.Insert(77, "red");           // 5,6,0,3,7,4,2,1 -> 5
    hash.Insert(2, "white");          // 2,3,5,0,4,1,7,6 -> 3
    hash.Display();
    hash.Insert(8, "black");          // 0,1,3,6,2,7,5,4 -> 0
    hash.Insert(47, "gray");          // 7,0,2,5,1,6,4,3 -> 7
    hash.Insert(90, "purple");        // 2,3,5,0,4,1,7,6 -> 4
    hash.Insert(1, "deep purple");    // 4,5,7,2,6,3,1,0 -> 6
    hash.Display();
    hash.Insert(15, "green");         // hash table overflow

    cout << "number#90 is " << hash.Search(90) << "\n\n";

    hash.Delete(90);
    cout << "after deleting (90,purple):\n";
    cout << "number#90 is " << hash.Search(90) << "\n";

    hash.Insert(12, "orange");        // 4,5,7,2,6,3,1,0 -> 4
    hash.Display();

    system("pause");
    return 0;
}