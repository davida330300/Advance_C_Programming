#include "iostream"
using namespace std;

class doublyCircularLinkedList
{

public:
    struct listnode
    {
        int data;
        listnode *next;
        listnode *prev;
    };
    listnode *head;
    /*
    constructor
    printlist
    insertEnd()
    insertbegin()
    insertAtPosistion()
    sortList()
    search()
    pop()
    
    delete()

    */
    doublyCircularLinkedList()
    {
        head = NULL;
    }
    ~doublyCircularLinkedList()
    {
    }
    void insertEnd(struct listnode** start, int value)
    {
        if(*start = NULL){
            listnode *newNode = new listnode();
            newNode->data = value;
            newNode->next = newNode;
            newNode->prev = newNode;
            *start = newNode;
        }else{
            listnode *newNode = new listnode();
            listnode *lastnode = (*start)->prev;
            newNode->data = value;
            newNode->next = *start;
            newNode->prev = lastnode;
            *start = newNode;
        }
    }
    void insertBegin()
    {
        if()
    }
    void insertBefotre()
    {
    }
    void insertAfter()
    {
    }
    void sortList(){

    }
    void search(){

    }
    void pop(){

    }
    void deleteNode(struct listnode, int key){
        
    }
    void display(listnode *start)
    {
        listnode *temp = start;

        cout << "traversal forward" << endl;
        while (temp->next != start)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "\n";

        cout << "traversal backward" << endl;
        while (temp->prev != start)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
}