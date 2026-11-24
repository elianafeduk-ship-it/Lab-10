
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "../Lab 10.1A/Lab 10.1A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab1011A
{
    TEST_CLASS(UnitTestLab1011A)
    {
    public:

        TEST_METHOD(TestCountExcellent)
        {
            Student p[3] =
            {
                {"Ivanenko", 1, KompiuterniNauky, 5, 4, 5},
                {"Petrenko", 2, Informatyka, 4, 5, 5},
                {"Shevchenko", 3, MatematykaEkonomika, 5, 5, 3}
            };

            int fiz = 0;
            int mat = 0;
            int inf = 0;

            CountExcellent(p, 3, fiz, mat, inf);

            Assert::AreEqual(2, fiz);
            Assert::AreEqual(2, mat);
            Assert::AreEqual(2, inf);
        }
    };
}
