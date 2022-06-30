
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
class List
{
    Node<T>* head;
    Node<T>* tail;
    int count;
public:
    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~List() { DelAll(); }
    int GetCount() { return count; }
    int Empty() { return (count == 0) ? true : false; }
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
        count++;
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
        count++;
    }
    void Insert(int pos = 0)
    {
        if (pos == 0) {
            cout << "Input position: ";
            cin >> pos;
        }
        else if (pos < 1 || pos > count + 1) {
            cout << "Incorrect position !\n";
            return;
        }
        if (pos == count + 1) {
            int data;
            cout << "Input new number: ";
            cin >> data;
            AddToTail(data);
            return;
        }
        else if (pos == 1) {
            int data;
            cout << "Input new number: ";
            cin >> data;
            AddToHead(data);
            return;
        }
        Node<T>* ins = head;
        int i = 1;
        while (i < pos) {
            ins = ins->next;
            i++;
        }
        Node<T>* prevIns = ins->prev;
        Node<T>* tmp = new Node<T>;
        cout << "Input new number: ";
        cin >> tmp->value;
        if (prevIns != 0 && count != 1)
            prevIns->next = tmp;
        tmp->next = ins;
        tmp->prev = prevIns;
        ins->prev = tmp;
        count++;
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
        count--;
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
        count--;
        delete tmp;
    }
    void DelAt(int pos = 0)
    {
        if (pos == 0) {
            cout << "Input position: ";
            cin >> pos;
        }
        else if (pos < 1 || pos > count + 1) {
            cout << "Incorrect position !\n";
            return;
        }
        Node<T>* del = head;
        int i = 1;
        while (i < pos)
        {
            del = del->next;
            i++;
        }
        Node<T>* prevDel = del->prev;
        Node<T>* afterDel = del->next;
        if (prevDel != 0 && count != 1)
            prevDel->next = afterDel;
        else if (afterDel != 0 && count != 1)
            afterDel->prev = prevDel;
        if (pos == 1)
            head = afterDel;
        else if (pos == count)
            tail = prevDel;
        delete del;
        count--;
    }
    void DelAll()
    {
        while (!Empty())
            DelFromHead();
    }
    void Show()
    {
        Node<T>* tmp = new Node<T>();
        if (Empty())
            cout << "List is empty!" << endl;
        else {
            cout << "List ->" << "\t";
            tmp = head;
            do {
                cout << tmp->GetValue() << "\t";
                tmp = tmp->next;
            } while (tmp != nullptr);
            cout << endl;
        }
    }
    T SearchByPos(int pos = 0)
    {
        if (pos == 0) {
            cout << "Input position: ";
            cin >> pos;
        }
        else if (pos < 1 || pos > count + 1) {
            cout << "Incorrect position !\n";
            return 0;
        }
        Node<T>* tmp;
        if (pos <= count / 2) {
            tmp = head;
            int i = 1;
            while (i < pos) {
                tmp = tmp->next;
                i++;
            }
        }
        else {
            tmp = tail;
            int i = 1;
            while (i <= count - pos) {
                tmp = tmp->prev;
                i++;
            }
        }
        return tmp->value;
    }
    T SearchAndChangeByPos(int pos = 0)
    {
        if (pos == 0) {
            cout << "Input position: ";
            cin >> pos;
        }
        else if (pos < 1 || pos > count + 1) {
            cout << "Incorrect position !\n";
            return 0;
        }
        Node<T>* newVal = new Node<T>;
        cout << "Input new value for this pos: ";
        cin >> newVal->value;
        Node<T>* tmp;
        if (pos <= count / 2) {
            tmp = head;
            int i = 1;
            while (i < pos) {
                tmp = tmp->next;
                i++;
            }
        }
        else {
            tmp = tail;
            int i = 1;
            while (i <= count - pos) {
                tmp = tmp->prev;
                i++;
            }
        }
        tmp->value = newVal->value;
        return tmp->value;
    }
    List operator - ()
    {
        List res;
        Node<T>* tmp = head;
        while (tmp != 0)
        {
            res.AddToHead(tmp->value);
            tmp = tmp->next;
        }
        return res;
    }
};

int main()
{
    List <int> list;
    const int N = 5;
    int arr[N] = { 0,1,2,3,4 };

    for (size_t i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            list.AddToHead(arr[i]);
        else
            list.AddToTail(arr[i]);
    }
    list.Show();

    list.Insert();
    list.Show();
    list.DelAt();
    list.Show();
    cout << "Value of this pos: " << list.SearchByPos() << "\n";
    list.SearchAndChangeByPos();
    list.Show();

    list.DelAll();
    list.Show();

    return 0;
}