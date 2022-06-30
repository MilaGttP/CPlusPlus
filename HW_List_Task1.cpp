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
        this->next = nullptr;
        this->prev = nullptr;
        this->value = 0;
    }
    Node(T value) :Node() { this->value = value; }
    T GetValue() { return this->value; }
};

template <typename T>
class Queue
{
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    ~Queue() { Clear(); }
    int GetLength() { return length; }
    int Empty() { return (length == 0) ? true : false; }
    void AddToHead(T elem)
    {
        Node<T>* tmp = new Node<T>(elem);
        if (Empty())
            head = tail = tmp;
        else {
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }
        length++;
    }
    void AddToTail(T elem)
    {
        Node<T>* tmp = new Node<T>(elem);
        if (Empty())
            head = tail = tmp;
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        length++;
    }
    void DelFromHead()
    {
        Node<T>* tmp = new Node<T>();
        tmp = head;
        if (tmp->next == nullptr)
            tail = head = nullptr;
        else
        {
            head = tmp->next;
            head->prev = nullptr;
        }
        length--;
        delete tmp;
    }
    void DelFromTail()
    {
        Node<T>* tmp = new Node<T>();
        tmp = tail;
        if (tmp->prev == nullptr)
            tail = head = nullptr;
        else
        {
            tail = tmp->prev;
            tail->next = nullptr;
        }
        length--;
        delete tmp;
    }
    void Show()
    {
        Node<T>* tmp = new Node<T>();
        if (Empty())
            cout << "Queue is empty!" << endl;
        else {
            cout << "Queue ->" << "\t";
            tmp = head;
            do {
                cout << tmp->GetValue() << "\t";
                tmp = tmp->next;
            } while (tmp != nullptr);
            cout << endl;
        }
    }
    void Clear()
    {
        while (!Empty())
            DelFromHead();
    }
};

int main()
{
    Queue <int> twoNodeQueue;
    const int N = 5;
    int arr[N] = { 0, 1, 2, 3, 4 };

    for (size_t i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            twoNodeQueue.AddToHead(arr[i]);
        else
            twoNodeQueue.AddToTail(arr[i]);
    }
    twoNodeQueue.Show();

    twoNodeQueue.Clear();
    twoNodeQueue.Show();

    return 0;
}