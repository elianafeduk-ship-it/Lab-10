
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

// Perelik spetsialnostei
enum Spetsialnist
{
    KompiuterniNauky,
    Informatyka,
    MatematykaEkonomika,
    FizykaInformatyka,
    TrudoveNavchannia
};

string spetsialnistStr[] =
{
    "Kompiuterni nauky",
    "Informatyka",
    "Matematyka i ekonomika",
    "Fizyka i informatika",
    "Trudove navchannia"
};

// Struktura studenta
struct Student
{
    string prizvyshche;
    int kurs;
    Spetsialnist spetsialnist;
    int fizyka;
    int matematyka;

    union
    {
        int programuvannia;
        int chyselniMetody;
        int pedahohika;
    };
};

// Funktsiia vvedennia danykh
void Create(Student* p, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Prizvyshche: ";
        cin >> p[i].prizvyshche;

        cout << "Kurs: ";
        cin >> p[i].kurs;

        cout << "\nSpetsialnist:" << endl;
        cout << "0 - Kompiuterni nauky" << endl;
        cout << "1 - Informatyka" << endl;
        cout << "2 - Matematyka i ekonomika" << endl;
        cout << "3 - Fizyka i informatika" << endl;
        cout << "4 - Trudove navchannia" << endl;
        cout << "Vash vybir: ";

        int s;
        cin >> s;

        while (s < 0 || s > 4)
        {
            cout << "Pomylka! Vvedit vid 0 do 4: ";
            cin >> s;
        }

        p[i].spetsialnist = (Spetsialnist)s;

        cout << "Obrana spetsialnist: "
            << spetsialnistStr[p[i].spetsialnist] << endl;

        cout << "Otsinka z fizyky: ";
        cin >> p[i].fizyka;

        cout << "Otsinka z matematyky: ";
        cin >> p[i].matematyka;

        switch (p[i].spetsialnist)
        {
        case KompiuterniNauky:
            cout << "Otsinka z programuvannia: ";
            cin >> p[i].programuvannia;
            break;

        case Informatyka:
            cout << "Otsinka z chyselnykh metodiv: ";
            cin >> p[i].chyselniMetody;
            break;

        default:
            cout << "Otsinka z pedahohiky: ";
            cin >> p[i].pedahohika;
            break;
        }
    }
}


void Print(const Student* p, const int N)
{
    cout << "\n";

    cout << "+----+-------------+----+----------------------+-----+-----+------+--------+----------+" << endl;

    cout << "| " << setw(2) << left << "No"
        << " | " << setw(11) << left << "Prizvyshche"
        << " | " << setw(2) << left << "K"
        << " | " << setw(20) << left << "Spetsialnist"
        << " | " << setw(3) << left << "Fiz"
        << " | " << setw(3) << left << "Mat"
        << " | " << setw(4) << left << "Prog"
        << " | " << setw(6) << left << "Chys."
        << " | " << setw(8) << left << "Ped."
        << " |" << endl;

    cout << "+----+-------------+----+----------------------+-----+-----+------+--------+----------+" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1
            << " | " << setw(11) << left << p[i].prizvyshche
            << " | " << setw(2) << right << p[i].kurs
            << " | " << setw(20) << left << spetsialnistStr[p[i].spetsialnist]
            << " | " << setw(3) << right << p[i].fizyka
            << " | " << setw(3) << right << p[i].matematyka;

        if (p[i].spetsialnist == KompiuterniNauky)
        {
            cout << " | " << setw(4) << right << p[i].programuvannia
                << " | " << setw(6) << right << "-"
                << " | " << setw(8) << right << "-";
        }
        else if (p[i].spetsialnist == Informatyka)
        {
            cout << " | " << setw(4) << right << "-"
                << " | " << setw(6) << right << p[i].chyselniMetody
                << " | " << setw(8) << right << "-";
        }
        else
        {
            cout << " | " << setw(4) << right << "-"
                << " | " << setw(6) << right << "-"
                << " | " << setw(8) << right << p[i].pedahohika;
        }

        cout << " |" << endl;
    }

    cout << "+----+-------------+----+----------------------+-----+-----+------+--------+----------+" << endl;
}


// Funktsiia pidrakhuvannia studentiv
int CountFivePhysicsMath(const Student* p, const int N)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5 && p[i].matematyka == 5)
        {
            count++;
        }
    }

    return count;
}

#ifndef UNIT_TEST
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;

    cout << "Vvedit kilkist studentiv: ";
    cin >> N;

    while (N <= 0)
    {
        cout << "Kilkist maie buty bilshe 0. Vvedit znovu: ";
        cin >> N;
    }

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    int result = CountFivePhysicsMath(p, N);

    cout << "\nKilkist studentiv, yaki otrymaly 5 z fizyky "
        << "ta matematyky: " << result << endl;

    delete[] p;

    return 0;
}
#endif


