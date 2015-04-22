#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Stack.h"
#include "../Queue.h"
#include "../Trees.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		// ----------------------------
		//            STACK
		// -----------------------------

		TEST_METHOD(StackDefaultConstr)
		{
			Stack<char> s;

			s.push('A');
			s.push('B');
			s.push('C');
			
			char ret;
			Assert::IsTrue(s.pop(ret));
			Assert::AreEqual(ret, 'C');
			Assert::IsTrue(s.pop(ret));
			Assert::AreEqual(ret, 'B');
			Assert::IsTrue(s.pop(ret));
			Assert::AreEqual(ret, 'A');
		}

		TEST_METHOD(StackConstrMemo)
		{
			Stack<char> s(2);

			s.push('A');
			s.push('B');
			s.push('C');

			char ret;
			Assert::IsTrue(s.pop(ret));
			Assert::AreEqual(ret, 'C');
			Assert::IsTrue(s.pop(ret));
			Assert::AreEqual(ret, 'B');
			Assert::IsTrue(s.pop(ret));
			Assert::AreEqual(ret, 'A');
		}

		TEST_METHOD(StackPushPop)
		{
			Stack<int> s(50);
				
			for (int i = 0; i < 1000; i++)
				s.push(i); 

			Assert::AreEqual(s.getElements(), (unsigned)1000);

			int ret;
			for (int i = 999; i >= 0; i--)
			{
				Assert::IsTrue(s.pop(ret));
				Assert::AreEqual(ret, i);
			}

			Assert::AreEqual(s.getElements(), (unsigned)0);

			for (int i = 0; i < 10; i++)
			{
				Assert::IsFalse(s.pop(ret));
				Assert::AreEqual(ret, 0);
			}	
		}

		TEST_METHOD(StackPeek)
		{
			Stack<int> s(50);

			for (int i = 0; i < 100; i++)
				s.push(i);

			for (int i = 0; i < 100; i++)
				Assert::AreEqual(s.peek(i), i);
		}

		// ----------------------------
		//            QUEUE
		// -----------------------------


		//}
		//TEST_METHOD(QueueGeneralTest)
		//{
		//	// We test various codes.
		//	Queue<int> s;

		//	s.push(1);
		//	s.push(2);
		//	s.push(3);

		//	Assert::AreEqual(s.peek(0), 1);
		//	Assert::AreEqual(s.peek(1), 2);
		//	Assert::AreEqual(s.peek(2), 3);

		//	int ret;
		//	Assert::IsTrue(s.pop(ret));
		//	Assert::AreEqual(ret, 1);
		//	Assert::IsTrue(s.pop(ret));
		//	Assert::AreEqual(ret, 2);
		//	Assert::IsTrue(s.pop(ret));
		//	Assert::AreEqual(ret, 3);
		//	Assert::IsFalse(s.pop(ret));
		//	Assert::AreEqual(ret, 3);
		//}
		//TEST_METHOD(TreesGeneralTest)
		//{
		//	Trees<int> tree(88);

		//	tree.add(99);
		//}

	};
}