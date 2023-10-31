/TASK1
#include<iostream>
#include<string>
using namespace std;
class array_stack
{
private:
	int top;
	int array[5];


public:
	array_stack()
	{
		int top = -1;
		int size = sizeof(array) / sizeof(array[0]);
		for (int i = 0; i < size; i++)
		{
			array[i] = 0;

		}
	}
	void showError(int i)
	{
		cout << "THIS EXPRESSION IS NOT CORRECT"<<endl;
		cout << "Error found at chararcter:" << i << " '";
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		int size = sizeof(array) / sizeof(array[0]);
		if (top == size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(int value)
	{
		if (isFull())
		{
			cout << "STACK OVERFLOW" << endl;
		}
		else
		{
			top++;
			array[top] = value;
		}
	}
	int pop()
	{
		if (isEmpty())
		{
			cout << "STACK UNDERFLOW" << endl;
			
		}
		else
		{
			int popValue = array[top];
			array[top] = 0;
			top--;
			return popValue;
		}
	}
	int count()
	{
		return top + 1;
	}
	char peek()
	{
		char array[100];
		int array_size = 0;
		if (isEmpty())
		{
			cout << "STACK UNDERFLOW" << endl;
		}
		else
		{
			return array[array_size-1];
		}
	}
	void change(int position, int value)
	{
		array[position] = value;
		cout << "Value changed at position" << position << endl;
	}
	void display()
	{
		cout << "ALL VALUE AT THE STACK ARE:";
		int size = sizeof(array) / sizeof(array[0]);
		for (int i = size - 1; i >= 0; i--)
		{
			cout << array[i] << "  ";
		}
	}
	int error(string s, int count, char c)
	{
		int stringSize = s.size();
		int a = 0;
		for (int i = 0; i < stringSize; i++)
		{
			if (s[i] == c)
			{
				a++;
				if (a == count)
				{
					return i + 1;
				}
			}
		}
		return stringSize;
	}

	
};
void array_check(string s)
{
	array_stack arr_stk;
	int parenthesis = 0, curly_brace = 0, square_brace = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			arr_stk.push('(');
			parenthesis++;
		}
		if (s[i] == '{')
		{
			arr_stk.push('{');
			curly_brace++;
		}
		if (s[i] == '[')
		{
			arr_stk.push('[');
			square_brace++;
		}
		if (s[i] == ')')
		{
			if (arr_stk.isEmpty())
			{
				arr_stk.showError(i + 1);
				cout << s[i] << "'-not opened\n";
				return;
			}
			int n;
			cout << "Please enter the index you want to peek";
			cin >> n;
			if (arr_stk.peek() != '(')
			{
				if (arr_stk.peek() == '{')
				{
					int index = arr_stk.error(s, curly_brace, '{');
					arr_stk.showError(index);
					cout << "'{' is not closed<<" << endl;
				}


				if (arr_stk.peek() == '[')
				{
					int index = arr_stk.error(s, square_brace, '[');
					arr_stk.showError(index);
					cout << "'[' is not closed<<" << endl;
				}
				return;
			}
			else
			{
				arr_stk.pop();
				parenthesis--;

			}
		}
		else {
			if (s[i] == '}')
			{
				if (arr_stk.isEmpty())
				{
					arr_stk.showError(i + 1);
					cout << s[i] << " not opened" << endl;
					return;
				}
			}
			if (arr_stk.peek() != '{')
			{
				if (arr_stk.peek() == '(')
				{
					int index = arr_stk.error(s, parenthesis, '(');
					arr_stk.showError(index);
					cout << "'(' is not closed" << endl;
				}
				if (arr_stk.peek() == '[')
				{
					int index = arr_stk.error(s, square_brace, '[');
					arr_stk.showError(index);
					cout << " '[' is not closed" << endl;
					return;
				}
			}
			else {
				arr_stk.pop();
				curly_brace--;
			}
		}
		if (s[i] == ']')
		{
			if (arr_stk.isEmpty())
			{
				arr_stk.showError(i + 1);
				cout << s[i] << " not opened" << endl;
				return;
			}
		}
		if (arr_stk.peek() != '[')
		{
			if (arr_stk.peek() == '{')
			{
				int index = arr_stk.error(s, curly_brace, '{');
				arr_stk.showError(index);
				cout << " '{' is not closed" << endl;
			}
			if (arr_stk.peek() == '(')
			{
				int index = arr_stk.error(s, square_brace, '(');
				arr_stk.showError(index);
				cout << " '(' is not closed" << endl;
				return;
			}
		}
		else {
			arr_stk.pop();
			square_brace--;
		}



	}
	if (!arr_stk.isEmpty())
	{
		if (arr_stk.peek() == '(')
		{
			arr_stk.showError(arr_stk.error(s, parenthesis, '('));
			cout << " '(' not closed" << endl;
		}
		if (arr_stk.peek() == '{')
		{
			arr_stk.showError(arr_stk.error(s, curly_brace, '{'));
			cout << " '{' not closed" << endl;
		}
		if (arr_stk.peek() == '(')
		{
			arr_stk.showError(arr_stk.error(s, square_brace, '['));
			cout << " '[' not closed" << endl;
		}
	}
	else
	{
		cout << "THIS EXPRESSION IS CORRECT" << endl;
	}
}


