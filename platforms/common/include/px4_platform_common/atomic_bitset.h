#pragma once

#include "atomic.h"

namespace gpm
{

template <size_t N>
class AtomicBitset
{
public:

	AtomicBitset() = default;

	size_t count() const
	{
		size_t total = 0;
		for (const auto &x : _data) {
			uint32_t y = x.load();
			while (y) {
				total += y & 1;
				y >>= 1;
			}
		}
		return total;
	}

	size_t size() const { return N; }

	bool operator[](size_t position) const
	{
		return _data[array_index(position)].load() & element_mask(position);
	}

	void set(size_t pos, bool val = true)
	{
		const uint32_t bitmask = element_mask(pos);
		if (val) {
			_data[array_index(pos)].fetch_or(bitmask);
		} else {
			_data[array_index(pos)].fetch_and(~bitmask);
		}
	}

private:
	static constexpr uint8_t BITS_PER_ELEMENT = 32;
	static constexpr size_t ARRAY_SIZE = ((N % BITS_PER_ELEMENT) == 0) ? (N / BITS_PER_ELEMENT) :
                            (N / BITS_PER_ELEMENT + 1);
	static constexpr size_t ALLOCATED_BITS = ARRAY_SIZE * BITS_PER_ELEMENT;

	size_t array_index(size_t position) const { return position / BITS_PER_ELEMENT; }
	uint32_t element_mask(size_t position) const { return (1 << (position % BITS_PER_ELEMENT)); }

	gpm::atomic<uint32_t> _data[ARRAY_SIZE];
};

}
