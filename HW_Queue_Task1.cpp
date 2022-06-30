#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
class Node
{
public:
    Node* next;
    Node* prev;
    Node()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }
    ~Node() { next = nullptr; prev = nullptr; }
};

template <typename T>
class TaxiStop
{
protected:
    uint32_t length;
    Node<T>* head;
    Node<T>* tail;
    uint32_t midPl;
    uint32_t midTax;
    bool IsLastStop;

public:
    TaxiStop()
    {
        length = 0; head = nullptr; tail = nullptr;
        midPl = 0; midTax = 0; IsLastStop = false;
    }
    ~TaxiStop() { Clear(); }

    void SetMidPl(uint32_t midPl) { this->midPl = midPl; }
    uint32_t GetMidPl() { return this->midPl; }
    void SetMidTax(uint32_t midTax) { this->midTax = midTax; }
    uint32_t GetMidTax() { return this->midTax; }
    void SetIsLastStop(bool IsLastStop) { this->IsLastStop = IsLastStop; }
    bool GetIsLastStop() { return this->IsLastStop; }

    bool Empty() { return (length == 0) ? true : false; }
    uint32_t MiddlePlStaying() { return midPl; }
    uint32_t NumberOfFreeSitPlaces()
    {
        srand(time(0));
        uint32_t allFreePlaces = 15; uint32_t freePlaces = 0;
        if (IsLastStop == true)
            return freePlaces = allFreePlaces;
        else {
            freePlaces = rand() % 15;
            return freePlaces;
        }
    }
    void Pop()
    {
        Node<T>* tmp = new Node<T>();
        tmp = head;
        if (tmp->next == nullptr)
            tail = head = nullptr;
        else {
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
    TaxiStop <uint32_t> tStop;
    tStop.SetIsLastStop(true);
    tStop.SetMidPl(3);
    tStop.SetMidTax(5);

    cout << "Number of free sit places: " 
        << tStop.NumberOfFreeSitPlaces() << endl;
    cout << "Middle people staying (in minutes): "
        << tStop.MiddlePlStaying() << endl;
    cout << "Middle taxi arriving (in minutes): "
        << tStop.GetMidTax() << endl;

    return 0;
}