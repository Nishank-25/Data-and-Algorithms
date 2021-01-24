// Vector,Templates and Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include"../../../std_lib_facilities.h"
using namespace std;



template<typename T, typename A>
struct vector_base {
	A alloc; // allocator
	T* elem; // start of allocation
	int sz; // number of elements
	int space; // amount of allocated space
	vector_base(const A& a, int n)
		: alloc{ a }, elem{ alloc.allocate(n) }, sz{ n }, space{ n }{ }
	~vector_base() { alloc.deallocate(elem, space); }
};

// a very simplified Vector of doubles
template<typename T , typename A = allocator<T>>
class Vector : private vector_base<T,A>{

	int sz;        // the size
	T* elem; // a pointer to the elements
	int space;   // number of elements plus “free space”/“slots”
                // for new elements (“the current allocation”)
	A alloc; // use allocate to handle memory for elements

public:

	Vector() :sz{ 0 }, elem{ nullptr }, space{ 0 } { }


	explicit Vector(int s) 
		:sz{ s }, elem{ new T[s] }, space{s} // constructor
	{
		for (int i = 0; i < s; ++i) elem[i] = 0; // initialize elements
	}
	~Vector() { delete[] elem; } // destructor

	Vector(initializer_list<T> lst)          // initializer-list constructor 
		:sz(lst.size()), elem{ new T[sz] }    // uninitialized memory for elements 
	{
		copy(lst.begin(), lst.end(), elem); // initialize (using std::copy())
	}

	
	Vector(const Vector& arg);           //copy constructor
	Vector& operator=(const Vector& a); //copy assignment

	Vector(Vector&& a);           // move constructor
	Vector& operator=(Vector&&); // move assignment

	T& operator[](int n) { return elem[n]; }       // return element
	T operator[](int n) const { return elem[n]; } // for const Vector

	int capacity() const { return space; }
	int size() const { return sz; } // the current size


	void resize(int newsize, T val = T());// allocate extra space and update the size
	void reserve(int newalloc);         //reserve space for future allocation
	void push_back(const T& val);               // grows a Vector by adding element from end

	T& at(int n);
	
	
};



template<typename T , typename A>
Vector<T,A>::Vector(const Vector<T,A>& arg) // allocate elements, then initialize them by copying (copy constructor)
	:sz{ arg.sz }, elem{ new T[arg.sz] }
{
	copy(arg.elem, arg.elem + sz, elem);
}
template<typename T , typename A>
Vector<T,A>& Vector<T,A>::operator=(const Vector<T,A>& a) // make this Vector a copy of a 
{
	//copy every element of a into this

	//double* p = new double[a.sz]; // allocate new space 
	//copy(a.elem, a.elem + a.sz, p); // copy elements
	//delete[] elem; // deallocate old space
	//elem = p; // now we can reset elem 
	//sz = a.sz;
	//return *this; // return a self-reference (see §17.10) 

	// we must deal with old elements

	//double* p = new double[a.sz]; // allocate new space
	//for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i]; // copy elements
	//delete[] elem; // deallocate old space
	//space = sz = a.sz; // set new size
	//elem = p; // set new elements
	//return *this; // return self-reference

	// an optimized version

	if (this == &a) return *this; // self-assignment, no work needed
	if (a.sz <= space) { // enough space, no need for new allocation
		for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i]; // copy elements
		sz = a.sz;
		return *this;
	}
	T* p = new T[a.sz]; // allocate new space
	for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i]; // copy elements
	delete[] elem; // deallocate old space
	space = sz = a.sz; // set new size
	elem = p; // set new elements
	return *this; // return a self-reference
}

template<typename T , typename A>
Vector<T,A>::Vector<T,A>(Vector<T,A>&& a)
	:sz{ a.sz }, elem{ a.elem } // copy a’s elem and sz
{
	a.sz = 0; // make a the empty Vector<T,A>
	a.elem = nullptr;
}

template<typename T , typename A>
Vector<T,A>& Vector<T,A>::operator=(Vector<T,A>&& a) // move a to this Vector<T,A>
{
	delete[] elem; // deallocate old space
	elem = a.elem; // copy a’s elem and sz
	sz = a.sz;
	a.elem = nullptr; // make a the empty Vector<T,A>
	a.sz = 0;
	return *this; // return a self-reference (see §17.10)
}

