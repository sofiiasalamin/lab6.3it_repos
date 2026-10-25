#include "pch.h"
#include "CppUnitTest.h"
#include "../6,3іт/6,3іт.cpp" 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsIterative
{
	
	template <typename F>
	string Capture(F func)
	{
		ostringstream out;
		streambuf* old = cout.rdbuf(out.rdbuf()); 
		func();                                   
		cout.rdbuf(old);                          
		return out.str();
	}

	TEST_CLASS(PrintIterativeTests)
	{
	public:

		
		TEST_METHOD(Print_Int_Ordinary)
		{
			int a[3] = { 1, 2, 3 };
			string result = Capture([&]() { Print(a, 3); });
			Assert::AreEqual(string("1 2 3 \n"), result);
		}

		
		TEST_METHOD(Print_Int_Template)
		{
			int a[3] = { 1, 2, 3 };
			string result = Capture([&]() { Print<int>(a, 3); });
			Assert::AreEqual(string("1 2 3 \n"), result);
		}
		
		TEST_METHOD(Print_EmptyArray)
		{
			int a[1] = { 0 };
			string result = Capture([&]() { Print(a, 0); });
			Assert::AreEqual(string("\n"), result);
		}

		
		TEST_METHOD(Print_DoesNotModifyArray)
		{
			int a[3] = { 4, 5, 6 };
			Capture([&]() { Print(a, 3); });
			Assert::AreEqual(4, a[0]);
			Assert::AreEqual(5, a[1]);
			Assert::AreEqual(6, a[2]);
		}
	};
}