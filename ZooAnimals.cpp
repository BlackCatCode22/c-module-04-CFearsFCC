#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


// Function to split a string by spaces

/*The function splitBySpace takes a string as input and splits 
it into individual words (separated by spaces), 
storing them in a vector<string>, which is returned. 
The stringstream class makes it easy to break the string 
into words using the stream extraction operator (>>).*/

vector<string> splitBySpace(const string& str) 
{
	vector<string> result;
	stringstream ss(str);
	string word;
	while (ss >> word)
	{
		result.push_back(word);
	}
	return result;
}

int main() {
	string myText = "";
	string mypause = "";

	// Open zooPopulation.txt
	ifstream MyFile("arrivingAnimals.txt");

	// Read zooPopulation.txt line by line
	while (getline(MyFile, myText))
	{
		cout << myText;
		cout << endl;
		// Parse one single line
		vector<string> parts;
		stringstream ss(myText);
		string item;
		// Split by commas
		while (getline(ss, item, ','))
		{
			// Remove any leading/trailing spaces from each part
			item.erase(0, item.find_first_not_of(" \t"));
			item.erase(item.find_last_not_of(" \t") + 1);
			parts.push_back(item);
		}
		// Print the split parts
		for (const auto& part : parts)
		{
			cout << part << endl;
		}
		// Now split each part by spaces and print the result
		int sectionNum = 0;
		for (const auto& part : parts)
		{
			vector<string> splitWords = splitBySpace(part);
			if (sectionNum == 0) 
			{
				cout << "Split part " << sectionNum << " age in years and species: " << part << endl;
					
			}
			if (sectionNum == 1) 
			{
				cout << "Split part " << sectionNum << " birth: " << part << endl;
					
			}
			if (sectionNum == 2)
			{
				cout << "Split part " << sectionNum << " color: " << part << endl;
					
			}
			if (sectionNum == 3)
			{
				cout << "Split part " << sectionNum << " weight: " << part << endl;
					
			}
			if (sectionNum == 4)
			{
				cout << "Split part " << sectionNum << " origin: " << part << endl;
					
			}
			if (sectionNum == 5)
			{
				cout << "Split part " << sectionNum << " origin: " << part << endl;
					
			}
			for (const auto& word : splitWords)
			{
				cout << word << endl;
			}
			cout << "**********" << endl; // Separator 
			sectionNum++;
		}
		sectionNum = 0;
	}

	// Close

	cout << "\n";

	
}

