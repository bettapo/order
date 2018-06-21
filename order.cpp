#include "order.h"
//#include <algorithm>
#include <iostream>
#include "string"

using namespace std;

/*Конструктор*/
template <typename T>
order_list<T>::order_list() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}

/*Деструктор*/
template <typename T>
order_list<T>::~order_list(){
    //clear();
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
        new_node->next = nullptr;
        tail->next = new_node;
        tail = new_node;
    }

    length++;
}

/*Убрать элемент из очереди без возврата значения.
 *  используется в clear()
 *  используется в деструкторе
 */
template <typename T>
void order_list<T>::dequeue_withoutReturn()
{
    if (length < 1) {
        throw std::out_of_range("Out of range");
    }

    if (length > 0)
    {
        node<T>* tmp = head;

        head = head->next;
        if(length == 1)
            tail = nullptr;

        delete tmp;

        length--;
    }
}

/*Убрать элемент из очереди (достать элемент из начала списка) и вернуть его значение.*/
template <typename T>
const T order_list<T>::dequeue()
{
    if (length < 1) {
        throw std::out_of_range("Out of range");
    }

    if(length > 0)
    {
        node<T>* tmp = head;
        const T pop = head->item;

        head = head->next;
        if(length == 1)
            tail = nullptr;

        delete tmp;
        length--;

        return pop;
    }
}

/*Очистить весь список.*/
template <typename T>
void order_list<T>::clear() {
    if ( !this->isEmpty() )
    {
        while (length != 0) {
            dequeue_withoutReturn();
        }
    }
}

/*Конкатенация this + B*/
template <typename T>
order_list<T> order_list<T>::concatenation(order_list<T> B){
    if ( (head== nullptr) && (tail == nullptr) && (length == 0) )
    {
        return B;
    } else if( (B.head == nullptr) && (B.tail == nullptr) && (B.length == 0) )
    {
        return *this;
    } else {
        order_list<T> concatResult;
        concatResult.head = head;
        concatResult.tail = tail;
        concatResult.length = length;

        concatResult.tail->next = B.head;
        concatResult.tail = B.tail;
        concatResult.length += B.length;

        return concatResult;
    }
}

/*Извлечь подпоследовательность по заданным индексам*/
template <typename T>
order_list<T> order_list<T>::subsequenceByIndexes(int from, int to)
{
    /*try
    {
        if ( (length <= 0) || (from <= 0) || (from > length) || (to <= 0) || (to > length) )
        {
            throw 666;
        }
    }
    catch(int i)//сюда передастся строка
    {
        cout << "Error. It is not possible to extract a subsequence."<< endl;
    }*/

    if ( (length <= 0) || (from <= 0) || (from > length) || (to <= 0) || (to > length) || (from > to) ){
        throw std::out_of_range("Out of range");
    }

    order_list<T> subsequence;

    if ( (length <= 0) || (from <= 0) || (from > length) || (to <= 0) || (to > length) ) //в случае ошибки можно возвращать пустой список
        return  subsequence;
    else
    {
        int counter = 1;
        node<T>* tmpPtr = head;
        while(tmpPtr != nullptr)
        {
            if( (counter >= from) && (counter <= to) )
            {
                subsequence.enqueue(tmpPtr->item);
            }
            tmpPtr = tmpPtr->next;
            counter++;
        }

        return subsequence;
    }
}

/*Поиск на вхождение подпоследовательности.*/
template <typename T>
bool order_list<T>::searchSubsequence(order_list<T> subsequence) //straight search
{
    if ( subsequence.length > this->length)
        return false;
    else
    {
        node<T>* mainPtr = head; //указатель на элемент в списке, где ищется подпоследовательность
        // всегда сдвигается
        int i = 1; //индекс этого элемента, чтобы вовремя выйти из списка
        node<T>* subPtr = subsequence.head;
        int counter = 0; //количество совпадений подряд

        while(i + subsequence.length - 1 <= length && counter < subsequence.length)
        {
            if(mainPtr->item == subPtr->item)
            {
                mainPtr = mainPtr->next;
                i++;
                subPtr = subPtr->next;
                counter++;
            } else
            {
                counter = 0; //количество совпадений обнуляется
                subPtr = subsequence.head;
                mainPtr = mainPtr->next;
                i++;
            }
        }

        if(counter == subsequence.length)
            return true;
        else return false;
    }
}

/*Получить длину списка.*/
template <typename T>
const int order_list<T>::get_length() const {
    return length;
}

/*Проверка списка неа пустоту.*/
template <typename T>
bool order_list<T>::isEmpty ()
{
    if ((length == 0) && (head == NULL) && (tail == NULL))
        return true;
    else return false;
}

template <typename T>
void order_list<T>::orderCout()
{
    node<T>* currentPtr = head;
    cout << "Order: ";
    while (currentPtr != nullptr)
    {
        cout << currentPtr->item << " ";
        currentPtr = currentPtr->next;
    }
    cout << endl;
}

template class order_list<int>;
template class order_list<string>;
