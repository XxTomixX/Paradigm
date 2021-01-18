#include "pch.h"
#include "CppUnitTest.h"
#include "../Bank/Konto.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestKonto
{
	TEST_CLASS(TestKonto1)
	{
	public:
		TEST_METHOD(KontoMetoda1)
		{
			long long int id_test = 999;
			Konto konto("x", "x", id_test, 0.0, false);
			Assert::AreEqual(id_test, konto.get_id());
		}
	};
}
