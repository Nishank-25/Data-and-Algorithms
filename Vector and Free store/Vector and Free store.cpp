// Vector and Free store.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// a very simplified vector of doubles
class vector {

	int sz; // the size
	double* elem; // a pointer to the elements

public:
	
	vector(int s)  :sz{ s }, elem{ new double[s] } // constructor
	{ 
		for (int i = 0; i < s; ++i) elem[i] = 0; // initialize elements
	} 
	~vector() { delete[] elem; } // destructor
	
	int size() const { return sz; } // the current size
	double get(int n) const { return elem[n]; } // access: read
	void set(int n, double v) { elem[n] = v; } // access: write
};
vector* f(int s)
{
	vector* p = new vector(s); // allocate a vector on free store
	// fill *p
	return p;
}
void ff()
{
	vector* q = f(4);
	// use *q
	delete q; // free vector on free store
}

//17.8 

//void f(void* pv) {
//	void* pv2 = pv; // copying is OK (copying is what void*s are for)
//	double* pd = pv; // error: cannot convert void* to double* 
//	*pv = 7; // error: cannot dereference a void*
//			 // (we don’t know what type of object it points to)
//	pv[2] = 9; // error: cannot subscript a void* 
//	int* pi = static_cast<int*>(pv); // OK: explicit conversion // . . . 
//}

//17.9.3 

//struct Link {
//	string value;
//	Link* prev;
//	Link* succ;
//	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
//		: value{ v }, prev{ p }, succ{ s }
//	{}
//};
//Link* insert(Link* p, Link* n) // insert n before p; return n
//{
//	if (n == nullptr) return p;
//	if (p == nullptr) return n;
//	n-> succ = p; // p comes after n
//	if (p-> prev) p-> prev-> succ = n;
//	n-> prev = p-> prev; // p’s predecessor becomes n’s predecessor
//	p-> prev = n; // n becomes p’s predecessor
//	return n;
//}

//17.9.4 List operations 

//Link* add(Link* p, Link* n) // insert n after p; return n
//{
//	// much like insert (see exercise 11)
//	return p;
//}
//
//Link* erase(Link* p) // remove *p from list; return p’s successor
//{
//	if (p == nullptr) return nullptr;
//	if (p-> succ) p-> succ-> prev = p-> prev;
//	if (p-> prev) p-> prev-> succ = p-> succ;
//	return p-> succ;
//}
//
//Link * find(Link * p, const string & s) // find s in list;
//// return nullptr for “not found”
//{
//	while (p) {
//		if (p-> value == s) return p;
//		p = p-> succ;
//	}
//	return nullptr;
//}
//Link* advance(Link* p, int n) // move n positions in list
//// return nullptr for “not found”
//// positive n moves forward, negative backward
//{
//	if (p == nullptr) return nullptr;
//	if (0 < n) {
//		while (n--) {
//			if (p-> succ == nullptr) return nullptr;
//			p = p-> succ;
//		}
//	}
//	else if (n < 0) {
//		while (n++) {
//			if (p-> prev == nullptr) return nullptr;
//			p = p-> prev;
//		}
//	}
//	return p;
//}
//void print_all(Link* p)
//{
//	cout << "{ ";
//	while (p) {
//		cout << p->value;
//		if (p = p->succ) cout << ", ";
//	}
//	cout << " }";
//}

//17.10 The this Pointer

//class Link {
//public:
//	string value;
//	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
//		: value{ v }, prev{ p }, succ{ s } { }
//	Link* insert(Link* n); // insert n before this object
//	Link* add(Link* n); // insert n after this object
//	Link* erase(); // remove this object from list
//	Link* find(const string& s); // find s in list
//	const Link* find(const string& s) const; // find s in const list (see §18.5.1)
//	Link* advance(int n) const; // move n positions in list
//	Link* next() const { return succ; }
//	Link* previous() const { return prev; }
//private:
//	Link * prev;
//	Link* succ;
//};
//Link* Link::insert(Link* n) // insert n before this object; return n
//{
//	if (n == nullptr) return this;
//	if (this == nullptr) return n;
//	n-> succ = this; // this object comes after n
//	if (prev) prev-> succ = n;
//	n-> prev = prev; // this object’s predecessor becomes n’s predecessor
//	prev = n; // n becomes this object’s predecessor
//	return n;
//}

