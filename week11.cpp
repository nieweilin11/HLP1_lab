#include "std_lib_facilities.h"
using namespace std;

template<typename T, typename A>
struct vector_base {
	A alloc; 				// allocator
	T* elem; 				// start of allocation
	int sz; 				// number of elements
	int space; 				// amount of allocated space

	vector_base(const vector_base<T, A>& vec);					//Copy constructor
	vector_base(vector_base<T, A>&& vec);						//Move Constructor
	vector_base<T, A>& operator=(vector_base<T, A>&& vec);				//Move Assignment
	void reserve(int newalloc);
	void resize(int newsize, T val = T());

	vector_base() : elem{ nullptr }, sz{ 0 }, space{ 0 }{ }
	vector_base(int n) :sz{ n }, elem{ alloc.allocate(n) }, space{ n }
	{
		for (T* p = elem; p != elem + n; p++)
			alloc.construct(p, T());
	}

	vector_base(const A& a, int n) : alloc{ a }, elem{ alloc.allocate(n) }, sz{ n }, space{ n }{ }
	~vector_base() { alloc.deallocate(elem, space); }
};

template<typename T, typename A = allocator<T> >
class our_vector : private vector_base<T, A> {

public:
	our_vector() : vector_base<T, A>() {};				//Default Constructor

	explicit our_vector(size_t s) :vector_base<T, A>(s) { 	//Normal Constructor
	}

	our_vector(const our_vector<T, A>& vec);					//Copy constructor

	our_vector<T, A>& operator=(const our_vector<T, A>& vec);			//Copy Assignment

	our_vector(our_vector<T, A>&& vec);						//Move Constructor

	our_vector<T, A>& operator=(our_vector<T, A>&& vec);				//Move Assignment

	~our_vector() {									//Destructor
	}

	T& operator[](int n) { return vector_base<T, A>::elem[n]; }					//For non-const vectors

	int size() const { return vector_base<T, A>::sz; };

	void print();

	void reserve(int newalloc);

	int capacity() const { return vector_base<T, A>::space; }

	void resize(int newsize, T val = T());

	void push_back(T& val);

	T& at(int n) {
		if (n < 0 || vector_base<T, A>::sz < n)
			throw std::out_of_range("It is out of range access!");
		return vector_base<T, A>::elem[n];
	}
};

template<typename T, typename A> vector_base<T, A>::vector_base(const vector_base<T, A>& vec) : sz{ vec.sz }, elem{ alloc.allocate(sz) }, space{ vec.sz } {	//Copy constructor
	copy(vec.elem, vec.elem + sz, elem);
}

template<typename T, typename A> our_vector<T, A>::our_vector(const our_vector<T, A>& vec) : vector_base(vec) {	//Copy constructor
	///copy(vec.elem, vec.elem + sz, elem);
}

template<typename T, typename A> our_vector<T, A>& our_vector<T, A>::operator=(const our_vector<T, A>& vec) {
	if (this == &vec)
		return *this;
	if (vec.vector_base::sz <= this.space) {								//never decrease deallocation
		copy(vec.elem, vec.elem + vec.sz, this.elem);
		/*for (int i = 0; i < vec.sz; i++)
		elem[i] = vec.elem[i];*/
		for (int i = vec.sz; i < this.sz; ++i)
			this.alloc.destroy(&this.elem[i]);
		this.sz = vec.sz;
		return *this;
	}

	T* p = this.alloc.allocate(vec.sz); 							// allocate new space
	copy(vec.elem, vec.elem + vec.sz, p); 						// copy elements
	for (int i = 0; i < this.sz; ++i) 							// deallocate old space
		this.alloc.destroy(&this.elem[i]);
	this.alloc.deallocate(this.elem, this.space);
	this.space = this.sz = vec.sz;
	this.elem = p; 									// now we can reset elem
	return *this; 									// return a self-reference

}

