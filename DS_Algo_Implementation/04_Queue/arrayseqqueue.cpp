#include "iostream"
using namespace std;
// use array to implement
class arrayseqqueue{
public:
    int capacity;
    int size = 0;
    int front,back;
    int *queue;
    
    arrayseqqueue(){
        capacity = 1;
        front = -1;
        back = -1;
        queue = new int[capacity];
    }
    void addcapacity(){
        capacity +=1;
        int *newqueue = new int[capacity];
        int newback = -1;
        for(int i = front+1;i<=back;i++){
            newback++;
            newqueue[newback] = queue[i];
        }
        front = -1;
        back = newback;
       
        queue = newqueue;

    }
    void Push(int val){
        if(back+1 == capacity){
            addcapacity();
        }

        queue[back+1] = val;
        back = back+1;
        size++;
    }
    void Pop(){
        if(IsEmpty()){
           cout << "Is Empty"<<endl;    
        }
        
        queue[front+1] = 0;
        front++;
        size--;
    }
    bool IsEmpty(){
        if(size ==0){
            return true;
        }else{
            return false;
        }
    }
    bool IsFull(){
        if(back-front == capacity){
            return true;
        }else{
            return false;
        }
    }
    int getFront(){
        if(IsEmpty()){
           cout << "Is Empty"<<endl;
        }
        return queue[front+1];
    }
    int getBack(){
        if(IsEmpty()){
           cout << "Is Empty"<<endl;    
        }
        return queue[back];
    }
    int getSize(){
        return size;
    }
    int getCapacity(){
        return capacity;
    }
    void resetCapacity(){
        int newqueue[size];

        for(int i = 0;i<size;i++){
            newqueue[i] = queue[i];
        }
        queue = newqueue;
    }

    void printSequentialQueue (arrayseqqueue q){

    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n"
    << "capacity: " << q.getCapacity() << "  number of elements: " << q.getSize() << "\n\n";

    return ;
    }


};
int main(){
    arrayseqqueue q;
    if (q.IsEmpty()) {
        cout << "Queue is empty.\n\n";
    }
    q.Push(24);
    cout << "After push 24: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n"
    << "capacity: " << q.getCapacity() << "  number of elements: " << q.getSize() << "\n\n";
    q.Push(8);
    q.Push(23);
    cout << "After push 8, 23: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n"
    << "capacity: " << q.getCapacity() << "  number of elements: " << q.getSize() << "\n\n";
    q.Pop();
    cout << "After pop 24: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n"
    << "capacity: " << q.getCapacity() << "  number of elements: " << q.getSize() << "\n\n";
    q.Push(13);
    cout << "After push 13: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n"
    << "capacity: " << q.getCapacity() << "  number of elements: " << q.getSize() << "\n\n";
    q.Pop();
    cout << "After pop 8: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n"
    << "capacity: " << q.getCapacity() << "  number of elements: " << q.getSize() << "\n\n";
    q.Push(35);
    cout << "After push 35: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n"
    << "capacity: " << q.getCapacity() << "  number of elements: " << q.getSize() << "\n\n";
    q.Push(9);
    cout << "After push 9: \n";
    cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n"
    << "capacity: " << q.getCapacity() << "  number of elements: " << q.getSize() << "\n\n";

    system("pause");
    return 0;
}