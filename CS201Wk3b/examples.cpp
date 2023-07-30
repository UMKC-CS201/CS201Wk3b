#include "examples.h"


bool isDigits1(string str1) {
	return str1.find_first_not_of("0123456789") == string::npos;
}

bool isDigits2(string str1) {
	for (int i = 0; i < str1.size(); i++) {
		if (!isdigit(str1[i]))
			return false;
	}
	return true;
}

void printVector(vector<int> data) {
	for (int i = 0; i < data.size(); i++) {
		cout << data.at(i) << " ";
	}
	cout << endl;
}
void readData(vector<int>& data) {
	//Read CSV File
	ifstream inFile;
	inFile.open("data.txt");
	if (!inFile.is_open()) {
		cout << "Unable to open file";
		return;
	}
	string tempStr;
	int tempInt;
	inFile >> tempStr;
	while (inFile.good()) {
		if (isDigits2(tempStr)) {
			data.push_back(stoi(tempStr));
		}
		inFile >> tempStr;
	}

}

void example1() {
	//Read CSV File & add digits to vector. Print Vector
	vector<int> data;
	readData(data);
	printVector(data);
}

float operation(int a, int b, char oper) {
	try {
		switch (oper) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b != 0)
				return static_cast<float>(a) / b;
			else
				throw invalid_argument("divide by 0");
		case '^': 
			return a ^ b;
		default : 
			throw invalid_argument("unrecognized operation " + to_string(a) + oper + to_string(b) );
			return 0;
		}
	}
	catch (invalid_argument &e) {
		cout << e.what() << endl;
		return 0;
	}

}
void example2() {
	//process input file (separated by spaces)
	//Read File
	ifstream inFile;
	inFile.open("data2.txt");
	if (!inFile.is_open()) {
		cout << "Unable to open file";
		return;
	}
	string tempStr;
	int a, b;
	char oper;
	while (getline(inFile, tempStr)) {
		stringstream inSS(tempStr);
		try {
			inSS >> a >> oper >> b;
			cout << a << " " << oper << " " << b << " = " << operation(a, b, oper) << endl;
		}
		catch (...) {
			cout << "invalid input for " << a << " " << oper << " " << b <<  endl;
		}
	}
}

int example3() {
	// Loop until a valid integer is entered
	int userInput;
	bool valid = false;

	while (!valid) {
		cout << "Enter an integer: ";
		try {
			if (cin >> userInput) {			// Attempt to read an integer from the user input
				valid = true;
				return userInput; 
			}
			else {
				throw std::invalid_argument("Invalid input. Please enter an integer.");
			}
		}
		catch (invalid_argument &e) {
			cin.clear();														// Clear the error flag of the input stream
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  	// Ignore the remaining characters in the input buffer up to the newline
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

}
