//TASK 1, 2 & 6:
#include<iostream>
using namespace std;
void printArray(int arr[], int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
}
void recursiveInsertion(int arr[], int n, int index)                //TASK 2
{
	if (index == n)
	{
		return;
	}
	else
	{
		int temp;
		for (int i = index - 1; i >= 0; i--)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			else
			{
				break;
			}
		}
		recursiveInsertion(arr, n, index + 1);
	}

}
void recursiveSelection(int arr[], int n)                  //TASK 1
{
	if (n == 0)
	{
		return;
	}
	else
	{
		int max_value = 0;
		int max_index = 0;
		for (int i = 0; i < n; i++)
		{
			if (max_value < arr[i])
			{
				max_value = arr[i];
				max_index = i;
			}
		}
		arr[max_index] = arr[n - 1];
		arr[n - 1] = max_value;
		recursiveSelection(arr, n - 1);
	}
}
int recursivebinarySearch(int arr[], int left, int right, int size, int data)                //TASK 6
{
	right = size - 1;
	if (right >= left)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == data)
		{
			return mid;
		}
		else
		{
			if (data < arr[mid])
			{
				return recursivebinarySearch(arr, left, mid - 1, size, data);
			}
			else
			{
				return recursivebinarySearch(arr, mid + 1, right, size, data);
			}
		}
	}
	else
	{
		return -1;
	}
}
int main()
{
	int arr[] = { 1,3,12,4,5,18,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "TASK 2: Insertion Sort=> ";
	recursiveInsertion(arr, n, 0);
	printArray(arr, n);
	cout << endl;
	cout << "TASK 1: Selection Sort=> ";
	recursiveSelection(arr, n);
	printArray(arr, n);
	cout << endl;
	cout << "TASK 6: Binary Search=> "<<endl;
	int data;
	cout << "Enter an element: ";
	cin >> data;
	recursiveSelection(arr, n);
	int ans = recursivebinarySearch(arr, 0, n - 1, n, data);
	if (ans == -1)
	{
		cout << "Element not in Array" << endl;
	}
	else
	{
		cout << "Element "<< data<<" found at index : " << ans;
	}
}



//TASK 3, 4 & 5:
#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;

};
class linkedList
{
private:
	Node* head;
public:
	linkedList()
	{
		head = NULL;
	}
	void insertElements()
	{
		int value;
		cout << "Enter elements: ";
		cin >> value;
		Node* newNode = new Node();
		if (newNode == NULL)
		{
			cout << "Can't insert" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = newNode;
				newNode->data = value;
				newNode->next = NULL;
			}
			else {
				Node* ptr1;
				ptr1 = head;
				head = newNode;
				newNode->data = value;
				newNode->next = ptr1;
			}
		}
	}
	void printLinkedList()
	{
		Node* ptr1;
		ptr1 = head;
		while (ptr1 != NULL)
		{
			cout << ptr1->data << endl;
			ptr1 = ptr1->next;
		}
	}
	
	void bubbleSort()                //TASK 3
	{
		Node* ptr1, * ptr2;
		ptr2 = NULL;
		int swap_count;
		if (head == NULL)
		{
			cout << "Linked List empty" << endl;

		}
		else
		{
			do {
				ptr1 = head;
				swap_count = 0;
				while (ptr1->next != ptr2)
				{
					if (ptr1->data > ptr1->next->data)
					{
						int temp;
						temp = ptr1->data;
						ptr1->data = ptr1->next->data;
						ptr1->next->data = temp;
						swap_count = 1;
					}
					ptr1 = ptr1->next;
				}
				ptr2 = ptr1;

			} while (swap_count);
		}
	}
	void selectionSort()                 //TASK 4
	{
		Node* ptr = head;
		while (ptr)
		{
			Node* min = ptr;
			Node* p = ptr->next;
			while (p)
			{
				if (min->data > p->data)
				{
					min = p;
				}
				p = p->next;
			}
			int a = ptr->data;
			ptr->data = min->data;
			min->data = a;
			ptr = ptr->next;
		}
	}
};
class doublyNode
{
public:
	int data;
	doublyNode* next;
	doublyNode* previous;
	doublyNode(int dt)
	{
		this->data = dt;
		this->next=NULL;
		this->previous = NULL;
	}

};
class doublyLinkedList
{
public:
	doublyNode* head;
	doublyNode* tail;
	doublyLinkedList()
	{
		
		this->head = NULL;
		this->tail = NULL;
	}
	int totalNodes()
	{
		doublyNode* p = head->next;
		int count = 0;
		while (p != NULL)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	void printdoubly()
	{
		if (this->head == NULL)
		{
			cout << "Doubly Linked List Empty" << endl;
		}
		else {
			doublyNode* ptr1;
			ptr1 = this->head;
			while (ptr1 != NULL)
			{
				cout << ptr1->data << endl;
				ptr1 = ptr1->next;
			}
		}
	}
	void insertElements()
	{
		int value;
		cout << "Plese enter doubly Linked List Element: ";
		cin >> value;
		doublyNode* newNode = new doublyNode(value);
		if (this->head == NULL)
		{
			this->head = newNode;
			this->tail = newNode;
			return;
		}
		else
		{
			this->tail->next = newNode;
			newNode->previous = this->tail;
			this->tail= newNode;
		}
	}
	void swap(doublyNode* a, doublyNode* b)
	{
		int val = a->data;
		a->data = b->data;
		b->data = val;
	}
	void insertionSort()                      //TASK 5
	{
		doublyNode* start = this->head;
		doublyNode* end = NULL;
		while (start != NULL)
		{
			end = start->next;
			while (end != NULL && end->previous != NULL && end->data < end->previous->data)
			{
				this->swap(end, end->previous);
				end = end->previous;
			}
			start = start->next;
		}
	}
};
int main()
{
	linkedList l;
	l.insertElements();
	l.insertElements();
	l.insertElements();
	l.insertElements();
	l.insertElements();
	l.insertElements();
	cout << "Task 3: Bubble Sort in Singly linked List=>" << endl;
	l.bubbleSort();
	l.printLinkedList();
	cout << "Task 4: Selection Sort in Singly linked List=>" << endl;
	l.selectionSort();
	l.printLinkedList();
	cout << "Task 5: Insertion Sort in Doubly Linked List=>" << endl;
	doublyLinkedList* ll=new doublyLinkedList();
	ll->insertElements();
	ll->insertElements();
	ll->insertElements();
	ll->insertElements();
	ll->insertElements();
	ll->insertionSort();
	ll->printdoubly();
}


//TASK 7
#include<iostream>
using namespace std;
int F[52];
int Fib(int n)
{
	if (n <= 1)
	{
		return n;
	}
	if (F[n] != -1)
	{
		return F[n];
	}
	else
	{
		F[n]=Fib(n - 1) + Fib(n - 2);
		return F[n];
	}
}
int main()
{
	for (int i = 0; i < 52; i++)
	{
		F[i] = -1;
	}
	int n;
	cin >> n;
	cout << Fib(n);
}


