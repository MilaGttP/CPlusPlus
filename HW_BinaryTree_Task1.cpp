
#include <iostream>
using namespace std;

struct Node
{
	int counter;
	string word; string translate;
	Node* left, *right, *parent;
};

class Tree
{
public:
	Node* root;
	Tree() { root = NULL; }
	~Tree() { Clear(); }
	Node* GetRoot() { return root; }

    void Print(Node* elem);
    Node* Min(Node* elem);
    Node* Next(Node* elem);
    void Insert(Node* elem);
    Node* Search(Node* elem, string k);
	void Clear(Node* other = 0);
};

void Tree::Print(Node* elem)
{
	if (elem != 0)
	{
		Print(elem->left);
		cout << "Eng: " << elem->word << "\tUa: " << elem->translate << endl;
		Print(elem->right);
	}
}

Node* Tree::Min(Node* elem)
{
    if (elem != 0)
        while (elem->left != 0)
            elem = elem->left;
    return elem;
}

Node* Tree::Next(Node* elem)
{
    Node* tmp = 0;
    if (elem != 0)
    {
        if (elem->right != 0)
            return Min(elem->right);
        tmp = elem->parent;
        while (tmp != 0 && elem == tmp->right)
        {
            elem = tmp;
            tmp = tmp->parent;
        }
    }
    return tmp;
}

void Tree::Insert(Node* elem)
{
    elem->left = NULL;
    elem->right = NULL;
    Node* buff = NULL;
    Node* tmp = root;
    while (tmp != 0) {
        buff = tmp;
        if (strcmp(elem->word.c_str(), tmp->word.c_str()) < 0)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    elem->parent = buff;
    if (buff == 0)
        root = elem;
    else if (strcmp(elem->word.c_str(), buff->word.c_str()) < 0)
        buff->left = elem;
    else
        buff->right = elem;
}

Node* Tree::Search(Node* elem, string str)
{
    while (elem != 0 && strcmp(str.c_str(), elem->word.c_str()) != 0)
    {
        if (strcmp(str.c_str(), elem->word.c_str()) < 0)
            elem = elem->left;
        else
            elem = elem->right;
    }
    return elem;
}

void Tree::Clear(Node* other)
{
    if (other != 0)
    {
        Node* elem, *tmp;
        if (other->left == 0 || other->right == 0)
            tmp = other;
        else
            tmp = Next(other);

        if (tmp->left != 0)
            elem = tmp->left;
        else
            elem = tmp->right;

        if (elem != 0)
            elem->parent = tmp->parent;

        if (tmp->parent == 0)
            root = elem;
        else if (tmp == tmp->parent->left)
            tmp->parent->left = elem;
        else              
            tmp->parent->right = elem;

        if (tmp != other)
        {
            other->counter = tmp->counter;
            other->word = tmp->word;
            other->translate = tmp->translate;
        }
        delete tmp;
    }
    else
        while (root != 0)
            Clear(root);
}

int main()
{
    
    return 0;
}