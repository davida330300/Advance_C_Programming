#include "iostream"
using namespace std;

class LinkedList
{
public:
    struct listnode
    { // basic attribute of node
        int data;
        listnode *next;

        listnode(int val)
        { // initial function
            next = NULL;
            data = val;
        }
    };
    listnode *head; // advance attribute for operation
                    //    int size;

    LinkedList()
    {
        head = NULL; //not necessary
    }
    ~LinkedList()
    {
    }
    void printlist()
    { //ok
        if (head == NULL)
        {                            // head means the label on the first node
            cout << "list is empty"; // if it indecate null, means the node is null
            return;
        }
        listnode *current = head; // create another
        while (current != NULL)
        { //
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
    void prepend(int val) //ok
    {
        listnode *node = new listnode(val);
        listnode *current = head;
        node->next = current;
        head = node;
    }
    void append(int val) //ok
    {
        listnode *node = new listnode(val);

        if (head == NULL)
        {
            head = node;
            return;
        }
        listnode *current = head;
        while (current->next != NULL)
        { // mistake current!=NULL

            current = current->next;
        }
        current->next = node;
    }
    int pop() //ok
    {
        listnode *current = head;
        listnode *previous = 0;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        int a = current->data;
        previous->next = NULL;
        delete current;
        return a;
    }
    int popFirst() //ok
    {
        listnode *current = head;
        int a = current->data;
        head = current->next;
        delete current;
        return a;
    }
    int front()
    {

        return head->data;
    }
    int tail()
    {
        if (head == NULL)
        {
            return -1;
        }
        listnode *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        return current->data;
    }
    int get(int i)
    {
        listnode *current = head;
        while (i > 0)
        {
            current = current->next;
            i--;
        }
        return current->data;
    }
    void remove(int i)
    {
        listnode *current = head;
        listnode *previous = 0;
        if (i == 0)
        {
            head = current->next;
            delete current;
            return;
        }
        while (i > 0)
        {
            previous = current;
            current = current->next;
            i--;
        }

        previous->next = current->next;
        delete current;
        return;
    }
    void deleteNegative(){
        listnode *previous = NULL;
        listnode *current = head->next;
        while(current!=NULL){
            previous = current;
            current = current->next;
        
            if (current->data<0){
                listnode *deletefront = previous;
                listnode *deleteend = current->next;

                previous 
            }
        }
    }
    void insert(int i, int val)
    {
        listnode *current = head;

        if (i == 0)
        {
            prepend(val);
        }
        else
        {
            while (--i > 0)
            {
                current = current->next;
            }

            listnode *node = new listnode(val);
            node->next = current->next;
            current->next = node;
        }
    }
    void clear()
    {

        while (head != NULL)
        { // mistake current != NULL
            listnode *current = head;
            head = head->next;
            delete current;
        }
    }
};

int main()
{
    LinkedList linkedlistStack ;
    LinkedList *linkedlistHeap = new LinkedList();

    linkedlistStack.append(1);
    linkedlistHeap->append(1);
    linkedlistStack.prepend(0);
    linkedlistStack.append(2);
    linkedlistStack.printlist();

    linkedlistStack.append(3);
    linkedlistStack.prepend(7);
    linkedlistStack.printlist();

    linkedlistStack.insert(2, 4);
    linkedlistStack.printlist();

    cout << linkedlistStack.front() << "\n";
    cout << linkedlistStack.tail() << "\n";

    cout << linkedlistStack.pop() << endl;
    linkedlistStack.printlist();

    cout << linkedlistStack.popFirst() << endl;
    linkedlistStack.printlist();

    linkedlistStack.remove(2);
    linkedlistStack.printlist();

    cout << linkedlistStack.get(1) << endl;

    linkedlistStack.clear();
    linkedlistStack.printlist();

    system("pause");
    return 0;
}

/* *
prepend(value)        -> Add a node in the beginning
append(value)         -> Add a node in the end
pop()                 -> Remove a node from the end, also return pop value
popFirst()            -> Remove a node from the beginning, also return pop value
front()               -> Return the first node
tail()                -> Return the last node
remove(Node)          -> Remove Node from the list

insert(Node, value)
clear()
*/