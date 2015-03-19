#ifndef TWLIST_H
#define TWLIST_H

#include "twNode.h"
#include <iostream>

using namespace std;

enum twListError{OUTOFRANGE};

/*
 TO DO

 PUSH SHOULD RETURN DATA T, OR A LIST, NOT VOID

 ITERATOR CLASS

 list[-1] SHOULD RETURN TAIL
 */

template <typename T>
class twList
{
public:
    twList();
    twList(const twList &other);
    ~twList();

    void pushFront(const T &data);
    void pushBack(const T &data);

    void pushFront(twList<T>& list, int i);
    void pushBack(twList<T>& list, int i);

    void pushFront(twList<T>& list);
    void pushBack(twList<T>& list);

    void popFront();
    void popBack();
    void popIndex(int i);

    const T& front();
    const T& back();
    const T& operator[](int i);

    int size();
    bool empty();

private:
    twNode<T> *head, *tail;

    twNode<T>* getNode(int i);
    void extractNode(twNode<T> *node);
    twNode<T>* extractNode(int i);

    void clear();
    void copy();

    void pushFront(twNode<T> *node);
    void pushBack(twNode<T> *node);

    twNode<T>* operator ()(int i=0);
};

template <typename T>
twList<T>::twList()
{
    head = tail = 0;
}

template <typename T>
twList<T>::twList(const twList &other)
{
    copy(other);
}

template <typename T>
twList<T>::~twList()
{
    clear();
}

template <typename T>
void twList<T>::pushFront(const T &data)
{
    if(!head)                               //case queue was empty
        tail = head = new twNode<T>(data);
    else
    {
        head->fore = new twNode<T>(data);   //case queue had at least 1 item
        head->fore->rear = head;
        head = head->fore;
    }
}

template <typename T>
void twList<T>::pushBack(const T &data)
{
    if(!tail)                               //case queue was empty
        head = tail = new twNode<T>(data);
    else
    {
        tail->rear = new twNode<T>(data);   //case queue had at least 1 item
        tail->rear->fore = tail;
        tail = tail->rear;
    }
}

template <typename T>
void twList<T>::pushFront(twNode<T> *node)
{
    if(!head)                               //case queue was empty
        tail = head = node;
    else
    {
        head->fore = node;                   //case queue had at least 1 item
        head->fore->rear = head;
        head = head->fore;
    }
}

template <typename T>
void twList<T>::pushBack(twNode<T> *node)
{
    if(!tail)                               //case queue was empty
        head = tail = node;
    else
    {
        tail->rear = node;                  //case queue had at least 1 item
        tail->rear->fore = tail;
        tail = tail->rear;
    }
}

template <typename T>
void twList<T>::pushFront(twList<T> &list, int i)
{
    pushFront(list(i));
}

template <typename T>
void twList<T>::pushBack(twList<T> &list, int i)
{
    pushBack(list(i));
}

template <typename T>
void twList<T>::pushFront(twList<T> &list)
{
    while(!list.empty())
        pushFront(list(0));
}

template <typename T>
void twList<T>::pushBack(twList<T> &list)
{
    while(!list.empty())
        pushBack(list(0));
}

template <typename T>
void twList<T>::popFront()
{
    if(head)
    {
        if(head->rear)
        {
            head = head->rear;
            delete head->fore;
            head->fore = 0;
        }
        else
        {
            delete head;
            head = tail = 0;
        }
    }
}

template <typename T>
void twList<T>::popBack()
{
    if(tail)
    {
        if(tail->fore)
        {
            tail = tail->fore;
            delete tail->rear;
            tail->rear = 0;
        }
        else
        {
            delete tail;
            head = tail = 0;
        }
    }
}

template <typename T>
void twList<T>::popIndex(int i)
{
    twNode<T> *node = getNode(i);
    extractNode(node);
    delete node;
}

template <typename T>
const T& twList<T>::front()
{
    if(head)
        return head->data;
    throw OUTOFRANGE;
}

template <typename T>
const T& twList<T>::back()
{
    if(tail)
        return tail->data;
    throw OUTOFRANGE;
}

template <typename T>
const T& twList<T>::operator [](int i)
{
    return (getNode(i))->data;
}

template <typename T>
twNode<T>* twList<T>::operator ()(int i)
{
    return extractNode(i);
}

template <typename T>
int twList<T>::size()
{
    if(head)
    {
        twNode<T> *temp=head;
        int count = 1;
        while(temp!=tail)
        {
            temp = temp->rear;
            count++;
        }
        return count;
    }
    return 0;
}

template <typename T>
bool twList<T>::empty()
{
    return !head;
}

template <typename T>
twNode<T>* twList<T>::getNode(int i)
{
    twNode<T> *node=head;
    if(node==tail && i==0)          //case only one element
        return node;
    while(node!=tail)
    {
        if(i==0)
            return node;
        node = node->rear;
        i--;
    }
    if(node==tail && i==0)          //case returning last element
        return node;
    throw OUTOFRANGE;
}

template <typename T>
void twList<T>::extractNode(twNode<T> *node)
{
    if(node->fore && node->rear)
    {
        node->fore->rear = node->rear;
        node->rear->fore = node->fore;
        node->fore = node->rear = 0;
    }
    else if(node->fore)
    {
        if(node == tail)
            tail = node->fore;
        node->fore->rear = 0;
        node->fore = 0;
    }
    else if(node->rear)
    {
        if(node == head)
            head = node->rear;
        node->rear->fore = 0;
        node->rear = 0;
    }
}

template <typename T>
twNode<T> *twList<T>::extractNode(int i)
{
    twNode<T> *node = getNode(i);
    if(node->fore && node->rear)
    {
        node->fore->rear = node->rear;
        node->rear->fore = node->fore;
        node->fore = node->rear = 0;
    }
    else if(node->fore)
    {
        if(node == tail)
            tail = node->fore;
        node->fore->rear = 0;
        node->fore = 0;
    }
    else if(node->rear)
    {
        if(node == head)
            head = node->rear;
        node->rear->fore = 0;
        node->rear = 0;
    }
    else                    //case 1 item in list
    {
        node->fore = node->rear = 0;
        head = tail = 0;
    }
    return node;
}

template <typename T>
void twList<T>::clear()
{
    while(head)
        popBack();
}

#endif // TWLIST_H
