
#include <iostream>
#include <exception>
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
    }
    Node(T value) { this->value = value; }
    T GetValue() { return this->value; }
    ~Node() { next = nullptr; prev = nullptr; }
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
        head = tail = nullptr;
        count = 0;
    }
    List(const List& other) :List()
    {
        Node<T>* temp = other.head;
        while (temp != 0)
        {
            AddToTail(temp->data);
            temp = temp->next;
        }
    }
    ~List() { DelAll(); }
    int GetCount() { return count; }
    //Node<T>* GetElem(T elem);
    int Empty() { return (count == 0) ? true : false; }
    void AddToHead(T el)
    {
        Node<T>* tmp = new Node<T>(el);
        if (Empty())
        {
            head = tail = tmp;
            throw (string)"List is empty! (AddToHead)";
        }
        else
        {
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }
        count++;
    }
    void AddToTail(T el)
    {
        Node<T>* tmp = new Node<T>(el);
        if (Empty())
        {
            head = tail = tmp;
            throw (string)"List is empty! (AddToTail)";
        }
        else
        {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        count++;
    }
    void DelFromHead()
    {
        Node<T>* tmp = new Node<T>();
        tmp = head;
        if (tmp->next == nullptr)
        {
            tail = head = nullptr;
            throw (char*)"Error: tmp->next == nullptr (DelFromHead)";
        }
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
        {
            tail = head = nullptr;
            throw (char*)"Error: tmp->next == nullptr (DelFromTail)";
        }
        else
        {
            tail = tmp->prev;
            tail->next = nullptr;
        }
        count--;
        delete tmp;
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
            throw (string)"List is empty! (Show)";
        else
        {
            cout << "List ->" << "\t";
            tmp = head;
            do {
                cout << tmp->GetValue() << "\t";
                tmp = tmp->next;
            } while (tmp != nullptr);
            cout << endl;
        }
    }

};

int main()
{
    List <int> list;
    const int N = 5;
    int arr[N] = { 0,1,2,3,4 };
    try
    {
        for (size_t i = 0; i < N; i++)
        {
            if (i % 2 == 0)
                list.AddToHead(arr[i]);
            else
                list.AddToTail(arr[i]);
        }

        cout << "List list: \n";
        list.Show();

        for (size_t i = 0; i < N; i++)
        {
            if (i % 2 == 0)
                list.DelFromHead();
            else
                list.DelFromTail();
        }

        cout << "List list: \n";
        list.Show();
    }
    catch (string line)
    {
        cout << line << endl;
    }
    catch (char* line)
    {
        cout << line << endl;
    }
    catch (exception& e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }
    return 0;
}