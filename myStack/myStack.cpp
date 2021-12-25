#include <iostream>
template <class T> 
class myStack {
    private:
    class Node;
        class Node {
            public:
                Node* prev = nullptr;
                T data;
                Node() {};
                Node(const T& _data) : data(_data) {};
        };
        Node* cur;
        int sz;
    public:
        myStack();
        ~myStack();
        myStack(const myStack& src);
        myStack<T>& operator =(const myStack& src);
        T& top();
        inline int size() { return sz; }
        inline bool empty() { return  sz == 0 ? true : false; }  
        void push(const T& _data);
        void pop();
       // void print() {
           // Node* temp = new Node();
           // temp = this->cur;
            //while (temp != nullptr) {
           // std::cout << temp->data <<std::endl;
          //  temp = temp->prev;
          //  }
        //}

};
template <class T>
myStack<T>::myStack(){
    this->cur = nullptr;
    this->sz = 0;
}
template <class T>
myStack<T>::~myStack(){
    while(this->cur == nullptr) {
        this-pop();
    }
    }
template <class T>
myStack<T>::myStack(const myStack& src){
    this->cur = nullptr;
    this->sz = 0;
    Node* temp = new Node();
    temp = src.cur;
    T* buf = new T[src.sz];
    int i = 0;
    while(temp != nullptr) {
        buf[i] = temp->data;
        i++;
        temp = temp->prev;
    }
    for(i--; i >= 0; i--) {
        this->push(buf[i]);
    }
}
template <class T>
myStack<T>& myStack<T>::operator =(const myStack& src) {
    if (this == &src) return *this;
    myStack copy(src);
    std::swap(this->cur, copy.cur);
    std::swap(this->sz, copy.sz);
    return *this;
}
template <class T>
void myStack<T>::push(const T& _data) {
    if (this->cur == nullptr) {
        this->cur = new Node(_data);
        this->sz++;
    }
    else {
        Node* temp = new Node(_data);
        temp->prev = this->cur;
        this->cur = temp;
        this->sz++;
    }
}
template <class T>
void myStack<T>::pop() {
    if (this->cur == nullptr) return;

    Node* temp = this->cur->prev;
    delete this->cur;
    this->cur = temp;
    this->sz--;
}
template <class T>
T& myStack<T>::top() {
    return this->cur->data;
}