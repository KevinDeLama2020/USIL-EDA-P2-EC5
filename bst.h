#ifndef __BST_H__ //Maizo Diego
#define __BST_H__  //kevin de lama

#include <iostream>
using namespace std;

//para la realización de este codigo Kevin De Lama y Diego Maizo trabajaron juntos y probaron distintos versiones de codigo

template <typename T>
class CBinaryTree
{
    struct Node
    {
      T data;//Maizo
      Node *m_pChild[2];
      Node(T &_data, Node *pLeft=nullptr, Node *pRight=nullptr)
        : data(_data)
      {   m_pChild[0] = pLeft;  m_pChild[1] = pRight;   }
      T getData()             { return data; } //Maizo
      void setData (T &_data) { data=_data; }  //Maizo
      
    };
    //Node *m_pRoot = nullptr;
public:

    Node *m_pRoot = nullptr;

    CBinaryTree() {}
    void insert_old(const T &dato)
    {   
        Node **ppNode = &m_pRoot;
        while(*ppNode != nullptr)      
        { if(dato > (*ppNode)->getData())
            ppNode = &ppNode->m_pChild[1];
          else
            ppNode = &ppNode->m_pChild[0];
        }
        *ppNode = new Node(dato);
    }
    void insert(T &dato)
    { 
      internal_insert(m_pRoot, dato);
      //print1(m_pRoot); v1.1 Maizo y Kevin funcionaba pero imprimia cada que se hacia un insert, no escalable
    }
    void printbase() //v1.2 nueva func Maizo (misma idea func insert)
    {
      cout<<"menor a mayor"<<endl;
      print1(m_pRoot);//v1.2kevin
      cout<<"mayor a menor"<<endl; 
      print2(m_pRoot);//v1.2Maizo
    }

private:
    void internal_insert(Node *&rParent, T &dato);//Maizo
    void print1(Node *&rParent);//v1.1 kevin funcion hecha para menor a mayor
    void print2(Node *&rParent);//v1.2 Maizo misma idea para mayor a menor
};

template <typename T>
void CBinaryTree<T>:: internal_insert(Node *&rParent, T &dato) // kevin de lama
{
  if(!rParent) //rParent!=nullptr
  {   rParent = new Node(dato);
      return;
  }
  //right or left
  internal_insert(rParent->m_pChild[ dato > rParent->getData() ], dato);
}

template <typename T>
void CBinaryTree<T>:: print1(Node *&rParent)//v1.1 de lama, imprimir los valores distintos errores presentados
{
  //rParent=m_pRoot; v1.1 Maizo, intento de remover el Node *&rParent del print1, para ser llamado en el main
  if (rParent==nullptr) //creada por De Lama para que trabaje de forma eficiente en vez de la manera old
    return;

  //cout<<"De menor a mayor"<<endl;

  print1(rParent->m_pChild[0]);
  //Primera idea y logica planteada como ejemplo por De Lama (print1(root->left))
  //rParent->m_pChild[0]; v1.1 Maizo, idea para imprimir luego de remover el Node *&rParent
  cout<<rParent->getData()<<endl;//idea planteada por De Lama 

  print1(rParent->m_pChild[1]);
  //Segunda idea y logica planteada como ejemplo por De Lama (print1(root->right))
  //rParent->m_pChild[1]; v1.1 Maizo, idea para imprimir luego de remover el Node *&rParent

  //v1.1 Kevin y Maizo, se probo hacer la opcion de mayor a menor en la función print1 (daba error)
  /*cout<<"De mayor a menor"<<endl;
  print1(rParent->m_pChild[1]);
  cout<<rParent->getData()<<""<<endl;
  print1(rParent->m_pChild[0]);*/
}

template <typename T>
void CBinaryTree<T>:: print2(Node *&rParent)//v1.2 Maizo, se duplico la func print1, pero ahora funciona de mayor a menor
{
  if (rParent==nullptr)
    return;

  print2(rParent->m_pChild[1]);
  cout<<rParent->getData()<<endl;
  print2(rParent->m_pChild[0]);
}

#endif //Maizo Diego  
