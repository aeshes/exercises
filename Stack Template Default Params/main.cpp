#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <functional>

#include "stack_template.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main()
{
	try
	{
		Stack<int> st;
		st.push(1);
		cout << st.top() << endl;

		st.pop();
		st.pop();
	}
	catch (std::exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
		return EXIT_FAILURE;
	}

	return 0;
}