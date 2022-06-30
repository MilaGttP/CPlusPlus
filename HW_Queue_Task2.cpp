#include <iostream>
using namespace std;

template <typename T>
class NodeClient
{
public:
    NodeClient* next;
    NodeClient* prev;
    uint32_t prior;
    uint32_t time;
    NodeClient()
    {
        this->prior = 0;
        this->next = nullptr;
        this->prev = nullptr;
        this->prior = 0;
        this->time = 0;
    }
    NodeClient(int prior) :NodeClient() { this->prior = prior; }
    NodeClient(uint32_t time, int prior = 0)
    {
        this->time = time;
        this->prior = prior;
    }
}; 

template <typename T>
class PrintQueue
{
protected:
    NodeClient<T>* head;
    NodeClient<T>* tail;
    NodeClient<T>* headStat;
    NodeClient<T>* tailStat;
    uint32_t length;
public:
    PrintQueue()
    {
        this->head = nullptr; this->tail = nullptr; 
        this->length = 0;
        this->headStat = NULL; this->tailStat = NULL;
    }
    ~PrintQueue() { Clear(); }
    bool Empty() { return (length == 0) ? true : false; }
    void AddQueue(uint32_t time, uint32_t prior)
    {
        NodeClient<T>* tmp = new NodeClient<T>;
        tmp->prior = prior;
        tmp->time = time;
        tmp->next = NULL;
        if (head != NULL)
        {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        }
        else
        {
            tmp->prev = NULL;
            head = tmp;
            tail = tmp;
        }
    }
    void ShowQueue()
    {
        NodeClient<T>* tmp = head;
        while (tmp)
        {
            cout << "Prioritet: " << tmp->prior << endl;
            cout << "Time of printing (in minutes): " << tmp->time << endl;
            tmp = tmp->next;
            cout << endl;
        }
    }
    void Statistics(uint32_t time, uint32_t prior)
    {
        NodeClient<T>* tmp = new NodeClient<T>;
        NodeClient<T>* buff = headStat;
        bool flag = false;
        while (buff != NULL)
        {
            flag = true;
            buff->time += time;
            buff = buff->next;
        }
        if (flag == false)
        {
            tmp->prior = prior;
            tmp->time = time;
            tmp->next = NULL;
            if (headStat != NULL)
            {
                tmp->prev = tailStat;
                tailStat->next = tmp;
                tailStat = tmp;
            }
            else
            {
                tmp->prev = NULL;
                headStat = tmp;
                tailStat = tmp;
            }
        }
    }
    void ShowStatistics()
    {
        NodeClient<T>* tmp = headStat;
        while (tmp)
        {
            cout << "Time of printing (in minutes): " << tmp->time << endl;
            tmp = tmp->next;
            cout << endl;
        }
    }
    void Pop()
    {
        NodeClient<T>* tmp = new NodeClient<T>();
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
    void Clear()
    {
        while (!Empty())
            Pop();
    }
};

int main()
{
    int menu = 0;
    uint32_t prior; uint32_t time;
    PrintQueue <uint32_t> queue;

    cout << "Hello! Enter your data: " << endl;
    cout << "Enter prior: ";
    cin >> prior;
    cout << "Enter time of printing (in minutes): ";
    cin >> time;
    queue.AddQueue(time, prior);
    queue.Statistics(time, prior);
    system("cls");
    cout << "Client: \n";
    queue.ShowQueue();
    system("pause");
    system("cls");
    cout << "Statistics \n";
    queue.ShowStatistics();
    system("pause");
    queue.Clear();

    return 0;
}