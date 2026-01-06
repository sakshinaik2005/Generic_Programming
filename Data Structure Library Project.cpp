////////////////////////////////////////////////////////////////////////////////////////
// Genralised Data Structure Library
///////////////////////////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------
Type               Name of class for node        Name of class for Functionality
--------------------------------------------------------------------------------------------
Singly Linear      SinglyLLLnode                 SingyLLL             Done
Singly Circular    SinglyCLLnode                 SinglyCLL            Done
Doubly Linear      DoublyLLLnode                 DoublyLLL            Done
Doubly Circular    DoublyCLLnode                 DoublyCLL            Done
---------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Final code of Singly Linear Linked list using generic approach
//////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
cout<<"Object of SinglyLL gets created.\n";
this->first = NULL;
this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertFirst
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at first position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: InsertFirst(T no)   
{
SinglyLLLnode<T>* newn = NULL;

newn = new SinglyLLLnode<T>(no);

newn->next = this->first;
this->first = newn;

this->iCount++;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertLast
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at last position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
SinglyLLLnode<T>* newn = NULL;
SinglyLLLnode<T>* temp = NULL;

newn = new SinglyLLLnode<T>(no);

if(this->iCount == 0)     
{
    this->first = newn;
}
else
{
    temp = this->first;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newn;
}
this->iCount++;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteFirst
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at first position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
SinglyLLLnode<T>* temp = NULL;

if(this->first == NULL)
{
    return;
}
else if(this->first->next == NULL)    
{
    delete this->first;
    this->first = NULL;
}
else
{
    temp = this->first;

    this->first = this->first -> next;
    delete temp;
}

this->iCount--;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteLast
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at last position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: DeleteLast()
{
SinglyLLLnode<T>* temp = NULL;

if(this->first == NULL)
{
    return;
}
else if(this->first->next == NULL)    
{
    delete this->first;
    this->first = NULL;
}
else
{
    temp = this->first;

    while(temp->next->next != NULL)
    {
        temp = temp -> next;
    }

    delete temp->next;
    temp->next = NULL;

}
this->iCount--;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : Display
//       Input         : Data of node
//       Output        : -
//       Description   : Used to display node on console
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: Display()
{
SinglyLLLnode<T>* temp = NULL;
int iCnt = 0;

temp = this->first;

for(iCnt = 1; iCnt <= this->iCount; iCnt++)   
{
    cout<<"| "<<temp->data<<" |-> ";
    temp = temp->next;
}

cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : Count
//       Input         : data of node
//       Output        : Nothing
//       Description   : Used to count nodes
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T> :: Count()
{
return this->iCount;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertAtPos
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at specific position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
SinglyLLLnode<T>* temp = NULL;
SinglyLLLnode<T>* newn = NULL;

int iCnt = 0;

if(pos < 1 || pos > this->iCount + 1)
{
    cout<<"Invalid position\n";
    return;
}

if(pos == 1)
{
    this->InsertFirst(no);
}
else if(pos == this->iCount+1)
{
    this->InsertLast(no);
}
else
{
    newn = new SinglyLLLnode<T>(no);

    newn->data = no;
    newn->next = NULL;

    temp = this->first;
    
    for(iCnt = 1; iCnt < pos-1; iCnt++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    temp->next = newn;

    this->iCount++;
}
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteAtPos
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at specific position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
SinglyLLLnode<T>* temp = NULL;
SinglyLLLnode<T>* target = NULL;

int iCnt = 0;

if(pos < 1 || pos > this->iCount)
{
    cout<<"Invalid position\n";
    return;
}

if(pos == 1)
{
    this->DeleteFirst();
}
else if(pos == this->iCount)
{
    this->DeleteLast();
}
else
{
    temp = this->first;
    
    for(iCnt = 1; iCnt < pos-1; iCnt++)
    {
        temp = temp->next;
    }

    target = temp->next;

    temp->next = target->next;
    delete target;

    this->iCount--;
}
}

///////////////////////////////////////////////////////////////////////////////
// Final code of Doubly Linear Linked list using generic approach
//////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
public :
    T data;
    DoublyLLLnode * next;
    DoublyLLLnode* prev;

    DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
 };
 template<class T>
 class DoublyLLL
 {
    private:
    DoublyLLLnode<T>*first ;
    int iCount ;

    public:
    DoublyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    
    void Display();
    int Count();
};
template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"LinkList gets Created\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertFirst
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at first position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL <T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this-> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        newn -> next = this->first;
        this-> first -> prev = newn;
        this -> first = newn;
    }
    this-> iCount++;
    
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertLast
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at last position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
 template<class T>
void DoublyLLL <T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);
    if(this-> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        
        temp = this->first;

        while(temp->next != NULL)
        {
            temp =temp-> next;
        }
        temp-> next = newn;
        newn-> prev = temp;
    }
    this -> iCount++;
    
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteFirst
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at first position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL <T> :: DeleteFirst()
{
    
 if(this -> first == NULL)              //LL is Emtpy
 {
    return;
 } 
 else if(this-> first->next ==NULL)     //LL contains one node
 {
    delete this-> first;
    this -> first = NULL;
 }  
 else                                   //LL contanis more then one node
 {
    this -> first = this->first ->next;
    delete this->first -> prev;
    this -> first-> prev = NULL;
 }
 this -> iCount--;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteLast
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at last position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;
    if(this -> first == NULL)              //LL is Emtpy
 {
    return;
 } 
 else if(this-> first->next ==NULL)     //LL contains one node
 {
    delete this-> first;
    this -> first = NULL;
 }  
 else                                   //LL contanis more then one node
 {
    temp = this->first;
    while(temp->next -> next != NULL)
    {
        temp = temp -> next;
    }
    delete temp-> next;
    temp -> next = NULL;
 }
 this -> iCount--;
    
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertAtPos
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at specific position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL <T>:: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
    int iCnt = 0;
    if((pos<1)||(pos>this->iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos ==1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1;iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteAtPos
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at specific position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos<1)||(pos>this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos ==1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1;iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : Display
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to display nodes 
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> ::Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this-> first;
    cout<<"\n Null<=>";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"| <=>";
        temp = temp -> next;

    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : Count
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to count nodes
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template<class T>
int  DoublyLLL <T> ::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////
// Final code of Singly Circular Linked list using generic approach
//////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertFirst
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at first position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertLast
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at last position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)   
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;

        this->last->next = first;
    }

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteFirst
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at first position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)     // LL is Empty
    {
        return;
    }
    else if(this->first == this->last)     // LL contains one node
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else                                // LL contains more than one node
    {
        this->first = this->first -> next;
        delete this->last->next;

        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteLast
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at last position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if((this->first == NULL) && (this->last == NULL))      //LL is Empty
    {
        return;
    }
    else if(this->first == this->last)                  // LL contains one node
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else                                      //LL contains more than one node
    {
        temp = this->first;

        while(temp -> next != this->last)
        {
            temp = temp -> next;
        }

        delete this->last;
        this->last = temp;

        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertAtPos
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at specific position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1;iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteAtPos
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at specific position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int iCnt = 0;
    
    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : Display
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to display nodes
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    if((this->first == NULL) && (last == NULL))
    {
        return;
    }

    SinglyCLLnode<T> * temp = this->first;

    cout<<"\n ->";
    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != this->last ->next);
    
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : Count
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to count nodes
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}


///////////////////////////////////////////////////////////////////////////////
// Final code of Doubly Circular Linked list using generic approach
//////////////////////////////////////////////////////////////////////////////


#pragma pack(1)

template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode *next;
        DoublyCLLnode *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
 class DoublyCLL
 {
    private:
        DoublyCLLnode<T>*first ;
        DoublyCLLnode<T>* last;
        int iCount ;

    public:
        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        
        void Display();
        int Count();
};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"LinkList gets Created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertFirst
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at first position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> ::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL)) 
    {
        this->first = newn;
        this->last = newn;
    }
    else    
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertLast
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at last position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> ::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    
    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL)) 
    {
        this->first = newn;
        this->last = newn;
    }
    else    
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteFirst
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at first position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL <T> :: DeleteFirst()
{
    if((this->first == NULL) && (this->last == NULL)) // LL is empty
    {
        return;
    }
    else if(this->first == this->last)    // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else                             // LL contains more than one node
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->last->next = this->first;
        this->first->prev = this->last;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteLast
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at last position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if((this->first == NULL) && (this->last == NULL)) // LL is empty
    {
        return;
    }
    else if(this->first == this->last)    // LL contains 1 node
    {
        delete first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
        
        this->last->next = this->first;
        this->first->prev = this->last;
    }    
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : InsertAtPos
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to insert node at specific position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL <T>:: InsertAtPos(T no,int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : DeleteAtPos
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to delete node at specific position
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : Display
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to display nodes
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T> ::Display()
{
    if(this->first == NULL)   // LL is empty
    {
        cout<<"Linked List is empty\n";
        return;
    }

    DoublyCLLnode<T>* temp = first;
    cout<<"\n<=>";
    do
    {
        cout<<" | "<<temp->data<<"| <=>";
        temp = temp->next;
    }while(temp != this->first);
    
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////
//     
//       Function Name : Count
//       Input         : Data of node
//       Output        : Nothing
//       Description   : Used to count nodes
//       Author        : Sakshi Santosh Naik
//       Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////
template <class T>
int  DoublyCLL <T> ::Count()
{
   return this->iCount;
}

/////////////////////////// End of Library ///////////////////////////////////////

int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>;
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    delete obj;
    
//////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj-> InsertFirst('A');
    dobj-> InsertFirst('B');
    dobj-> InsertFirst('C');

    dobj-> Display();
    cout<<"Number of elemnts are :"<< dobj->Count()<<"\n";

    dobj-> InsertLast('X');
    dobj-> InsertLast('Y');
    dobj-> InsertLast('Z');

    dobj-> Display();
    cout<<"Number of elemnts are :"<< dobj->Count()<<"\n";

    dobj -> DeleteFirst();

    dobj-> Display();
    cout<<"Number of elemnts are :"<< dobj->Count()<<"\n";

    dobj -> DeleteLast();

    dobj-> Display();
    cout<<"Number of elemnts are :"<< dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);

    dobj-> Display();
    cout<<"Number of elemnts are :"<< dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj-> Display();
    cout<<"Number of elemnts are :"<< dobj->Count()<<"\n";

    delete dobj;

//////////////////////////////////////////////////////////////////////

SinglyCLL<int> *sobj = new SinglyCLL<int>();

    sobj->InsertFirst(51);
    sobj->InsertFirst(21);
    sobj->InsertFirst(11);
    
    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    sobj->InsertLast(101);
    sobj->InsertLast(111);
    sobj->InsertLast(121);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->DeleteFirst();

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    sobj->DeleteLast();

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    sobj->InsertAtPos(105,4);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    sobj->DeleteAtPos(4);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";

    delete sobj;

//////////////////////////////////////////////////////////////////////

DoublyCLL<int>* cobj = new DoublyCLL<int>();

    cobj->InsertFirst(51);
    cobj->InsertFirst(21);
    cobj->InsertFirst(11);

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";
    
    cobj->InsertLast(121);
    cobj->InsertLast(111);
    cobj->InsertLast(101);

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";
    
    cobj->DeleteFirst();
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";
    
    cobj->DeleteLast();
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";
     
    cobj->InsertAtPos(105,4);
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";
     
    cobj->DeleteAtPos(4);
    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";
    
    delete cobj;

    return 0;
}


/*
------------------------------------------------------------------
    Output of Data Structure Library Project
------------------------------------------------------------------
    Object of SinglyLL gets created.
    | 11 |-> | 21 |-> | 51 |-> NULL
    Number of nodes are : 3
    | 11 |-> | 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL
    Number of nodes are : 6
    | 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL
    Number of nodes are : 5
    | 21 |-> | 51 |-> | 101 |-> | 111 |-> NULL
    Number of nodes are : 4
    | 21 |-> | 51 |-> | 101 |-> | 105 |-> | 111 |-> NULL
    Number of nodes are : 5
    | 21 |-> | 51 |-> | 101 |-> | 111 |-> NULL
    Number of nodes are : 4
    LinkList gets Created

    Null<=>| C| <=>| B| <=>| A| <=>NULL
    Number of elemnts are :3

    Null<=>| C| <=>| B| <=>| A| <=>| X| <=>| Y| <=>| Z| <=>NULL
    Number of elemnts are :6

    Null<=>| B| <=>| A| <=>| X| <=>| Y| <=>| Z| <=>NULL
    Number of elemnts are :5

    Null<=>| B| <=>| A| <=>| X| <=>| Y| <=>NULL
    Number of elemnts are :4

    Null<=>| B| <=>| A| <=>| X| <=>| $| <=>| Y| <=>NULL
    Number of elemnts are :5

    Null<=>| B| <=>| A| <=>| X| <=>| Y| <=>NULL
    Number of elemnts are :4
    Linked list gets created

    ->| 11 | -> | 21 | -> | 51 | ->
    Number of elements are : 3

    ->| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->
    Number of elements are : 6

    ->| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->
    Number of elements are : 5

    ->| 21 | -> | 51 | -> | 101 | -> | 111 | ->
    Number of elements are : 4

    ->| 21 | -> | 51 | -> | 101 | -> | 105 | -> | 111 | ->
    Number of elements are : 5

    ->| 21 | -> | 51 | -> | 101 | -> | 111 | ->
    Number of elements are : 4
    LinkList gets Created

    <=> | 11| <=> | 21| <=> | 51| <=>
    Number of nodes are :3

    <=> | 11| <=> | 21| <=> | 51| <=> | 121| <=> | 111| <=> | 101| <=>
    Number of nodes are :6

    <=> | 21| <=> | 51| <=> | 121| <=> | 111| <=> | 101| <=>
    Number of nodes are :5

    <=> | 21| <=> | 51| <=> | 121| <=> | 111| <=>
    Number of nodes are :4

    <=> | 21| <=> | 51| <=> | 121| <=> | 105| <=> | 111| <=>
    Number of nodes are :5

    <=> | 21| <=> | 51| <=> | 121| <=> | 111| <=>
    Number of nodes are :4

*/
