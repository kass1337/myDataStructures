#include <iostream>
template <class T>
class myDeque {
    private:
        class Node {
            public:
                Node* next = nullptr;
                T data;
                Node() {};
                Node (const T& _data) : data(_data) {};
        };
        Node* head;
        Node* tail;
        void pushFirst(Node*& temp);
        int sz;
    public:
        myDeque();
        myDeque(const myDeque& src);
        ~myDeque();
        myDeque<T>& operator =(const myDeque& src);
        inline int size() { return sz; }
        inline bool empty() { return sz == 0 ? true : false; }
        void clear();
        T& front();
        T& back();
        void push_back(const T& _data);
        void push_front(const T& _data);
        void pop_back();
        void pop_front();
        //void print() {
          //  Node* temp = new Node();
          //  temp = this->head;
          //  while(temp != nullptr) {
           //     std::cout<<temp->data<<std::endl;
           //     temp = temp->next;
           // }
       // }

};
template <class T>
myDeque<T>::myDeque() {
    this->head = nullptr;
    this->tail = nullptr;
    this->sz = 0;
}
template <class T>
myDeque<T>::~myDeque() {
    this->clear();
}
template <class T>
myDeque<T>& myDeque<T>::operator=(const myDeque& src) {
    if(this == &src) return *this;
    myDeque copy(src);
    std::swap(this->tail, copy.tail);
    std::swap(this->head, copy.head);
    std::swap(this.sz, copy.sz);
}
template<class T>
myDeque<T>::myDeque(const myDeque& src) {
    this->head = nullptr;
    this->tail = nullptr;
    this->sz = 0;
    Node* temp = src.head;
    while(temp != nullptr) {
        this->push_back(temp->data);
        temp = temp->next;
    }
}
template <class T>
void myDeque<T>::clear() {
    if(this->head == nullptr) return;
    while(this->head != nullptr) {
        this->pop_back();
    }
}
template <class T>
T& myDeque<T>::back() {
    if(this->tail == nullptr) {
        throw(std::runtime_error("Empty Deque"));
    }
    else {
        return this->tail->data;
    }
}
template <class T>
T& myDeque<T>::front() {
    if(this->head == nullptr) {
        throw(std::runtime_error("Empty Deque"));
    }
    else {
        return this->head->data;
    }
}
template <class T>
void myDeque<T>::pushFirst(Node*& temp) {
    this->head = temp;
    this->tail = this->head;
    this->sz++;
}
template <class T>
void myDeque<T>::push_front(const T& data) {
    Node* temp = new Node(data);
    if (this->head == nullptr) {
        this->pushFirst(temp);
        return;
    }
    else { 
        temp->next = this->head;
        this->head = temp;
        this->sz++;
    }
}
template <class T>
void myDeque<T>::push_back(const T& data) {
    Node* temp = new Node(data);
    if (this->head == nullptr) {
        this->pushFirst(temp);
        return;
    }
    else {
        if (this->head->next == nullptr) this->head->next = this->tail;
        this->tail->next = temp;
        this->tail = this->tail->next;
        this->sz++;
    }
}
template <class T>
void myDeque<T>::pop_front() {
    if(this->head == nullptr) return;
    Node* temp = this->head->next;
    delete this->head;
    this->head = temp;
    this-sz--; 
}
template <class T>
void myDeque<T>::pop_back() {
    if(this->tail == nullptr) return;
    if(this->head->next == nullptr) {
        this->pop_front();
        return;
    }
    Node*& temp = this->head;
    while(temp->next != this->tail) {
        temp = temp->next;
    }
    delete this->tail;
    this->tail = temp;
    this->tail->next = nullptr; 
    this->sz--;
}
