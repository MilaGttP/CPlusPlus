
#include <iostream>
using namespace std;

namespace DynStructData
{
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
        Node(T value) :Node() { this->value = value; }
        T GetValue() { return this->value; }
    };

	namespace Stack
	{
        
        template <typename T>
        class Stack 
        {
        private:
            Node<T>* head;
            Node<T>* tail;
            uint32_t length;
        public:
            Stack()
            {
                this->head = nullptr;
                this->tail = nullptr;
                this->length = 0;
            }
            ~Stack() { Clear(); }
            bool Empty() { return (length == 0) ? true : false; }
            T Top()
            {
                if (Empty())
                    return (T)NULL;
                else
                    return tail->GetValue();
            }
            void Push(T elem)
            {
                Node<T>* other = new Node<T>(elem);
                if (Empty())
                    head = tail = other;
                else {
                    tail->next = other;
                    other->prev = tail;
                    tail = other;
                }
                length++;
            }
            void Pop()
            {
                Node<T>* other = new Node<T>();
                other = tail;
                if (other->prev == nullptr)
                    tail = head = nullptr;
                else {
                    tail = other->prev;
                    tail->next = nullptr;
                }
                length--;
                delete other;
            }
            void Print()
            {
                Node<T>* tmp = new Node<T>();
                if (Empty())
                    cout << "Stack is empty!" << endl;
                else {
                    cout << "Stack ->" << "\t";
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
        };
	}

    namespace Queue
    {
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
            ~Queue() { Clear(); }
            uint32_t size() { return length; }
            bool Empty() { return (length == 0) ? true : false; }
            void Push(T elem)
            {
                Node<T>* node_elem = new Node<T>(elem);
                if (Empty())
                    head = tail = node_elem;
                else
                {
                    tail->next = node_elem;
                    node_elem->prev = tail;
                    tail = node_elem;
                }
                length++;
            }
            void Pop()
            {
                Node<T>* node_elem = new Node<T>();
                node_elem = head;
                if (node_elem->next == nullptr)
                    tail = head = nullptr;
                else {
                    head = node_elem->next;
                    head->prev = nullptr;
                }
                length--;
                delete node_elem;
            }
            void Print()
            {
                Node<T>* node_elem = new Node<T>();
                if (Empty())
                    cout << "Queue is empty!" << endl;
                else {
                    cout << "Queue ->" << "\t";
                    node_elem = head;
                    do {
                        cout << node_elem->GetValue() << "\t";
                        node_elem = node_elem->next;
                    } while (node_elem != nullptr);
                    cout << endl;
                }
            }
            void Clear()
            {
                while (!Empty())
                    Pop();
            }
        };  
    }

    namespace List
    {
        template <typename T>
        class List
        {
            Node<T>* head;
            Node<T>* tail;
            int length;
        public:
            List()
            {
                this->head = nullptr;
                this->tail = nullptr;
                this->length = 0;
            }
            ~List() { DelAll(); }
            int GetLength() { return length; }
            int Empty() { return (length == 0) ? true : false; }
            void Add(T elem)
            {
                Node<T>* tmp = new Node<T>(elem);
                if (Empty())
                    head = tail = tmp;
                else 
                {
                    head->prev = tmp;
                    tmp->next = head;
                    head = tmp;
                }
                length++;
            }
            void Delete()
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
            void Print()
            {
                Node<T>* tmp = new Node<T>();
                if (Empty())
                    cout << "List is empty!" << endl;
                else {
                    cout << "List -> \t";
                    tmp = head;
                    do {
                        cout << tmp->GetValue() << "\t";
                        tmp = tmp->next;
                    } while (tmp != nullptr);
                    cout << endl;
                }
            }
            void DelAll()
            {
                while (!Empty())
                    Delete();
            }
        };
    }
}

using DynStructData::Stack::Stack;
void CheckStack()
{
    cout << endl << " --- STACK --- " << endl;
    Stack <uint32_t> stack;
    const int N = 5;
    int arr[N] = { 0,1,2,3,4 };
    for (size_t i = 0; i < N; i++)
    {
        stack.Push(arr[i]);
    }
    stack.Print();
    cout << "Stack`s top: " << stack.Top() << endl;
    stack.Clear(); stack.Print();
    cout << endl << endl;
}

using DynStructData::Queue::Queue;
void CheckQueue()
{
    cout << " --- QUEUE --- " << endl;
    Queue <uint32_t> queue;
    const int N = 5;
    int arr[N] = { 0,1,2,3,4 };
    for (size_t i = 0; i < N; i++)
    {
        queue.Push(arr[i]);
    }
    queue.Print();
    cout << "Queue`s size: " << queue.size() << endl;
    queue.Clear(); queue.Print();
    cout << endl << endl;
}

using DynStructData::List::List;
void CheckList()
{
    cout << " --- LIST --- " << endl;
    List <uint32_t> list;
    const int N = 5;
    int arr[N] = { 0,1,2,3,4 };
    for (size_t i = 0; i < N; i++)
    {
        list.Add(arr[i]);
    }
    list.Print();
    cout << "List`s length: " << list.GetLength() << endl;
    list.DelAll(); list.Print();
    cout << endl << endl;
}

int main()
{
    CheckStack();
    CheckQueue();
    CheckList();

    return 0;
}