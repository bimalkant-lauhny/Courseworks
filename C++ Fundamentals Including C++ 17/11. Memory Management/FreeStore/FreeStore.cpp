// FreeStore.cpp : Defines the entry point for the console application.
//

#include "Resource.h"
#include <string>
using std::string;

int main()
{
	/*
	As given below, we may use stack variables. As localResource go out of scope,
	it's destructor goes off and cleans the memory.
	*/
	{
		Resource localResource ("local");
		string localString = localResource.GetName();
	}
	
	Resource* pResource = new Resource("created with new");
	string newString = pResource->GetName();
	int j =3;
	if (j == 3)
	{
		return 0;
	}
	
	// Disadvantages of using old styles of memory management
	
	/*
	Disadv 1: pResource will still be available even after deleting it.
	Program behaves badly if we try to access some member of the pResource
	after deleting it.
	*/
	
	/*
	Disadv 2: If we copied the pointer to Resource("created with new") from 
	pResource to p2, and, we deleted pResource, but try to access any member 
	using p2, bad things happen.
	*/

	/*
	Disadv 3: If we try to delete things twice, bad things happen. Here, for ex, 
	we may delete pResource twice, or, we may delete pResource once and the 
	delete p2.
	*/

	/*
	Disadv 4: If we created an object using new and the control never reached 
	the line where we delete the pointer to the object, there will be memory
	leaks. Ex, given above, we might check some condition for variable j, and we
	may decide to quit if condition met, but, control never reached the line
	where we delete pResource!
	*/

	Resource* p2 = pResource;

	delete pResource;
	pResource = nullptr;
	//string string2 = p2->GetName();
	delete pResource;
	delete p2;

	//string string3 = pResource->GetName();

	return 0;
}

