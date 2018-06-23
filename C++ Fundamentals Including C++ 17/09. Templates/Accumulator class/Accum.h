#pragma once
template <class T>
class Accum
{
private: 
	T total;
public:
	Accum(T start): total(start) {};
    /*overloading '+=' to accumulate into total*/
	T operator+=(T const& t){return total = total + t;};
	T GetTotal() const {return total;}
};

/*Template Specialization for Person type*/
/*
For Person type, the Accum should accumulate the arbitrarynumber
This is different behaviour as compared to generic Accum class, hence,
from design point of view, it is better to define a specialized Accum
class for Person type
*/
template <>
class Accum<Person>
{
private:
	int total;
public:
	Accum(int start) : total(start) {};
	int operator+=(Person const& t) { return total = total + t.GetNumber(); };
	int GetTotal() const { return total; }
};
