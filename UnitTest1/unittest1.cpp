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
				Assert::AreEqual(*s.peek(i), i);
		}

		// ----------------------------
		//            QUEUE
		// -----------------------------

		TEST_METHOD(QueuePush)
		{
			Queue<int> q;

			for (int i = 0; i < 100; i++)
				q.push(i);

			int ret;
			for (int i = 0; i < 100; i++)
			{
				q.pop(ret);
				Assert::AreEqual(ret, i);
			}

			for (int i = 0; i < 100; i++)
			{
				q.pop(ret);
				Assert::AreEqual(ret, 99);
			}
		}

		TEST_METHOD(QueueCount)
		{
			Queue<int> q;

			for (int i = 0; i < 100 ; i++)
				q.push(i);

			Assert::AreEqual(q.count(), (unsigned) 100);

			int ret;
			for (unsigned int i = 99; i > 0; i--)
			{
				q.pop(ret);
				Assert::AreEqual(q.count(), i);
			}

			for (unsigned int i = 0; i < 10 ; i++)
			{
				q.pop(ret);
				Assert::AreEqual(q.count(), (unsigned) 0);
			}
		}

		TEST_METHOD(QueuePeek)
		{
			Queue<int> q;

			for (int i = 0; i < 100; i++)
				q.push(i);

			for (int i = 0; i < 100; i++)
				Assert::AreEqual(*(q.peek(i)), i);		
		}

		TEST_METHOD(QueueClear)
		{
			Queue<int> q;

			for (int i = 0; i < 100; i++)
				q.push(i);

			Assert::AreEqual(q.count(), (unsigned) 100);

			q.clear();

			Assert::AreEqual(q.count(), (unsigned) 0);


		}

		// ----------------------------
		//            QUEUE
		// -----------------------------

		TEST_METHOD(Queue2Push)
		{
			Queue2<int> q;

			for (int i = 0; i < 100; i++)
				q.push(i);

			int ret;
			for (int i = 0; i < 100; i++)
			{
				q.pop(ret);
				Assert::AreEqual(ret, i);
			}

			for (int i = 0; i < 100; i++)
			{
				q.pop(ret);
				Assert::AreEqual(ret, 99);
			}
		}

		TEST_METHOD(Queue2Count)
		{
			Queue2<int> q;

			for (int i = 0; i < 100; i++)
				q.push(i);

			Assert::AreEqual(q.count(), (unsigned)100);

			int ret;
			for (unsigned int i = 99; i > 0; i--)
			{
				q.pop(ret);
				Assert::AreEqual(q.count(), i);
			}

			for (unsigned int i = 0; i < 10; i++)
			{
				q.pop(ret);
				Assert::AreEqual(q.count(), (unsigned)0);
			}
		}

	};
}