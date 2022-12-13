#include<iostream>
#include<dos.h>
#include <charconv>
using namespace std;

template<class T>
struct node
{
T data;
struct node *next;
};

template<class T>
struct NODE
{
T data;
struct NODE *next;
};

template<class T>
struct NODE1
{
T data;
struct NODE1 *next;
struct NODE1 *prev;
};

template<class T>
struct NODE2
{
T data;
struct NODE2 *next;
struct NODE2 *prev;
};

template<class T>
struct NODE3
{
T data;
struct NODE3 *next;
};


template<class T>
struct NODE4
{
T data;
struct NODE4 *next;
};


template <class T>
class SinglyLL            //Singly Linear Linked List
{
private:
    struct node<T> *Head;
    
public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(T);
    void Display();
    int Count();

};


template <class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		newn->next=Head;
		Head=newn;
			
	}
}


template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    struct node<T> *temp = Head;

    newn->data = no;
    newn->next = NULL;

    if(Head==NULL)
	{
		Head=newn;
	}
    else
    {
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
    }

}

template <class T>
void SinglyLL<T>::InsertAtPos(T no,T pos)
{
	struct node<T> *newn=NULL;
	
	
	if((Head == NULL)||(pos > (Count() + 1)) ||(pos<=0))
	{
		cout<<"Invalid Position"<<endl;
		return;
	}
	if(pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos==(Count() + 1))
	{
		InsertLast(no);
	}
	else
	{
		int iCnt = 0;
		struct node<T> *newn = NULL;
		struct node<T> *temp = Head;
		newn = new node<T>;
		newn->data= no;
		newn->next=NULL;
		
		for(iCnt=1;iCnt <= (pos-2);iCnt++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> *temp = Head;
	if(Head == NULL)
	{
		return;
	}
	else
	{
		Head = temp->next;
		delete temp;
	}
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T> *temp = NULL;
	if(Head == NULL)
	{
		return;
	}
	else if(Head->next==NULL)
	{
		delete(Head);
		Head=NULL;
	}
	else
	{
		temp = Head;
		while(temp->next->next != NULL)
		{
			temp=temp->next;
		}
		delete(temp->next);
		temp->next=NULL;
	}
}


template <class T>
void SinglyLL<T>::DeleteAtPos(T pos)
{  
	int iCnt=0;
	
	if((Head == NULL)||(pos > Count())||(pos<=0))
	{
		cout<<"Invalid Position";
		return;
	}
	if(pos==1)
	{
		DeleteFirst();
	}
	else if(pos==(Count()))
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp = NULL;
		temp = Head;
		struct node<T> *tempdelete=NULL;
		int iCnt = 0;
		
		for(iCnt=1;iCnt<(pos-1);iCnt++)
		{
			temp=temp->next;
		}
		tempdelete=temp->next;
		temp->next=temp->next->next;
		delete(tempdelete);
	}
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements from Linked list are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

template <class T>
int SinglyLL<T>::Count()
{
	struct node<T> *temp = Head;
    int iCnt=0;
	while(temp!=NULL)
	{
		iCnt++;
		temp=temp->next;
	}
	return iCnt;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SinglyCircular

template<class T>
class SinglyCLL
{
public: 
    struct node<T> *Head;
    struct node<T> *Tail;

public:                      
    SinglyCLL(); 
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(T);
    void Display();
    int Count();
};


template<class T>
SinglyCLL<T>::SinglyCLL() 
{
    Head = NULL;
    Tail = NULL;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>; //    malloc in C

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) //    if LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else //            if LL contains atleast one node
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head; //           imp
}

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn  = NULL;

    newn = new node<T>; //    malloc in C

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) //    if LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else //            if LL contains atleast one node
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head; //      imp
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, T ipos)
{
    int iSize = Count();

    if ((ipos < 1) || (ipos > iSize + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no); //         method is from same class so no need of object
    }
    else if (ipos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn  = NULL;
        newn = new node <T>;

        newn->data = no;
        newn->next = NULL;

        struct node<T> *temp = Head;
        int iCnt = 0;

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if (Head == NULL && Tail == NULL) //    If LL is empty
    {
        return;
    }
    else if (Head == Tail) //       If LL contains 1 node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else //        If LL contains more than 1 node
    {
        Head = Head->next;

        delete Tail->next;

        Tail->next = Head;
    }
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    if (Head == NULL && Tail == NULL) //    If LL is empty
    {
        return;
    }
    else if (Head == Tail) //       If LL contains 1 node
    {
        delete Head; //  Intead of Head we can write Tail also
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct node<T> *temp = Head;

        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = Head;
    }
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(T ipos)
{
    int iSize = Count();

    if ((ipos < 1) || (ipos > iSize))
    {
        cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst(); 
    }
    else if (ipos == iSize + 1)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp1 = Head;
        int iCnt = 0;
        struct node<T> *temp2 = NULL;

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct node<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) 
    {
        return;
    }

    do
    {
        cout << "[ " << temp->data << " ]->";
        temp = temp->next;
    } while (temp != Head);

    cout << endl;
}

template<class T>
int SinglyCLL<T>::Count()
{
    int iCnt = 0;
    struct node<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL))
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Head);

    return iCnt;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//DoublyLinear

