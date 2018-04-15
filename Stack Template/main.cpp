#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <functional>

#include "stack_template.h"

using std::cin;
using std::cout;
using std::endl;


int main()
{
	Stack<int> st;
	st.push(0);
	st.push(1);
	st.push(2);

	cout << st.top() << endl;

	return 0;
}