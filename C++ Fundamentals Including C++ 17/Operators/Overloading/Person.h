#include <string>
class Person
{
private:
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;
    
    /*
    operator< is defined as a friend function of Person
    a friend function is allowed to access private variables of Person
    TIP: It's better to use a non friend function and access the variables using
    Public member functions.
    */
    //friend bool operator<(int i, Person const& p)

public:
	Person(std::string first,
		std::string last,
		int arbitrary);
	~Person();
	std::string GetName() const;
	int GetNumber() const {return arbitrarynumber;}
	void SetNumber(int number) {arbitrarynumber = number;}
    
    /* overloading operator <
    The Person has to be compared with another instance of Person
    ex. p1 < p2*/
	bool operator<(Person const& p) const;
    
    /*Person has to be compared with int, ex. p < 300*/
	bool operator<(int i) const;
	

};

/*a free function to overload <
Used in cases like 300 < p
note that here, 300 comes first before p, which cannot be accomplished using a member function*/
bool operator<(int i, Person const& p);
