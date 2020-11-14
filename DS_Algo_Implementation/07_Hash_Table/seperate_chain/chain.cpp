
/**
 * @file chain.cpp
 * @author Shau-Shiun, Chu (b06501018@ntu.edu.tw)
 * @brief 
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "iostream"
#include "math.h"
#include "string"
#include "vector"
using namespace std;
/**
 * 
 * 
 */
struct Node
{
    int key;
    string value;
    Node *next;

    Node()
    {
        key = 0;
        value = "";
        next = NULL;
    }
    Node(int i, string v)
    {
        key = i;
        value = v;
        next = NULL;
    }
    Node(Node const &data)
    {
        key = data.key;
        value = data.value;
        next = data.next;
    }
};
/**
 * 
 * 
 */
class HashChainNode
{
private:
    int size;
    int count;
    Node **table; //use **table (dynamic) instead of table[][] (static)
                  //pointer to pointer, hash table with chain
    int HashFunction(int key);
    void TableDoubling();
    void TableShrinking();
    void Rehashing(int size);

public:
    HashChainNode();
    /**
     * @brief Construct a new Hash Chain Node object
     * 
     *        Node, compare to DList<Entry<K,V>>
     * 
     * @param m the size of the table(index)
     */
    HashChainNode(int m)
    {
        size = m;
        count = 0;
        table = new Node *[size];

        for (int i = 0; i < size; i++)
        {
            table[i] = 0;
        }
    }

    ~HashChainNode();

    void Insert(Node data); //consisder TableDoubling
    void Delete(int key);   // consider TableShrinking
    string Search(int key);
    void DisplayTable();
};
/**
 * 
 * 
 */

/**
 * @brief 
 * 
 * @param data 
 */
void HashChainNode::Insert(Node data)
{

    count++;
    if (count > size)
    {
        TableDoubling();
    }

    int index = HashFunction(data.key);
    Node *newNode = new Node(data);

    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        Node *next = table[index]->next;
        table[index]->next = newNode;
        newNode->next = next;
    }
}
void HashChainNode::Delete(int key)
{
    int index = HashFunction(key);
    Node *current = table[index];
    Node *prev = NULL;

    while (current != NULL && current->key != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "data is not found" << endl;
        return;
    }
    else
    {
        if (prev == NULL)
        {
            table[index] = current->next;
        }
        else
        {
            prev->next = current->next;
        }
    }
    delete current;
    current = NULL;

    count--;

    if (count < size / 4)
    {
        TableShrinking();
    }
}

string HashChainNode::Search(int key)
{
    int index = HashFunction(key);
    Node *current = table[index];

    while (current != NULL && current->key != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        return "data is not found";
    }
    else
    {
        return current->key + " " + current->value;
    }
}
/**
 * the following are private method
 */
int HashChainNode::HashFunction(int key)
{
    double A = 0.6180339887;
    double frac = key * A - floor(key * A);
    return floor(this->size * frac);
}

void HashChainNode::TableDoubling()
{
    int originSize = size;
    size = size * 2;
    Rehashing(originSize);
}

void HashChainNode::TableShrinking()
{
    int originSize = size;
    size = size / 2;
    Rehashing(originSize);
}

void HashChainNode::Rehashing(int originSize)
{
    Node **newtable = new Node *[size];
    for (int i = 0; i < size; i++)
    {
        newtable[i] = 0;
    }

    for (int i = 0; i < originSize; i++)
    {
        Node *originCurrent = table[i];
        Node *originPrevious = NULL;

        while (originCurrent != NULL)
        {
            originPrevious = originCurrent->next;

            int index = HashFunction(originCurrent->key); // get index of slot in new table
            if (newtable[index] == NULL)
            { // means newtable[index] is empty
                newtable[index] = originCurrent;
                originCurrent->next = 0; // equivalent to curr_orig->next = 0;
            }
            else
            {                                       // if newtable[index] is not empty
                Node *next = newtable[index]->next; // push_front()
                newtable[index]->next = originCurrent;
                originCurrent->next = next;
            }
            originCurrent = originPrevious;
        }
    }
    delete[] table; // release memory of original table
    this->table = newtable;
}
HashChainNode::~HashChainNode()
{

    for (int i = 0; i < size; i++)
    {                             // visit every node in table
                                  // and release the memory of each node
        Node *current = table[i]; // point *current to first node in list
        while (current != NULL)
        { // traversal in list
            Node *previous = current;
            current = current->next;
            delete previous;
            previous = 0;
        }
    }
    delete[] table;
}
void HashChainNode::DisplayTable()
{

    for (int i = 0; i < size; i++)
    { // visit every node in table
        cout << "#slot#" << i << ": ";
        Node *current = table[i];
        while (current != NULL)
        {
            cout << "(" << current->key << "," << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    HashChainNode hash(2);

    hash.Insert(Node(12, "post rock"));
    hash.Insert(Node(592, "shoegaze"));
    cout << "After inserting key(12),key(592):\n";
    hash.DisplayTable();
    hash.Insert(Node(6594, "blues")); // evoke TableDoubling()
    cout << "After inserting key(6594), evoke TableDoubling():\n";
    hash.DisplayTable();
    hash.Insert(Node(7, "folk"));
    cout << "After inserting key(7):\n";
    hash.DisplayTable();
    hash.Insert(Node(123596, "hiphop")); // evoke TableDoubling()
    cout << "After inserting key(123596), evoke TableDoubling():\n";
    hash.DisplayTable();
    hash.Insert(Node(93, "soul"));
    hash.Insert(Node(2288, "indie"));
    hash.Insert(Node(793, "jazz"));
    cout << "After inserting key(93),key(2288),key(793):\n";
    hash.DisplayTable();
    hash.Insert(Node(8491, "electro")); // evoke TableDoubling()
    cout << "After inserting key(8491), evoke TableDoubling():\n";
    hash.DisplayTable();
    hash.Insert(Node(323359, "pop"));
    cout << "After inserting key(323359):\n";
    hash.DisplayTable();

    cout << "Searching: genre(8491) is " << hash.Search(8491) << ".\n\n";
    cout << "Searching: genre(7) is " << hash.Search(7) << ".\n\n";

    hash.Delete(7);
    cout << "After deleting key(7):\n";
    cout << "Searching: genre(7) is " << hash.Search(7) << ".\n\n";

    hash.Delete(592);
    cout << "After deleting key(592):\n";
    hash.DisplayTable();

    cout << "Want to  delete key(592) again:\n";
    hash.Delete(592);

    hash.Delete(123596);
    hash.Delete(323359);
    hash.Delete(793);
    hash.Delete(93);
    cout << "After deleting key(123596),key(323359),key(793),key(93):\n";
    hash.DisplayTable();

    hash.Delete(6594); // evoke TableShrinking()
    cout << "After deleting key(6594), evoke TableShrinking():\n";
    hash.DisplayTable();

    system("pause");
    return 0;
}
