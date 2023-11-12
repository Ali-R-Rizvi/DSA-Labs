// Lab 02
// Task 2 - Student Class

#include "iostream"
#include "cstdio"
#include "fstream"
#include "string"

using namespace std;

class Student
{
private:
	int id;
	float marks;

	friend istream& operator >> (istream& input, Student& obj);
	friend ostream& operator << (ostream& print, const Student& obj);

public:
	int getId() const
	{
		return id;
	}

	float getMarks() const
	{
		return marks;
	}

	Student(int id = 0, float marks = 0.0f)
	{
		this->id = id;
		this->marks = marks;
	}

	void addStudent(ofstream& obj) // 1- Add Student
	{
		obj.write(reinterpret_cast<char*>(this), sizeof(this));
		cout << "Student Added Successfully!!!";
	}

	void displayAllStudents(ifstream& obj) // 2- Display All Students
	{
		obj.seekg(0, ios::end);
		if (obj.tellg() == 0)
		{
			cout << "ERROR!!! File is Empty" << endl;
			return;
		}
		obj.seekg(ios::beg); // Brings the Pointer Back to the Starting Position

		if (!obj)
		{
			cout << "ERROR!!! File Doesn't Exist" << endl;
			return;
		}

		if (!obj.is_open())
		{
			cout << "ERROR!!! File Stream Not Opened" << endl;
			return;
		}

		Student temp;
		obj.read(reinterpret_cast<char*>(&temp), sizeof(temp));

		if (!obj.good())
		{
			cout << "ERROR!!! Unable to Read File" << endl;
			return;
		}

		while (!obj.eof()) // Reading
		{
			cout << temp;
			obj.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}



	bool findStudent(ifstream& file) // 3- Find Student
	{
		Student temp;
		int flag = 0;

		if (!file)
		{
			cout << "\nERROR!!! File Doesn't Exist" << endl;
			return false;
		}

		file.seekg(0, ios::end);
		if (file.tellg() == 0)
		{
			cout << "\nERROR!!! File is Empty" << endl;
			return false;
		}
		file.seekg(ios::beg); // Brings the Pointer Back to the Starting Position

		file.read(reinterpret_cast<char*>(&temp), sizeof(this));
		while (!file.eof())
		{
			file.read(reinterpret_cast<char*>(&temp), sizeof(this));
			if (this->id == id && this->marks == marks)
			{
				cout << "\nStudent Successfully Found" << endl;
				flag = 1;
				return true;
			}
		}
		if (flag == 0)
		{
			cout << "\nERROR!!! Student Doesn't Exist";
			return false;
		}
	}

	void deleteStudent(ifstream& file) // 4- Delete Student
	{
		if (!file.is_open()) 
		{
			cout << "ERROR!!! File Not Opened or Empty\n";
			return;
		}

		ofstream temp("temp.dat", ios::binary);
		if (!temp)
		{
			cout << "ERROR!!! Temporary File for Deletion is Not Created\n";
		}
		Student tempObj;

		bool deleted = false;
		
		while (file.read(reinterpret_cast<char*>(&tempObj), sizeof(tempObj)))
		{
			if (tempObj.id == id && tempObj.marks == marks)
			{
				deleted = true;
				continue;
			}
			temp.write(reinterpret_cast<char*>(&tempObj), sizeof(tempObj));
		}

		file.close();
		temp.close();
	
		if (deleted)
		{
			remove("student.dat");
			rename("temp.dat", "student.dat");
			cout << "\nStudent Deleted Successfully!!!\n";
		}
		else
		{
			remove("temp.dat");
			cout << "\nERROR!!! Student Not Found\n";
		}
	}
};

istream& operator >> (istream& input, Student& obj)
{
	cout << "Enter ID: ";
	input >> obj.id;

	cout << "Enter Marks: ";
	input >> obj.marks;

	return input;
}

ostream& operator << (ostream& print, const Student& obj)
{
	print << "\nID: " << obj.getId();
	print << "\nMarks: " << obj.getMarks();

	return print;
}

int main()
{
	/*Student obj1(1, 1.1), obj2(2, 2.2), obj3(3, 3.3), obj4(4, 4.4);

	//cin >> obj1;
	cout << "\n------------------- 1 -------------------" << obj1 << "\n-----------------------------------------\n";

	//cin >> obj2;
	cout << "\n------------------- 2 -------------------" << obj2 << "\n-----------------------------------------\n";

	//cin >> obj3;
	cout << "\n------------------- 3 -------------------" << obj3 << "\n-----------------------------------------\n";

	//cin >> obj4;
	cout << "\n------------------- 4 -------------------" << obj4 << "\n-----------------------------------------\n";


	Student arr1[4] = { obj1,obj2,obj3,obj4 }, arr2[4];

	ofstream outf("abc.dat", ios::binary | ios::out);
	//outf.write(reinterpret_cast<char*>(&arr1), sizeof(Student) * 4);
	obj1.addStudent(outf);
	obj2.addStudent(outf);
	obj3.addStudent(outf);
	obj4.addStudent(outf);
	outf.close();

	/fstream intf("abc.dat", ios::binary);
	obj1.findStudent(intf);
	obj1.displayAllStudents(intf);
	intf.close();


	ifstream int1f("abc.dat", ios::binary);
	obj4.deleteStudent(int1f);
	int1f.close();

	ifstream newFile("abc.dat", ios::binary);
	obj3.displayAllStudents(newFile);
	newFile.close();*/

	while (true) {
		cout << "\nMenu:\n1. Add Student\n2. Display All Students\n3. Find Student\n4. Delete Student\n5. Exit\n";
		int choice;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			Student newStudent;
			cin >> newStudent;
			ofstream outFile("student.dat", ios::binary | ios::app);
			newStudent.addStudent(outFile);
			outFile.close();
			break;
		}
		case 2: {
			Student obj;
			ifstream inFile("student.dat", ios::binary);
			obj.displayAllStudents(inFile);
			inFile.close();
			break;
		}
		case 3: {
			Student searchStudent;
			cout << "Enter student details to find:\n";
			cin >> searchStudent;
			ifstream inFile("student.dat", ios::binary);
			searchStudent.findStudent(inFile);
			inFile.close();
			break;
		}
		case 4: {
			Student deleteStudent;
			cout << "Enter student details to delete:\n";
			cin >> deleteStudent;
			ifstream inFile("student.dat", ios::binary);
			deleteStudent.deleteStudent(inFile);
			inFile.close();
			break;
		}
		case 5:
			exit(0);
		default:
			cout << "Invalid choice. Try again." << endl;
		}
	}

	return 0;
}
