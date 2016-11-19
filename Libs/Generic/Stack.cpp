
template <class T>
struct Stack {
    Array<T> Data;
    size_t Count;

    T &operator [](size_t i) { return Data[i]; }

    T &Current() { return Data[Count - 1]; }

	T *Index_ptr() { return &Data[Count]; }

    Stack(size_t Length) : Data(Length) { Count = 0; }

	bool isFull()  { return (Count >= Data.Length); }
	bool isEmpty() { return (Count == 0); }

    bool Add(T item)
    {
        if (isFull()) return false;
        
        Data[Count++] = item;
        return true;
    }

    bool Remove()
    {
        if (isEmpty()) return false;

        Count--;
        return true;
    }
};