template<typename T, typename A> vector_base<T, A>::vector_base(vector_base<T, A>&& vec) : sz{ vec.sz }, elem{ vec.elem }, space{ vec.space } {		//Move Constructore
	vec.sz = 0;
	vec.elem = nullptr;
}

template<typename T, typename A> our_vector<T, A>::our_vector(our_vector<T, A>&& vec) : vector_base(vec) {		//Move Constructore
	///vec.sz = 0;
	///vec.elem = nullptr;
}


template<typename T, typename A> vector_base<T, A>& vector_base<T, A>::operator=(vector_base<T, A>&& vec) {		//Move Assignment
	for (int i = 0; i < sz; ++i) 											// deallocate old space
		alloc.destroy(&elem[i]);
	alloc.deallocate(elem, space);
	elem = vec.elem; 			// copy a��s elem and sz
	sz = vec.sz;
	space = vec.space;
	vec.elem = nullptr; 		// make a the empty vector
	vec.sz = 0;
	return *this; 			// return a self-reference

}

template<typename T, typename A> our_vector<T, A>& our_vector<T, A>::operator=(our_vector<T, A>&& vec) {		//Move Assignment
	if (this != vec)
	{
		vector_base::operator= (vec);
	}
	return *this; 			// return a self-reference
}


template<typename T, typename A> void vector_base<T, A>::reserve(int newalloc) {		//reserve
	if (newalloc <= space) return; 							// never decrease allocation
	T* p = alloc.allocate(newalloc); 						// allocate new space
	for (int i = 0; i < sz; ++i)
		alloc.construct(&p[i], elem[i]);					// copy old elements
	for (int i = 0; i < sz; ++i) 							// deallocate old space
		alloc.destroy(&elem[i]);
	alloc.deallocate(elem, space);
	elem = p;
	space = newalloc;
}
template<typename T, typename A> void our_vector<T, A>::reserve(int newalloc) {		//reserve
	vector_base<T, A>::reserve(newalloc);
}

template<typename T, typename A> void vector_base<T, A>::resize(int newsize, T val) {
	reserve(newsize);
	for (int i = sz; i < newsize; i++)
		alloc.construct(&elem[i], val);
	for (int i = newsize; i < sz; i++)
		alloc.destroy(&elem[i]);
	sz = newsize;
}
template<typename T, typename A> void our_vector<T, A>::resize(int newsize, T val) {
	vector_base<T, A>::resize(newsize, val);
}

template<typename T, typename A> void our_vector<T, A>::push_back(T& val) {  		//increase vector size by one; initialize the new element with d
	if (vector_base<T, A>::space == 0)
		reserve(8); 								// start with space for 8 elements
	else if (vector_base<T, A>::sz == vector_base<T, A>::space)
		reserve(2 * vector_base<T, A>::space); 							// get more space
	vector_base<T, A>::alloc.construct(&vector_base<T, A>::elem[vector_base<T, A>::sz], val);
	++vector_base<T, A>::sz; 										// increase the size (sz is the number of elements)
}

template<typename T, typename A> void our_vector<T, A>::print() {
	for (int i = 0; i < vector_base<T, A>::sz; i++) {
		cout << vector_base<T, A>::elem[i] << " ";
	}
	cout << endl;
}

int main() {
	try {
		our_vector<string> p(2);
		p[0] = "first";
		p[1] = "second";

		cout << p.at(3) << endl;
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
	}

	our_vector<double>* n_p = new our_vector<double>();
	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;

	n_p->resize(10);
	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;

	double x = 2;
	n_p->push_back(x);

	cout << n_p->size() << endl;
	cout << n_p->capacity() << endl;
	n_p->print();

	//Copy check
	our_vector<double>* copy_p(n_p);
	cout << copy_p->size() << endl;
	cout << copy_p->capacity() << endl;
	copy_p->print();

	our_vector<double>* copy_assign = copy_p;
	cout << copy_assign->size() << endl;
	cout << copy_assign->capacity() << endl;
	copy_assign->print();



	return 0;
}
