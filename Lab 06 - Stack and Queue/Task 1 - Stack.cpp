// Lab 06
// Task 1 - Stack

#include "iostream"
#include "stack"

using namespace std;

template <class T>
class Stack1
{
private:
	T* data;
	int top;
	const int MAX_SIZE;

public:
	Stack1(const int MAX_SIZE = 5) :MAX_SIZE(MAX_SIZE)
	{
		data = new T[MAX_SIZE];
		top = -1;
	}

	~Stack1()
	{
		delete[]data;
	}

	void push(const T newItem)
	{
		if (top == (MAX_SIZE - 1))
		{
			cout << "Stack OverFlow";
		}
		else
		{
			data[++top] = newItem;
		}
	}

	void pop()
	{
		if (top == -1)
		{
			cout << "Stack Overflow";
		}
		else
		{
			--top;
		}
	}

	void clear()
	{
		top = -1;
	}

	T getTop() const
	{
		if (top == -1)
		{
			cout << "Stack Overflow";
			return 0;
		}
		else
		{
			return data[top];
		}
	}

	bool isEmpty() const
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
	bool isFull() const
	{
		if (top == (MAX_SIZE - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void showStructure() const
	{
		if (top == -1)
		{
			cout << "ERROR!!! Empty Stack";
		}
		else
		{
			for (int i = top; i >= 0; i--)
			{
				if (i == top)
				{
					cout << "\n\nTop --> ";
				}
				cout << data[i] << "\t";
			}
		}
	}
};

int main()
{
	Stack1 <float> obj1(6);

	obj1.push(5.0);
	obj1.push(6.5);
	obj1.showStructure();

	obj1.push(-3.0);
	obj1.push(-8.0);
	obj1.showStructure();

	obj1.pop();
	obj1.pop();
	obj1.showStructure();



	return 0;
}
