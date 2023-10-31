//~TASK1
//1)
#include <iostream>
using namespace std;
class Node
{
public:
	int element;
	Node* next;
};
int main()
{
	return 0;
}
//2)
#include <iostream>
using namespace std;
class Node
{
public:
	int element;
	Node* next;
};
int myList(Node* a)
{
	while (a != NULL)
	{
		cout << a->element << endl;
		a = a->next;
	}
}
int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	head->element = 2;
	second->element = 4;
	third->element = 6;
	head->next = second;
	second->next = third;
	third->next = NULL;
	return 0;
}
//~TASK 2 (BASIC OPERATIONS)

#include<iostream>                                    //1)
using namespace std;
class Node
{
public:
	int element;
	Node* next;

}

*head = NULL;

int totalNodes(struct Node* p)
{
	int total = 0;
	while (p != NULL)
	{
		total++;
		p = p->next;
	}
	return total;
}
void myList(int array[], int n)
{
	struct Node* ptr, * tail;
	head = new Node();
	head->element = array[0];
	head->next = NULL;
	tail = head;
	for (int i = 0; i < n; i++)
	{
		ptr = new Node();
		ptr->element = array[i];
		ptr->next = NULL;
		tail->next = ptr;
		tail = ptr;
	}
}

void showList(struct Node* p)                                      //2)
{
	if (head == 0)
	{
		cout << "Emmpty List" << endl;
	}
	else
	{
		while (p != NULL)
		{
			cout << p->element << endl;
			p = p->next;
		}
	}
}

bool isEmpty(struct Node* p)                                       //3)
{
	if (p->next = NULL)
		return true;
	else
		return false;
}

void clear(struct Node* p)                                          //4)
{
	struct Node* tail = NULL;
	while (p != NULL)
	{
		p->next = tail;
		delete p;
		p = tail;
	}
	if (p = NULL)
	{
		cout << "All the Elements are removed" << endl;
	}
}

void insert(struct Node* p, int array[])                           //5)
{
	struct Node* ptr;
	ptr = new Node;

	int n;
	cout << "Please enter a number:";
	cin >> n;
	ptr->element = n;
	for (int i = 0; i < 4; i++)
	{
		if (array[i] == ptr->element)

			cout << "KEY ALREADY EXISTS" << endl;
		else
			p = p->next;
	}

	ptr->next = p->next;
	cout << ptr->next;
	p->next = ptr;
}

int remove(struct Node* p, int index)                           //7)
{
	struct Node* l;
	int temp = -1;
	if (index == 1)
	{
		l = head;
		temp = head->element;
		head = head->next;
		delete l;
		return temp;
	}

	else {
		for (int i = 0; i < index - 1; i++)
		{
			l = p;
			p = p->next;
		}

		l->next = p->next;
		temp = p->element;

		delete p;

		return temp;
	}
}

void insertAtindex(struct Node* p, int array[], int index)                               //6)
{
	struct Node* ptr;
	if (index > totalNodes(p) || index < 0) return;


	int duplicate = 0;
	ptr = new Node();
	int n;
	cout << "Please enter a number:";
	cin >> n;
	ptr->element = n;


	for (int i = 0; i < index - 1; i++)
	{
		if (array[i] == ptr->element)
		{
			duplicate = duplicate + 1;
		}

		p = p->next;

	}


	ptr->next = p->next;
	p->next = ptr;
}



int main()
{
	int array[] = { 1,2,3,5,6,7,8 };
	myList(array, 4);
	showList(head);
	isEmpty(head);
	clear(head);
	insert(head, array);
	insertAtindex(head, array, 2);
	remove(head, 2);
	return 0;
}



//~TASK 3
#include<iostream>
using namespace std;
class Node
{
public:
	int element;
	Node* next;

}

*head = NULL;

void linkedList(int array[], int n)
{
	struct Node* a, * tail;
	head = new Node();
	head->element = array[0];
	head->next = NULL;
	tail = head;


	for (int i = 0; i < n; i++)
	{
		a = new Node();
		a->element = array[i];
		a->next = NULL;
		tail->next = a;
		tail = a;
		cout << a->element << " ";
		a = a->next;
	}

}
void evenChecker(struct Node* p)                //1)
{
	struct Node* q;
	head = new Node();
	while (p != nullptr)

	{
		if (p->element % 2 == 0)
			head->element = p->element;
		head->next = NULL;

	}

	q = new Node();
	q = head;
	cout << q->element << " ";
	q = q->next;

}

void search(struct Node* p, int k)            //2)
{
	int total = 0;
	while (p != NULL)
	{
		if (p->element == k)
			total++;
		else
			p = p->next;
	}
	if (total > 0)
	{
		cout << "TRUE" << endl;

	}
	else {
		cout << "FALSE" << endl;
	}
}
void reverse()                            //3)
{
	struct Node* present = head;
	struct Node* previous = NULL;
	struct Node* tail = NULL;

	while (present != NULL)
	{
		tail = present->next;
		present->next = previous;
		previous = present;
		present = head;

	}
	head = previous;
	cout << present->element;
	present = present->next;
}

void sorting()                        //4)
{
	struct Node* p;
	struct Node* tail;
	int a = 0;
	p = head;

	while (p->next != NULL)
	{
		tail = p->next;

		while (tail != NULL)
		{
			if (tail->element < p->element)
			{
				a = p->element;
				p->element = tail->element;
				tail->element = a;
				cout << a->element << " ";
				a = a->next;
			}
			else
			{
				p = p->next;
				cout << p->element << " ";
				p = p->next;
			}
		}
	}

}

void addition(struct Node* p)                   //5)
{
	int total = 0;


	while (p != NULL)
	{

		total = total + p->element;
		p = p->next;
	}
	cout << total;
}


int main()
{
	int array[] = { 1,2,5,3,8 };
	linkedList(array, 5);
	evenChecker(head);
	search(head, 2);
	sorting();
	reverse();
	addition(head);
	return 0;

}

