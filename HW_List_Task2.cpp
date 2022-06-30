#include <iostream>
#include <ctime>
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
    Queue(const Queue& other)
    {
        head = tail = NULL; length = 0;
        Node<T>* tmp = other.head;
        while (tmp != 0)
        {
            AddToTail(tmp->value);
            tmp = tmp->next;
        }
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


    Queue& operator = (const Queue& other)
    {
        if (this == &other)
            return *this;
        this->~Queue();
        Node<T>* tmp = other.head;
        while (tmp != 0) 
        {
            AddToTail(tmp->value);
            tmp = tmp->next;
        }
        return *this;
    }
    Queue operator + (const Queue& other)
    {
        Queue res(*this);
        Node<T>* tmp = other.head;
        while (tmp != 0)
        {
            res.AddToTail(tmp->value);
            tmp = tmp->next;
        }
        return res;
    }
    Queue operator * (const Queue& other)
    {
        Queue res;
        bool flag = false;
        Node<T>* buff;
        Node<T>* tmp = other.head;
        while (tmp != 0)
        {
            buff = this->head;
            while (buff != 0)
            {
                if (buff->value == tmp->value)
                {
                    Queue copy_q = res;
                    Node<T>* copy = copy_q.head;
                    while (copy != 0)
                    {
                        if (buff->value == copy->value)
                        {
                            flag = true;
                            break;
                        }
                        copy = copy->next;
                    }
                    if (flag == false)
                        res.AddToTail(buff->value);
                    break;
                }
                buff = buff->next;
            }
            tmp = tmp->next;
        }
        return res;
    }
};

int main()
{
    srand(time(0));
    Queue <int> twoNodesQueue;
    const int N = 5;
    int arr1[N] = { 0, 1, 2, 3, 4 };
    for (size_t i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            twoNodesQueue.AddToHead(arr1[i]);
        else
            twoNodesQueue.AddToTail(arr1[i]);
    }
    twoNodesQueue.Show();

    Queue <int> queue2;
    int buff;
    for (size_t i = 0; i < N; i++)
    {
        buff = rand() % 10;
        queue2.AddToTail(buff); 
    }
    queue2.Show();
    cout << "Queue2: ";
    
    Queue <int> sum = twoNodesQueue + queue2;
    cout << "Sum: ";
    sum.Show();

    Queue <int> mult = twoNodesQueue * queue2;
    cout << "Multiply: ";
    mult.Show();

    return 0;
}