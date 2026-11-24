
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "../Lab 10.1.2B/Lab 10.1.2B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1014B
{
    TEST_CLASS(UnitTest1014B)
    {
    public:

        TEST_METHOD(TestCountFivePhysicsMath)
        {
            Student p[4];

            p[0].spetsialnist = KompiuterniNauky;
            p[0].fizyka = 5;
            p[0].matematyka = 5;
            p[0].programuvannia = 4;

            p[1].spetsialnist = Informatyka;
            p[1].fizyka = 5;
            p[1].matematyka = 4;
            p[1].chyselniMetody = 5;

            p[2].spetsialnist = MatematykaEkonomika;
            p[2].fizyka = 4;
            p[2].matematyka = 5;
            p[2].pedahohika = 4;

            p[3].spetsialnist = FizykaInformatyka;
            p[3].fizyka = 5;
            p[3].matematyka = 5;
            p[3].pedahohika = 5;

            int result = CountFivePhysicsMath(p, 4);

            Assert::AreEqual(2, result);
        }
    };
}
