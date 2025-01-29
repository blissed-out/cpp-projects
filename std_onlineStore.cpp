#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct product
{
    int id;
    string name, category;
};

struct order
{
    int id, productID, quantity;
    string customerID;
    time_t orderDate;
};

struct customer
{
    string id, name, address;
};

int main()
{
    // sample data
    vector<product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Mobile Phone", "Electronics"},
        {103, "Coffe Marker", "Kitchen"},
        {104, "Washing Machine", "Kitchen"},
        {105, "Desk Lamp", "Home"},
    };
    deque<customer> recentCustomers = {
        {"C001", "Naval Ravikant", "California"},
        {"C002", "Elon Musk", "Texas"},
        {"C003", "Hitesh Choudhary", "North India"},
        {"C004", "Jhon", "New York"},
        {"C005", "noOne", "Washington DC"},
    };

    recentCustomers.push_back({"C006", "Someone", "Washington DC"});
    recentCustomers.push_front({"C007", "Anyone", "Washington DC"}); // expensive computation with push_front

    list<order> orderHistory;
    orderHistory.push_back({1, 101, 1, "C001", time(0)});
    orderHistory.push_back({2, 102, 2, "C002", time(0)});
    orderHistory.push_back({3, 103, 1, "C003", time(0)});

    set<string> categories;
    int i = 0;
    for (const auto &prod : products)
    {
        categories.insert(prod.category);
    }
    for (string category : categories) {
        cout << category << endl;
    }
    
    map<int, int> productStock = {
        {101, 20},
        {102, 12},
        {103, 14},
        {104, 11},
        {105, 8},
    };
    
    multimap<string, int> customerOrders;
    for (const auto &order: orderHistory) {
        customerOrders.insert({order.customerID, order.id});
    }

    unordered_map<string, string> customerData = {
        {"C001", "Alina"},
    };

    return 0;
}