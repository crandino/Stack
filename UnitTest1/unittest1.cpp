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
			Stack<int> s5(5);
			Stack<float> s0;
			
			s5.push(1);
			s5.push(2);
			s5.push(3);
			s5.push(4);
			s5.push(5);
			s5.push(6);

			Assert::AreEqual(s5.peek(0), 1);
			Assert::AreEqual(s5.peek(1), 2);
			Assert::AreEqual(s5.peek(2), 3);
			Assert::AreEqual(s5.peek(4), 5);
			Assert::AreEqual(s5.peek(5), 6);
			
			Assert::AreEqual(s5.pop(), 6);
			Assert::AreEqual(s5.pop(), 5);
			Assert::AreEqual(s5.pop(), 4);
			Assert::AreEqual(s5.pop(), 3);
			Assert::AreEqual(s5.pop(), 2);
			Assert::AreEqual(s5.pop(), 1);
			Assert::AreEqual(s5.pop(), -1);

			s0.push(1.0f);
			s0.push(2.0f);
			s0.push(3.0f);
			s0.push(4.0f);
		
			Assert::AreEqual(s0.pop(), 4.0f);
			Assert::AreEqual(s0.pop(), 3.0f);
			Assert::AreEqual(s0.pop(), 2.0f);
			Assert::AreEqual(s0.pop(), 1.0f);
			Assert::AreEqual(s0.pop(), -1.0f);




		}

		//TEST_METHOD(StackGeneralTest)
		//{
		//	// We test various codes.
		//	Stack<int> s(5);

		//	s.push(1);
		//	s.push(2);
		//	s.push(3);

		//	Assert::AreEqual(s.peek(2), 3);

		//	Assert::AreEqual(s.pop(), 3);
		//	Assert::AreEqual(s.pop(), 2);
		//	Assert::AreEqual(s.pop(), 1);
		//}

		//TEST_METHOD(QueueGeneralTest)
		//{
		//	// We test various codes.
		//	Queue<int> s;

		//	s.push(1);
		//	s.push(2);
		//	s.push(3);

		//	Assert::AreEqual(s.peek(2), 3);

		//	Assert::AreEqual(s.pop(), 1);
		//	Assert::AreEqual(s.pop(), 2);
		//	Assert::AreEqual(s.pop(), 3);
		//}

	};
}