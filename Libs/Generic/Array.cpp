// Note: Templates (like the following) are only available when the file is #included not compiled.
//       This is not a problem when doing a unity build.

template <class T>
struct Array {
private:
	const bool owned;
public:
    const size_t Length;
    T* const Raw;

    T& operator [](size_t i)
    {
        return Raw[i];
    }

    bool operator ==(Array<T> &OtherArray)
    {
        size_t minLen = Math::min(Length, OtherArray.Length);
        for (size_t i = 0; i < minLen; i++) {
            if (Raw[i] != OtherArray.Raw[i]) return false;
        }
        return true;
    }

    Array(size_t Size, T Raw[])
        : Length(Size), Raw(Raw), owned(false)
    {}

    Array(size_t Size)
        : Length(Size), Raw(new T[Size]), owned(true)
    {}

	~Array() { if (owned) delete Raw; }

    void Fill(T value)
    {
        for (size_t i = 0; i < Length; i++) Raw[i] = value;
    }
};
