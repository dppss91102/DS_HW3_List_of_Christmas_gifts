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
    Node* first;
    Node* last;
    Node* search(int price) {
        Node* now = first;
        while (now != nullptr && now->price != price) {
                now = now->next;
        }
        return now;
    };

public:
    List() {
        first = nullptr;
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
        first = new Node(price, gift, nullptr);
        last = first;
        return;
    }
    if (search(price) != nullptr)
        return;
    Node *temp = new Node(price, gift, nullptr);
    last->next = temp;
    last = temp;
}
void List::insertAfter(int price, string gift, int place) {
    if (empty())
        return;
    if (search(price) != nullptr)
        return;
    Node* currentNode = search(place);
    if (currentNode != nullptr) {
        Node* temp = new Node(price, gift, currentNode->next);
        currentNode->next = temp;
        if (currentNode == last)
            last = temp;
    }
}
void List::Delete(int price) {
    if (empty())
        return;
    Node *currentNode = first, *prevNode = nullptr;
    while (currentNode != nullptr && currentNode->price != price) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr)
        return;
    else if (currentNode == first) {
        first = currentNode->next;
        delete currentNode;
        currentNode = nullptr;
    } else {
        prevNode->next = currentNode->next;
        if (currentNode == last)
            last = prevNode;
        delete currentNode;
        currentNode = nullptr;
    }
}
void List::Reverse() {
    if (empty())
        return;
    Node *current = first, *prev = nullptr, *temp = nullptr;
    last = current;
    while (current != nullptr){
        temp = prev;
        prev = current;
        current = current->next;
        prev->next = temp;
    }
    first = prev;
}
void List::print() {
    if (empty())
        cout << "Empty" << endl;
    else {
        cout << "List" << endl;
        Node *now = first;
        while (now != nullptr) {
            cout << '(' << now->gift << ',' << now->price << ')';
            now = now->next;
            if (now == nullptr)
                cout << endl;
            else
                cout << "->";
        }
    }
}
bool List::empty() {
    return first == nullptr;
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
            gift_list.print();
            return 0;
        } else
            return 0;
        gift_list.print();
    }
}