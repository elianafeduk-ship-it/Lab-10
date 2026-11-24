
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
        int prohramuvannia;
        int chyselniMetody;
        int pedahohika;
    };
};

string SpecialtyName(Spetsialnist s)
{
    switch (s)
    {
    case KompiuterniNauky: return "Kompiuterni nauky";
    case Informatyka: return "Informatyka";
    case MatematykaEkonomika: return "Matematyka i ekonomika";
    case FizykaInformatyka: return "Fizyka i informatyka";
    case TrudoveNavchannia: return "Trudove navchannia";
    default: return "Nevidomo";
    }
}

int ThirdGrade(const Student& s)
{
    switch (s.spetsialnist)
    {
    case KompiuterniNauky:
        return s.prohramuvannia;
    case Informatyka:
        return s.chyselniMetody;
    default:
        return s.pedahohika;
    }
}

void Create(Student* p, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Prizvyshche: ";
        cin >> p[i].prizvyshche;

        cout << "Kurs: ";
        cin >> p[i].kurs;

        cout << "Spetsialnist:" << endl;
        cout << "0 - Kompiuterni nauky" << endl;
        cout << "1 - Informatyka" << endl;
        cout << "2 - Matematyka i ekonomika" << endl;
        cout << "3 - Fizyka i informatyka" << endl;
        cout << "4 - Trudove navchannia" << endl;

        cout << "Vash vybir: ";
        int choice;
        cin >> choice;

        while (choice < 0 || choice > 4)
        {
            cout << "Pomylka. Vvedit vid 0 do 4: ";
            cin >> choice;
        }

        p[i].spetsialnist = (Spetsialnist)choice;

        cout << "Otsinka z fizyky: ";
        cin >> p[i].fizyka;

        cout << "Otsinka z matematyky: ";
        cin >> p[i].matematyka;

        int grade;

        if (p[i].spetsialnist == KompiuterniNauky)
        {
            cout << "Otsinka z prohramuvannia: ";
            cin >> grade;
            p[i].prohramuvannia = grade;
        }
        else if (p[i].spetsialnist == Informatyka)
        {
            cout << "Otsinka z chyselnykh metodiv: ";
            cin >> grade;
            p[i].chyselniMetody = grade;
        }
        else
        {
            cout << "Otsinka z pedahohiky: ";
            cin >> grade;
            p[i].pedahohika = grade;
        }
    }
}

double Average(const Student& s)
{
    return (s.fizyka + s.matematyka + ThirdGrade(s)) / 3.0;
}

int Compare(const Student& a, const Student& b)
{
    if (Average(a) < Average(b))
        return -1;

    if (Average(a) > Average(b))
        return 1;

    if (SpecialtyName(a.spetsialnist) <
        SpecialtyName(b.spetsialnist))
        return -1;

    if (SpecialtyName(a.spetsialnist) >
        SpecialtyName(b.spetsialnist))
        return 1;

    if (a.prizvyshche < b.prizvyshche)
        return -1;

    if (a.prizvyshche > b.prizvyshche)
        return 1;

    return 0;
}

void CreateIndex(int* index, int N)
{
    for (int i = 0; i < N; i++)
        index[i] = i;
}

void SortIndex(const Student* p, int* index, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (Compare(p[index[j]], p[index[j + 1]]) > 0)
            {
                int temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }
}


void Print(const Student* p, const int* index, int N)
{
    cout << "\nSPYSOK STUDENTIV\n";

    cout << "+----+-----+----------------+------+------------------------+-----+-----+-----+-----+-----+" << endl;
    cout << "| No | Ind | Prizvyshche    | Kurs | Spetsialnist           | Fiz | Mat | Pro | ChM | Ped |" << endl;
    cout << "+----+-----+----------------+------+------------------------+-----+-----+-----+-----+-----+" << endl;

    for (int i = 0; i < N; i++)
    {
        const Student& s = p[index[i]];

        cout << "| " << setw(2) << right << i + 1
            << " | " << setw(3) << right << index[i]
            << " | " << setw(14) << left << s.prizvyshche
            << " | " << setw(4) << right << s.kurs
            << " | " << setw(22) << left << SpecialtyName(s.spetsialnist)
            << " | " << setw(3) << right << s.fizyka
            << " | " << setw(3) << right << s.matematyka
            << " | ";

        if (s.spetsialnist == KompiuterniNauky)
            cout << setw(3) << right << s.prohramuvannia;
        else
            cout << "   ";

        cout << " | ";

        if (s.spetsialnist == Informatyka)
            cout << setw(3) << right << s.chyselniMetody;
        else
            cout << "   ";

        cout << " | ";

        if (s.spetsialnist != KompiuterniNauky &&
            s.spetsialnist != Informatyka)
            cout << setw(3) << right << s.pedahohika;
        else
            cout << "   ";

        cout << " |" << endl;
    }

    cout << "+----+-----+----------------+------+------------------------+-----+-----+-----+-----+-----+" << endl;
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
        cout << "Kilkist povynna buty bilshe 0. Vvedit znovu: ";
        cin >> N;
    }

    Student* p = new Student[N];
    int* index = new int[N];

    Create(p, N);

    int menu;

    do
    {
        cout << "\nMENU" << endl;
        cout << "1 - Vporiadkuvaty indeksy" << endl;
        cout << "0 - Vykhid" << endl;
        cout << "Vash vybir: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            CreateIndex(index, N);
            SortIndex(p, index, N);
            Print(p, index, N);
            break;

        case 0:
            break;

        default:
            cout << "Nepravylnyi vybir!" << endl;
        }

    } while (menu != 0);

    delete[] p;
    delete[] index;

    return 0;
}
#endif

