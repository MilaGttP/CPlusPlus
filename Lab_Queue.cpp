
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
    int prior;
    Node()
    {
        this->prior = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int prior) :Node() { this->prior = prior; }
    Node(T value, int prior = 0)
    {
        this->value = value;
        this->prior = prior;
    }
    T GetValue() { return this->value; }
    int GetPrioritet() {  return this->prior; }
};

template <typename T>
class QueuePriority
{
private:
    Node<T>* head;
    Node<T>* tail;
    uint32_t length;
public:
    QueuePriority()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    ~QueuePriority() { Clear(); }
    bool Empty() { return (length == 0) ? true : false; }
    bool Full() { return (length != 0) ? true : false; }
    void InsertWithPriority(T elem, int prior = 0)
    {
        Node<T>* tmp = new Node<T>(elem, prior);
        Node<T>* buff = nullptr;
        if (head == NULL || prior > head->prior) {
            tmp->next = head;
            head = tmp;
        }
        else {
            buff = head;
            while (buff->next != NULL && buff->next->prior >= prior)
                buff = buff->next;
            tmp->next = buff->next;
            buff->next = tmp;
        }
        length++;
    }
    void PullHighestPriorityElement()
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
    T Peek() { return head->prior; }
    void Show()
    {
        Node<T>* tmp = new Node<T>();
        if (Empty())
            cout << "Queue is empty!" << endl;
        else {
            cout << "Queue -> \t";
            tmp = head;
            do {
                cout << "[" << tmp->GetValue() 
                    << " : " << tmp->GetPrioritet() << "]" << ' ';
                tmp = tmp->next;
            } while (tmp != nullptr);
            cout << endl;
        }
    }
    bool Clear()
    {
        while (!Empty())
            PullHighestPriorityElement();
        return true;
    }
};

int main()
{
    srand(time(0));
    QueuePriority <int> queueP;
    int elem, prior;
    for (size_t i = 0; i < 5; i++)
    {
        elem = rand() % 10; prior = rand() % 5;
        cout << "Iteration #" << i << endl;
        queueP.InsertWithPriority(elem, prior);
        queueP.InsertWithPriority(i);
        queueP.Show();
        cout << endl << endl;
    }
    queueP.Show();
    queueP.PullHighestPriorityElement();
    cout << "Popped a highest priority elem" << endl;
    queueP.Show();
    cout << "Highest priority elem: " << queueP.Peek() << endl;
    queueP.Clear();
    if (queueP.Empty())
        cout << "Queue is empty!" << endl;
    else if (queueP.Full())
        cout << "Queue is full!" << endl;
    return 0;
}