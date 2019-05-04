//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <fstream>

using namespace std;

struct node {
    int data;
    node * next;
};

class linkedlist {
private:
    node * head;
    int count(); // RECURSIVE
    int sum(); // RECURSIVE

public:
    linkedlist();
    ~linkedlist(); // RECURSIVE
    void addToFront(int n);
    double average(); // uses sum and count functions
    void writeInorder(ofstream & outData);
    void writeReversed(ofstream & outData);
    void writeReversed(node * ptr, ofstream & outData);
    void deleteNode(node * ptr);
    void insertInOrder(int num);
    void printList();
    int sum(node *);
    int count(node *);
};
#endif // end linkedlist.h
