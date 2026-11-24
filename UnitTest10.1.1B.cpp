
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "../Lab10.1.1B/Lab10.1.1B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1011B
{
    TEST_CLASS(UnitTest1011B)
    {
    public:

        TEST_METHOD(TestCountExcellent)
        {
            Student p[3];

            p[0].spetsialnist = KompiuterniNauky;
            p[0].fizyka = 5;
            p[0].matematyka = 4;
            p[0].programuvannia = 5;

            p[1].spetsialnist = Informatyka;
            p[1].fizyka = 4;
            p[1].matematyka = 5;
            p[1].chyselniMetody = 5;

            p[2].spetsialnist = MatematykaEkonomika;
            p[2].fizyka = 5;
            p[2].matematyka = 5;
            p[2].pedahohika = 5;

            int fiz = 0;
            int mat = 0;
            int prog = 0;
            int chys = 0;
            int ped = 0;

            CountExcellent(p, 3, fiz, mat, prog, chys, ped);

            Assert::AreEqual(2, fiz);
            Assert::AreEqual(2, mat);
            Assert::AreEqual(1, prog);
            Assert::AreEqual(1, chys);
            Assert::AreEqual(1, ped);
        }
    };
}
