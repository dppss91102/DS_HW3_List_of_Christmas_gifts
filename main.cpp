#include <iostream>
using namespace std;

class List {
private:
    class Node{
    public:
        int price;
        string gift;
        Node* next;
        Node (int p = 0, string g = "", Node* n = nullptr){
            price = p;
            gift = g;
            next = n;
        };
    };
    class Head{
    public:
        Node* first;
    };
    Head head;
    Node* last;
    Node* search(int price, bool previous) {
        Node* now = head.first;
        Node* temp = head.first;
        while (now != nullptr) {
            if (now->price == price)
                return previous ? temp : now;
            else {
                temp = now;
                now = now->next;
            }
        }
        return nullptr;
    };

public:
    List() {
        head.first = nullptr;
        last = nullptr;
    };
    void insertBack(int price, string gift);
    void insertAfter(int price, string gift, int place);
    void Delete(int price);
    void Reverse();
    void print ();
    bool empty();
};
void List::insertBack(int price, string gift) {
    if (empty()) {
        head.first = new Node(price, gift, nullptr);
        last = head.first;
        //print();
        return;
    }
    if (search(price, false) != nullptr)
        return;
    Node *temp = new Node(price, gift, nullptr);
    last->next = temp;
    last = temp;
    //print();
}
void List::insertAfter(int price, string gift, int place) {
    if (empty())
        return;
    Node* currentNode = search(place, false);
    if (currentNode != nullptr) {
        Node* temp = new Node(price, gift, currentNode->next);
        currentNode->next = temp;
        if (currentNode == last)
            last = temp;
    }
    //print();
}
void List::Delete(int price) {
    if (empty())
        return;
    Node* prevNode = search(price, true);
    if (prevNode != nullptr) {
        if (prevNode == last && prevNode == head.first) {
            delete head.first;
            head.first = nullptr;
            last = nullptr;
            return;
        }
        if (prevNode->next == last)
            last = prevNode;
        Node* temp = prevNode->next->next;
        delete prevNode->next;
        prevNode->next = temp;
    }
    //print();
}
void List::Reverse() {
    if (empty())
        return;
    Node *current = head.first, *prev = nullptr, *temp = nullptr;
    last = current;
    while (current != nullptr){
        temp = prev;
        prev = current;
        current = current->next;
        prev->next = temp;
    }
    head.first = prev;
    //print();
}
void List::print() {
    Node* now = head.first;
    while (now != nullptr) {
        cout << '(' << now->gift << ',' << now->price << ')';
        now = now->next;
        if (now == nullptr)
            cout << endl;
        else
            cout << "->";
    }
}
bool List::empty() {
    return head.first == nullptr;
}

int main() {
    List gift_list;
    string command;

    while (cin >> command) {
        int price;
        string gift;

        if (command == "InsertBack") {
            cin >> gift;
            cin >> price;
            gift_list.insertBack(price, gift);
        } else if (command == "InsertAfter") {
            cin >> gift;
            cin >> price;
            int place;
            cin >> place;
            gift_list.insertAfter(price, gift, place);
        } else if (command == "Delete") {
            cin >> price;
            gift_list.Delete(price);
        } else if (command == "Reverse") {
            gift_list.Reverse();
        } else if (command == "End") {
            if (gift_list.empty())
                cout << "Empty" << endl;
            else {
                cout << "List" << endl;
                gift_list.print();
            }
            return 0;
        } else
            return 0;
    }
}