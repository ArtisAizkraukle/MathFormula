//I'm finding out how to work c++ classes

#include "stdafx.h"
#include "class2.cpp"

int main()
{
	MathClass myMathClass;
	cin >> myMathClass.user_input_string;
	cout << "My function return: " << myMathClass.get_result() << endl;
    return 0;
}