template<class T>
class DoublyLL
{
    public:
        struct NODE1<T> *Head;
        int Count;

        DoublyLL();
		
        void InsertFirst(T);
        void InsertLast(T);
        void Display();
        int CountNode();
		void DeleteFirst();
		void DeleteLast();
		void InsertAtPos(T,T);
		void DeleteAtPos(T);
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct NODE1<T> *newn = NULL;
    newn = new NODE1<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
		Head->prev = newn;
        newn -> next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct NODE1<T> *newn = NULL;
    newn = new NODE1<T>;

    newn->data = no;
    newn->next = NULL;
	newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
            struct NODE1<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }

            temp->next = newn;
			newn->prev = temp;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements from Linked list are : "<<endl;
    struct NODE1<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
	 struct NODE1<T> *temp = Head;
	 if(Head==NULL)
	 {
		 return;
	 }
	 else
	 {
		 Head=Head->next;
		 Head->prev=NULL;
		 delete(temp);
	 }
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		struct NODE1<T> *temp = Head;
		
		
		while((temp->next)!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		delete(temp);
	}
	
}


template<class T>
void DoublyLL<T>::InsertAtPos(T pos,T no)
{
	if((Head == NULL)||(pos>Count+1)||(pos<=0))
	{
		return;
	}
	if(pos == 1)
	{
		return(InsertFirst(no));
	}
	else if(pos == (Count)+1)
	{
		return(InsertLast(no));
	}
	else
	{
		struct NODE1<T> *newn = NULL;
		struct NODE1<T> *temp = Head;
		
		newn = new NODE1<T>;
		
		if(newn==NULL)
		{
			return;
		}
		newn->next = NULL;
		newn->data=no;
		newn->prev = NULL;
		
		for(int i=1;i<=(pos-2);i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		newn->prev = temp;
		temp->next = newn;
	}
}

	
template<class T>
void DoublyLL<T>::DeleteAtPos(T pos)
{
	if((Head == NULL)||(pos>Count)||(pos<=0))
	{
		return;
	}
	else if(pos == 1)
	{
		DeleteFirst();
	}
	else if(pos == (Count))
	{
		DeleteLast();
	}
	else
	{
		
		struct NODE1<T> *temp = Head;
		//struct node<T> *tempdelete = NULL;
		
		for(int i=1;i<=(pos-2);i++)
		{
			temp->next=temp->next->next;
			delete temp->next->prev;
			temp->next->prev=temp;
		}
		
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//DoublyCircular

template<class T>

class DoublyCLL
{
    public:
        struct NODE2<T> *Head;
        struct NODE2<T> *Tail;

        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,T);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T);

        int Count();
        void Display();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
   
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct NODE2<T> *newn = NULL;
    newn = new NODE2 <T>;

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if((Head == NULL)&&(Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
		Head->prev = newn;
        newn -> next = Head;
        Tail->next = newn;
        newn->prev = Head;
        Head = newn;
    }
    
}

template<class T>
 void DoublyCLL<T>::InsertLast(T iNo)
 {
    struct NODE2 <T> *newn = NULL;
    newn = new NODE2 <T>;

    newn->data = iNo;
    newn->prev = NULL;
    newn->next = NULL;

    if((Head == NULL)&&(Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
		
        Tail->next = newn;
        Tail = newn;
        newn->prev = Head;
        newn->next = Head;
    }

 }

template<class T>
void DoublyCLL<T>::InsertAtPos(T iNo, T ipos)
{
    int iSize = Count();

    if((Head == NULL)||(ipos>iSize+1)||(ipos<=0))
	{
		return;
	}
	if(ipos == 1)
	{
		return(InsertFirst(iNo));
	}
	else if(ipos == (iSize)+1)
	{
		return(InsertLast(iNo));
	}
    else
    {
        struct NODE2<T> *newn = NULL;
        newn = new NODE2 <T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->next = NULL;

		struct NODE2<T> *temp = Head;
		
		
		for(int i=1;i<=(ipos-2);i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		newn->prev = temp;
		temp->next = newn;
	
    }

}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if (Head == NULL && Tail == NULL) 
    {
        return;
    }
    else if (Head == Tail) 
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {    
        Head = Head->next;

        delete Tail->next;

        Tail->next = Head;
    
    }

}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if (Head == NULL && Tail == NULL) 
    {
        return;
    }
    else if (Head == Tail) 
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct NODE2<T> *temp = NULL;
        temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }
       delete Tail;
       Tail = temp;
       Tail->next = Head;
       Head->prev = temp;

    }

}

