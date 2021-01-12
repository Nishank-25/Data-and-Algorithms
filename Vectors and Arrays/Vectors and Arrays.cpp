// Vectors and Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
using namespace std;

// a very simplified vector of doubles
class vector {

	int sz; // the size
	double* elem; // a pointer to the elements

public:
																																																															
	explicit vector(int s) :sz{ s }, elem{ new double[s] } // constructor
	{
		for (int i = 0; i < s; ++i) elem[i] = 0; // initialize elements
	}
	~vector() { delete[] elem; } // destructor

	vector(initializer_list<double> lst)          // initializer-list constructor 
		:sz(lst.size()), elem{new double[sz]}    // uninitialized memory for elements 
	{ 
		copy( lst.begin(),lst.end(),elem); // initialize (using std::copy())
	}

	vector(const vector& arg) // allocate elements, then initialize them by copying 
		:sz{arg.sz}, elem{new double[arg.sz]} 
	{ 
		copy(arg.elem,arg.elem+sz,elem); 
	}

	vector& operator=(const vector& a);
	
	vector(vector&& a); // move constructor
	vector& operator=(vector&&); // move assignment

	double& operator[](int n) { return elem[n]; } // return element
	double operator[](int n) const { return elem[n]; } // for const vector

	int size() const { return sz; } // the current size
	double get(int n) const { return elem[n]; } // access: read
	void set(int n, double v) { elem[n] = v; } // access: write
};

vector& vector::operator=(const vector& a) // make this vector a copy of a 
{ 
double* p = new double[a.sz]; // allocate new space 
copy(a.elem,a.elem+a.sz,p); // copy elements
delete[] elem; // deallocate old space
elem = p; // now we can reset elem 
sz = a.sz;
return *this; // return a self-reference (see §17.10) 
}

vector::vector(vector&& a)
	:sz{ a.sz }, elem{ a.elem } // copy a’s elem and sz
{
	a.sz = 0; // make a the empty vector
	a.elem = nullptr;
}
vector& vector::operator=(vector&& a) // move a to this vector
{
	delete[] elem; // deallocate old space
	elem = a.elem; // copy a’s elem and sz
	sz = a.sz;
	a.elem = nullptr; // make a the empty vector
	a.sz = 0;
	return *this; // return a self-reference (see §17.10)
}

vector fill(istream& is)
{
	
	vector res(100000000);
	for (double i = 0;i < res.size();++i) res.set(i, i);
	return res;
}
void use()
{
	vector vec = fill(cin);
	// … use vec …
}




//18.4.2
struct X { // simple test class
	int val;
	void out(const string& s, int nv)
	{
		cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
	}
	X() { out("X()", 0); val = 0; } // default constructor
	X(int v) { val = v; out("X(int)", v); }
	X(const X& x) { val = x.val; out("X(X&) ", x.val); } // copy constructor
	X& operator=(const X& a) // copy assignment
	{
		out("X::operator=()", a.val); val = a.val; return *this;
	}
	~X() { out("~X()", 0);	 } // destructor
};

X glob(2); // a global variable
X copy(X a) { return a; }
X copy2(X a) { X aa = a; return aa; }
X& ref_to(X & a) { return a; }
X* make(int i) { X a(i); return new X(a); }

struct XX { 
	X a; X b; 
};


//18.7 palindromes

//using strings
bool is_palindrome(const string& s)
{
	int first = 0; // index of first letter
	int last = s.length()-1; // index of last letter
	while (first < last) { // we haven’t reached the middle
		if (s[first] != s[last]) return false;
		++first; // move forward
		--last; // move backward
	}
	return true;
}

//using arrays

bool is_palindrome(const char s[], int n)
// s points to the first character of an array of n characters
{
	int first = 0; // index of first letter
	int last = n-1; // index of last letter
	while (first < last) { // we haven’t reached the middle
		if (s[first] != s[last]) return false;
		++first; // move forward
		--last; // move backward
	}
	return true;
}

//using pointers(iterative)
bool is_palindrome(const char* first, const char* last)
// first points to the first letter, last to the last letter
{
	while (first < last) { // we haven’t reached the middle
		if (*first != *last) return false;
		++first; // move forward
		--last; // move backward
	}
	return true;
}

// using pointers(recursive)

//bool is_palindrome(const char* first, const char* last)
//// first points to the first letter, last to the last letter
//{
//	if (first < last) {
//		if (*first != *last) return false;
//		return is_palindrome(first + 1, last-1);
//	}
//	return true;
//}



int main()
{
	//vector v(3);
	//v.set(0, 23);
	//vector v2(4);
	//v2.set(0, 33);
	//v2= v;

	////v.set(1, 99); // set v[1] to 99 
	////v2.set(0,88); // set v2[0] to 88 
	//cout << v.get(0) << ' ' << v2.get(0)<<endl;
	//
	//v2 = v2;
	//cout << v.get(0) << ' ' << v2.get(0);


	//18.3.3 Copy Terminology 
	
	//Shallow copying
	//int* p = new int{ 77 }; 
	//int* q = p; // copy the pointer p
	//*p = 88; // change the value of the int pointed to by p and q

	////Deep copying
	//int* p = new int{ 77 }; 
	//int* q = new int{ *p }; // allocate a new int, then copy the value pointed to by p 
	//*p = 88; // change the value of the int pointed to by p

	
	//use();

	//18.4.1 Explicit Constructors 
	
	//vector v = 10; // error: no int-to-vector conversion 
	//v = 20; // error: no int-to-vector conversion 
	//vector v0(10); // OK void f(const vector&); 
	//f(10); // error: no int-to-vector<double> conversion
	//f(vector(10)); // OK

	//18.4.2 Debugging Constructors and Destructors

	//X loc{ 4 }; // local variable
	//X loc2{ loc }; // copy construction
	//loc = X{ 5 }; // copy assignment
	//loc2 = copy(loc); // call by value and return
	//loc2 = copy2(loc);
	//X loc3{ 6 };
	//X& r = ref_to(loc); // call by reference and return
	//delete make(7);
	//delete make(8);
	////vector<X> v(4); // default values
	//XX loc4;
	//X* p = new X{ 9 }; // an X on the free store
	//delete p;
	//X* pp = new X[5]; // an array of Xs on the free store
	//delete[] pp;
	
	//18.5 Access to vector elements

	//vector v(10);
	//v[2]=23.0;
	//double x = v[2]; // fine
	// v[3] = x;

	 //18.6  Arrays

	 //double ad[2];
	 //ad[0] = 23.2;
	 //double ad1[2];
	 //ad1[0] = 24.5;
	 //
	 //double* p = ad; // implicit array name to pointer conversion
	 //double* p1 = &ad1[0]; 
	 //cout << *p << " " << *p1;

	 //18.7 Palindromes

	 //using strings
	 for (string s; cin >> s; ) {
		 cout << s << " is";
		 if (!is_palindrome(s)) cout << " not";
		 cout << " a palindrome\n";
	 }

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
