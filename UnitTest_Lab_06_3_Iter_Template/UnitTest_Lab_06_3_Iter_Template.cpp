#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_3_Iter_Template/Lab_06_3_Iter_Template.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template <typename R>
void Test(R* a, R* c, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		R min = c[i];
		int imin = i;
		for (int j = i + 1; j < size; j++)
			if (min > c[j])
			{
				min = c[j];
				imin = j;
			}
		c[imin] = c[i];
		c[i] = min;
	}
	for (int i = 0; i < size; i++)
		Assert::AreEqual(a, c);
}

namespace UnitTestLab063Iter
{
	TEST_CLASS(UnitTestLab063Iter)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int c[n];
			int Low = -10, High = 10;
			Create(c, n, Low, High);
			int* a = Sort(c, n);
			Test(a, c, n);
		}
	};
}