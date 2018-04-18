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
		Stack<double> st;
		st.push(1.0);

		Stack<int> st2;
		st2 = st;
	}
	catch (std::exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
		return EXIT_FAILURE;
	}

	return 0;
}