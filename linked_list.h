#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // Constructors 
    Node<T>(T d, Node<T>* n) {
        data = d;
        next = n;
    }

    Node<T>(T d) {
        data = d;
        next = NULL;
    }

    Node<T>(Node<T>* n) {
        data = T();
        next = n;
    }

    Node<T>() {
        data = T();
        next = NULL;
    }
};

template <typename T>
class LinkedList {
public:
    Node<T>* head;
    int length;

    LinkedList<T>(Node<T>* h) {
        head = h;
        length = 1;
    }

    LinkedList<T>() { 
        head = NULL;
        length = 0;
    }

    Node<T>* tail() {
        if (head == NULL)
            return head;
        Node<T>* tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        return tail;
    }

    void add(T item) {
        Node<T>* node = new Node<T>(item);
        // std::cout << "ADD: node->data is " << node->data << std::endl; // debug
        add_node(node);
    }

    void add_node(Node<T>* n) {
        if (length == 0)
            head = n;
        else
            tail()->next = n;
        ++length;
    }

    Node<T>* node_at(int index) { // warning: slow
        if (index < 0 || index > length || length == 0) {
            std::cout << "linked_list.h: LinkedList::at: Index out of bounds!\n";
            throw -1;
        }

        Node<T>* current = head;
        while (index > 0) {
            current = current->next;
            --index;
        }

        return current;
    }

    T at(int index) {
        return (at(index))->data;
    }

    friend std::ostream& operator<<(std::ostream& output, const LinkedList<T>& ll) {
        ll.print();
        return output;
    }

private:
    void print() const {
        Node<T>* current = head;
        std::cout << "[";
        while (current->next != NULL) {
            std::cout << current->data << ", ";
            current = current->next;
        }
        std::cout << current->data << "]";
    }
};

#endif // _LINKED_LIST_H
