
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

        cout << "Otsinka z informatyky: ";
        cin >> p[i].informatyka;
    }
}

double Average(const Student& s)
{
    return (s.fizyka + s.matematyka + s.informatyka) / 3.0;
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

void Sort(Student* p, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (Compare(p[j], p[j + 1]) > 0)
            {
                Student temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void Print(const Student* p, int N)
{
    cout << "\nSPYSOK STUDENTIV\n";

    cout << "+----+----------------+------+------------------------+-----+-----+-----+--------+" << endl;
    cout << "| No | Prizvyshche    | Kurs | Spetsialnist           | Fiz | Mat | Inf | Ser.   |" << endl;
    cout << "+----+----------------+------+------------------------+-----+-----+-----+--------+" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1
            << " | " << setw(14) << left << p[i].prizvyshche
            << " | " << setw(4) << right << p[i].kurs
            << " | " << setw(22) << left << SpecialtyName(p[i].spetsialnist)
            << " | " << setw(3) << right << p[i].fizyka
            << " | " << setw(3) << right << p[i].matematyka
            << " | " << setw(3) << right << p[i].informatyka
            << " | " << fixed << setprecision(2)
            << setw(6) << right << Average(p[i])
            << " |" << endl;
    }

    cout << "+----+----------------+------+------------------------+-----+-----+-----+--------+" << endl;
}

int CompareWithKey(const Student& s, const string& surname,
    Spetsialnist specialty, double average)
{
    if (Average(s) < average)
        return -1;

    if (Average(s) > average)
        return 1;

    if (SpecialtyName(s.spetsialnist) < SpecialtyName(specialty))
        return -1;

    if (SpecialtyName(s.spetsialnist) > SpecialtyName(specialty))
        return 1;

    if (s.prizvyshche < surname)
        return -1;

    if (s.prizvyshche > surname)
        return 1;

    return 0;
}

int BinarySearch(const Student* p, int N, const string& surname,
    Spetsialnist specialty, double average)
{
    int left = 0;
    int right = N - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        int result = CompareWithKey(
            p[middle], surname, specialty, average);

        if (result == 0)
            return middle;

        if (result < 0)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
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

    Create(p, N);

    int menu;

    do
    {
        cout << "\nMENU" << endl;
        cout << "1 - Vporiadkuvaty studentiv" << endl;
        cout << "2 - Znaity studenta" << endl;
        cout << "0 - Vykhid" << endl;
        cout << "Vash vybir: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            Sort(p, N);
            Print(p, N);
            break;

        case 2:
        {
            Sort(p, N);

            string surname;
            int choice;
            double average;

            cout << "Vvedit prizvyshche: ";
            cin >> surname;

            cout << "Vvedit spetsialnist (0-4): ";
            cin >> choice;

            while (choice < 0 || choice > 4)
            {
                cout << "Pomylka. Vvedit vid 0 do 4: ";
                cin >> choice;
            }

            cout << "Vvedit serednii bal: ";
            cin >> average;

            int result = BinarySearch(
                p, N, surname, (Spetsialnist)choice, average);

            if (result != -1)
                cout << "Studenta znaideno. Nomеr u spysku: "
                << result + 1 << endl;
            else
                cout << "Studenta ne znaideno." << endl;

            break;
        }

        case 0:
            break;

        default:
            cout << "Nepravylnyi vybir!" << endl;
        }

    } while (menu != 0);

    delete[] p;

    return 0;
}
#endif
