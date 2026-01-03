/*
    Doubly Circular Linked List

    Inside constructor of doublyCLL
    <=>|11|<=>|21|<=>|51|<=>
    Number of nodes are : 3
    <=>|11|<=>|21|<=>|51|<=>|101|<=>|111|<=>|121|<=>
    Number of nodes are : 6
    <=>|21|<=>|51|<=>|101|<=>|111|<=>|121|<=>
    Number of nodes are : 5
    <=>|21|<=>|51|<=>|101|<=>|111|<=>
    Number of nodes are : 4
    <=>|21|<=>|51|<=>|101|<=>|105|<=>|111|<=>
    Number of nodes are : 5
    <=>|21|<=>|51|<=>|101|<=>|111|<=>
    Number of nodes are : 4
*/ 

#include<iostream>
using namespace std;

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
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
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Inside constructor of doublyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    cout<<"<=>";

    struct DoublyCLLnode<T> * temp = first;
    
    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;

    }while(temp != last->next);

    cout<<"\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}


template <class  T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position"<<"\n";
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * target = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position"<<"\n";
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        
        for(i = 1; i < pos -1;i++)
        {
            temp = temp ->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;
    }
    iCount--;
}

int main()
{
    DoublyCLL<int> sobj;
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
