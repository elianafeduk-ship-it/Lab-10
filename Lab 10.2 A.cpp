
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
    int informatyka;
};

// Funktsiia vvedennia danykh
void Create(Student* p, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Vvedit prizvyshche: ";
        cin >> p[i].prizvyshche;

        cout << "Vvedit kurs: ";
        cin >> p[i].kurs;

        cout << "\nOberit spetsialnist:" << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << j << " - " << spetsialnistStr[j] << endl;
        }

        int s;
        cout << "Vash vybir (0-4): ";
        cin >> s;

        while (s < 0 || s > 4)
        {
            cout << "Pomylka! Vvedit chislo vid 0 do 4: ";
            cin >> s;
        }

        p[i].spetsialnist = (Spetsialnist)s;

        cout << "Obrana spetsialnist: "
            << spetsialnistStr[s] << endl;

        cout << "\nVvedit otsinky vid 2 do 5:" << endl;

        cout << "Fizyka: ";
        cin >> p[i].fizyka;

        while (p[i].fizyka < 2 || p[i].fizyka > 5)
        {
            cout << "Pomylka! Vvedit otsinku vid 2 do 5: ";
            cin >> p[i].fizyka;
        }

        cout << "Matematyka: ";
        cin >> p[i].matematyka;

        while (p[i].matematyka < 2 || p[i].matematyka > 5)
        {
            cout << "Pomylka! Vvedit otsinku vid 2 do 5: ";
            cin >> p[i].matematyka;
        }

        cout << "Informatyka: ";
        cin >> p[i].informatyka;

        while (p[i].informatyka < 2 || p[i].informatyka > 5)
        {
            cout << "Pomylka! Vvedit otsinku vid 2 do 5: ";
            cin >> p[i].informatyka;
        }
    }
}

// Funktsiia obchyslennia serednoho balu
double Average(const Student& s)
{
    return (s.fizyka + s.matematyka + s.informatyka) / 3.0;
}

// Funktsiia porivniannia studentiv
bool Compare(const Student& a, const Student& b)
{
    if (Average(a) != Average(b))
        return Average(a) < Average(b);

    if (spetsialnistStr[a.spetsialnist] !=
        spetsialnistStr[b.spetsialnist])
        return spetsialnistStr[a.spetsialnist] <
        spetsialnistStr[b.spetsialnist];

    return a.prizvyshche < b.prizvyshche;
}

// Funktsiia fizychnoho vporyadkuvannia
void Sort(Student* p, const int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (Compare(p[j + 1], p[j]))
            {
                Student temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}


// Funktsiia vyvedennia danykh
void Print(const Student* p, const int N)
{
    cout << "\n";
    cout << "                              SPYSOK STUDENTIV" << endl;

    cout << "+----+----------------+------+--------------------------+-----+-----+-----+--------+" << endl;
    cout << "| No | Prizvyshche    | Kurs | Spetsialnist             | Fiz | Mat | Inf | Ser.   |" << endl;
    cout << "+----+----------------+------+--------------------------+-----+-----+-----+--------+" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1
            << " | " << setw(14) << left << p[i].prizvyshche
            << " | " << setw(4) << right << p[i].kurs
            << " | " << setw(24) << left << spetsialnistStr[p[i].spetsialnist]
            << " | " << setw(3) << right << p[i].fizyka
            << " | " << setw(3) << right << p[i].matematyka
            << " | " << setw(3) << right << p[i].informatyka
            << " | " << fixed << setprecision(2)
            << setw(6) << right << Average(p[i])
            << " |" << endl;
    }

    cout << "+----+----------------+------+--------------------------+-----+-----+-----+--------+" << endl;
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
        cout << "Pomylka! Kilkist maie buty bilshe 0: ";
        cin >> N;
    }

    Student* p = new Student[N];

    Create(p, N);

    cout << "\nDani do vporyadkuvannia:";
    Print(p, N);

    int choice;

    do
    {
        cout << "\nMENIU" << endl;
        cout << "1 - Fizychne vporyadkuvannia" << endl;
        cout << "0 - Vyhid" << endl;
        cout << "Vash vybir: ";
        cin >> choice;

        if (choice == 1)
        {
            Sort(p, N);

            cout << "\nDani pislia vporyadkuvannia:";
            Print(p, N);
        }
        else if (choice != 0)
        {
            cout << "Pomylka! Oberit 0 abo 1." << endl;
        }

    } while (choice != 0);

    delete[] p;

    return 0;
}
#endif

