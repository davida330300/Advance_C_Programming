#include "iostream"
using namespace std;
class LinkedListStack
{
public:
    struct stacknode
    {
        int data;
        stacknode *next;

        stacknode(int val)
        {
            data = val;
            next = NULL;
        }
    };
    stacknode *top;
    int size;

    LinkedListStack()
    {
        top = NULL;
        size = 1;
    }
    void Push(int val)
    {
        stacknode *node = new stacknode(val);
        if (top == NULL)
        {
            top = node;
        }
        else
        {
            node->next = top;
            top = node;
        }
        size++;
    }
    void Pop()
    {
        if (Empty())
        {
            cout << "Empty" << endl;
        }
        else
        {
            stacknode *deletenode = top;
            top = deletenode->next;
            deletenode->next = NULL;
            delete deletenode;
            size--;
        }
    }
    bool Empty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int Top()
    {
        if (top == NULL)
        {
            return NULL;
        }
        return top->data;
    }
    int getSize()
    {
        return size;
    }
    void Clear()
    {
        stacknode *deletenode = top;
        top = top->next;
        delete deletenode;
    }
};
int main()
{

    LinkedListStack s;
    s.Pop();
    s.Push(32);
    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Push(15);
    s.Push(12);
    s.Push(7);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Pop();
    cout << s.Empty() << endl;
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Clear();
    cout << s.Empty() << endl;
    s.Clear();
    cout << s.Empty() << endl;

    system("pause");
    return 0;
}