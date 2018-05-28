#include "order.h"
//#include <algorithm>
#include <iostream>

using namespace std;


/*Конструктор*/
template <typename T>
order_list<T>::order_list() {
    length = 0;
    head = NULL; //???
    tail = NULL; //???
}

/*Деструктор*/
template <typename T>
order_list<T>::~order_list() {
    clear();
}

/*Поставить объект item в очередь (в конец списка).*/
template <typename T>
void order_list<T>::enqueue(T item) {
    node<T>* new_node = new node<T>();
    new_node->item = item;

    if (length == 0) {
        head = new_node;
        //head->next = NULL;
        tail = new_node;
    } else {
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }

    length++;
}

/*Убрать элемент из очереди без возврата значения.*/
template <typename T>
void order_list<T>::dequeue_withoutReturn() {
    if (length < 1) {
        throw std::out_of_range("Out of range"); //Исключение
    }

    node<T>* tmp = head;

    head = head->next;
    if(length == 1)
        tail = NULL;

    delete tmp;

    length--;
}

/*Убрать элемент из очереди (достать элемент из начала списка) и вернуть его значение.
 * используется в деструкторе
 * */
template <typename T>
const T order_list<T>::dequeue(){
    if (length < 1) {
        throw std::out_of_range("Out of range"); //Исключение
    }

    node<T>* tmp = head;
    T pop = head->item;

    head = head->next;
    if(length == 1)
        tail = NULL;

    delete tmp;

    length--;
    return pop;
}

/*Очистить весь список.*/
template <typename T>
void order_list<T>::clear() {
    while (length != 0) {
        dequeue();
    }
}

/*Получить длину списка.*/
template <typename T>
const int order_list<T>::get_length() const {
    return length;
}

/*Конкатенация*/
template <typename T>
order_list<T> order_list<T>::concatenation(order_list<T> B){
    order_list<T> concatResult;
    concatResult.head = head;
    concatResult.tail = tail;
    concatResult.length = length;

    concatResult.tail->next = B.head;
    concatResult.tail = B.tail;
    concatResult.length += B.length;

    return concatResult;
}
/*
 Добавить к текущему списку список new_list
 */
/*
template <typename T>
void circular_list<T>::append(const circular_list<T> &new_list) {
    int list_length = new_list.get_length();
    for (int i = 0; i < list_length; i++) {
        T new_item = new_list.get_item(i);
        push_back(new_item);
    }
}
*/
/*
 Обработать список методом reduce
 */
/*
template <typename T>
template <typename U>U circular_list<T>::reduce(U (*reduce_function)(U,T), U initial_value) {
    if (length == 0) {
        return initial_value;
    }

    U current_result  = initial_value;

    bool loop_started;
    node<T>* i;
    for (i = head, loop_started = false; (i != head) || !loop_started; i = i->next, loop_started = true) {
        current_result = reduce_function(current_result, i->item);
    }

    return current_result;
}
*/
/*
 Поменять местами элементы node_1 и node_2
 */
/*
template <typename T>
void circular_list<T>::swap(node<T> *node_1, node<T> *node_2) {
    T tmp_item = node_1->item;
    node_1->item = node_2->item;
    node_2->item = tmp_item;
}
*/
/*
 Сортировка списка по функции compare_function методом пузырька
 */
/*
template <typename T>
void circular_list<T>::sort(bool (*compare_function)(T,T)) {
    if (length == 0) {
        return;
    }

    bool started_i = false;
    for (node<T>* i = head; (i != head) || !started_i; i = i->next) {
        started_i = true;
        bool started_j = false;
        for (node<T>* j = i; (j != head) || !started_j; j = j->next) {
            started_j = true;
            if (compare_function(i->item, j->item) == false) {
                swap(i, j);
            }
        }
    }
}
*/

/*
 Получить узел (не сам элемент!) списка с идентификатором index
 */
/*
template <typename T>
const node<T>* circular_list<T>::get_element(int index) const {
    if ((0 > index) || (index >= length )) {
        throw std::out_of_range("Out of range");
    }

    node<T>* res_node = head;

    // разных обход в зависимости от местоположения элемента
    if (index <= length/2) {
        for (int i = 0; i < index; i++) {
            res_node = res_node->next;
        }
    } else {
        for (int i = length; i > index; i--) {
            res_node = res_node->prev;
        }
    }

    return res_node;
}

template <typename T>
const T circular_list<T>::get_item(int index) const {
    const node<T>* res_node = get_element(index);

    return res_node->item;
}

// перегрузка операторов

template <typename T>
T circular_list<T>::operator[] (const int index) {
    return get_item(index);
}
*/

