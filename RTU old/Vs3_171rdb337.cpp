#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <filesystem>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <cstddef>
using namespace std;

bool is_number(const string& s) 
{
	try
	{
		std::stod(s);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

double toDouble(const string& s) { 
	double val = stod(s);
	return val;
}



bool days(int dayCount, int month, int year) {
	bool dayTest = false;
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 400 == 0 || year % 100 != 0) && (year % 4 == 0)) {
		daysInMonth[1] = 29;
	}
	if (dayCount <= daysInMonth[month - 1]) {
		dayTest = true;
	}
	return dayTest;
}
bool goodDate(string Date) { 
	bool test = false;
	int dotInd = (int)Date.find_last_of(".");
	if (dotInd == Date.size() - 1) { 									
		stringstream check(Date);
		string datePart;
		vector<string> partList;
		while (getline(check, datePart, '.'))
		{
			partList.push_back(datePart);
		}
		if (partList.size() == 3) {			
			if (is_number(partList[2]) && partList[2].length() == 4 && toDouble(partList[2]) > 0) {
				int yearVal = (int)toDouble(partList[2]);			
					int monthVal = (int)toDouble(partList[1]);
					if (monthVal <= 12 && monthVal > 0) {				
						if (partList[0].length() == 2 && is_number(partList[0])) {
							int daysVal = (int)toDouble(partList[0]);
							if (days(daysVal, monthVal, yearVal)) {						
								test = true;
							}
						}
					}
				}
			}
		}
	}
	return test;
}
bool testForLegit(string String) { 													   
	bool seg = false, str1 = false, num1 = false, str2 = false, num2 = false, date = false;
	bool test = false;
	String.erase(remove(String.begin(), String.end(), ' '), String.end()); 
	if (String.length() > 0) {
		stringstream stream(String);
		string segment;
		vector<string> seglist;
		int semCount = 0;
		while (getline(stream, segment, ';')) {
			seglist.push_back(segment);
			semCount++; 
		}	
		if (seglist.size() == 5 && semCount == 5) {
			seg = true;
		}
		else {
			seg = false;
		}		
	if (seg) {
			
			if (seglist[0].length() > 0) {
				str1 = true;
			}		
			if (is_number(seglist[1]) && toDouble(seglist[1]) > 0) { 																 
			stringstream numStream(seglist[1]);
				string pos;
				vector<string> numHalf;
				while (getline(numStream, pos, '.')) {
					numHalf.push_back(pos);
				}
				if (numHalf.size() == 2) {
					if (numHalf[1].length() == 2) {
						num1 = true;
				}			
				}
			}			
			if (seglist[2].length() > 0) {
				str2 = true;
			}		
		
			if (is_number(seglist[3]) && toDouble(seglist[3]) > 0) { 
																	
				stringstream numStream(seglist[3]);
				string pos;
				vector<string> numHalf;
			while (getline(numStream, pos, '.')) {
					numHalf.push_back(pos);
				}
				if (numHalf.size() == 2) {
					if (numHalf[1].length() == 2) {
					num2 = true;
				}
				}
		}
			
		if (goodDate(seglist[4])) {
				date = true;
		}			
		}
	}
	if (str1 && num1 && str2 && num2 && date) {
		test = true;
	}
	return test;
}
vector<string> lineOut(string String) {
	stringstream Stringstream(String);
	string seg;
	vector<string> StringSegment;
	while (getline(Stringstream, seg, ';')) {
		StringSegment.push_back(seg);
	}
	for (int k = 0; k < StringSegment.size(); k++) {
		if (k == 0 || k ==2) { 
			for (int i = 0; i < StringSegment[k].length() - 1;) {
			if (i == 0) {
				if (StringSegment[k][i] == ' ') {
				StringSegment[k].erase(i, 1);
					continue;
				}
				else {
						i++;
						continue;
				}
				}
			else {
					if (StringSegment[k][i] == ' ' && StringSegment[k][i + 1] == ' ') {
						if (i + 1 == StringSegment[k].length() - 1) {
						StringSegment[k].erase(i, 2);
						}
					else {
							StringSegment[k].erase(i, 1);
						}
					continue;
					}
					else {
						i++;
						continue;
					}
				}

			}
		}
		else {
			   
			StringSegment[k].erase(remove(StringSegment[k].begin(), StringSegment[k].end(), ' '), StringSegment[k].end());
		}
	}
	return StringSegment;
}
string getErrPath(string filename) { 
	string errfile;
	int ind = (int)filename.find_last_of("/\\");
	if (ind != -1) {
		errfile = filename.substr(0, ind) + "err.txt";
	}
	else {
		errfile = "err.txt";
	}
	return errfile;
}
void funk1(vector<vector<string>> Vec) {
	cout << "Ievadiet razotaju: ";	
	string temp;
	cin.clear();
	cin.ignore();
	getline(cin, temp);
		cout << "\nIegutais rezultats: \n\n";
		for (int i = 0; i < Vec.size(); i++) {
			if (temp.compare(Vec[i][2])==0) {
				for (int j = 0; j < Vec[i].size(); j++) {
					cout << setw(15) << Vec[i][j];
				}
				cout << "\n";
			}
		}
		cout << "\n";	
}
void funk2(vector<vector<string>> Vec) {  
	cout << "Ievadiet preces nosaukumu: ";
	string temp;
	cin.clear();
	cin.ignore();
	getline(cin, temp);
	cout << "\nIegutais rezultats: \n\n";
	for (int i = 0; i < Vec.size(); i++) {
		if (temp.compare(Vec[i][0]) == 0) {
			for (int j = 0; j < Vec[i].size(); j++) {
				cout << setw(15) << Vec[i][j];
			}
			cout << "\n";
		}
	}
	cout << "\n";
}
void funk3(vector<vector<string>> Vec) { 
	cout << "Ievadiet preces daudzumu: ";
	double daudz;
	string temp;
	cin >> temp;
	while (true) {


		try {
			daudz = toDouble(temp);
		}
		catch (...) {
			cout << "\n Nepareiza ievade\n\n";
			break;
		}
		cout << "\nIegutais rezultats: \n\n";
		for (int i = 0; i < Vec.size(); i++) {
			if (daudz > toDouble(Vec[i][3])) {
				for (int j = 0; j < Vec[i].size(); j++) {
					cout << setw(15) << Vec[i][j];
				}
				cout << "\n";
			}
		}
		cout << "\n";
		break;
	}
}
void rezIzvada(vector<vector<string>> Vec) {
	cout << "Labu ierakstu tabula : \n";
	cout << setw(15) << "Nosaukums" << setw(15) << "Cena " << setw(15) << "Razotajs" << setw(15) << "Daudzums" << setw(15) << "Deriguma termins\n\n";
	for (int i = 0; i < Vec.size(); i++) {
		for (int j = 0; j < Vec[i].size(); j++) {
			cout << setw(15) << Vec[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
int main() {
	string filename; 
	string errfile;
	cout << "171RDB337 Marks Fomins 11.grupa \n";
	cout << "File to open: (For path use \\\\, example: C:\\\\Users\\\\User\\\\Documents\\\\file.txt)\n";
	cin >> filename;
	ifstream dataFile(filename);	
	vector<vector<string>> goodLines;
	vector<string> badLines;
	if (dataFile.is_open()) {
		errfile = getErrPath(filename); 
		cout << errfile << "\n";
		cout << "Labu ierakstu tabula : \n";
		cout << setw(15) << "Nosaukums" << setw(15) << "Cena " << setw(15) << "Razotajs" << setw(15) << "Daudzums" << setw(15) << "Deriguma termins\n\n";
		string line;
		while (getline(dataFile, line)) {
			if (testForLegit(line)) {
				vector<string> goodLine = lineOut(line);
				goodLines.push_back(goodLine);
				for (int i = 0; i < goodLine.size(); i++) {
					cout << setw(15) << goodLine[i];
				}
				cout << "\n";
			}
			else {
				badLines.push_back(line);
			}
		}
		dataFile.close(); 
		ofstream outfile(errfile); 
		for (int i = 0; i < badLines.size(); i++) { 
			outfile << badLines[i] << endl;
		}
		outfile.close(); 
		cout << "\nfile " + errfile + " was made\n";
		bool notEnd = true;
		while (notEnd) {
			while (true) {
				cout << "Choose action to perform:\n\n";
				cout << "1	Izdrukat datus par noteikta razotaja precem \n";
				cout << "2	Meklet preces pec nosaukuma \n";
				cout << "3	Meklet preces, kuru daudzums ir mazaks neka ievaditais skaitlis\n";
				cout << "0	Beigt darbu\n";
				int acc;
				string temp;
				cin >> temp;
				try {
					acc = toDouble(temp);
					while (acc < 0 || acc > 3) {
						cout << "\nChoose form 0 - 4\n";
					}
				}
				catch (...) {
					"\nNot a number, try again\n";
					break;
				}
				switch (acc) {
				case 0: notEnd = false;
					break;
				case 1: funk1(goodLines);
					break;
				case 2: funk2(goodLines);
					break;
				case 3: funk3(goodLines);
					break;
				}
				break;
			}
			if (notEnd) {
				rezIzvada(goodLines);
			}
		}
	}
	else {
		cout << "Were not able to open that file\n";
	}
}