int main()
{
	// Chapter 17 

	//17.3 Memory, Addresses and Pointers 

	//int x = 17; 
	//int* pi = &x; // pointer to int

	//double e = 2.71828; 
	//double* pd = &e; // pointer to double

	//cout << "pi==" << pi << "; contents of pi==" << *pi << "\n"; 
	//cout << "pd==" << pd << "; contents of pd==" << *pd << "\n";
	
	//17.3.1 The sizeof operator

	/*char ch;
	int i;
	int* p;
	
	cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
	cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
	cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';*/
	
	//17.4.3 Ranges 

	/*double* pd = new double[3]; 
	pd[2] = 2.2; 
	pd[4] = 4.4;
	pd[-3] = -3.3;

	for (int i = -5; i < 5; i++)
	{
		cout << pd[i] << endl;
	}*/
	
	//double* p = new double; // allocate a double 
	//double* q = new double[1000]; // allocate 1000 doubles 
	//q[700] = 7.7; // fine 
	//q[0] = 445.4;
	//cout << q[700]<<"  "<<q[0]<<endl;
	//q = p; // let q point to the same as p 
	//double d = q[700]; // out-of-range access!
	//cout << q[700]<<" " <<q[0];
	
	//17.4.4 Initialization

	//double* p0; // uninitialized: likely trouble
	//double* p1 = new double; // get (allocate) an uninitialized double 
	//double* p2 = new double{5.5}; // get a double initialized to 5.5 
	//double* p3 = new double[5]; // get (allocate) 5 uninitialized doubles
	//double* p4 = new double[5]{ 0,1,2,3,4 }; 
	//double* p5 = new double[] {0, 1, 2, 3, 4};

	//17.7 Pointers to class objects
	
	/*vector* p = new vector(4); 
	int x = p-> size(); 
	double d = p->get(3);
	cout << x << d;*/

	//17.8 Messing with types: void* and casts

	//void* pv1 = new int; // OK: int* converts to void*
	//void* pv2 = new double[10]; // OK: double* converts to void*
	//
	//// explicit conversion
	//void* pv; int i;
	//int* pi = static_cast<int*>(pv); 
    // int* ip = reinterpret_cast<int*>(i);
	//const vector* v;
	//vector* vi = const_cast<vector*>(v);

	//17.9 Pointers and references 

	//Pointer Ex
	//int x = 10;
	//int* p = &x;      // you need & to get a pointer
	//*p = 7;          // use * to assign to x through p
	//int x2 = *p;    // read x through p
	//int* p2 = &x2; // get a pointer to another int
	//p2 = p;       // p2 and p both point to x
	//p = &x2;     // make p point to another object
	
	//The corresponding example for references is
	//int y = 10;
	//int& r = y;      // the & is in the type, not in the initializer
	//r = 7;          // assign to y through r (no * needed)
	//int y2 = r;    // read y through r (no * needed)
	//int& r2 = y2; // get a reference to another int
	//r2 = r;      // the value of y is assigned to y2
	//r = &y2;    // error: you can’t change the value of a reference
	//           // (no assignment of an int* to an int&)
	
	//17.9.3 Lists 
		
	// norse_gods--->Freia--->Odin--->Thor
	/*Link* norse_gods = new Link{ "Thor",nullptr,nullptr };
	norse_gods = new Link{ "Odin",nullptr,norse_gods };
	norse_gods-> succ-> prev = norse_gods;
	norse_gods = new Link{ "Freia",nullptr,norse_gods };
	norse_gods-> succ-> prev = norse_gods;*/
	
	// a better version
	/*Link* norse_gods = new Link{ "Thor" };
	norse_gods = insert(norse_gods, new Link{ "Odin" });
	norse_gods = insert(norse_gods, new Link{ "Freia" });*/

	//17.9.5 List use

	/*Link* norse_gods = new Link("Thor");
	norse_gods = insert(norse_gods, new Link{ "Odin" });
	norse_gods = insert(norse_gods, new Link{ "Zeus" });
	norse_gods = insert(norse_gods, new Link{ "Freia" });
	
	Link* greek_gods = new Link("Hera");
	greek_gods = insert(greek_gods, new Link{ "Athena" });
	greek_gods = insert(greek_gods, new Link{ "Mars" });
	greek_gods = insert(greek_gods, new Link{ "Poseidon" });*/

	
	/*print_all(norse_gods);
	cout << "\n";
	print_all(greek_gods);
	cout << "\n";

	Link* p1 = find(greek_gods, "Mars");
	if (p1) p1-> value = "Ares";

	Link* p = find(norse_gods, "Zeus");
	if (p) {
		if (p == norse_gods) norse_gods = p-> succ;
		erase(p);
		greek_gods = insert(greek_gods, p);
	}

	print_all(norse_gods);
	cout << "\n";
	print_all(greek_gods);
	cout << "\n";*/


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
