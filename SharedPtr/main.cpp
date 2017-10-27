#include <iostream>
#include <vector>
#include <algorithm>


class Expression
{

};

class SharedPtr
{
public:
	explicit SharedPtr(Expression * ptr = 0);
	~SharedPtr();
	SharedPtr(SharedPtr const&);
	SharedPtr & operator=(SharedPtr const&);

	Expression * get() const;
	Expression * release();
	void reset(Expression * ptr = 0);
	void swap(SharedPtr & ptr);

	Expression & operator*() const;
	Expression * operator->() const;

private:
	Expression * ptr;
	mutable std::size_t *count;

	void free();
};

SharedPtr::SharedPtr(Expression * ptr)
	: ptr(ptr), count(new std::size_t(1))
{

}

SharedPtr::~SharedPtr()
{
	free();
}

SharedPtr::SharedPtr(SharedPtr const& other)
	: ptr (other.ptr), count(other.count)
{
	++*other.count;
}

SharedPtr & SharedPtr::operator=(SharedPtr const& other)
{
	SharedPtr(other).swap(*this);
	return *this;
}

Expression * SharedPtr::get() const
{
	return ptr;
}

Expression * SharedPtr::release()
{
	Expression *tmp = ptr;
	free();
	ptr = 0;
	return tmp;
}

void SharedPtr::reset(Expression * ptr)
{
	SharedPtr(ptr).swap(*this);
}

void SharedPtr::swap(SharedPtr & other)
{
	using std::swap;
	swap(ptr, other.ptr);
	swap(count, other.count);
}

Expression & SharedPtr::operator*() const
{
	return *ptr;
}

Expression * SharedPtr::operator->() const
{
	return ptr;
}

void SharedPtr::free()
{
	if (--*count == 0)
	{
		delete count;
		delete ptr;
	}
}


int main()
{
	SharedPtr ptr(0);
	SharedPtr rtp(new Expression);
	ptr = ptr;
	ptr = rtp;
	ptr.reset(0);
	ptr.release();