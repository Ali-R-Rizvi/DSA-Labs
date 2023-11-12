// Lab 03
// Task 1 - Point List

#include "iostream"

using namespace std;

struct Point3D
{
	float x, y, z;
};

class PointList
{
	Point3D* arr;
	int maxSize;
	int currSize;
	int cursor;

public:
	int getCurrSize()
	{
		return currSize;
	}

	int getCursor_Int()
	{
		return cursor;
	}

	PointList(int maxSize = 0) // A- Constructor
	{
		this->maxSize = maxSize;
		arr = new Point3D[maxSize];

		for (int i = 0; i < maxSize; i++)
		{
			arr[i].x = 0;
			arr[i].y = 0;
			arr[i].z = 0;
		}

		currSize = 0;
		cursor = -1;
	}

	~PointList() // B- Destructor
	{
		delete[]arr;
		currSize = 0;
	}

	bool isEmpty() // C- Checks if the List is Empty
	{
		if (currSize == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFull() // D- Checks if the List is Full
	{
		if (currSize == maxSize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void insert(Point3D newPoint) // E- Insert
	{
		if (!isFull())
		{
			if (isEmpty())
			{
				cursor = 0;
			}
			arr[currSize].x = newPoint.x; // Inserts New Point at the End
			arr[currSize].y = newPoint.y;
			arr[currSize].z = newPoint.z;
			//cursor = currSize; // Moves the Cursor to the New Point
			currSize++;
			cursor++;
		}
		else
		{
			arr[1] = newPoint;
			currSize++;
			cursor++;
		}
	}

	void showStructure() // F- Display the List Items
	{
		if (currSize == 0)
		{
			cout << "List is Empty!!!";
		}
		else
		{
			for (int i = 0; i < currSize; i++)
			{
				cout << "--------------------------------";
				cout << "\nx = " << arr[i].x;
				cout << "\ny = " << arr[i].y;
				cout << "\nz = " << arr[i].z;
				cout << "\n--------------------------------\n";
			}
		}
	}


	Point3D getCursor() // G- Get Cursor
	{
		cout << "\n\n------------------ Get Cursor ------------------";
		if (currSize == 0)  // If the List is Empty
		{
			cout << "ERROR!!! List is Empty";
			Point3D temp;
			temp.x = -1;
			temp.y = -1;
			temp.z = -1;
			cout << "\n\nX=" << temp.x << "\nY= " << temp.y << "\nZ=" << temp.z << endl;
			cout << "\n------------------------------------------------\n\n";
			return temp;
		}
		else // Returns a Copy Pointed by the Cursor
		{
			cout << "\n\nX=" << arr[cursor].x << "\nY= " << arr[cursor].y << "\nZ=" << arr[cursor].z << endl;
			cout << "\n------------------------------------------------\n\n";
			return { arr[cursor].x, arr[cursor].y, arr[cursor].z };
			//return arr[cursor];
		}
		
	}

	void gotoBeginning() // H- Go To Beginning
	{
		if (!isEmpty())
		{
			cursor = 0;
		}
	}

	void gotoEnd() // I- Go To End
	{
		if (!isEmpty())
		{
			cursor = currSize - 1;
		}
	}

	bool gotoNext() // J- Go To Next 
	{
		if (currSize != 0)
		{
			if (cursor != (maxSize - 1))
			{
				cursor++;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool gotoPrior() // K- Go To Prior
	{
		if (currSize != 0)
		{
			if (cursor != 0)
			{
				cursor--;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	void clear() // L- Clear
	{
		currSize = 0;
		cursor = -1;
	}

	bool replace(Point3D newPoint) // M- Replace
	{
		if (!isEmpty())
		{
			//arr[cursor] = newPoint;
			arr[cursor].x = newPoint.x;
			arr[cursor].y = newPoint.y;
			arr[cursor].z = newPoint.z;

			return true;
		}
		else
		{
			return false;
		}
	}


	void remove() // N- Remove
	{
		if (!isEmpty())
		{
			if (cursor != currSize)
			{
				arr[cursor].x = arr[currSize - 1].x;
				arr[cursor].y = arr[currSize - 1].y;
				arr[cursor].z = arr[currSize - 1].z;

				arr[currSize - 1].x = 0;
				arr[currSize - 1].y = 0;
				arr[currSize - 1].z = 0;

				currSize--;
			}
		}
		if (!isEmpty() && currSize != 0)
		{
			cursor = currSize;
		}
		else
		{
			cursor = 0;
		}
	}
};

int main()
{
	Point3D a1 = { 1,2,3 };
	Point3D a2 = { 2,8,5 };
	Point3D a3 = { 3,2,3 };
	Point3D a4 = { 4,1,76 };

	PointList obj1(5);

	obj1.insert(a1);
	obj1.insert(a2);
	obj1.insert(a3);
	obj1.insert(a4);
	obj1.showStructure();

	cout << "Current Size: " << obj1.getCurrSize();
	obj1.remove();
	cout << "\n\n\n";
	obj1.showStructure();
	obj1.getCursor();
	obj1.gotoEnd();
	obj1.getCursor();
	obj1.remove();
	obj1.showStructure();

	obj1.gotoEnd();
	obj1.getCursor();
	obj1.remove();
	obj1.showStructure();

	obj1.gotoEnd();
	obj1.getCursor();
	obj1.remove();
	obj1.showStructure();

	obj1.gotoEnd();
	obj1.replace(a4);
	obj1.showStructure();

	//cout << "\nCurrent Size: " << obj1.getCurrSize();
	//cout << "\nCursor: " << obj1.getCursor_Int();
	//obj1.replace(a1);
	//obj1.showStructure();

	return 0;
}
