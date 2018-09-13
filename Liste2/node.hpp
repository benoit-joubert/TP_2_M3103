#pragma once
#include <iostream>
template <typename T>

class CNode
{
private:
    T m_Data;
    CNode* m_Next;
public:
    //constructor
    CNode (const T& Val = T(), CNode* next = nullptr);
    //destructor
    ~CNode () {delete m_Next;}
    //getter
    const T &GetData();
    CNode* GetNextNode() const {return m_Next;}
    // setter
    void setData(T Val) {m_Data = Val;}
    void SetNextNode(CNode* next) {m_Next = next;}
};

template <typename T>
CNode<T>::CNode(const T& Val, CNode * next) : m_Data (Val), m_Next(next){}

template <typename T>
const T& CNode<T>::GetData()
{
    std::cout <<&m_Data<<std::endl;
    return m_Data;
}
