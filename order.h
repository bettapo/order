#ifndef ORDER_ORDER_H
#define ORDER_ORDER_H

#include <iostream>
#include <cstdio>
#include <cstdlib>

/*Структура элемента, использующаяся в реализации списка.*/
template <typename T>
struct node {
    T item;
    node* next;
};

/*Основной класс очереди.*/
template <typename T>
class order_list {
private:
    node<T>* head;
    node<T>* tail;
    int length;


public:
    order_list();
    ~order_list();


    void enqueue(T item); //private or public?
    const T dequeue(); //private or public?
    void dequeue_withoutReturn(); //private or public?
    void clear();

    const int get_length() const;
    order_list<T> concatenation(order_list<T> B);
    order_list<T> subsequenceByIndexes(int from, int to);
    bool searchSubsequence(order_list<T> subsequence);
    bool isEmpty();
    void orderCout();

    //order_list<T> operator+ (const order_list<T> A, const order_list<T> B);
};


#endif //ORDER_ORDER_H
