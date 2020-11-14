#include "iostream"
#include "list"
#include "vector"
#include "string"
#include "cmath"

using namespace std;

class HashChain{

public :
    struct dict{
        string key;
        string value;
        dict(){
            key = "";
            value = "";
        }
        dict(string Key, string Value){
            key = Key;
            value = Value; 
        }
    };

    int size, count;// size of table, count: number of data
    vector<list<dict>> table;

    HashChain(){
        size = 0;
        count = 0;
    }
    HashChain(int m){
        size = m;
        count = 0;
        table.resize(size);
    }

    int PreHashing(string key_str){
        int exp = 9; 
        int hashcode = 0;
        int p = 1;

        for(int i = int(key_str.size()-1); i>=0;i--){
            hashcode += key_str[i]*p;
            p *= exp;
        }
        return hashcode;
    }
    int HashFunction(string key_str){// using Division method
        return (PreHashing(key_str)% this->size);
    }

    void Insert(dict data){
        int index = HashFunction(data.key);
        table[index].push_front(data);
    }
    void Delete(string key_str){
        int index = HashFunction(key_str);

        for(list<dict>::iterator itr = table[index].begin();itr != table[index].end(); itr++){
            if(itr->key == key_str){
               table[index].erase(itr);
               break;
            }
        }
    }
    string Search(string key_str){
        int index = HashFunction(key_str);

        for(list<dict>::iterator itr = table[index].begin();itr != table[index].end(); itr++){
            if(itr->key == key_str){
               return itr->value;
               break;
            }
        }
        return "...no element.";
        
    }
    void DisplayTable(){
        for(int i = 0; i<table.size();i++){
            cout <<"slot#"<<i<<":";
            for(list<dict>::iterator itr = table[i].begin(); itr!=table[i].end();itr++){
                cout << "("<<itr->key<<","<<itr->value<<")";
            }
            cout << "\n";
        } 
        cout << "\n";
    }



};

int main() {

    HashChain hash(5);
    hash.Insert(HashChain::dict("T-Mac","Magic"));
    hash.Insert(HashChain::dict("Bryant","Lakers"));
    hash.Insert(HashChain::dict("Webber","Kings"));
    hash.Insert(HashChain::dict("Arenas", "Wizards"));
    hash.Insert(HashChain::dict("Davis","Clippers"));
    hash.Insert(HashChain::dict("Kidd","Nets"));
    hash.DisplayTable();

    cout << "T-Mac is in " << hash.Search("T-Mac") << ". " << endl;
    cout << "Arenas is in " << hash.Search("Arenas") << ". " << endl;
    cout << "david is in "<< hash.Search("david") << ". "<<endl;

    hash.Delete("Kidd");
    hash.Delete("T-Mac");
    cout << "\nAfter deleing Kidd and T-Mac:\n";
    hash.DisplayTable();

    system("pause");
    return 0;
}