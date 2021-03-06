// Generic pointer to a bit in a u32
struct BitPointer
{
    u32* Register;
    u32 BitMask;

	BitPointer(u32* Register, u32 BitMask) : Register(Register), BitMask(BitMask) {}
	BitPointer() : BitPointer(nullptr, 0) {}

    u32 Get()
    {
        return (*Register) & BitMask;
    }
    void Set()
    {
        (*Register) |= BitMask;
    }
    void Clear()
    {
        (*Register) &= ~BitMask;
    }
    void Apply(u32 Value)
    {
        if (Value) Set();
        else Clear();
    }
};

// Bits in bundles of 32
struct Bits
{
    const size_t Length;
    Array<u32> Raw;

    Bits(size_t Length)
        : Length(Length), Raw(upperdiv(Length, 32))
    {}

    BitPointer GetPointer(const size_t Index)
    {
        return BitPointer(&(Raw[Index / 32]), (1 << (Index % 32)));
    }

    u32 Get(const size_t Index)
    {
        return GetPointer(Index).Get();
    }

    void SetAll()
    {
        Raw.Fill(~0);
    }
    void ClearAll()
    {
        Raw.Fill(0);
    }

    void Set(const size_t Index)
    {
        GetPointer(Index).Set();
    }
    void Clear(const size_t Index)
    {
        GetPointer(Index).Clear();
    }
    void Apply(const size_t Index, u32 Value)
    {
        GetPointer(Index).Apply(Value);
    }
};
