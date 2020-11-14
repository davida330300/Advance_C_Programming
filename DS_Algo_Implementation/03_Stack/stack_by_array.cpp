#include "iostream"
using namespace std;
class ArrayStack
{

public: // sometimes will forget, watch out
    int top;
    int capacity;
    int *stack; //array_base stack
    void addcapacity()
    {

        int *newstack = new int[capacity+1];
        for (int i = 0; i < capacity; i++)
        {
            newstack[i] = stack[i];
        }
        delete[] stack;
        stack = newstack;
        capacity +=1;
    }
    ArrayStack()
    {
        top = -1;
        capacity = 1;
        stack = new int[capacity];
    }

    void Push(int val)
    {
        if (Full())
        {
            addcapacity();
        }
        stack[++top] = val;
    }
    void Pop()
    {
        if(Empty()){
            return;
        }else{
            stack[top] = NULL;
            top--;
        }
    }
    bool Empty()
    {
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
    bool Full()
    {
        if(top == capacity-1){
            return true;
        }else{
            return false;
        }
    }
    int Top()
    {
        if(Empty()){
            cout << "stack is empty."<<endl;
            return 0;
        }
        return stack[top];
    }
    int getSize()
    {
        return top+1;
    }
    int getCapacity()
    {
        return capacity;
    }
    void Clear()
    {
        for(int i = top;i > -1;i++){
            stack[top] = NULL;
            top--;
        }
    }
};
/*
InitStack()
DestoryStack()
ClearStack()

 */
int main()
{
    ArrayStack s;
    s.Pop();
    cout << s.getCapacity()<<endl;
    s.Push(14);
    cout << s.getCapacity()<<endl;
    s.Push(9);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    cout << s.getCapacity()<<endl;
    s.Push(7);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    cout << s.getCapacity()<<endl;
    s.Pop();
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl; 
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    cout << s.getCapacity()<<endl;
    system("pause");
    return 0;
}