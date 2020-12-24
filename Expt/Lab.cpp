// Expt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<list>
using namespace std;

class T {

public:
	T(int a, int b) : a(a), b{ b }{ cout << "T(int a, int b) called" << endl;}
	T() { cout << "T() called" << endl; }
	~T()
	{
		cout << "~T() called" << endl;
		a = 0;
		b = 0;
		cout << a << b;
	}
	int a, b;
};

class T1 :T {

public:

	T1() { cout << "T1() called" << endl; }
	~T1(){cout<< "~T1() called" << endl;}

};



int main()
{
	//17.3
	//vector<char> v(1000); // vector with 1000 elements of type int
	//cout << "the size of vector<int>(1000) is " << sizeof(v) << '\n';

	//Null pointer

	//double* p = nullptr;

	//Destructors
	/*T t{ 2,3 };
	cout << t.a << t.b;

	T t1;
	T1 t3;*/

	/*int i = 5;
	int* p = &i;

	cout << "p==" << p << "; contents of p==" << *p << "\n";
	++*p;
	cout << "p==" << p << "; contents of p==" << *p << "\n";
	++p;
	cout << "p==" << p << "; contents of p==" << *p << "\n";
	++p;
	cout << "p==" << p << "; contents of p==" << *p << "\n";*/

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
