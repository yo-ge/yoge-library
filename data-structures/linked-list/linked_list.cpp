#include <iostream>
using namespace std;

template<typename Nodetype>
struct Node
{
	Nodetype data;
	Node *next;
	friend ostream &operator>>(ostream &in, Node &n)
	{
		return in >> data;
	}
};

template<typename Nodetype>
class LinkList
{
private:
	Node<Nodetype> *Head;
public:
	LinkList();
	LinkList(Nodetype n);
	void CreatList();
	void Insert(Node<Nodetype> *&, int index = 1);
	void Delete(int index);
	void Display();
};

template<typename Nodetype>
LinkList<Nodetype>::LinkList()
{
	Head = NULL;
}
template<typename Nodetype>
LinkList<Nodetype>::LinkList(Nodetype n)
{
	this->data = n->data;
	this->next = n->next;
}
template<typename Nodetype>
void LinkList<Nodetype>::CreatList()
{
	Node<Nodetype> *ptr;
	int size;
	cout << "How long is your list:";
	cin >> size;
	cout << "Enter your data in reverse sequence:" << endl;
	for (int i = 0; i < size; ++i)
	{
		ptr = new Node<Nodetype>;
		cout << "your Node value:"; cin >> (*ptr);//need to overloading operator for Node class
		ptr->next = Head;
		Head = ptr;
	}
}
template<typename Nodetype>
void LinkList<Nodetype>::Display()
{
	Node<Nodetype> *p = Head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
template<typename Nodetype>
void LinkList<Nodetype>::Insert(Node<Nodetype> *&p, int index = 1)
{
	;
}
template<typename Nodetype>
void LinkList<Nodetype>::Delete(int index)
{
	;
}
/*test class list*/
int main()
{
	LinkList<int> h;
	h.CreatList();
	Node<int> *n1, *n2;
	n1->data = 2;
	n2->data = 3;
	h.Insert(n1);
	h.Insert(n2, 1);
	h.Display();
}