LINEAR ARRAY
~Task 1  Shift Left k Cells
#include<iostream>
using namespace std;
void shiftLeft(int array[], int k, int n) {
	
	for (int i = 0; i < n; i++)
    {
		
        int new_i = i - k;
		if (new_i >= 0) {
			array[new_i] = array[i];
		}

		
	    array[i] = 0;
	}
	for (int i = 0; i < n ; i++) {
		cout << array[i] << "  ";
	}
}

int main() 
{
	int source[] = { 10,20,30,40,50,60,70 };
	int n = sizeof(source) / sizeof(source[0]);
	shiftLeft(source, 3, n);
	system("pause>0");
}

~TASK2 Rotate Left k cells 
#include <iostream>
using namespace std;

void rotateLeft(int array[], int k, int n) {
	for (int i = 0; i < k; i++) {
		int temp;
		temp = array[i];
		array[i] = array[i + k];
		array[i + k] = temp;
		//cout << array[i + k] << endl;
		
		//cout << temp<< " ";
	}
	for (int i = 0; i < n; i++) {
		cout << array[i] << "  ";
	}
}
int main()
{
	int source[] = { 10,20,30,40,50,60 };
	int n = sizeof(source) / sizeof(source[0]);
	rotateLeft(source, 3, n);
	system("pause>0");
}

~TASK 3 Remove an element from an array
#include<iostream>
using namespace std;
void remove(int array[], int size, int idx)
{
	for (int i = idx + 1; i < size; i++)
	{
		int new_i = i - 1;

		array[new_i] = array[i];
		//cout << array[i] << endl;

	}

	for (int i = 0; i < size; i++) {
		cout << array[i] << "  ";
	}
}
int main()
{
	int source[] = { 10,20,30,40,50,0,0 };
	int size = sizeof(source) / sizeof(source[0]);
	int idx;
	cout << "Index: " << endl;
	cin >> idx;
	remove(source, size, idx);
}



~TASK 4 Remove an element from an array
#include<iostream>
using namespace std;
void removeAll(int array[], int size, int element)
{
	int temp = element;
	for (int i = 0; i < size; i++)
	{
		int j = 0;
		if (array[i] == temp)
		{
			for (int k = i; k >=j; --k)
			{
				array[k] = array[k - 1];
				array[j++] = 0;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "  ";
	}
}
int main() {
	int source[] = { 10,2,30,2,50,2,2,0,0 };
	int size = sizeof(source) / sizeof(source[0]);
	int element;
	cout << "Enter an element: ";
	cin >> element;
	removeAll(source, size, element);
}

~TASK 5 Splitting an Array
#include<iostream>
using namespace std;
bool beamBalance(int array[], int length)
{
	int index = length / 2;
	int total1 = 0, total2 = 0;
	if (length % 2 == 0)
	{
		for (int i = 0; i < index; i++)
		{
			total1 += array[i];
		}
		for (int j = index; j < length; j++)
		{
			total2 += array[j];
		}
		if (total1 == total2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			total1 += array[i];
		}
		for (int j = index + 1; j < length; j++)
		{
			total2 += array[j];
		}
		if (total1 + 1 == total2 || total2 + 1 == total1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	int weights[] = { 1,1,1,2,1 };
	int length = sizeof(weights) / sizeof(weights[0]);
	beamBalance(weights, length);
	if (beamBalance(weights, length) == 1)
	{
		cout<< "true";
	}
	else
	{
		cout<<"false";
	}
	
}

~TASK 6 Array series

#include <iostream>
using namespace std;

int* printarray(int n)
{
	int* number = new int[n * n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= i)
			{
				number[n * (i + 1) - (j + 1)] = j + 1;
			}
			else
			{
				number[n * (i + 1) - (j + 1)] = 0;
			}
		}
	}
	return number;
}
void main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	int* a = printarray(n);
	for (int i = 0; i < n * n; i++)
	{
		cout << a[i] << "  ";
	}
}


~TASK 7 Max Bunch Count
#include <iostream>
using namespace std;

int maxBunch(int array[],int size)
{
	int count = 1;
	int arr2[7];

	for (int i = 0; i < size; i++)
	{
		if (array[i] == array[i + 1])
		{
			count += 1;
		}
		else
		{
			if (count > 1)
			{
				arr2[i] = count;
				count = 1;
			}
		}
	}
	int maximum = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr2[i] >= arr2[i + 1])
		{
			maximum = arr2[i];
		}
		else
		{
			maximum = arr2[i + 1];
		}
	}
	return maximum;
}

