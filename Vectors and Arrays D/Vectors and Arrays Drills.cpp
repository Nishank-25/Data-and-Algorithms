// Vectors and Arrays D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"../../../std_lib_facilities.h"
using namespace std;
// Array Drills

//int ga[]={1,2,4,8,16,32,64,128,256,512};
//
//void f(int a[], int n) { // takes an int array and no of elements in the array as args
//
//	constexpr int la_size = 10;
//	int la[la_size];
//
//	for (int i = 0; i < la_size; i++)
//	{
//		la[i] = ga[i];
//	}
//
//	for (int i = 0;i < n;++i) { cout << "la" << "[" << i << "]" << "= " << la[i] << endl;}
//
//	int* iap = new int[n];
//	
//	for (int i = 0; i < n; i++)
//	{
//		iap[i] = a[i];
//	}
//
//	for (int i = 0;i < n;++i ) { cout << "iap" << "[" << i << "]" << "= " << iap[i] << endl; }
//
//	delete[] iap;
//}
//
//int fact(int no) {
//
//	if (no == 0) return 1;
//	 return no * fact(no-1);
//}

//E1
char* Strdup(const char* a) {

	//find the length of string
	int count = 0;
	while (*a) {
		++count;++a;
	}
	int temp{ count };
	char* cp = new char[count+1];

	while (temp > 0) {
		--a;--temp;
	}

	while (*a) { 
		*cp = *a;
		++cp;
		++a;
	}
	temp = count;
	*cp = 0; // add the terminating zero
	while (temp > 0) {
		--cp;--temp;
	}
	return cp;
}

//E2

//finds first occurence of x in s

char* findx(const char* s, const char* x) {  

	const char* start = x;
	int flag = 0, occur = 0, count = 0;
	while (*x++) ++count;
		for (; *s ; ++x,++s)
		{
			
			/*char s1 = *s;
			char x1 = *x;*/

			if (*s == ' ') { /// if space encountered check if found and return
				             /// else point at start
			if (flag == 0) ++occur; 
			while (*s == ' ') ++s;
				
			if (occur == 1) {
					++count;
					while (count--) --s;
					return const_cast<char*>(s);
				}

			flag = 0;
			x = start;
	
			}
			else 
				if (*x == 0) { // point x to start increment s till new word
					x = start;
					flag = 0; 
					while (*s != ' ')++s; 
					++s; 
				}
				
			
			if (*x != *s) ++flag; // compare
		}
		if (occur == 0) return nullptr;

}

//E3

int Strcmp(const char* s1, const char* s2) {

	if (!s1 || !s2)error("can't compare nullptr");
	
	constexpr int before{ -1 }, after{ 1 }, equal{ 0 };
	
	for (; *s1 && *s2; ++s1,++s2)
	{
		if (*s1 != *s2) {
			if (*s1 > * s2) { return after; }
			if (*s1 < *s2) { return before; }

		}
		
	}
	return equal;
}

void print(const char* c) {
	if (!c) error("Cant print nullptr");
	while (*c) cout<< *c++;
}
void print_strcmp(int a,const char* s1,const char* s2 ) {

	if (a == 1) { print(s1); cout << " comes after "; print(s2); }
	if (a == -1) { print(s1); cout << " comes before "; print(s2); }
	if (a == 0) { print(s1); cout << " equals "; print(s2); }
}

//E5,E6
string cat_dot(const string& s1, const string& s2,const string& seprator) {

	string cat_dot = s1 + seprator + s2;
	return cat_dot;
}

//E7
char* cat_dot(const char* s1, const char* s2, const char* seprator) {
	
	 /*int s1_count{ 0 };
	 int s2_count{ 0 };
	 int sep_count{ 0 };*/

	const char* s1_start = s1;
	const char* s2_start = s2;
	const char* sep_start = seprator;
	int cat_str_count = 0;

	while (*s1++) ++cat_str_count;
	while (*s2++) ++cat_str_count;
	while (*seprator++) ++cat_str_count;
	
	char* cat_str = new char[cat_str_count+1];
	s1 = s1_start;
	s2 = s2_start;
	seprator = sep_start;

	while (*s1) *cat_str++ = *s1++;
	while (*seprator) *cat_str++ = *seprator++;
	while (*s2) *cat_str++ = *s2++;
	*cat_str = 0;

	while (--cat_str_count) --cat_str;
	--cat_str;
	return cat_str;

}

int main()
{

	//Chapter 18 

	  // Drills

	  /// Arrays Drill

	  /*f(ga,10);
	  int aa[10];
	  for (int i = 0;i < 10;++i) aa[i] = fact(i + 1);
	  f(aa,10);*/



	  /// std::vector drill


	  // Exercises

	  //E1 

	/*char cs[] = "Hello World";
	char* cp = Strdup(cs);
	print(cp);
	delete cp;*/

	//E2

	/*char x[] = "tell";
	char s[] = "The external scars tell only part of the story.";
	char* cp = findx(s, x);
	print(cp);*/
	
	//E3

	/*char s1[] = "Nishank";
	char s2[] = "Patil";
	char s3[] = "Nishad";
	char s4[] = "Nishank";
	print_strcmp(Strcmp(s1, s2),s1,s2);	cout << endl;
	print_strcmp(Strcmp(s1, s3),s1,s3);	cout << endl;
	print_strcmp(Strcmp(s1, s4),s1,s4);	cout << endl;*/

	//E5,E6
	
	/*string s1{ "Nishank" }, s{ "Patil" };
	cout << cat_dot(s1, s,".");*/

	//E7

	/*char s1[] = "Nishank", s2[] = "Patil",s3[]="+====";
	char* cat_str = cat_dot(s1, s2, s3);
	cout << cat_str;
	print(cat_str);
	delete[] cat_str;*/

	//E9 

	/*char* ip = new char[] {5, 6};
    if (&ip[0] > & ip[1]) cout << "Lower address";
	else cout << "Higher address";
	delete[] ip;*/
	
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
