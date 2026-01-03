/*
    Singly Linear Linked List

    Inside constructor of SinglyLLL
    |11|->|21|->|51|->NULL
    Number of nodes are : 3
    |11|->|21|->|51|->|101|->|111|->|121|->NULL
    Number of nodes are : 6
    |21|->|51|->|101|->|111|->|121|->NULL
    Number of nodes are : 5
    |21|->|51|->|101|->|111|->NULL
    Number of nodes are : 4
    |21|->|51|->|101|->|105|->|111|->NULL
    Number of nodes are : 5
    |21|->|51|->|101|->|111|->NULL
    Number of nodes are : 4
*/
#include<iostream>
using namespace std;

template <class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T> *next;
};

template <class T>
class SinglyLLL
{
private:
    struct SinglyLLLnode<T> * first;
    int iCount;

public:
    SinglyLLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no, int pos);
    void DeleteAtPos(int pos);
    void Display();
    int Count();
};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"Inside constructor of SinglyLLL\n";
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    struct SinglyLLLnode<T> * newn = new SinglyLLLnode<T>;

    newn->data = no;
    newn->next = first;
    first = newn;

    iCount++;
}

template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    struct SinglyLLLnode<T> * newn = new SinglyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        struct SinglyLLLnode<T> * temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    if(first == NULL)
        return;

    struct SinglyLLLnode<T> * temp = first;
    first = first->next;
    delete temp;

    iCount--;
}

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    if(first == NULL)
        return;

    if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct SinglyLLLnode<T> * temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct SinglyLLLnode<T> * newn = new SinglyLLLnode<T>;
        newn->data = no;

        struct SinglyLLLnode<T> * temp = first;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else
    {
        struct SinglyLLLnode<T> * temp = first;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        struct SinglyLLLnode<T> * target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

template <class T>
void SinglyLLL<T>::Display()
{
    struct SinglyLLLnode<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLLL<T>::Count()
{
    return iCount;
}

int main()
{
    SinglyLLL<int> sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.InsertAtPos(105,4);
    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.DeleteAtPos(4);
    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    return 0;
}
