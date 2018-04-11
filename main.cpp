#include <iostream>
using namespace std;

class List {
private:
    class Node{
    public:
        int price;
        string gift;
        Node* next;
        Node (int p = 0, string g = "\0", Node* n = nullptr){
            price = p;
            gift = g;
            next = n;
        };
    };
    Node* first;
    Node* last;
    Node* search(int price, bool previous) {
        Node* now = first->next;
        Node* temp = first;
        while (now != nullptr) {
            if (now->price == price)
                return previous ? temp : now;
            else {
                temp = now;
                now = now->next;
                if (now == nullptr)
                    break;
            }
        }

        return nullptr;
    };

public:
    List() {
        first = new Node();
        last = first;
    };
    void insertBack(int price, string gift);
    void insertAfter(int price, string gift, int prev);
    void Delete(int price);
    void Reverse();
    void print ();
    bool empty();
};
void List::insertBack(int price, string gift) {
    Node *temp = new Node(price, gift, nullptr);
    last->next = temp;
    last = temp;
    //print();
}
void List::insertAfter(int price, string gift, int prev) {
    Node* currentNode = search(prev, false);
    if (currentNode != nullptr) {
        Node* newNode = new Node(price, gift, currentNode->next);
        currentNode->next = newNode;
    }
    //print();
}
void List::Delete(int price) {
    Node* prevNode = search(price, true);
    if (prevNode != nullptr) {
        if (prevNode->next == last)
            last = first;
        Node* temp = prevNode->next->next;
        prevNode->next = nullptr;
        delete prevNode->next;
        prevNode->next = temp;
    }
    //print();
}
void List::Reverse() {
    Node *current = first->next, *prev = nullptr, *temp = nullptr;
    last = (current == nullptr) ? first : current;
    while (current != nullptr){
        temp = prev;
        prev = current;
        current = current->next;
        prev->next = temp;
    }
    first->next = prev;
    //print();
}
void List::print() {
    Node* now = first->next;
    while (now != nullptr) {
        cout << '(' << now->gift << ',' << now->price << ')';
        now = now->next;
        if (now == nullptr) {
            cout << endl;
            return;
        } else {
            cout << "->";
        }
    }
}
bool List::empty() {
    return first == last;
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
            int prev;
            cin >> prev;
            gift_list.insertAfter(price, gift, prev);
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
            break;
    }

    return 0;
}