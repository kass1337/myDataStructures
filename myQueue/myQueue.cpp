#include <iostream>
template <class T> 
class myQueue {
    private:
    class Node;
        class Node {
            public:
                Node* next = nullptr;
                T data;
                Node() {};
                Node(const T& _data) : data(_data) {};
        };
        Node* tail;
        Node* head;
        int sz;
    public:
        myQueue();
        ~myQueue();
        myQueue(const myQueue& src);
        myQueue<T>& operator =(const myQueue& src);
        T& front();
        T& back();
        inline int size() { return sz; }
        inline bool empty() { return  sz == 0 ? true : false; }  
        void push(const T& _data);
        void pop();
        //void print() {
            //Node* temp = new Node();
           // temp = this->head;
            //while (temp != nullptr) {
            //std::cout << temp->data <<std::endl;
           // temp = temp->next;
            //}
        //}

};
template <class T>
myQueue<T>::myQueue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->sz = 0;
}
template <class T>
myQueue<T>::~myQueue(){
    while(this->head != nullptr) {
        this->pop();
        this->head = this->head->next;
    }
    }
template <class T>
myQueue<T>::myQueue(const myQueue& src){
    this->head = nullptr;
    this->tail = nullptr;
    this->sz = 0;
    Node* temp = new Node();
    temp = src.head;
    while (temp != nullptr) {
        this->push(temp->data);
        temp = temp->next;
    }
}
template <class T>
myQueue<T>& myQueue<T>::operator =(const myQueue& src) {
    if (this == &src) return *this;
    myQueue copy(src);
    std::swap(this->tail, copy.tail);
    std::swap(this->sz, copy.sz);
    std::swap(this->head, copy.head);
    return *this;
}
template <class T>
void myQueue<T>::push(const T& _data) {
    this->sz++;
    Node* temp = new Node(_data);
    if (this->head == nullptr) {
        this->tail = temp;
        this->head = this->tail;
    }
    else {
        if (this->head->next == nullptr) this->head->next = this->tail;
        this->tail->next = temp;
        this->tail = this->tail->next;
    }
}
template <class T>
void myQueue<T>::pop() {
    if (this->head == nullptr) return;

    Node* temp = this->head->next;
    delete this->head;
    this->head = temp;
    this->sz--;
}
template <class T>
T& myQueue<T>::back() {
    return this->tail->data;
}
template <class T>
T& myQueue<T>::front() {
    return this->head->data;
}