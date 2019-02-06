#include "TDynamicArray.h"

using namespace JWENGINE;

struct SPerson
{
	wchar_t name[20];
	int age;

	SPerson()
	{
		memset(name, 0, 20);
		age = 0;
	};

	SPerson(const wchar_t* _name, int _age)
	{
		memcpy(name, _name, 20);
		age = _age;
	};
};

int main()
{
	SPerson me;
	SPerson my_gf;
	SPerson first;
	SPerson last;
	TDynamicArray<SPerson> test_da;

	// @ WARNING:
	// This line below WILL throw an error,
	// because TDynamicArray has no data yet.
	//first = test_da[0];

	test_da.push_back(SPerson(L"Alejandra", 26));

	my_gf = test_da[0];

	test_da.push_back(SPerson(L"Jesus", 29));

	me = test_da[1];

	test_da.push_back(SPerson(L"Tommy", 6));

	test_da.push_back(SPerson(L"Sara", 24));

	test_da.pop_back();

	test_da.push_back(SPerson(L"Sofia", 29));

	test_da.pop_back();

	test_da.empty();

	test_da.push_back(SPerson(L"Lucas", 28));

	// @ WARNING:
	// This line below will NOT throw an error
	// becuase when an index value that exceeds the size of the dynamic array,
	// TDynamicArray automatically change it to the index value that indicates
	// the last element of the dynamic array.
	last = test_da[100];

	test_da.clear();

	// @ WARNING:
	// This line below WILL throw an error,
	// because TDynamicArray has no data again.
	//test_da[0] = me;

	system("pause");

	return 0;
}