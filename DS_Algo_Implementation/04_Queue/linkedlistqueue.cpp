#include "iostream"
using namespace std;
// use linkedlist to implement

class linkedQueuenode{
public:
    struct queuenode{
        int data = 0;
        queuenode* next = 0;

        queuenode(int val){
            data = val;
            next = NULL;
        }
    };
    queuenode *front;
    queuenode *tail;
    int size = 0;

    int getFront(){
        if(QueueEmpty()){
            cout << "is empty, no head"<<endl;
            return 0;
        }else{
            return front->data;
        }
    }
    int getBack(){
        if(QueueEmpty()){
            cout << "is empty, no tail"<<endl;
            return 0;
        }else{
            queuenode *current = front;
            while(current->next !=NULL){
                current = current->next;
            }
            return current->data;
        }
    }
    void EnQueue(int val){
        queuenode *newnode = new queuenode(val);
        if(QueueEmpty()){
            front = newnode;
            tail = newnode;
            size++;
        }else{
            queuenode *current = tail;

            current->next = newnode;
            tail = newnode;
            size++;
            
        }
    }
    void DeQueue(){
        if(QueueEmpty()){
            cout << "is empty"<<endl;
        }else{
            queuenode *current = front;
            front = current->next;
            delete current;
            size --;
        }
        
    }
    int QueueLength(){
        return size;
    }
    bool QueueEmpty(){
        if(size == 0){
            return true;
        }else{
            return false;
        }
    }
    void ClearQueue(){
        if(QueueEmpty()){
            cout << "is empty"<<endl;
        }else{
            
            while(front !=NULL){
                queuenode *current = front;
                front = front->next;
                delete current;
            }
        }
    }

};
/*
InitQueue()
DestoryQueue()
ClearQueue()
QueueEmpty()
GetHead()
EnQueue()
DeQueue()
QueueLength()
 */
int main(){
   linkedQueuenode q;
    if (q.QueueEmpty()) {
        std::cout << "Queue is empty.\n";
    }
    q.EnQueue(24);
    std::cout<< "\nAfter push 24: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() <<" "<<q.QueueLength()<< "\n";
    q.EnQueue(8);
    std::cout<< "\nAfter push 8: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() <<" "<<q.QueueLength()<< "\n";
    q.EnQueue(23);
    std::cout<< "\nAfter push 23: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() <<" "<<q.QueueLength()<< "\n";
    q.EnQueue(13);
    std::cout<< "\nAfter push 13: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() <<" "<<q.QueueLength()<< "\n";
    q.DeQueue();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() <<" "<<q.QueueLength()<< "\n";
    q.EnQueue(35);
    std::cout<< "\nAfter push 35: \n";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() <<" "<<q.QueueLength()<<"\n";
    q.DeQueue();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() <<" "<<q.QueueLength()<< "\n";
    q.DeQueue();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() <<" "<<q.QueueLength()<< "\n";
    q.DeQueue();
    std::cout<< "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() <<" "<<q.QueueLength()<< "\n";
    q.DeQueue();
    std::cout<< "\nAfter pop the front element: \n";
    q.DeQueue();

    system("pause");
    return 0;
}