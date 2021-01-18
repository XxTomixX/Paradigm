#include "pch.h"
#include "CppUnitTest.h"
#include "../Bank/Lokata.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
    TEST_CLASS(UnitTest3)
    {
    public:
        TEST_METHOD(LokataMetoda1)
        {
            string t = "typ";
            double k = 0.0;
            int op = 5;
            long long id = 999;
            Lokata lok(t, k, op, id);
            Assert::AreEqual(id, lok.get_id());
        }
    };
}

// Lokata(string typ = "",double kwo = 0, int opr = 0, long long  int id_lo = 0):typ_lokaty(typ),kwota(kwo),oprocentowanie(opr),id_lokaty(id_lo){}