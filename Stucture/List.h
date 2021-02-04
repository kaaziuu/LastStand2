//
// Created by xkey on 29.01.2021.
//

#ifndef MAZEGAME_LIST_H
#define MAZEGAME_LIST_H

#include <stdexcept>


template<typename T>
class List {
public:
    ~List();
    void add(T *elem);


    void remove(int i);

    int getSize();

    T*get(int i);

private:
    int size;
    typedef struct list {
        T *elem;
        struct list *next;
        struct list *before;
    } list;

    list *head = nullptr;
};

template<typename T>
void List<T>::add(T *elem) {
    if (head != nullptr) {
        list *current = head;
        while (current->next) {
            current = current->next;
        }
        list *newElem = new list;
        newElem->next = nullptr;
        newElem->before = current;
        newElem->elem = elem;

        current->next = newElem;

    } else {
        head = new list;
        head->next = nullptr;
        head->before = nullptr;
        head->elem = elem;
    }
    this->size++;

}

template<typename T>
void List<T>::remove(int i) {
    if (i >= this->size)
        throw std::out_of_range("out of list index\n");
    list *current = this->head;
    for (int j = 0; j < i; j++)
        current = current->next;
    if (current->before) {
        current->before = current->next;
    } else {
        this->head = current->next;
    }
    if (current->next)
        current->next = current->before;
    delete current->elem;
    this->size--;
}

template<typename T>
int List<T>::getSize() {
    return this->size;
}

template<typename T>
T *List<T>::get(int i) {
    if (i >= this->size)
        throw std::out_of_range("out of index \n");

    list *current = this->head;
    for (int j = 0; j < i; j++)
        current = current->next;

    return current->elem;
}

template<typename T>
List<T>::~List() {
    list *current = this->head;
    while (head)
    {
        head = current->next;
//        delete current->elem;
        free(current);
        current = head;
    }

}


#endif //MAZEGAME_LIST_H
