#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node* next;
    Node* prev;

    Node()
    {
        value = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(T value) :Node() { this->value = value; }
};

template <typename T>
class Stack
{
private:
    Node<T>* head;
    Node<T>* tail;
    int lenght;

public:
    Stack();
    ~Stack();

    T GetValue() { return this->value; }
    void Push(T elem);
    void Pop();
    int Size() { return lenght; }
    bool Empty() { return (lenght == 0) ? true : false; }
    bool Full() { return (lenght != 0) ? true : false; }
    void PrintAll();
    void Clear();
    T Top();
};

template<typename T>
Stack<T>::Stack()
{
    this->head = nullptr; this->tail = nullptr; lenght = 0;
}

template<typename T>
Stack<T>::~Stack()
{
    Clear();
}

template<typename T>
inline void Stack<T>::Push(T elem)
{
    Node<T>* other = new Node<T>(elem);
    if (Empty())
        head = tail = other;
    
    else
    {
        tail->next = other;
        other->prev = tail;
        tail = other;
    }
    lenght++;
}

template<typename T>
void Stack<T>::Pop()
{
    Node<T>* other = new Node<T>();
    other = tail;
    if (other->prev = nullptr)
        tail = head = nullptr;
    
    else
    {
        tail = other->prev;
    }
    delete other;
    --lenght;
}

template<typename T>
void Stack<T>::PrintAll()
{
    Node<T>* other = tail;
    do {
        cout << other->value << "\t";
        other = other->prev;
    } while (other != nullptr);
    cout << endl;
}

template<typename T>
void Stack<T>::Clear()
{
    do {
        Pop();
    } while (tail != nullptr);
}

template<typename T>
T Stack<T>::Top()
{
    if (Empty())
        return (T)NULL;
    else
        return tail->value;
}

//check
int main()
{
    Stack <char> stack;
    for (size_t i = 0; i < 10; i++)
    {
        stack.Push(i);
        cout << "Top [" << i << "] : " << stack.Top() << endl;
    }
    stack.Pop();
    cout << "Top : " << stack.Top() << endl;
    stack.PrintAll();
    if (stack.Empty())
        cout << "Stack is empty!" << endl;
    else
        cout << "Stack is not empty!" << endl;

    cout << "Size: " << stack.Size() << endl;
    stack.Clear();
    return 0;
}