template<typename T, typename A>
void Vector<T, A>::resize(int newsize, T val )
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val); // construct
	for (int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]); // destroy
	sz = newsize;
}

template<typename T , typename A >
void Vector<T,A>::reserve(int newalloc)
{
	if (newalloc <= this-> space) return; // never decrease allocation
	vector_base<T, A> b(this-> alloc, newalloc); // allocate new space
	uninitialized_copy(b.elem, &b.elem[this-> sz], this-> elem); // copy
	for (int i = 0; i< this->sz; ++i)
		this-> alloc.destroy(&this-> elem[i]); // destroy old
	swap<vector_base<T, A>>(*this, b); // swap representations
}

template<typename T , typename A>
void Vector<T,A>::push_back(const T& val)
// increase Vector size by one; initialize the new element with d
{
	if (space == 0) reserve(8); // start with space for 8 elements
	else if (sz == space) reserve(2 * space); // get more space
	alloc.construct(&elem[sz], val); // add val at end
	++sz; // increase the size
}





//19.3.5 
template<typename T, int N>
struct Array {
	T elem[N]; // hold elements in member Array
	
     // rely on the default constructors, destructor, and assignment
	
	T& operator[] (int n); // access: return reference
	const T& operator[] (int n) const;
	T* data() { return elem; } // conversion to T*
	const T* data() const { return elem; }
	int size() const { return N; }
};

Array<int, 256> gb; // 256 integers
Array<double, 6> ad = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };
const int Max = 1024;


void some_fct(int n)
{
	Array<char, Max> loc;
	//Array<char, n> oops; // error: the value of n not known to compiler
	// . . .
	//Array<char, Max> loc2 = loc; // make backup copy
	// . . .
	//loc = loc2; // restore
	// . . .
}


template<typename C> void printout(const C& c) // function template
{
	for (int i = 0; i < c.size(); ++i) cout << c[i] << '\n';
}


//19.4 

struct Out_of_range { /* . . . */ }; // class used to report range access errors
template<typename T, typename A > T& Vector<T, A>::at(int n)
{
	if (n < 0 || sz <= n) throw Out_of_range();
	return elem[n];
}

void print_some(Vector<double>& v)
{
	int i = -1;
	while (cin >> i && i != -1)
		try {
		cout << "v[" << i << "]==" << v.at(i) << "\n";
	}
	catch (Out_of_range) {
		cout << "bad index: " << i << "\n";
	}
}

//19.5.1 Resource management problems
void suspicious(int s, int x)
{
	int* p = new int[s]; // acquire memory
	// . . .
	int* q = new int[s];
	if (x) p = q; // make p point to another object
	// . . .
	delete[] p; // release memory
}

struct Default {


	Default();
};

struct No_default {
	
	No_default(int);
};
int main()
{
	// read elements into a Vector without using push_back:

	//Vector<double> * p = new Vector<double> (10);
	//int n = 0; // number of elements
	//for (double d; cin >> d; ) {
	//	if (n == p-> size()) {
	//		Vector<double> * q = new Vector<double> (p-> size() * 2);
	//		copy(p-> begin(), p-> end(), q-> begin());
	//			delete p;
	//		p = q;
	//	}
	//	(*p)[n] = d;
	//	++n;
	//}

	Vector<double> p{2.3,4.5,6.7};
	cout << p.size()<<p.capacity()<<endl;
	
	Vector<double> p2;
	cout << p2.size()<<p2.capacity()<<endl;
	//p2.resize(5, 1.0);
	//p.push_back(4.9);
	
	//for(int i =0;i<=8;++i) p2.push_back(23);

	//p.resize(1);
	//p2.resize(5);
	cout << p.size() << " " << p2.size() << endl;
	cout << p.capacity() << " " << p2.capacity()<<endl;

	// 19.2.5 Assignment
	p = p2;
	cout << p.size() << " " << p2.size() << endl;
	cout << p.capacity() << " " << p2.capacity()<<endl;


	//19.3.5 Integers as template parameters
	
	//double* p = ad; // error: no implicit conversion to pointer
	//double* q = ad.data(); // OK: explicit conversion
	//printout(ad);
	
	//19.4 Range checking and exceptions 
	
	print_some(p);
	
	
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
