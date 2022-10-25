class MyCircularQueue {
private:
    int front,rear,arr[1001],size,count;
public:
    MyCircularQueue(int k) {
        size = k;
        front = 0,rear = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(count == size) return false;
        arr[rear%size] = value;
        rear = (rear+1)%size;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(count == 0) return false;
        front = (front+1)%size;
        count--;
        return true;
    }
    
    int Front() {
        if(count == 0) return -1;
        return arr[front%size];
    }
    
    int Rear() {
        if(count == 0) return -1;
        return arr[(rear-1 + size)%size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size; 
    }
};