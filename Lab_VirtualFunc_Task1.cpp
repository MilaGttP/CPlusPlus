
#include <iostream>
using namespace std;

class Node
{
public:
	uint32_t value;
	Node* next;
	Node* prev;
	Node()
	{
		value = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	Node(uint32_t value) :Node() { this->value = value; }
	uint32_t GetValue() { return this->value; }
};

class List
{
protected:
	Node* head;
	Node* tail;
	uint32_t length;
public:
	virtual void Push(uint32_t elem) = 0;
	virtual void Pop() = 0;
	virtual void Print() = 0;
	virtual void Clear() = 0;
};

class Stack : public List
{
public:
	Stack()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->length = 0;
	}
	~Stack() { Clear(); }
	void Push(uint32_t elem) override
	{
		Node* tmp = new Node (elem);
		if (length == 0)
			head = tail = tmp;
		else 
		{
			this->tail->next = tmp;
			tmp->prev = this->tail;
			this->tail = tmp;
		}
		length++;
	}
	void Pop() override
	{
		Node* tmp = new Node();
		tmp = head;
		if (tmp->next == NULL)
			tail = head = nullptr;
		else
		{
			this->head = tmp->next;
			this->head->prev = nullptr;
		}
		length--;
		delete tmp;
	}
	void Print() override
	{
		Node* tmp = new Node();
		if (length == 0)
			cout << "Stack is empty!" << endl;
		else
		{
			cout << "Stack -> " << "\t";
			tmp = head;
			do {
				cout << tmp->GetValue() << "\t";
				tmp = tmp->next;
			} while (tmp != nullptr);
			cout << endl;
		}
	}
	void Clear() override
	{
		while (length != 0)
			Pop();
	}
};

class Queue : public List
{
public:
	Queue()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->length = 0;
	}
	~Queue() { Clear(); }
	void Push(uint32_t elem) override
	{
		Node* tmp = new Node(elem);
		if (length == 0)
			head = tail = tmp;
		else
		{
			this->tail->next = tmp;
			tmp->prev = this->tail;
			this->tail = tmp;
		}
		length++;
	}
	void Pop() override
	{
		Node* tmp = new Node();
		tmp = head;
		if (tmp->next == NULL)
			tail = head = nullptr;
		else
		{
			this->head = tmp->next;
			this->head->prev = nullptr;
		}
		length--;
		delete tmp;
	}
	void Print() override
	{
		Node* tmp = new Node();
		if (length == 0)
			cout << "Queue is empty!" << endl;
		else 
		{
			cout << "Queue -> " << "\t";
			tmp = head;
			do {
				cout << tmp->GetValue() << "\t";
				tmp = tmp->next;
			} while (tmp != nullptr);
			cout << endl;
		}
	}
	void Clear() override
	{
		while (length != 0)
			Pop();
	}
};

int main()
{
	List ** list = new List*();
	list[0] = new Stack();
	list[1] = new Queue();
	uint32_t tmp = 5;

	for (size_t i = 0; i < 2; i++)
	{
		list[i]->Push(tmp);
		list[i]->Print();
		list[i]->Pop();
		list[i]->Print();
		list[i]->Clear();
	}

	return 0;
}