#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

template <class Type>
class LL
{
	struct node
	{
		Type item;
		node * next;
		node * prev;
	};

public:
	class iterator
	{
	public:
		friend class LL;
		iterator();
		iterator(node*);
		Type operator*();
		iterator operator++(int);
		iterator operator--(int);
		bool operator==(const iterator&) const;
		bool operator!=(const iterator&) const;
	private:
		node * current;
	};

	LL();
	LL(const LL&);
	const LL& operator=(const LL&);
	~LL();
	iterator begin() const;
	iterator end() const;
	void headRemove();
	void tailRemove();
	bool isEmpty() const;
	void headInsert(const Type&);
	void tailInsert(const Type&);
	void update(const iterator&, const Type&);
private:
	node * head;
	node * tail;
};

/*********************************************************************
iterator implementation
*********************************************************************/

//default constructor that sets current to NULL
template <class Type>
LL<Type>::iterator::iterator()
{
    current = NULL;
}

template <class Type>
LL<Type>::iterator::iterator(node * pointer)
{
    current = pointer;
}

template <class Type>
Type LL<Type>::iterator::operator*()
{
    if (current != NULL)
    {
        return current->item; 
    }
}

template <class Type>
typename LL<Type>::iterator LL<Type>::iterator::operator++(int)
{
    
    current = current->next;
    if (current != NULL)
    {
        return *this;
    }
}
//- overloads a unary operator, moves the current pointer over to the previous node of the linked list
template <class Type>
typename LL<Type>::iterator LL<Type>::iterator::operator--(int)
{
	current = current->prev;
    //cout << "Current: " << current << endl;
    if (current != NULL)
    {
        return *this;
    }
}

/*- overloads the binary equals operator, returns true if the iterator on the left side of the operator points to the same node as the iterator on the right
side, and returns false otherwise */
template <class Type>
bool LL<Type>::iterator::operator==(const iterator& rhs) const
{
    if (current == rhs.current)
    {
        return true;
    } else {
        return false;
    }	
}

/*
overloads the binary equals operator, returns false if
the iterator on the left side of the operator points to the same node as the iterator on the right
side, and returns false otherwise
*/
template <class Type>
bool LL<Type>::iterator::operator!=(const iterator& rhs) const
{
    //cout << "current: " << current << endl;
    if (current == rhs.current)
    {
        return false;
    } else {
        return true;
    }
    
}

/*********************************************************************
LL implementation
*********************************************************************/
//the default constructor that sets an empty linked list
template <class Type>
LL<Type>::LL()
{
	head = NULL;
    tail = NULL;
}

//the copy constructor, performs a deep copy of the LL object passed in
template <class Type>
LL<Type>::LL(const LL& copy)
{
	head = new node;
	head-> item= copy.head-> item;
	head->next = NULL;
	node * x = copy.head;
	node * y = head;

    while(y->next != NULL)
	{
		x = x -> next;
		y->next = new node;
		y = y -> next;
		y-> item = x->item;
		y-> next = NULL;
	}
}

// the assignment operator, performs a deep copy of the LL object
//passed in (the object on the right hand side of the assignment operator)

template <class Type>
const LL<Type>& LL<Type>::operator=(const LL& rhs)
{
	if (this != &rhs)
	{
        rhs.swap(*this);
	}
	return *this;
}

template <class Type>
LL<Type>::~LL()
{
	while (head->next != nullptr) {
        node * temp = head;
        head = head->next;
        delete temp;
      }
      delete head;
}

template <class Type>
typename LL<Type>::iterator LL<Type>::begin() const
{
	iterator current(head);
   // cout << "Iterator Head: " << current.current << endl;
    //cout << "Head: " << head << endl;
    //cout << "HEAD next: " << head->next->next << endl;
    return current;  
}

template <class Type>
typename LL<Type>::iterator LL<Type>::end() const
{
	iterator current(tail);
    return current;
}

template <class Type>
void LL<Type>::headRemove()
{
	if (head == NULL || tail == NULL) 
        return; 
  
    // Move the head pointer to the next node 
    node * temp = head; 
    head = head->next; 
    delete temp; 
}

template <class Type>	
void LL<Type>::tailRemove()
{
    node * temp;
    temp = head -> prev;
    while(temp->next != NULL)
    {
        temp = temp-> next; 
    } 
    temp -> next = NULL;
    delete head;
}
/*
 returns true if the list is empty and false otherwise
*/
template <class Type>	
bool LL<Type>::isEmpty() const
{
	if (head->next == NULL && tail->prev == NULL)
    {
        return true;

    }
    else 
    {
        return false;
    }
}
/*
inserts a new node to the front of the list, sets this node’s item
field to the value passed into the function
*/
template <class Type>
void LL<Type>::headInsert(const Type& element)
{
	node * newItem;
    newItem=new node;
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->item=element;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        newItem->next=head;
        newItem->item=element;
        newItem->prev=NULL;
        head->prev=newItem;
        head=newItem;
    }
}
/*
- inserts a new node to the end of the list, sets this node’s item field
to the value passed into the function
 */
template <class Type>
void LL<Type>::tailInsert(const Type& element)
{
	node * newItem;
    newItem=new node;
    newItem->item=element;
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        newItem->prev=tail;
        tail->next=newItem;
        newItem->next=NULL;
        tail=newItem;
    }
}

/*
reassigns a value of the node that the iterator
object points to with the value passed in (the second parameter)
*/
template <class Type>
void LL<Type>::update(const LL<Type>::iterator& it, const Type& element)
{
	it.current->item = element;
}