template<class T>
void DoublyCLL<T>::DeleteAtPos(T ipos)
{
    int iSize = Count();
    if((Head == NULL)||(ipos>iSize)||(ipos<=0))
	{
		return;
	}
	if(ipos == 1)
	{
		return(DeleteFirst());
	}
	else if(ipos == (iSize))
	{
		return(DeleteLast());
	}

    else
    {
       struct NODE2<T> *temp = Head;
        for(int i =1;i<=(ipos-2);i++)
        {
            temp=temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;


    }
}

template<class T>
void DoublyCLL<T>::Display()
 {
    struct NODE2<T> *temp = NULL;
    temp = Head;

    if ((Head == NULL) && (Tail == NULL)) 
    {
        return;
    }

    do
    {
        cout << "[ " << temp->data << " ]->";
        temp = temp->next;
    } while (temp != Head);

    cout << endl;
}

template<class T>
int DoublyCLL<T>::Count()
{   int iCnt = 0;
    struct NODE2<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) 
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Head);

    return iCnt;        
    
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//Queue

template<class T>
class Queue
{
    public:
        struct node<T> *Head;
        int Count;

        Queue();
        void Enqueue(T);        // InsertLast
        void Dequeue();            // DeleteFirst
        void Display();
        int CountNode();
};

template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Queue<T>::Enqueue(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
            struct node<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }

            temp->next = newn;
    }
    Count++;
}

