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
class Array
{
    Node<T>* head;
    Node<T>* tail;
    int length;
    int count;
public:
    Array()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
        this->count = 10;
    }
    Array(const Array& array)
    {
        head = tail = NULL;
        length = 0;
        Node<T>* tmp = array.head;
        while (tmp != 0)
        {
            AddToTail(tmp->value);
            tmp = tmp->next;
        }
    }
    ~Array() { Clear(); }
    bool Empty() { return (length == 0) ? true : false; }
    int GetSize() { return length; }
    void SetSize(int size, int grow = 1)
    {
        if (size > length)
        {
            int tmp = size;
            int newLen = tmp + grow - 1;
            length = newLen;
        }
        else
        {
            length = size;
            grow = 0;
        }
    }
    int GetUpperBound()
    {
        cout << length << "/" << count << endl;
        return length - 1;
    }
    void FreeExtra()
    {
        Node<T>* tmp = new Node<T>;
        tmp = head;
        for (size_t i = 0; i < length; i++)
        {
            while (tmp->value != NULL)
                tmp = tmp->next;
            tmp = 0;
        }
        delete tmp;
    }
    T GetAt(int pos = 0)
    {
        if (pos == 0) {
            cout << "Input position: ";
            cin >> pos;
        }
        else if (pos < 1 || pos > count + 1) {
            cout << "Incorrect position !\n";
            return 0;
        }
        Node<T>* tmp = new Node<T>;
        if (pos < count) {
            tmp = head;
            int i = 1;
            while (i < pos) {
                tmp = tmp->next;
                i++;
            }
        }
        return tmp->value;
    }
    void SetAt(T value, int pos = 0)
    {
        if (pos == 0) {
            cout << "Input position: ";
            cin >> pos;
        }
        else if (pos < 1 || pos > count + 1) {
            cout << "Incorrect position !\n";
            pos--;
            if (pos >= 0 || pos < length)
            {
                Node<T>* tmp = this->head;
                int i = 0;
                while (tmp != 0)
                {
                    if (i == pos)
                        tmp->value = value;
                    tmp = tmp->next;
                    i++;
                }
            }
        }
    }
    void AddToHead(T elem)
    {
        Node<T>* tmp = new Node<T>;
        tmp->prev = 0; tmp->value = elem; tmp->next = head;
        if (head != 0)
            head->prev = tmp;
        if (length == 0)
            head = tail = tmp;
        else
            head = tmp;
        if (tmp->value != 0)
            length++;
    }
    void AddToTail(T elem)
    {
        Node<T>* tmp = new Node<T>;
        tmp->next = 0; tmp->value = elem; tmp->prev = tail;
        if (tail != 0)
            tail->next = tmp;
        if (length == 0)
            head = tail = tmp;
        else
            tail = tmp;
        if (tmp->value != 0)
            length++;
    }
    void InsertAt(int pos = 0)
    {
        if (pos == 0) {
            cout << "Input position: ";
            cin >> pos;
        }
        else if (pos < 1 || pos > length + 1) {
            cout << "Incorrect position !\n";
            return;
        }
        if (pos == length + 1) {
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
        if (prevIns != 0 && length != 1)
            prevIns->next = tmp;
        tmp->next = ins;
        tmp->prev = prevIns;
        ins->prev = tmp;
        if (tmp->value != 0)
            length++;
    }
    Array Append(const Array & arr)
    {
        Array res(*this);
        Node<T>* tmp = arr.head;
        while (tmp != 0)
        {
            res.AddToTail(tmp->value);
            tmp = tmp->next;
        }
        return res;
    }
    void Pop()
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
    void DeleteAt(int pos = 0)
    {
        if (pos == 0) {
            cout << "Input position: ";
            cin >> pos;
        }
        else if (pos < 1 || pos > length + 1) {
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
        if (prevDel != 0 && length != 1)
            prevDel->next = afterDel;
        else if (afterDel != 0 && length != 1)
            afterDel->prev = prevDel;
        if (pos == 1)
            head = afterDel;
        else if (pos == length)
            tail = prevDel;
        delete del;
        length--;
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
    void Clear()
    {
        while (!Empty())
            Pop();
    }
    Array& operator = (const Array & arr)
    {
        if (this == &arr)
            return *this;
        this->~Array();
        Node<T>* tmp = arr.head;
        while (tmp != 0)
        {
            AddToTail(tmp->value);
            tmp = tmp->next;
        }
        return *this;
    }
};

int main()
{
    Array <int> array;
    const int N = 8;
    int arr1[N] = { 1, 2, 3, 4 };
    int arr2[N] = { 5, 1, 3, 8, 3 };
    for (int i = 0; i < N; i++)
        array.AddToTail(arr1[i]);
    array.Show();

    cout << "GetUpperBound: " << array.GetUpperBound() << endl;
    array.SetSize(6, 5);
    cout << "size: " << array.GetSize() << endl;

    array.SetAt(12, 4);
    array.Show();
    cout << array.GetAt(4) << endl;

    Array <int> array2;
    Array <int> array3;
    for (int i = 0; i < N; i++)
        array2.AddToTail(arr2[i]);
    array2.Show();

    array3 = array.Append(array2);
    array3.Show();

    array.FreeExtra();
    array.Show();

    return 0;
}