int main()
{
	string input;
	cout << "ENTER YOUR STRING: ";
	cin >> input;
	array_check(input);
	
}












/TASK2
#include<iostream>
using namespace std;
class Node
{
public:
	char data;
	Node* next;

	Node(char dt, Node* nxt)
	{
		data = dt;
		next = nxt;
	}
};
class stack
{
public:

	int size;
	int top;
	char* s;
};

class linkedListStack
{
public:
	Node* head = NULL;

	void errorShow(int index)
	{
		cout << "THIS EXPRESSION IS NOT CORRECT" << endl;
		cout << "ERROR AT CHARACTER: " << index << " '" << endl;
	}
	int error(string s, int count, char c)
	{
		int stringSize = s.size();
		int a = 0;
		for (int i = 0; i < stringSize; i++)
		{
			if (s[i] == c)
			{
				a++;
				if (a == count)
				{
					return i + 1;
				}
			}
		}
		return stringSize;
	}

	bool isEmpty()
	{
		return head == NULL;
	}
	char peek()
	{
		if (isEmpty())
		{
			cout << "STACK UNDERFLOW" << endl;
		}
		else
		{
			return head->data;
		}
	}
	char pop()
	{
		if (isEmpty())
		{
			cout << "STACK UNDERFLOW" << endl;
		}
		else
		{
			char v = head->data;
			head = head->next;
			return v;
		}
	}
	void push(char c)
	{
		Node* n = new Node(c, head);
		head = n;
	}
};

void linkedListCheck(string s)
{
	linkedListStack l_stack;
	int parenthesis = 0, curly_brace = 0, square_brace = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			parenthesis++;
			l_stack.push('(');
		}
		if (s[i] == '{')
		{
			l_stack.push('{');
			curly_brace++;
		}
		if (s[i] == '[')
		{
			square_brace++;
			l_stack.push('[');
		}
		if (s[i] == ')')
		{
			if (l_stack.isEmpty())
			{
				l_stack.errorShow(i + 1);
				cout << s[i] << " NOT OPENED" << endl;
				return;
			}
			if (l_stack.peek() != '(')
			{
				if (l_stack.peek() == '{')
				{
					int index = l_stack.error(s, curly_brace, '{');
					l_stack.errorShow(index);
					cout << "'{' NOT CLOSED" << endl;
				}
				if (l_stack.peek() == '[')
				{
					int index = l_stack.error(s, square_brace, '[');
					l_stack.errorShow(index);
					cout << "'[' NOT CLOSED" << endl;
				}
				return;
			}
			else
			{
				l_stack.pop();
				parenthesis--;
			}
		}
		if (s[i] == '}')
		{
			if (l_stack.isEmpty())
			{
				l_stack.errorShow(i + 1);
				cout << s[i] << " NOT OPENED" << endl;
				return;
			}
			if (l_stack.peek() != '{')
			{
				if (l_stack.peek() == '(')
				{
					int index = l_stack.error(s, parenthesis, '(');
					l_stack.errorShow(index);
					cout << "'(' NOT CLOSED" << endl;
				}
				if (l_stack.peek() == '[')
				{
					int index = l_stack.error(s, square_brace, '[');
					l_stack.errorShow(index);
					cout << "'[' NOT CLOSED" << endl;

				}
				return;
			}
			else {
				l_stack.pop();
				curly_brace--;
			}
		}
		if (s[i] == ']')
		{
			if (l_stack.isEmpty())
			{
				l_stack.errorShow(i + 1);
				cout << s[i] << " NOT OPENED" << endl;
				return;
			}
			if (l_stack.peek() != '[')
			{
				if (l_stack.peek() == '{')
				{
					int index = l_stack.error(s, curly_brace, '{');
					l_stack.errorShow(index);
					cout << "'{' NOT CLOSED" << endl;
				}
				if (l_stack.peek() == '(')
				{
					int index = l_stack.error(s, parenthesis, '(');
					l_stack.errorShow(index);
					cout << "'(' NOT CLOSEDD" << endl;
				}
				return;
			}
			else
			{
				l_stack.pop();
				square_brace--;
			}
		}
	}
	if (!l_stack.peek() == '(')
	{
		if (l_stack.peek() == '(')
		{
			l_stack.errorShow(l_stack.error(s, parenthesis, '('));
			cout << "'(' NOT CLOSED" << endl;
		}
		if (l_stack.peek() == '{')
		{
			l_stack.errorShow(l_stack.error(s, curly_brace, '{'));
			cout << "'{' NOT CLOSED" << endl;
		}
		if (l_stack.peek() == '[')
		{
			l_stack.errorShow(l_stack.error(s, square_brace, '['));
			cout << "'[' NOT CLOSED" << endl;
		}
	}
	else {
		cout << "THIS EXPRESSION IS CORRECT" << endl;
	}
}

int main()
{
	string input;
	cout << "PLEASE ENTER A STRING TO CHECK: ";
	cin >> input;
	linkedListCheck(input);
	return 0;
}