// Lab 05
// Task 3 - Frequency of a Particular Word

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream inputFile("input1.txt");

    if (!inputFile)
    {
        cout << "ERROR!!! File Does Not Exist\n";
        exit(0);
    }

    // Read the Word to be Searched
    string wordToSearch;
    getline(inputFile, wordToSearch);

    // Check if Word to be Searched is Empty
    if (wordToSearch.empty())
    {
        cout << "ERROR!!! The Word to be Searched is Empty\n";
    }

    string line;
    int lineNumber = 1;

    while (getline(inputFile, line))
    {
        istringstream lineStream(line);
        string word;
        int wordCount = 0;

        // Count Occurrences of the Word in the Line
        while (lineStream >> word)
        {
            // Convert Word to Lowercase for Case-Insensitive Comparison
            for (auto& character : word)
            {
                character = tolower(character);
            }
            if (word == wordToSearch)
            {
                wordCount++;
            }
        }

        // Output the Count for the Current Line
        cout << "Occurrences of '" << wordToSearch << "' in Line " << lineNumber << ": " << wordCount << endl;
        lineNumber++;
    }

    inputFile.close();

    /*
    	fstream inf("input1.txt");

	if (!inf)
	{
		cout << "ERROR!!! File Does Not Exist";
		exit(0);
	}

	string str1;
	getline(inf, str1);
	//cout << str1;


	string str2;
	int a = 1;
	int stringCount = 0, stringCount1 = 0;
	while (getline(inf, str2))
	{
		int k = 0; // For str1
		stringCount = 0;

		for (int i = 0; i < str2.length(); i++)
		{
			if (str1[k] == str2[i])
			{
				k++;
				if (k == str1.length())
				{
					k = 0;
					stringCount++;
				}
			}
			else
			{
				k = 0;
			}
		}
		cout << "Line " << a <<" contains " <<str1<<" : " << stringCount<<"\n";
		a++;
	}
	
	inf.close();
    */

    return 0;
}
