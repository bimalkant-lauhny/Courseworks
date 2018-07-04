#include <bits/stdc++.h> 
using namespace std;
template <typename T> struct Maybe;

// this is a Maybe object factory
template <typename T> Maybe<T> maybe(T* context)
{
	return Maybe<T>(context);
}

template <typename T> struct Maybe
{
	T* context;
	explicit Maybe (T* const context)
		: context{context}
	{}

	template <typename Func>
	auto With(Func evaluator) 
	{
		if (context == nullptr)	 
		{
			return Maybe<typename remove_pointer<decltype(evaluator(context))>::type>(nullptr);
		}
		else 
		{
			return maybe(evaluator(context));
		}
	}

	template <typename Func>
	auto Do(Func action)
	{
		if (context != nullptr)	
			action(context);
		return *this;
	}
};


struct Address
{
	/** 
	* address may or may not have house name, therefore a string pointer
	* initialized to nullptr
	*/
	string* house_name = nullptr;
};

struct Person
{ 
	/** 
	* Person may or may not have an address, therefore an Address pointer
	* initialized to nullptr
	*/
	Address* address = nullptr;	
};

void print_house_name(Person* p) {
	/**
	*This way of checking whethere p is initialized or not is bad!
	*/
	/* if (p != nullptr && p->address != nullptr && p->address->house_name != nullptr)
	{
		cout <<	*(p->address->house_name) << endl;
	}*/ 
 
	/**
	* Now we want a Maybe object here
	* But, we cannot simply write -
	*		Maybe(p)
	* reason being the type has to be explicitly supplied.
	*		Maybe <Person> (p)
	* but we want auto type deduction! Therefore we generally come across 
	* make() factory functions. So we've declare a maybe() factory function
	* for producing Maybe objects.
	*/
	maybe(p)
		.With([](auto x) { return x->address;})
		.With([](auto x) { return x->house_name;})
		.Do([](auto x) { cout << *x << endl;});
} 

int main(void)
{
	Person p;
	p.address = new Address;
	p.address->house_name = new string ("362 RA Bazar");
	print_house_name(&p);
	delete p.address->house_name;
	delete p.address;
	return 0;
}