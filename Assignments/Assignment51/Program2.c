/*
    Doubly Linear Linked List

    Inside constructor of DoublyLL
    |11|<=>|21|<=>|51|<=>NULL
    Number of nodes are : 3
    |11|<=>|21|<=>|51|<=>|101|<=>|111|<=>|121|<=>NULL
    Number of nodes are : 6
    |21|<=>|51|<=>|101|<=>|111|<=>|121|<=>NULL
    Number of nodes are : 5
    |21|<=>|51|<=>|101|<=>|111|<=>NULL
    Number of nodes are : 4
    |21|<=>|51|<=>|101|<=>|105|<=>|111|<=>NULL
    Number of nodes are : 5
    |21|<=>|51|<=>|101|<=>|111|<=>NULL
    Number of nodes are : 4
*/
#include<iostream>
using namespace std;

template <class T>
struct DoublyLLnode
{
    T data;
    struct DoublyLLnode<T> *next;
    struct DoublyLLnode<T> *prev;
};

template <class T>
class DoublyLL
{
private:
    struct DoublyLLnode<T> * first;
    struct DoublyLLnode<T> * last;
    int iCount;

public:
    DoublyLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int pos);
    void Display();
    int Count();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside constructor of DoublyLL\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct DoublyLLnode<T> * newn = new DoublyLLnode<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = first;

    if(first == NULL)
    {
        first = last = newn;
    }
    else
    {
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct DoublyLLnode<T> * newn = new DoublyLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = last;

    if(first == NULL)
    {
        first = last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
        return;

    if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        struct DoublyLLnode<T> * temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
        return;

    if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        struct DoublyLLnode<T> * temp = last;
        last = last->prev;
        last->next = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount + 1)
        InsertLast(no);
    else
    {
        struct DoublyLLnode<T> * newn = new DoublyLLnode<T>;
        newn->data = no;

        struct DoublyLLnode<T> * temp = first;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        struct DoublyLLnode<T> * temp = first;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        struct DoublyLLnode<T> * target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;
        iCount--;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    struct DoublyLLnode<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

int main()
{
    DoublyLL<int> sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.InsertAtPos(105,4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    sobj.DeleteAtPos(4);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}
