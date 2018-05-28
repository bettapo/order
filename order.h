#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H

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

    int length; //???

    /*void swap(node<T> *node_1, node<T> *node_2);
    const node<T>* get_element(int index) const;

    void pop_back();
    void pop_front();*/

public:
    order_list();
    ~order_list();

    //const T get_item(int index) const;

    void enqueue(T item);
    const T dequeue();
    void dequeue_withoutReturn();
    void clear();

    const int get_length() const;
    order_list<T> concatenation(order_list<T> B);

    /*void push_front(T item);
    void insert_at_index(int index, T item);

    void pop_by_index(int index);



    void append(const circular_list<T> &new_list);
    void sort(bool (*compare_function)(T,T));
    template <typename U> U reduce(U (*reduce_function)(U,T), U initial_value);


    T operator[] (const int index);*/
};

#include "order.cpp"

#endif //UNTITLED_ORDER_H
