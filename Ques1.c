#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}
    int getFront() {
        if (front == nullptr) {
            std::cerr << "Queue is empty." << std::endl;
            return -1; 
        }
        return front->data;
    }
    int getRear() {
        if (rear == nullptr) {
            std::cerr << "Queue is empty." << std::endl;
            return -1;
        }
        return rear->data;
    }
    void enQueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { 
            front = rear = newNode;
            newNode->next = front; 
        } else {
            newNode->next = front; 
            rear->next = newNode;  
            rear = newNode;       
        }
    }
    void deQueue() {
        if (front == nullptr) {
            std::cerr << "Queue is empty." << std::endl;
            return;
        }

        if (front == rear) { 
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; 
            delete temp;
        }
    }
};

int main() {
    CircularQueue q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    std::cout << "Front: " << q.getFront() << std::endl; 
    std::cout << "Rear: " << q.getRear() << std::endl;   

    q.deQueue();
    std::cout << "Front: " << q.getFront() << std::endl; 

    return 0;
}
