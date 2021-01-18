#include "pch.h"
#include "CppUnitTest.h"
#include "../Bank/Blad.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:
        TEST_METHOD(BladMetoda1)
        {
            string t = "x";
            string d = "xy";
            string tm = "xyz";
            unsigned long int id = 999;
            bool n = 0;
            Blad blad(t, d, id, n, tm);
            Assert::AreEqual(id, blad.get_id());
        }
    };
}