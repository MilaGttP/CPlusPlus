
#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
using namespace std;

struct Order
{
    string product;
    int count;
};

void AddProducts(unordered_map <string, double>& list)
{
    int n;
    cout << "Enter count of products in shop: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        string product;
        double cost;
        cout << "Enter product name: ";
        getline(cin, product);
        cout << "Enter product cost: ";
        cin >> cost;
        list[product] = cost;
    }
}

void ShowProducts(const unordered_map <string, double> list)
{
    cout << "\nProducts count in shop: " << list.size() << endl;
    for (auto product : list)
    {
        cout << product.first << ": " 
            << fixed << setprecision(2) << product.second << endl;
    }
}

void AddShoppingList(vector<Order>& orders)
{
    int n;
    cout << "\nEnter count of products in shopping list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        Order order;
        cout << "Enter product name: ";
        getline(cin, order.product);
        cout << "Enter product count: ";
        cin >> order.count;
        orders.push_back(order);
    }
}

void ShowShoppingList(const vector<Order> orders)
{
    cout << "\nYour order list: " << orders.size() << " product[s]" << endl;
    for (auto order : orders)
    {
        cout << order.product << ": " 
            << order.count << endl;
    }
}

double PurchasePrice(unordered_map <string, double> list, const vector<Order> orders)
{
    double price = 0.0;
    for (auto order : orders)
    {
        if (list.count(order.product) != 0)
            price += list[order.product] * order.count;
        else
            cout << "Product [" << order.product << "] not exist" << endl;
    }
    return price;
}

int main()
{
    unordered_map <string, double> products;
    vector<Order> orders;

    AddProducts(products);
    ShowProducts(products);
    AddShoppingList(orders);
    ShowShoppingList(orders);

    cout << "\nCost of your products = " << PurchasePrice(products, orders) << endl;

    return 0;
}