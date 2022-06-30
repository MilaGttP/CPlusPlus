#include <iostream>
using namespace std;

struct Tree
{
	Tree* left, * right, * parent;
    int num;
    int pass;
    string Name;
    string Surname;

    void SetPass(int pass) { this->pass = pass; }
    void SetName(string name)
    {
        Name = name;
    }
    void SetSurname(string sur)
    { 
        Surname = sur; 
    }
    Tree() :num(), left(), right(), parent(), pass(), Name(), Surname() {};
    Tree(int n) :num(n), left(), right() {};
    Tree(int n, int pass, string name, string surname)
        :num(n), left(), right(), pass(pass) { SetName(name); SetSurname(surname); };
    ~Tree()
    {
        delete this->left; delete this->right; delete this->parent;
        num = 0; pass = 0; Name = nullptr; Surname = nullptr;
    }
};

class Bus
{
protected:
    Tree* root;
public:
	Bus() { root = NULL; }
	~Bus() { Clear(); }
	Tree* GetRoot() const { return this->root; }

	Tree* Min(Tree* elem);
	Tree* Next(Tree* elem);
    void Add(Tree*& t, int n, int pass, string name, string sur);
    void AddItem(int n, int pass, string name, string sur);
    void ShowTree(Tree* root) { inOrder(root); }
    void Search(int key, Tree*& elem)
    {
        if (elem->num != key && elem != nullptr)
        {
            inOrder(elem->left);
            inOrder(elem->right);
        }
    }
    Bus* SearchByNum(int key, const Bus& A); 
	void Clear(Tree* other = 0);
    static void inOrder(Tree*& elem)
    {
        if (elem != nullptr)
        {
            inOrder(elem->left);
            cout << "Bus num: " << elem->num << " | "
                << "Passengers quantity: " << elem->pass << " | "
                << "Driver`s full name: " << elem->Name << " " << elem->Surname << endl;
            inOrder(elem->right);
        }
    }
    friend ostream& operator << (ostream& os, const Bus& A) 
    {
        Tree* elem = A.GetRoot();
        if (elem != nullptr)
        {
            Bus::inOrder(elem->left);
            Bus::inOrder(elem->right);
        }
        os << endl;
        return os;
    };
};

Tree* Bus::Min(Tree* elem)
{
    if (elem != 0)
        while (elem->left != 0)
            elem = elem->left;
    return elem;
}

Tree* Bus::Next(Tree* elem)
{
    Tree* tmp = 0;
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

void Bus::Add(Tree*& elem, int n, int pass, string name, string sur)
{
    if (elem == nullptr)
        elem = new Tree(n, pass, name, sur);
    else 
    {
        if (n < elem->num)
            Add(elem->left, n, pass, name, sur);
        else
            Add(elem->right, n, pass, name, sur);
    }
}

void Bus::AddItem(int n, int pass, string name, string sur)
{
    Add(root, n, pass, name, sur);
}

Bus* Bus::SearchByNum(int key, const Bus& A)
{
    Tree* elem = A.GetRoot();
    if (elem->num == key)
    {
        ShowTree(elem);
        return this;
    }
    else
    {
        if (key < elem->num)
            Search(key, elem->left);
        else
            Search(key, elem->right);
    }
};

void Bus::Clear(Tree* other)
{
    if (other != 0)
    {
        Tree* elem, * tmp;
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
            other->num = tmp->num;
            other->Name = tmp->Name;
            other->Surname = tmp->Surname;
            other->num = tmp->num;
            other->pass = tmp->pass;
        }
        delete tmp;
    }
    else
        while (root != 0)
            Clear(root);
}

int main()
{
    Bus bus;
    cout << "Value to add into tree: " << endl;
    int num; int pass;
    string name; string surname;

    for (int i = 0; i != 2; i++) 
    {
        cout << "Bus num: ";            
        cin >> num; cout << endl;
        cout << "Passengers quantity: ";           
        cin >> pass; cin.ignore(); cout << endl;
        cout << "Driver`s name: ";                
        cin >> name; cout << endl;
        cout << "Driver`s surname: ";        
        cin >> surname; cout << endl;

        bus.AddItem(num, pass, name, surname);
    }
    cout << endl;
    cout << "Tree: " << endl;
    cout << bus;

    cout << "Num of searching bus: "; 
    cin >> num;
    bus.SearchByNum(num, bus);

    return 0;
}