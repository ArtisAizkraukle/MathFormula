//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

class MathClass
{
public:
	char user_input_string[256];

	// Convert user input to 2 strings
	// We wont to get the numbers from user input like string, something like this: 5-88-999-3-		
	// and string of operatos: "+=*/"  

	int convert_to_string() {
		length = strlen(user_input_string); // length of user input
		for (size_t i = 0; i < length; i++)
		{
			if (isdigit(user_input_string[i]))
			{
				str_of_numbers = str_of_numbers + user_input_string[i];
				if (!isdigit(user_input_string[i + 1]))
				{
					str_of_numbers = str_of_numbers + "-"; // String one
				}
			}
			else
			{
				str_of_operators = str_of_operators + user_input_string[i]; // String two
			}
		}
		return 0;
	};

	// We wont to get numbers from string "5-88-99-3-" 
	// in to the array like this {5, 88, 99, 3 }

	int get_number_array() {
		convert_to_string();
		length = str_of_numbers.length();
		string buf = "";
		for (size_t i = 0; i < length; i++)
		{
			string tmp = str_of_numbers.substr(i, 1); // Cutting first character from numbers string
			if (tmp != "-") //  Simbol "-" means that it is the end of number and after that is the next number
			{
				buf = buf + tmp;
			}
			else
			{
				array_of_numbers.push_back(stoi(buf)); //  Convert string in to integer and push it in the end of array
				buf = "";
			}
		}
		return 0;
	}

	// Finaly we can build oure formula  
	// Whe get numbers from array and operators from string
	// and put it all in math formula

	int get_result() {
		get_number_array();
		int res = 0;
		length = str_of_operators.length() + 1; // Getting the number of operation with oure formula + 1 = number of numbers
		for (size_t i = 0; i < length; i++)
		{
			if (i == 0) { res = array_of_numbers.at(0); } // For first time we get first number
			else
			{
				string oper = str_of_operators.substr(i - 1, 1);  // Get the operator
																  // Find out what operation we need an exequit it
				if (oper == "+") { res = res + array_of_numbers.at(i); }
				if (oper == "-") { res = res - array_of_numbers.at(i); }
				if (oper == "*") { res = res * array_of_numbers.at(i); }
				if (oper == "/") { res = res / array_of_numbers.at(i); }
			}
		}
		return res;
	};
protected:
	int length;
	string str_of_numbers = "";
	string str_of_operators = "";
	vector <int> array_of_numbers;
};