template <class T>
void Queue<T>::Dequeue()       // Deletefirst
{
    T no;

    if(Count == 0)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    if(Count ==1)
    {
            no = Head->data;
            delete Head;
            Head = NULL;
     }
    else
    {
        no = Head -> data;
        struct node<T> *temp = Head;
        Head = Head->next;
        delete temp;
    }
    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

template<class T>
void Queue<T>::Display()
{
    cout<<"Elements from Queue are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int Queue<T>::CountNode()
{
    return Count;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Stack

template <class T>
class Stack
{
    public:
        struct node<T> *Head;
        int Count;

        Stack();
        void Push(T);        // InsertFirst
        void Pop();            // DeleteFirst
        void Display();
        int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;
    Count++;
}

template <class T>
void Stack<T>::Pop()       // Deletefirst
{
    T no;   // int no;

    if(Count == 0)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    no = Head -> data;
    struct node<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

template<class T>
void Stack<T>::Display()
{
    cout<<"Elements from Stack are : "<<endl;
    struct node<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
Stack<T>::CountNode()
{
    return Count;
}

void menu1()
{
    cout<<"\n 1.Integer\n 2.Float\n 3.Character\n";
}

void menu()
{
        cout<<"\n 1.InsertFirst\n 2.InsertLast\n 3.DeleteFirst\n 4.DeleteLast\n 5.Display\n 6.Count\n 7.InsertAtposition\n 8.DeleteAtposition\n";
}

void menu2()
{
    cout<<"\n 1.Singly Linked List\n 2.Singly Circular Linked List\n 3.Doubly Linear Linked List\n 4.Doubly Circular Linked List\n 5.Queue\n 6.Stack\n";
}

void menu3()
{
    cout<<"\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Count\n";
}

void menu4()
{
    cout<<"\n 1.Push\n 2.Pop\n 3.Display\n 4.Count\n";
}





int main()
{
    SinglyLL <int>SL_obj1;
    SinglyLL <float>SL_obj2;
	SinglyLL <char>SL_obj3;

    SinglyCLL<int>SC_obj1;
    SinglyCLL<float>SC_obj2;
	SinglyCLL<char>SC_obj3;


    DoublyLL <int>DL_obj1;
    DoublyLL <float>DL_obj2;
	DoublyLL <char>DL_obj3;


    DoublyCLL <int>DC_obj1;
    DoublyCLL <float>DC_obj2;
	DoublyCLL <char>DC_obj3;


    Queue<int>Q_obj1;
    Queue<float>Q_obj2;
    Queue<char>Q_obj3;


    Stack <int>S_obj1;
    Stack <float>S_obj2;
    Stack <char>S_obj3;



    int ch,x,y,num,val;
    float x1,y1;
    char x2=char();

    menu2();
    cout<<"Enter type of DS\n";
    cin>>val;
    switch(val)
    {
        case 1:
        cout<<"For SinglyLinked List"<<endl;
        menu1();
            cout<<"\nEnter the choice of datatype\n";
            cin>>num;
            switch(num)
            {
                case 1:
                        cout<<"\nInteger type\n";
                        do
                        {
                            {
                                menu();
                                cout<<"\nEnter the choice\n";
                                cin>>ch;
                                switch(ch)
                                {
                                    case 1:
                                        cout<<"\nEnter Integer value to insert first into the Singly Linked List\n";
                                        cin>>x;
                                        SL_obj1.InsertFirst(x);
                                        break;
                                    case 2:
                                        cout<<"\nEnter Integer value to insert last into the Singly Linked List\n";
                                        cin>>x;
                                        SL_obj1.InsertLast(x);
                                        break;
                                    case 3:
                        
                                        SL_obj1.DeleteFirst();
                                        break;
                                    case 4:
                        
                                        SL_obj1.DeleteLast();
                                        break;
                                    case 5:
                                        SL_obj1.Display();
                                        break;

                                    case 6:
                                        x=SL_obj1.Count();
                                        cout<<"\nNumber of nodes"<<x<<endl;
                                        break;

                                    case 7:
                                        cout<<"\nEnter position to insert  value into the Singly Linked List\n";
                                        cin>>x;
                                        cin>>y;
                                        SL_obj1.InsertAtPos(x,y);
                                        break;

                                    case 8:
                                        cout<<"\nEnter position to Delete Value from the Singly Linked List\n";
                                        cin>>x;
                                        SL_obj1.DeleteAtPos(x);
                                        break;


                                    default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                        
                                }
                            }

                        }while(ch>=1&&ch<=8);

                        break;
            
                

                case 2:
                        cout<<"\nFloat type\n";
                        do
                        {
                            {
                                menu();
                                cout<<"\nEnter the choice\n";
                                cin>>ch;
                                switch(ch)
                                {
                                    case 1:
                                        cout<<"\nEnter Float value to insert first into the Singly Linked List\n";
                                        cin>>x1;
                                        SL_obj2.InsertFirst(x1);
                                        break;
                                    case 2:
                                        cout<<"\nEnter Float value to insert last into the Singly Linked List\n";
                                        cin>>x;
                                        SL_obj2.InsertLast(x1);
                                        break;
                                    case 3:
                        
                                        SL_obj2.DeleteFirst();
                                        break;
                                    case 4:
                        
                                        SL_obj2.DeleteLast();
                                        break;
                                    case 5:
                                        SL_obj2.Display();
                                        break;

                                    case 6:
                                        x=SL_obj2.Count();
                                        cout<<"\nNumber of nodes "<<x<<endl;
                                        break;

                                    case 7:
                                        cout<<"\nEnter position to insert  value into the Singly Linked List\n";
                                        cin>>x;
                                        cin>>y;
                                        SL_obj2.InsertAtPos(x1,y);
                                        break;

                                    case 8:
                                        cout<<"\nEnter position to Delete value from the Singly Linked List\n";
                                        cin>>x;
                                        SL_obj2.DeleteAtPos(x1);
                                        break;


                                    default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                        
                                }
                            }

                        }while(ch>=1&&ch<=8);

                        break;
            
            case 3:
                        cout<<"\nCharacter type\n";
                        do
                        {
                            {
                                menu();
                                cout<<"\nEnter the choice\n";
                                cin>>ch;
                                switch(ch)
                                {
                                    case 1:
                                        cout<<"\nEnter Character value to insert first into the Singly Linked List\n";
                                        cin>>x2;
                                        SL_obj3.InsertFirst(x2);
                                        break;
                                    case 2:
                                        cout<<"\nEnter Character value to insert last into the Singly Linked List\n";
                                        cin>>x2;
                                        SL_obj3.InsertLast(x2);
                                        break;
                                    case 3:
                        
                                        SL_obj3.DeleteFirst();
                                        break;
                                    case 4:
                        
                                        SL_obj3.DeleteLast();
                                        break;
                                    case 5:
                                        SL_obj3.Display();
                                        break;

                                    case 6:
                                        x=SL_obj3.Count();
                                        cout<<"\nNumber of nodes "<<x<<endl;
                                        break;

                                    case 7:
                                        cout<<"\nEnter position to insert value into the Singly Linked List\n";
                                        cin>>x2;
                                        cin>>y;
                                        SL_obj3.InsertAtPos(x2,y);
                                        break;

                                    case 8:
                                        cout<<"\nEnter position to delete value from the Singly Linked List\n";
                                        cin>>x2;
                                        SL_obj3.DeleteAtPos(x2);
                                        break;
                                        
                                    default :
                                        cout<<"Enter Correct Choice\n";
                                        break;

                                }
                            }

                        }while(ch>=1&&ch<=8);

                        break;  
            }
    
    
    
    
    
    


    case 2:


    cout<<"For Singly Circular Linked List"<<endl;
    menu1();
        cout<<"\nEnter the choice of datatype\n";
        cin>>num;
        switch(num)
        {
            case 1:
                    cout<<"\nInteger type\n";
                    do
                    {
                        {
                            menu();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter  Integer value to insert first into the Singly Circular Linked List\n";
                                    cin>>x;
                                    SC_obj1.InsertFirst(x);
                                    break;
                                case 2:
                                    cout<<"\nEnter Integer value to insert last into the Singly Circular Linked List\n";
                                    cin>>x;
                                    SC_obj1.InsertLast(x);
                                    break;
                                case 3:
                    
                                    SC_obj1.DeleteFirst();
                                    break;
                                case 4:
                    
                                    SC_obj1.DeleteLast();
                                    break;
                                case 5:
                                    SC_obj1.Display();
                                    break;

                                case 6:
                                    x=SC_obj1.Count();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                case 7:
                                    cout<<"\nEnter position to insert into the Singly Circular Linked List\n";
                                    cin>>x;
                                    cin>>y;
                                    SC_obj1.InsertAtPos(x,y);
                                    break;

                                case 8:
                                    cout<<"\nEnter position to Delete value from  the Singly Circular Linked List\n";
                                    cin>>x;
                                    SC_obj1.DeleteAtPos(x);
                                    break;

                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                    
                            }
                        }

                    }while(ch>=1&&ch<=8);

                    break;
        
        
            

             case 2:
                    cout<<"\nFloat type\n";
                    do
                    {
                        {
                            menu();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Float value to insert first into the Singly Circular Linked List\n";
                                    cin>>x1;
                                    SC_obj2.InsertFirst(x1);
                                    break;
                                case 2:
                                    cout<<"\nEnter Float value to insert last into the Singly Circular Linked List\n";
                                    cin>>x;
                                    SC_obj2.InsertLast(x1);
                                    break;
                                case 3:
                    
                                    SC_obj2.DeleteFirst();
                                    break;
                                case 4:
                    
                                    SC_obj2.DeleteLast();
                                    break;
                                case 5:
                                    SC_obj2.Display();
                                    break;

                                case 6:
                                    x=SC_obj2.Count();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                case 7:
                                    cout<<"\nEnter position to insert  value into the Singly Circular Linked List\n";
                                    cin>>x;
                                    cin>>y;
                                    SC_obj2.InsertAtPos(x1,y);
                                    break;

                                case 8:
                                    cout<<"\nEnter position to Delete value from the Singly  Circular Linked List\n";
                                    cin>>x;
                                    SC_obj2.DeleteAtPos(x1);
                                    break;


                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                    
                            }
                        }

                    }while(ch>=1&&ch<=8);

                    break;
        
            case 3:
                    cout<<"\nCharacter type\n";
                    do
                    {
                        {
                            menu();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Character value to insert first into the Singly Circular Linked List\n";
                                    cin>>x2;
                                    SC_obj3.InsertFirst(x2);
                                    break;
                                case 2:
                                    cout<<"\nEnter Character value to insert last into the Singly Circular Linked List\n";
                                    cin>>x2;
                                    SC_obj3.InsertLast(x2);
                                    break;
                                case 3:
                    
                                    SC_obj3.DeleteFirst();
                                    break;
                                case 4:
                    
                                    SC_obj3.DeleteLast();
                                    break;
                                case 5:
                                    SC_obj3.Display();
                                    break;

                                case 6:
                                    x=SC_obj3.Count();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                case 7:
                                    cout<<"\nEnter position to insert value into the Singly Circular Linked List\n";
                                    cin>>x2;
                                    cin>>y;
                                    SC_obj3.InsertAtPos(x2,y);
                                    break;

                                case 8:
                                    cout<<"\nEnter position to Delete value into the Singly Circular Linked List\n";
                                    cin>>x2;
                                    SC_obj3.DeleteAtPos(x2);
                                    break;


                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                    
                            }
                        }

                    }while(ch>=1&&ch<=8);

                    break;  
        }




        case 3:


    cout<<"For Doubly Linear Linked List"<<endl;
    menu1();
    cout<<"\nEnter the choice of datatype\n";
    cin>>num;
    switch(num)
    {
        case 1:
                cout<<"\nInteger type\n";
                do
                {
                    {
                        menu();
                        cout<<"\nEnter the choice\n";
                        cin>>ch;
                        switch(ch)
                        {
                            case 1:
                                cout<<"\nEnter Integer value to insert first into the Doubly Linear Linked List\n";
                                cin>>x;
                                DL_obj1.InsertFirst(x);
                                break;
                            case 2:
                                cout<<"\nEnter Integer value to insert last into the Doubly Linear Linked List\n";
                                cin>>x;
                                DL_obj1.InsertLast(x);
                                break;

                            case 3:
                                DL_obj1.DeleteFirst();
                                break;
                            
                            case 4:
                    
                                DL_obj1.DeleteLast();
                                break;
                            
                            case 5:

                                DL_obj1.Display();
                                break;

                            case 6:

                                x=DL_obj1.CountNode();
                                cout<<"\nNumber of nodes "<<x<<endl;
                                break;

                            case 7:
                                cout<<"\nEnter position to insert value into the Doubly linear Linked List\n";
                                cin>>x;
                                cin>>y;
                                DL_obj1.InsertAtPos(x,y);
                                break;

                            case 8:
                                cout<<"\nEnter position to Delete value into the Doubly Linear Linked List\n";
                                cin>>x;
                                DL_obj1.DeleteAtPos(x);
                                break;
                                    

                            default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                        }
                        
                    }


                }while(ch>=1&&ch<=8);

                break;
        
            

        case 2:
                cout<<"\nFloat type\n";
                do          
                {
                    {
                        menu();
                        cout<<"\nEnter the choice\n";
                        cin>>ch;
                        switch(ch)
                        {
                            case 1:
                                cout<<"\nEnter Float value to insert first into the Doubly linear Linked List\n";
                                cin>>x1;
                                DL_obj2.InsertFirst(x1);
                                break;
                            case 2:
                                cout<<"\nEnter Float value to insert last into the Doubly Linear Linked List\n";
                                cin>>x;
                                DL_obj2.InsertLast(x1);
                                break;
                            case 3:
                
                                DL_obj2.DeleteFirst();
                                break;
                            case 4:
                
                                DL_obj2.DeleteLast();
                                break;
                            case 5:
                                DL_obj2.Display();
                                break;

                            case 6:
                                x=DL_obj2.CountNode();
                                cout<<"\nNumber of nodes "<<x<<endl;
                                break;

                            case 7:
                                cout<<"\nEnter position to insert value into the Doubly Linear Linked List\n";
                                cin>>x;
                                cin>>y;
                                DL_obj2.InsertAtPos(x1,y);
                                break;

                            case 8:
                                cout<<"\nEnter position to Delete value from the Doubly Linear Linked List\n";
                                cin>>x;
                                DL_obj2.DeleteAtPos(x1);
                                break;
                                
                        }
                    }


                }while(ch>=1&&ch<=8);   

                break;




        
        case 3:
                cout<<"\nCharacter type\n";
                do
                {
                    {
                            menu();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter character value to insert first into the Doubly linear Linked List\n";
                                    cin>>x2;
                                    DL_obj3.InsertFirst(x2);
                                    break;
                                case 2:
                                    cout<<"\nEnter character value to insert last into the Doubly linear Linked List\n";
                                    cin>>x2;
                                    DL_obj3.InsertLast(x2);
                                    break;
                                case 3:
                    
                                    DL_obj3.DeleteFirst();
                                    break;
                                case 4:
                    
                                    DL_obj3.DeleteLast();
                                    break;
                                case 5:
                                    DL_obj3.Display();
                                    break;

                                case 6:
                                    x=DL_obj3.CountNode();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                case 7:
                                    cout<<"\nEnter position to insert value into the Doubly Linear Linked List\n";
                                    cin>>x2;
                                    cin>>y;
                                    DL_obj3.InsertAtPos(x2,y);
                                    break;

                                case 8:
                                    cout<<"\nEnter position to Delete value from  Doubly Linear Linked List\n";
                                    cin>>x2;
                                    DL_obj3.DeleteAtPos(x2);
                                    break;

                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                    
                            }
                        }

                    }while(ch>=1&&ch<=8);

                    break;  
        }




        
    case 4:


    cout<<"For Doubly Circular Linked List"<<endl;
    menu1();
        cout<<"\nEnter the choice of datatype\n";
        cin>>num;
        switch(num)
        {
            case 1:
                    cout<<"\nInteger type\n";
                    do
                    {
                        {
                            menu();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Integer value to insert first into the Doubly Circular Linked List\n";
                                    cin>>x;
                                    DC_obj1.InsertFirst(x);
                                    break;
                                case 2:
                                    cout<<"\nEnter Integer value to insert last into the Doubly Circular Linked List\n";
                                    cin>>x;
                                    DC_obj1.InsertLast(x);
                                    break;
                                case 3:
                    
                                    DC_obj1.DeleteFirst();
                                    break;
                                case 4:
                    
                                    DC_obj1.DeleteLast();
                                    break;
                                case 5:
                                    DC_obj1.Display();
                                    break;

                                case 6:
                                    x=DC_obj1.Count();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                case 7:
                                    cout<<"\nEnter position to insert value into the Doubly Circular Linked List\n";
                                    cin>>x;
                                    cin>>y;
                                    DC_obj1.InsertAtPos(x,y);
                                    break;

                                case 8:
                                    cout<<"\nEnter position to delete from the Doubly Circular Linked List\n";
                                    cin>>x;
                                    DC_obj1.DeleteAtPos(x);
                                    break;
                                    
                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                            }
                        }

                    }while(ch>=1&&ch<=8);

                    break;
        
        
            

             case 2:
                    cout<<"\nFloat type\n";
                    do
                    {
                        {
                            menu();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Float value to insert first into the Doubly Circular Linked List\n";
                                    cin>>x1;
                                    DC_obj2.InsertFirst(x1);
                                    break;
                                case 2:
                                    cout<<"\nEnter Float value to insert last into the Doubly Circular Linked List\n";
                                    cin>>x;
                                    DC_obj2.InsertLast(x1);
                                    break;
                                case 3:
                    
                                    DC_obj2.DeleteFirst();
                                    break;
                                case 4:
                    
                                    DC_obj2.DeleteLast();
                                    break;
                                case 5:
                                    DC_obj2.Display();
                                    break;

                                case 6:
                                    x=DC_obj2.Count();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                case 7:
                                    cout<<"\nEnter position to insert value into the Doubly Circular Linked List\n";
                                    cin>>x;
                                    cin>>y;
                                    DC_obj2.InsertAtPos(x1,y);
                                    break;

                                case 8:
                                    cout<<"\nEnter position to delete value from Doubly Circular Linked List\n";
                                    cin>>x;
                                    DC_obj2.DeleteAtPos(x1);
                                    break;


                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                    
                            }
                        }

                    }while(ch>=1&&ch<=8);

                    break;
        
            case 3:
                    cout<<"\nCharacter type\n";
                    do
                    {
                        {
                            menu();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Character value to insert first into the Doubly Circular Linked List\n";
                                    cin>>x2;
                                    DC_obj3.InsertFirst(x2);
                                    break;
                                case 2:
                                    cout<<"\nEnter  character value to insert last into the Doubly Circular Linked List\n";
                                    cin>>x2;
                                    DC_obj3.InsertLast(x2);
                                    break;
                                case 3:
                    
                                    DC_obj3.DeleteFirst();
                                    break;
                                case 4:
                    
                                    DC_obj3.DeleteLast();
                                    break;
                                case 5:
                                    DC_obj3.Display();
                                    break;

                                case 6:
                                    x=DC_obj3.Count();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                case 7:
                                    cout<<"\nEnter position to insert value into the Doubly Circular Linked List\n";
                                    cin>>x2;
                                    cin>>y;
                                    DC_obj3.InsertAtPos(x2,y);
                                    break;

                                case 8:
                                    cout<<"\nEnter position to delete from the Doubly Circular Linked List\n";
                                    cin>>x2;
                                    DC_obj3.DeleteAtPos(x2);
                                    break;


                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                    
                            }
                        }

                    }while(ch>=1&&ch<=8);

                    break;  
        }



         case 5:


    cout<<"For Queue"<<endl;
    menu1();
        cout<<"\nEnter the choice of datatype\n";
        cin>>num;
        switch(num)
        {
            case 1:
                    cout<<"\nInteger type\n";
                    do
                    {
                        {
                            menu3();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter  Integer value\n";
                                    cin>>x;
                                    Q_obj1.Enqueue(x);
                                    break;
                                case 2:
                                    // cout<<"\nenter value\n";
                                    // cin>>x;
                                    Q_obj1.Dequeue();
                                    break;
                                
                                case 3:
                                    Q_obj1.Display();
                                    break;

                                case 4:
                                    x=Q_obj1.CountNode();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                               default :
                                        cout<<"Enter Correct Choice\n";
                                        break;
                                    
                            }
                        }

                    }while(ch>=1&&ch<=4);

                    break;
        
        
            

             case 2:
                    cout<<"\nFloat type\n";
                    do
                    {
                        {
                            menu3();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Float value \n";
                                    cin>>x1;
                                    Q_obj2.Enqueue(x1);
                                    break;
                                case 2:
                                    // cout<<"\nEnter value\n";
                                    // cin>>x;
                                     Q_obj2.Dequeue();
                                    break;
                                
                                case 4:
                                     Q_obj2.Display();
                                    break;

                                case 5:
                                     Q_obj2.CountNode();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;

                               
                                    
                            }
                        }

                    }while(ch>=1&&ch<=4);

                    break;
        
            case 3:
                    cout<<"\nCharacter type\n";
                    do
                    {
                        {
                            menu3();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Character value\n";
                                    cin>>x2;
                                    Q_obj3.Enqueue(x2);
                                    break;
                                case 2:
                                    //cout<<"\nEnter value\n";
                                    //cin>>x2;
                                    Q_obj3.Dequeue();
                                    break;
                                
                                case 3:
                                    Q_obj3.Display();
                                    break;

                                case 4:
                                    x=Q_obj3.CountNode();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;


                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;

                                
                                    
                            }
                        }

                    }while(ch>=1&&ch<=4);

                    break;  
        }


        case 6:


    cout<<"For Stack"<<endl;
    menu1();
        cout<<"\nEnter the choice of datatype\n";
        cin>>num;
        switch(num)
        {
            case 1:
                    cout<<"\nInteger type\n";
                    do
                    {
                        {
                            menu4();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Integer value\n";
                                    cin>>x;
                                    S_obj1.Push(x);
                                    break;
                                case 2:
                                    cout<<"\nEnter value\n";
                                    cin>>x;
                                    S_obj1.Pop();
                                    break;
                                
                                case 3:
                                    S_obj1.Display();
                                    break;

                                case 4:
                                    x=S_obj1.CountNode();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;


                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;

                               
                                    
                            }
                        }

                    }while(ch>=1&&ch<=4);

                    break;
        
        
            

             case 2:
                    cout<<"\nFloat type\n";
                    do
                    {
                        {
                            menu4();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter Float value \n";
                                    cin>>x1;
                                    S_obj2.Push(x1);
                                    break;
                                case 2:
                                    cout<<"\nEnter value \n";
                                    cin>>x;
                                     S_obj2.Pop();
                                    break;
                                
                                case 4:
                                     S_obj2.Display();
                                    break;

                                case 5:
                                     S_obj2.CountNode();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;


                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;

                               
                                    
                            }
                        }

                    }while(ch>=1&&ch<=4);

                    break;
        
            case 3:
                    cout<<"\nCharacter type\n";
                    do
                    {
                        {
                            menu4();
                            cout<<"\nEnter the choice\n";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:
                                    cout<<"\nEnter  Charcter value\n";
                                    cin>>x2;
                                    S_obj3.Push(x2);
                                    break;
                                case 2:
                                    cout<<"\nEnter value\n";
                                    cin>>x2;
                                    S_obj3.Pop();
                                    break;
                                
                                case 3:
                                    S_obj3.Display();
                                    break;

                                case 4:
                                    x=S_obj3.CountNode();
                                    cout<<"\nNumber of nodes "<<x<<endl;
                                    break;

                                default :
                                        cout<<"Enter Correct Choice\n";
                                        break;


                                
                                    
                            }
                        }

                    }while(ch>=1&&ch<=4);

                    break;  
        }



    }
    
}