int main()
{
	
	int numbers[] = { 1,1,2,3,3,3,3};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int value = maxBunch(numbers, size);
	cout << value;
	return 0;
}

~TASK 8 Repetition
#include <iostream>
using namespace std;

int repetition(int numbers[], int size)
{
	int maximum = 0;
	for (int i = 0; i < size ; i ++)
	{
		if (numbers[i] > numbers[i + 1])
		{
			maximum = numbers[i];
		}
		else
		{
			maximum = numbers[i + 1];
		}
	}
	
	int arr2[maximum+1] = { 0 };
	for (int i = 0; i < size; i++)
	{
		arr2[numbers[i]] += 1;
	}
	for (int i = 0; i < maximum + 1; i ++)
	{
		if (arr2[i] > 1)
		{
			for (int j = i + 1; j < maximum + 1; j ++)
			{
				if (arr2[i] == arr2[j] && arr2[j] > 1)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int numbers[] = { 4,5,6,6,4,3,6,4 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	repetition(numbers, size);
	if (repetition(numbers, size) == 1)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
}

CIRCULAR ARRAY
~TASK 1  Palindrome
#include <iostream>
using namespace std;

bool palindrome(int cir_arr[], int size, int length, int start)
{
	int index = start;
	bool check = true;

	int end_i = (start + size) / length;
	
	for (int i = 0; i < size / 2; i ++)
	{
		if (cir_arr[index] != cir_arr[end_i])
		{
			check = false;
			index = (index + 1) % length;
			end_i -= 1;
			if (end_i == -1)
			{
				end_i = length - 1;
			}
			break;
		}
		else
		{
			continue;
		}
	}
	return check;
}

int main()
{
	int number[] = { 10,20,0,0,0,10,20,30 };
	int size = sizeof(number) / sizeof(number[0]);
	palindrome(number, 5, size, 5);
	if (palindrome(number, 5, size, 5) == 1)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
	return 0;
}


~TASK 2 Intersection

#include <iostream>
using namespace std;

int* intersection(int cir_arr1[], int start1, int size1, int length1, int cir_arr2[], int start2, int size2, int length2)
{
	int new_size = 0;
	if (size1 < size2)
	{
		new_size = size1;
	}
	else
	{
		new_size = size2;
	}
	int* new_array = new int[new_size];
	int index1 = start1;
	int index2 = start2;
	int k = 0;
	for (int i = 0; i < length1; i ++)
	{
		for (int j = 0; j < length2; j++ )
		{
			if (cir_arr1[index1] == cir_arr2[index2] && cir_arr1[index1] != 0 && cir_arr2[index2] != 0)
			{
				new_array[k] = cir_arr1[index1];
				k += 1;
			}
			index2 = (index2 + 1) % length2;
		}
		index1 = (index1 + 1) % length1;
	}
	return new_array;
}

int main()
{
	int cir_arr1[] = { 40,50,0,0,0,10,20,30 };
	int cir_arr2[] = { 10,20,5,0,0,0,0,0,5,40,15,25 };
	int length1 = sizeof(cir_arr1) / sizeof(cir_arr1[0]);
	int length2 = sizeof(cir_arr2) / sizeof(cir_arr2[0]);
	int* a;
	a = intersection(cir_arr1, 5, 5, length1, cir_arr2, 8, 7, length2);
	for (int i = 0; i < 5; i++)
	{
		if (a[i] != 0)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}


~TASK 3
#include <iostream>
using namespace std;

void musicalChair(char array[], int size)
{
	while (size != 1)
	{

		int random_number = rand() % 4;
		if (random_number == 1)
		{
			for (int i = size / 2; i < size - 1; i++)
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			size--;
			for (int i = 0; i < size; i++)
			{
				cout << array[i] << " ";
			}
			cout << endl;
		}

		else
		{
			int temp1 = array[size - 1];
			for (int i = size - 1; i > 0; i -= 1)
			{
				array[i] =array[i - 1];
			}
			array[0] = temp1;
		}
	}
}

int main()
{
	char array[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	int size = sizeof(array) / sizeof(array[0]);
	musicalChair(array, size);
	return 0;
}

