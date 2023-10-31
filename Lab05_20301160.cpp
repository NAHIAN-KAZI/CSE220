//TASK1
#include <iostream>
using namespace std;
int factorial(int n)               //a
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n* factorial(n - 1);
	}
}
int fibonacci(int n)              //b
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	
	}
	
}
int printArrayElements(int array[], int size, int i)    //c
{
	if (i==size)
	{
		cout << endl;
		return i;
	}
	
	else
	{
		
		cout<<array[i]<< " ";
		i++;
		printArrayElements(array, size, i);
	}
}
int power(int base, int n)                  //d
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return base;
	}
	else
	{
		return power(base, n - 1) * base;
	}
}

int main()
{
	int array[] = { 1,2,3,4,5,6 };
	cout << "FACTORIAL: "<<factorial(3) << endl;
	cout << "n-th FIBONACCI: "<<fibonacci(8) << endl;
	int size = sizeof(array) / sizeof(array[0]);
	cout << "ARRAY ELEMENST: ";
	printArrayElements(array, size, 0);
	cout << "The value of base to the power n: " << power(5, 3) << endl;
	return 0;
}


//TASK2
#include <iostream>
using namespace std;
int binary(int num)               //a
{
	if (num == 0)
	{
		return 0;
	}
	else
	{
		return((num % 2) + 10 * binary(num / 2));
	}
}
class Node                     
{
public:
	int data;
	class Node* next;
}*head = NULL;
void create(int arr[], int n)
{
	Node* p, * tail;
	head = new Node();
	head->data = arr[0];
	head->next = NULL;
	tail = head;
	for (int i = 1; i < n; i++)
	{
		p = new Node();
		p->data = arr[i];
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
}
int addElements(Node* head)               //b
{
	if (head != NULL)
	{
		return head->data + addElements(head->next);
	}
	else
	{
		return 0;
	}
}
int printReverse(Node* head)          //c
{
	if (head != NULL)
	{
		printReverse(head->next);
		return head->data;
	}
}
int main()
{
	int n = 100;
	cout << "BINARY OF " << n <<":  " << binary(n) << endl;
	cout << "ADDITING ELEMENTS IN LINKED LIST: " << addElements(head) << endl;
	cout <<"REVERSE OF THE LINKED LIST: " << printReverse(head) << endl;
}

//TASK3
#include<iostream>
using namespace std;
int hocBuilder(int height)
{
	if (height == 0)
		return 0;
	if (height == 1)
	{
		return 8;
	}

	else
	{
		int count = 0;
		count += 5;
		return count + hocBuilder(height - 1);
	}
}
int main()
{
	cout << hocBuilder(4);
}


//TASK4

#include <iostream>
using namespace std;


void printS(int num)
{
	
	if (num == 0)
		return;
	cout << " "<<" ";
	printS(num - 1);
}


void pattern(int n)
{
	if (n > 0)
	{
		pattern(n - 1);
		cout << n << " ";
	}
	else
	{
		return;
	}
}
void printHalfPyramid1(int num)                      //a
{
	if (num > 0)
	{
		printHalfPyramid1(num - 1);
		pattern(num);
		cout << endl;
	}
	else
	{
		return;
	}
}
void printHalfPyramid2(int n1, int n2)               //b
{
	if (n1 == 0)
	{
		return;
	}
	else
	{
		printS(n1 - 1);
		pattern(n2 - n1 + 1);
		cout << endl;
		printHalfPyramid2(n1 - 1, n2);
	}
	
}
int main()
{
	cout << "TASK 5(a):  " << endl;
	printHalfPyramid1(5);
	cout << "TASK 5(b):  " << endl;
	printHalfPyramid2(5,5);
	return 0;
}

//TASK5
#include<iostream>
using namespace std;
int profit(int amount)
{
	int n;
	if (amount <= 25000)
	{
		return 0.0;
	}
	else
	{
		n = amount - 100000;
		n = n / 100;
		n = n+n+n+n+n+n+n+n;
		return n + 3375.0;

	}
}
void displayProfit(int arr[], int i)
{
	int totalProfit;
	if (i < 4)
	{
		totalProfit = profit(arr[i]);
		cout << i + 1 << ". Investment: " << arr[i] << "; Profit: " <<totalProfit << ".0" << "\n";
		displayProfit(arr, i + 1);
	}

}
int main()
{
	int array[] = { 25000,100000,250000,350000 };
	displayProfit(array, 0);
}