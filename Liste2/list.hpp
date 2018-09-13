#pragma once
#include <node.hpp>
#include <iostream>
template <typename T>

class CList
{
private:
    CNode<T>* m_Head;
    CNode<T>* m_Tail;
public:
    CList ();
    ~CList ();
   //ajout en tête de liste
    void push_front (const T & val);
   //affichage
    void Show () const;
    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find (const T & val) const;
    //ajout d'une valeur après un maillon de la liste
    void Add (const T & val, CNode<T>* ptr);
    //détache un maillon de la liste et le supprime
    void Delete (CNode<T>* pDelete);
    void push_back(const T& val);
};

template <typename T>
CList<T>::CList(): m_Head (nullptr), m_Tail (nullptr) {}

template <typename T>
void CList<T>::push_front(const T& val)
{
    m_Head = new CNode<T>(val,m_Head);
}

template <typename T>
void CList<T>::Show() const
{
    for(CNode<T>* ptr (m_Head); ptr != nullptr; ptr =ptr->GetNextNode())
        std::cout<<ptr->GetData()<<';';
}

template <typename T>
CList<T>::~CList()
{
    delete m_Head;
    delete m_Tail;
}

template <typename T>
CNode<T>* CList<T>::Find (const T& val) const
{
    CNode<T>* ptr (m_Head);
    for ( ; ptr != nullptr && ptr->GetData () != val
         ; ptr = ptr->GetNextNode ());

    return ptr;
}

template <typename T>
void CList<T>::Add(const T &val, CNode<T>* ptr)
{
    if (nullptr == ptr) return;
    CNode<T>* ptrTmp = new CNode<T>(val, ptr->GetNextNode());
    ptr->SetNextNode (ptrTmp);
}

template <typename T>
void CList<T>::Delete (CNode<T>* pDelete)
{
    CNode<T>* pFind (m_Head);
    for ( ; pFind->GetNextNode() != pDelete ;
           pFind = pFind->GetNextNode ())
        if (pFind->GetNextNode () == nullptr) return;

    pFind->SetNextNode (pDelete->GetNextNode ());
    pDelete->SetNextNode (nullptr);

    delete pDelete;

} // Delete()

template <typename T>
void CList<T>::push_back(const T& val)
{
    CNode<T>* pTmp = new CNode<T> (val,NULL);
    m_Tail -> SetNextNode(pTmp);
    m_Tail = pTmp;
}
