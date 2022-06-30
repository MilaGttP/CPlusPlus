
#include <iostream>
#include <ctime>
#include <queue>
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
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int prior) :Node()
    {
        this->prior = prior;
    }
    Node(T value, int prior = 0)
    {
        this->value = value;
        this->prior = prior;
    }
    T GetValue()
    {
        return this->value;
    }
    int GetPrior()
    {
        return this->prior;
    }
};
template <typename T>
class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;
    uint32_t length;
public:
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    ~Queue()
    {
        Clear();
    }
    uint32_t size()
    {
        return length;
    }
    bool empty()
    {
        return (length == 0) ? true : false;
    }
    bool Push(T elem, int prior = 0) // з пріоритетом
    {
        Node<T>* node_elem = new Node<T>(elem, prior);
        Node<T>* buf;
        if (head == NULL || prior < head->prior) {
            node_elem->next = head;
            head = node_elem;
        }
        else {
            buf = head;
            while (buf->next != NULL && buf->next->prior <= prior)
                buf = buf->next;
            node_elem->next = buf->next;
            buf->next = node_elem;
        }
        length++;
        return true;
    }
    //bool Push(T elem) //без пріорітету
    //{
    //    Node<T>* node_elem = new Node<T>(elem);
    //    if (empty())
    //    {
    //        head = tail = node_elem;
    //    }
    //    else
    //    {
    //        tail->next = node_elem;
    //        node_elem->prev = tail;
    //        tail = node_elem;
    //    }
    //    length++;
    //    return true;
    //}
    bool Pop()
    {
        Node<T>* node_elem = new Node<T>();
        node_elem = head;
        if (node_elem->next == nullptr)
        {
            tail = head = nullptr;
        }
        else {
            head = node_elem->next;
            head->prev = nullptr;
        }
        length--;
        delete node_elem;
        return true;
    }
    T Front()
    {
        if (length == 0)
        {
            return (T)NULL;
        }
        else {
            return head->GetValue();
        }
    }
    T Back()
    {
        if (length == 0)
        {
            return (T)NULL;
        }
        else {
            return tail->GetValue();
        }
    }
    void Print()
    {
        Node<T>* node_elem = new Node<T>();
        if (empty())
        {
            cout << "Queue is empty!" << endl;
        }
        else {
            cout << "Queue -> ";
            node_elem = head;
            do {
                cout << "[" << node_elem->GetValue() << " : " << node_elem->GetPrioritet() << "]" << ' ';
                node_elem = node_elem->next;
            } while (node_elem != nullptr);
            cout << endl;
            // 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> nullptr      // |    |    // head       tail       }
        }
    }

    bool Clear()
    {
        do {
            Pop();
        } while (tail != nullptr);
    }
};

void StlQueue()
{
    priority_queue <int> p_q;
    for (size_t i = 0; i < 10; i++)
    {
        //cout << i << endl;
        p_q.push(i);
    }
    cout << p_q.top() << endl;
}

int main()
{
    srand(time(0));
    Queue <int> queue;
    int elem, prior;
    for (size_t i = 0; i < 5; i++)
    {
        elem = rand() % 10; prior = rand() % 5;
        cout << "Iteration #" << i << endl;
        queue.Push(elem, prior);
        queue.Push(i);
        /*cout << "Front = " << queue.Front() << endl;
        cout << "Back = " << queue.Back() << endl;*/
        cout << endl << endl;
    }
    queue.Print();
    queue.Pop();    
    cout << "Front = " << queue.Front() << endl;
    queue.Pop();    
    cout << "Front = " << queue.Front() << endl;
    queue.Print();
    queue.Clear();
    if (queue.empty())
    {
        cout << "Queue is empty!" << endl;
    }
    else {
        cout << "Queue is not empty!" << endl;
    }

    return 0;
}