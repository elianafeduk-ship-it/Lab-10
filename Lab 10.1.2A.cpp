
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spetsialnist
{
    KompiuterniNauky,
    Informatyka,
    MatematykaEkonomika,
    FizykaInformatyka,
    TrudoveNavchannia
};

struct Student
{
    string prizvyshche;
    int kurs;
    Spetsialnist spetsialnist;
    int fizyka;
    int matematyka;
    int informatyka;
};

string spetsialnistStr[] =
{
    "Kompiuterni nauky",
    "Informatyka",
    "Mat. ta ekonomika",
    "Fizyka ta inf.",
    "Trudove navch."
};

void Create(Student* p, const int N);
void Print(const Student* p, const int N);
int CountFivePhysicsMath(const Student* p, const int N);

#ifndef UNIT_TEST
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;

    cout << "Vvedit kilkist studentiv: ";
    cin >> N;

    if (N <= 0)
    {
        cout << "Kilkist studentiv povynna buty bilshe 0!" << endl;
        return 1;
    }

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    int count = CountFivePhysicsMath(p, N);

    cout << "\nKilkist studentiv, yaki otrymaly 5 z fizyky "
        << "ta matematyky: " << count << endl;

    delete[] p;

    return 0;
}
#endif

void Create(Student* p, const int N)
{
    int spets;

    for (int i = 0; i < N; i++)
    {
        cout << "\nStudent No " << i + 1 << ":" << endl;

        cout << "Prizvyshche: ";
        getline(cin >> ws, p[i].prizvyshche);

        cout << "Kurs: ";
        cin >> p[i].kurs;

        cout << "Spetsialnist:" << endl;

        for (int j = 0; j < 5; j++)
            cout << j << " - " << spetsialnistStr[j] << endl;

        cout << "Vash vybir: ";
        cin >> spets;

        while (spets < 0 || spets > 4)
        {
            cout << "Vvedit znachennia vid 0 do 4: ";
            cin >> spets;
        }

        p[i].spetsialnist = (Spetsialnist)spets;

        cout << "Otsinka z fizyky: ";
        cin >> p[i].fizyka;

        cout << "Otsinka z matematyky: ";
        cin >> p[i].matematyka;

        cout << "Otsinka z informatyky: ";
        cin >> p[i].informatyka;
    }
}

void Print(const Student* p, const int N)
{
    cout << "\n";
    cout << "+-----+--------------+-------+----------------------+---------+-------------+--------------+" << endl;
    cout << "| No  | Prizvyshche  | Kurs  | Spetsialnist         | Fizyka  | Matematyka  | Informatyka  |" << endl;
    cout << "+-----+--------------+-------+----------------------+---------+-------------+--------------+" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1;
        cout << " | " << setw(12) << left << p[i].prizvyshche;
        cout << " | " << setw(5) << right << p[i].kurs;
        cout << " | " << setw(20) << left
            << spetsialnistStr[p[i].spetsialnist];
        cout << " | " << setw(7) << right << p[i].fizyka;
        cout << " | " << setw(11) << right << p[i].matematyka;
        cout << " | " << setw(12) << right << p[i].informatyka;
        cout << " |" << endl;
    }

    cout << "+-----+--------------+-------+----------------------+---------+-------------+--------------+" << endl;
}

int CountFivePhysicsMath(const Student* p, const int N)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5 && p[i].matematyka == 5)
            count++;
    }

    return count;
}

