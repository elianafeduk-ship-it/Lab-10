
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

    union
    {
        int programuvannia;
        int chyselniMetody;
        int pedahohika;
    };
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
void CountExcellent(const Student* p, const int N,
    int& fiz, int& mat, int& prog, int& chys, int& ped);

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

    int fiz = 0;
    int mat = 0;
    int prog = 0;
    int chys = 0;
    int ped = 0;

    CountExcellent(p, N, fiz, mat, prog, chys, ped);

    cout << "\nKilkist otsinok 5:" << endl;
    cout << "Fizyka: " << fiz << endl;
    cout << "Matematyka: " << mat << endl;
    cout << "Programuvannia: " << prog << endl;
    cout << "Chyselni metody: " << chys << endl;
    cout << "Pedahohika: " << ped << endl;

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
    cout << "====================================================================================================================" << endl;
    cout << "| No | Prizvyshche | Kurs | Spetsialnist      | Fizyka | Matematyka | Programuvannia | Chyselni metody | Pedahohika |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(12) << left << p[i].prizvyshche;
        cout << "| " << setw(4) << right << p[i].kurs << " ";
        cout << "| " << setw(18) << left
            << spetsialnistStr[p[i].spetsialnist];
        cout << "| " << setw(6) << right << p[i].fizyka << " ";
        cout << "| " << setw(10) << right << p[i].matematyka << " ";

        if (p[i].spetsialnist == KompiuterniNauky)
            cout << "| " << setw(16) << right << p[i].programuvannia << " |"
            << setw(17) << " " << "|"
            << setw(14) << " " << "|";
        else if (p[i].spetsialnist == Informatyka)
            cout << "| " << setw(14) << " " << "|"
            << setw(16) << right << p[i].chyselniMetody << " |"
            << setw(18) << " " << "|";
        else
            cout << "| " << setw(14) << " " << "|"
            << setw(17) << " " << "|"
            << setw(12) << right << p[i].pedahohika << " |";

        cout << endl;
    }

    cout << "=====================================================================================================================" << endl;
}

void CountExcellent(const Student* p, const int N,
    int& fiz, int& mat, int& prog, int& chys, int& ped)
{
    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5)
            fiz++;

        if (p[i].matematyka == 5)
            mat++;

        switch (p[i].spetsialnist)
        {
        case KompiuterniNauky:
            if (p[i].programuvannia == 5)
                prog++;
            break;

        case Informatyka:
            if (p[i].chyselniMetody == 5)
                chys++;
            break;

        default:
            if (p[i].pedahohika == 5)
                ped++;
            break;
        }
    }
}

