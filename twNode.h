#ifndef TWNODE_H
#define TWNODE_H

template<typename T>
struct twNode
{
    twNode(const T &dataIn);
    ~twNode();

    void zero();

    T data;
    twNode *rear, *fore;
};

template<typename T>
twNode<T>::twNode(const T &dataIn)
{
    data = dataIn;
    rear = fore = 0;
}

template<typename T>
twNode<T>::~twNode()
{
    rear = fore = 0;
}

#endif // TWNODE_H
