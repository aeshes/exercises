struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : ICloneable
{
	ValueHolder(T const& data) : data_(data) {}
	ICloneable * clone() const
	{
		return new ValueHolder(*this);
	}
	T data_;
};