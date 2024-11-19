#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			string s = "abcdefg";

			int result = CountVowels(s);

			Assert::AreEqual(2, result); 
		}
	};
}
