#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Stack.h"
#include "../Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(StackGeneralTest)
		{
			// We test various codes.
			Stack<int> s(5);

			s.push(1);
			s.push(2);
			s.push(3);

			Assert::AreEqual(s.peek(2), 3);

			Assert::AreEqual(s.pop(), 3);
			Assert::AreEqual(s.pop(), 2);
			Assert::AreEqual(s.pop(), 1);
		}

		TEST_METHOD(QueueGeneralTest)
		{
			// We test various codes.
			Queue<int> s;

			s.push(1);
			s.push(2);
			s.push(3);

			Assert::AreEqual(s.peek(2), 3);

			Assert::AreEqual(s.pop(), 1);
			Assert::AreEqual(s.pop(), 2);
			Assert::AreEqual(s.pop(), 3);
		}

	};
}