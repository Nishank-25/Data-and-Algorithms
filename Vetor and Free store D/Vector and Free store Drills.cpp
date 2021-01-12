// Vetor and Free store D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdexcept>
#include<ctype.h>
#include"../../../std_lib_facilities.h"
using namespace std;

//D4 

//void print_array(ostream& os, int* a, int n) {
//
//	for (int i = 0; i < n; i++)
//	{
//		os << a[i] << endl;
//	}
//}
//void print_array10(ostream& os, int* a) { print_array(os, a, 10); }

//E3 

//void to_lower(char* s) {
//
//	if (!s) error("pointer points to nullptr");
//
//	for (int i = 0;char c = s[i];++i) {
//		if ('A' <= c && c <= 'Z') { c += 32; s[i] = c; }
//
//	}
//}

//E4 

//char* strdup(const char* p) {

	
//}

//E5 

// char* findx(const char* s, const char* x) {
//	
//	const char* start = x;
//	int flag = 0,occur=0;
//	for (; *s ; ++x,++s)
//	{
//		
//		char s1 = *s;
//		char x1 = *x;
//		if (*s == ' ') {
//
//			if (flag == 0) ++occur;
//			while (*s == ' ') ++s;
//			flag = 0;
//			x = start;
//
//		}
//		else 
//			if (*x == '0') { x = start;	flag = 0; while (*s != ' ') ++s; ++s; }
//			
//		
//		if (*x != *s) ++flag; // compare
//		 
//		if (occur == 1) {  return const_cast<char*>(s); }
//		 
//
//	}
//	if (occur == 0) return nullptr;
//
//}


int main()
{
	
	//Chapter 17 Drills and Exercises 

	//Drills 

	//int* ip = new int[]{-1,1,2,3,4,5,6,7,8,9};
	
	
	/*for (int i = 0; i <10; i++)
	{
		cout << ip[i]<<endl;
		
	}

	print_array10(cout, ip);
	print_array(cout, ip, 5);*/

	//delete[]ip;

	////int x = 7;
	//int* p1 = new int{ 7 };
	//cout<<showbase << "value of p1="<< p1 << " contents of object p1 points to=" << *p1<<endl;

	//int* p2 = new int[7] {1, 2, 4, 5, 6, 8, 9};
	//cout << "value of p2 = " << p2 << endl;
	//print_array(cout, p2, 8);

	//int* p3 = p2;	
	//p2 = p1;
	//p2 = p3;

	//cout << "value of p1,p2,p3" << p1 << " " << p2 << " " << p3 << endl;
	//cout << "p1 points to:";
	//print_array(cout, p1, 1);
	//cout << "p2 points to:";
	//print_array(cout, p2, 5);
	//cout << "p3 points to:";
	//print_array(cout, p3, 5);

	//delete p1;
	//delete[]p2;
	//delete[]p3;


	//Exercises

	//E3 

	/*string ss;
	cout << "Enter string\n";
	getline(cin, ss);
	to_lower(&ss[0]);
	cout << "The lowercase string is " << ss;*/

	//E5
	
	//Find first occurence of x in s
	/*string s;
	string x; 
	getline(cin, s);
	cin >> x;
	char* p = findx(&s[0] , &x[0]);
	if (p)cout << "Found";*/

	//E6
	/*int count = 0;
	while (true)
	{
		double* pd = new double[131072]; 		
		cout << count<<" Mb" << endl;
		++count;
	}*/

	//E7

	//Error prone program :  // after 5th char program might write ch into an no allocated location 
	                        // which may be is used for different purpose by heap
	/*char ch; 
	
	char* cp = new char[5];
	int pos=0, max=6; 
	while (cin>>ch && ch!='!')
	{
	    cp[pos] = ch; 
		++pos;
	}

	for (int i = 0; i <pos ; i++)
	{
		cout << cp[i];
	}*/

	//E9

	 // determine stack growth direction
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	cout << "Addresses on stack:\n" << &i1 << "\n" << &i2 << "\n" << &i3 << "\n";
	int stack_diff = &i2 - &i1;
	if (stack_diff > 0) cout << "Stack grows up\n";
	else cout << "Stack grows down\n";

	// determine heap growth direction
	/*int* ip1 = new int(0);
	int* ip2 = new int(0);
	int* ip3 = new int(0);
	cout << "Addresses on heap:\n" << ip1 << "\n" << ip2 << "\n" << ip3 << "\n";
	int heap_diff = ip2 - ip1;
	if (heap_diff > 0) cout << "Heap grows up\n";
	else cout << "heap grows down\n";

	delete ip1;
	delete ip2;
	delete ip3;*/



	
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
