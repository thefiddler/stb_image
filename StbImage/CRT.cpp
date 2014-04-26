using namespace System;
using namespace System::Runtime::InteropServices;

#define NULL 0

#pragma warning(disable:4483)

void __clrcall __identifier(".cctor")()
{
}

extern "C"
{
	int abs(int n)
	{
		return Math::Abs(n);
	}

	double ldexp(double x, int exp)
	{
		return x * (2 << exp);
	}

	double pow(double x, double y)
	{
		return Math::Pow(x, y);
	}

	void *malloc(size_t bytes)
	{
		return Marshal::AllocHGlobal(IntPtr((long long)bytes)).ToPointer();
	}

	void free(void *ptr)
	{
		Marshal::FreeHGlobal(IntPtr(ptr));
	}

	void *realloc(void *ptr, size_t bytes)
	{
		free(ptr);
		return malloc(bytes);
	}

	void *memcpy(void *dest, const void *src, size_t n)
	{
		while (--n)
		{
			((char*)dest)[n] = ((char*)src)[n];
		}
		return dest;
	}

	void *memset(void *s, int c, size_t n)
	{
		while (--n)
		{
			((char*)s)[n] = (char)c;
		}
		return s;
	}

	int strcmp(const char *s1, const char *s2)
	{
		while (*s1 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		return *(const unsigned char*)s1 - *(const unsigned char*)s2;
	}

	int strncmp(const char* s1, const char* s2, size_t n)
	{
		while (n--)
		{
			if (*s1++ != *s2++)
				return *(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1);
		}
		return 0;
	}

	unsigned long _lrotr(unsigned long value, int shift);
	unsigned long _lrotl(unsigned long value, int shift);

	unsigned long _lrotr(unsigned long value, int shift)
	{
		int max_bits = sizeof(unsigned long) << 3;
		if (shift < 0)
			return _lrotl(value, -shift);

		if (shift > max_bits)
			shift = shift % max_bits;
		return (value >> shift) | (value << (max_bits - shift));
	}

	unsigned long _lrotl(unsigned long value, int shift)
	{
		int max_bits = sizeof(unsigned long) << 3;
		if (shift < 0)
			return _lrotr(value, -shift);
		if (shift > max_bits)
			shift = shift % max_bits;
		return (value << shift) | (value >> (max_bits - shift));
	}

	void _wassert(const wchar_t *msg, const wchar_t *file, unsigned line)
	{
	}
}
