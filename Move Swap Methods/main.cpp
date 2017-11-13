#include <utility>

template<class T>
struct Array
{
    // все объявленные ниже методы уже реализованы
    explicit Array(size_t size = 0);
    Array(Array const& a);
    Array & operator=(Array const& a);
    ~Array();

    size_t size() const;
    T &         operator[](size_t i);
    T const&    operator[](size_t i) const;
    void swap(Array & other);

    // реализуйте перемещающий конструктор
    Array(Array && other)
        : size_(0), data_(nullptr)
    {
        swap(other);
    }

    // реализуйте перемещающий оператор присваивания
    Array & operator=(Array && other)
    {
        swap(other);
        return *this;
    }

private:    
    size_t  size_;
    T *     data_;    
};

template <typename T>
void Array<T>::swap(Array & other)
{
    using std::swap;
    swap(size_, other.size_);
    swap(data_, other.data_);
}