// Array may be: Array<int>, Array<double>, ..., Array<Array<T>>, ...
// Print all elements in subarrays

template <typename T>
void flatten(const T& t, std::ostream& out)
{
    out << t << ' ';
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out)
{
    for (size_t i = 0; i < array.size(); ++i)
        flatten(array[i], out);
}