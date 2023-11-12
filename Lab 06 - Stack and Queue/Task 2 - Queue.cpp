// Lab 06
// Task 2 - Queue

#include "iostream"
#include "queue"
#include "math.h"

using namespace std;

template <class T>
class Queue1
{
private:
	T* data;
	int front;
	int rear;
	const int MAX_SIZE;

public:
	Queue1(const int MAX_SIZE = 5) :MAX_SIZE(MAX_SIZE)
	{
		data = new T[MAX_SIZE];
		front = -1;
		rear = -1;
	}

	~Queue1()
	{
		delete[]data;
	}

	void enQueue(const T newItem)
	{
		if (((rear + 1) % MAX_SIZE) == front) // Queue is Full
		{
			cout << "Queue is Full";
		}
		else
		{
			if (front == -1) // Queue is Empty
			{
				front = 0;
			}
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = newItem;
		}
	}

	void deQueue()
	{
		if (front == -1) // Queue is Empty
		{
			cout << "ERROR!!! Queue is Empty";
		}
		else
		{
			if (front == rear)
			{
				front = rear = -1;
			}
			front = (front + 1) % MAX_SIZE;
		}
	}

	void clear()
	{
		front = rear = -1;
	}

	T getFront() const
	{
		if (front == -1)
		{
			cout << "ERROR!!! Queue is Empty";
			return 0;
		}
		else
		{
			return data[front];
		}
	}

	T getRear() const
	{
		if (rear == -1)
		{
			cout << "ERROR!!! Queue is Empty";
			return 0;
		}
		else
		{
			return data[rear];
		}
	}
	bool isEmpty() const
	{
		if (front == -1 || rear == -1)
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
		if (((rear + 1) % MAX_SIZE) == front)
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
		if (front == -1 || rear == -1)
		{
			cout << "ERROR!!! Queue is Empty";
		}
		else
		{
			for (int i = front; i <= rear; i++)
			{
				if (i == front)
				{
					cout << "\n\nFront --> ";
				}
				cout << data[i] << "\t";

				if (i == rear)
				{
					cout << "<-- Rear\n\n";
				}
			}
		}
	}
};

int main()
{
	/*queue<int> obj1;
	obj1.push(1);
	obj1.push(2);
	obj1.push(3);
	obj1.push(4);

	cout<<obj1.front();*/

	Queue1<float> obj2(6);

	obj2.enQueue(5.0);
	obj2.enQueue(6.5);
	obj2.showStructure();

	obj2.enQueue(-3.0);
	obj2.enQueue(-8.0);
	obj2.showStructure();

	obj2.deQueue();
	obj2.deQueue();
	obj2.showStructure();

	return 0;
}
