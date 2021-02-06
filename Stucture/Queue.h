//
// Created by xkey on 04.02.2021.
//

#ifndef LASTSTAND2_QUEUE_H
#define LASTSTAND2_QUEUE_H

template<typename T>
class Queue {
public:
    bool empty();

    T *get();

    void push(T *el);

    void pop();

private:
    typedef struct queue {
        T *el;
        struct queue *next;
    } queue;
    queue *head = nullptr;
};

template<typename T>
bool Queue<T>::empty() {
    if (this->head == nullptr)
        return true;
    return false;
}

template<typename T>
T *Queue<T>::get() {
    if (this->head != nullptr)
        return head->el;
    return nullptr;
}

template<typename T>
void Queue<T>::push(T *el) {
    queue *q = (queue *) malloc(sizeof(queue));
    q->el = el;
    q->next = nullptr;
    if (this->head != nullptr) {
        queue *current = this->head;
        while (current->next)
            current = current->next;
        current->next = q;
    } else {
        this->head = q;
    }
}

template<typename T>
void Queue<T>::pop() {
    queue *tmp = this->head;
    this->head = this->head->next;
    delete tmp->el;
    free(tmp);


}


#endif //LASTSTAND2_QUEUE_H
