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
    }
    Node(T value) :Node() { this->value = value; }
    T GetValue() { return this->value; }
};

template <typename T>
class Stack {
private:
    Node<T>* head;
    Node<T>* tail;
    uint32_t length;
    uint32_t pos;
public:
    Stack()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
        this->pos = 0;
    }
    ~Stack() { Clear(); }
    bool Empty() { return (length == 0) ? true : false; }
    bool Check(int elem1, int elem2)
    {
        return (elem1 == '(' && elem2 == ')') 
            ||(elem1 == '{' && elem2 == '}') 
            ||(elem1 == '[' && elem2 == ']');
    }
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
    T Balance(const string& str)
    {
        Stack <char> stack;
        for (char ch : str) 
        {
            switch (ch) 
            {
            case '(': stack.Push(')'); break;
            case '[': stack.Push(']'); break;
            case '{': stack.Push('}'); break;

            case ')':
            case ']':
            case '}':
                if (stack.Empty() || stack.Top() != ch)
                    return false;
                stack.Pop();
                break;
            default:
                break;
            }
        }
        return stack.Empty();
    }

    void Testing(const string& str) 
    {
        cout << "Your string: " << str << "\t" << (Balance(str) ? "Str is balanced" : "Erorr") << endl;
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
    
    void Clear()
    {
        while (!Empty())
            Pop();
    }
};

int main()
{
    Stack <char> stack;
    stack.Testing("({x-y-z}*[x+2y]-(z+4x));");
    stack.Testing("([x-y-z}*[x+2y)-{z+4x)].");

    return 0;
}