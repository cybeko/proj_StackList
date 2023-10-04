#include <iostream>
using namespace std;

struct Elem
{
    int data;
    Elem* next, * prev;
};

class List
{
    Elem* Head, * Tail;
    int Count;

public:

    List();
    List(const List&);
    ~List();

    int GetCount();
    void DelAll();

    void Pop();
    void Push(int n);

    void Print();

};

List::List()
{
    Head = Tail = NULL;
    Count = 0;
}

List::List(const List& L)
{
    Head = Tail = NULL;
    Count = 0;

    Elem* temp = L.Head;
    while (temp != 0)
    {
        Push(temp->data);
        temp = temp->next;
    }
}

List::~List()
{
    DelAll();
}

void List::Push(int n)
{
    Elem* temp = new Elem;
    temp->prev = 0;
    temp->data = n;
    temp->next = Head;

    if (Head != 0)
    {
        Head->prev = temp;
    }
    if (Count == 0)
    {
        Head = Tail = temp;
    }
    else
    {
        Head = temp;
    }

    Count++;
}

void List::Pop()
{
    if (Count == 0)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    Elem* temp = Head;

    if (Count == 1)
    {
        Head = Tail = NULL;
    }
    else
    {
        Head = Head->next;
        Head->prev = NULL;
    }

    delete temp;
    Count--;
}

void List::Print()
{
    if (Count != 0)
    {
        Elem* temp = Head;
        cout << "( ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << " )\n";
    }
    cout << endl;
}

void List::DelAll()
{
    while (Count != 0)
    {
        Pop();
    }
}

int List::GetCount()
{
    return Count;
}


void main()
{
    List stack;

    const int n = 10;
    int a[n] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < n; i++)
    {
        stack.Push(a[i]);
    }

    cout << "Stack:\n";
    stack.Print();

    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Print();

    stack.Push(2);
    stack.Print();
}