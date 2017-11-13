struct Unit
{
	unsigned id() const { return 1; }
	unsigned hp;
};

template<typename T,  typename RetType>
bool compare(T const& a, T const& b, RetType (T::*mptr)() const)
{
	return (a.*mptr)() < (b.*mptr)();
}

int main()
{
	Unit u, v;
	std::cout << compare(u, v, &Unit::id);
}