
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "../Lab 10.1.2A/Lab 10.1.2A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1013A
{
    TEST_CLASS(UnitTest1013A)
    {
    public:

        TEST_METHOD(TestCountFivePhysicsMath)
        {
            Student p[4] =
            {
                {"Ivanenko", 1, KompiuterniNauky, 5, 5, 4},
                {"Petrenko", 2, Informatyka, 5, 4, 5},
                {"Shevchenko", 3, MatematykaEkonomika, 4, 5, 5},
                {"Kovalenko", 2, FizykaInformatyka, 5, 5, 5}
            };

            int result = CountFivePhysicsMath(p, 4);

            Assert::AreEqual(2, result);
        }
    };
}

