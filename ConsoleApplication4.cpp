#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

//ZADANIE 1

//michal.borowski@student.put.poznan.pl
#pragma region zadanie1
bool is_palindrome(string word) {
    std::cout << "ZADANIE 1" << endl;

    string reversed_word = word;

    int n = word.length();

    for (int i = 0; i < n / 2; i++)
    {
        swap(reversed_word[i], reversed_word[n - i - 1]);
    }

    if (word == reversed_word) return true;

    return false;
}
#pragma endregion

///michal.borowski@student.put.poznan.pl
//ZADANIE 2 
#pragma region zadanie2
std::vector<int> find_all(string word, char input, std::vector<int> hits)
{
    std::cout << "ZADANIE 2" << endl;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == input)
        {
            hits.push_back(i);
        }
    }

    for (int i = 0; i < hits.size(); i++) {
        cout << hits[i] << endl;
    }

    return hits;
}
#pragma endregion
//michal.borowski@student.put.poznan.pl


//ZADANIE 3
//michal.borowski@student.put.poznan.pl
#pragma region zadanie3
string find_longest_word(string word)
{
    std::cout << "ZADANIE 3" << endl;

    //znajdź wszystkie pozycje gdzie jest spacja
    std::vector<int> hits;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == ' ') {
            hits.push_back(i);
        }
    }

    std::vector<string> splitted_strings;
    //corner case, splitujemy 1 wyraz

    splitted_strings.push_back(word.substr(0, hits[0]));

    //forloop na splitowanie stringa

    for (int i = 0; i < hits.size(); i++)
    {
        splitted_strings.push_back(word.substr(hits[i], hits[i + 1] - hits[i]));
    }

    //szukamy najwieskzy size

    string longest = splitted_strings[0];
    int counter = splitted_strings[0].length();

    for (int i = 1; i <= splitted_strings.size(); i++)
    {
        if (splitted_strings[i].length() > counter) {
            longest = splitted_strings[i];
            counter = splitted_strings[i].length();
        }
    }

    cout << longest << " " << counter << endl;

    return longest;

}

#pragma endregion


//ZADANIE 4 
//michal.borowski@student.put.poznan.pl
#pragma region zadanie4
std::vector<string> split(string sentence, char Splitter)
{

    std::vector<int> hits;

    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == Splitter)
        {
            hits.push_back(i);
        }
    }

    std::vector<string> splitted;

    int start = 0;
    for (int i = 0; i < hits.size(); i++)
    {
        splitted.push_back(sentence.substr(start, hits[i] - start));
        start = hits[i] + 1;
    }

    splitted.push_back(sentence.substr(start));

    for (int i = 0; i < splitted.size(); i++)
    {
        cout << splitted[i] << endl;;
    }

    cout << '\n';

    return splitted;
}
#pragma endregion



//ZADANIE 5 
//michal.borowski@student.put.poznan.pl
#pragma  region zadanie5
string find_and_replace(string input, string wordToFind, string wordToReplace)
{
    std::cout << "ZADANIE 5" << endl;

    std::vector<string> splitted = split(input, ' ');

    for (int i = 0; i < splitted.size(); i++)
    {
        if (splitted[i] == wordToFind)
        {
            splitted[i] = wordToReplace;
        }
    }

    string splitted_sentence = "";

    for (int i = 0; i < splitted.size(); i++)

    {
        splitted_sentence += splitted[i] += " ";
    }

    cout << splitted_sentence << endl;

    return splitted_sentence;
}
#pragma endregion


//ZADANIE 6
//michal.borowski@student.put.poznan.pl

#pragma region zadanie6
std::vector<double> bubble_sort(std::vector<double>& vectorToSort)
{

    std::cout << "ZADANIE 6" << endl;

    for (int i = 0; i < vectorToSort.size(); i++)
    {
        for (int j = 0; j < vectorToSort.size() - 1; j++)
        {
            if (vectorToSort[j] > vectorToSort[j + 1])
            {
                swap(vectorToSort[j], vectorToSort[j + 1]);
            }
        }
    }


    return vectorToSort;
}
#pragma endregion



//ZADANIE 7
//michal.borowski@student.put.poznan.pl
#pragma region zadanie7
int binarySearch(std::vector<double>& vector, double number) {

    int lo = 0;
    int hi = vector.size() - 1;

    int middle;

    while (lo <= hi)
    {
        middle = (lo + hi) / 2;

        if (number == vector[middle])
        {
            std::cout <<"Binary search, poszukiwany element znajduje się na pozycji => " << middle << std::endl;
            return middle;
        }
        else if (number > vector[middle])
        {
            lo = middle + 1;
        }
        else {
            hi = middle - 1;
        }
    }

    cout << "not found" << endl;
    return -1;
}
#pragma endregion



//ZADANIE 8,9
//michal.borowski@student.put.poznan.pl
#pragma region zadaniacsv
struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

std::vector<Exchange_rate> rates;

std::vector<Exchange_rate> sort_usd(std::vector<Exchange_rate> vectorRates)
{
    for (int i = 0; i < vectorRates.size(); i++)
    {
        for (int j = 0; j < vectorRates.size() - 1; j++)
        {
            if (rates[j].usd > rates[j + 1].usd)
            {
                swap(rates[j], rates[j + 1]);
            }
        }
    }


    return vectorRates;
}

std::vector<Exchange_rate> sort_eur(std::vector<Exchange_rate> vectorRates)
{
    for (int i = 0; i < vectorRates.size(); i++)
    {
        for (int j = 0; j < vectorRates.size() - 1; j++)
        {
            if (rates[j].eur > rates[j + 1].eur)
            {
                swap(rates[j], rates[j + 1]);
            }
        }
    }


    return vectorRates;
}

struct Stacja_Pogodowa {
    string Date;
    string Time;
    double SpeedOfSound;
    double TempOfSound;
    double Pressure;
    double Temperatura;
};

std::vector<Stacja_Pogodowa> dane_ze_stacji;

std::vector<Stacja_Pogodowa> sort_Temp()
{
    for (int i = 0; i < dane_ze_stacji.size(); i++)
    {
        for (int j = 0; j < dane_ze_stacji.size() - 1; j++)
        {
            if (dane_ze_stacji[j].Temperatura > dane_ze_stacji[j + 1].Temperatura)
            {
                swap(dane_ze_stacji[j], dane_ze_stacji[j + 1]);
            }
        }
    }


    return dane_ze_stacji;
}


#pragma enderegion


int main()
{

        std::string word = "racecar";
        if (is_palindrome(word)) {
            std::cout << "to palindrom!" << std::endl;
        } else {
            std::cout << "nope" << std::endl;
        }

        std::string input = "ala ma kota";

        std::vector<int> tab;

        find_all(input, 'a', tab);

     find_longest_word("ala ma kota i kot jezdzi testestsetsetsetsosbfdfodbsf na roombie");

     std::cout << "Zadanie 4" << endl;

    std::string csv = "mount everest,1213213,8848,1953";
    split(csv, ',');

   std::string input1 = "ala ma kota, ale kot ali cos tam cos tam i kot kot kot zjadl ale!";
    std::string output = find_and_replace(input1, "kot", "hefalump");

    std::vector<double> liczby = { 5,4,674,24,6,1,754,74223,523 };
  
    std::vector<double> liczby_ale_posortowane_specjalnie_dla_zadania = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

    std::cout << "ZADANIE 7" << endl;

    binarySearch(liczby_ale_posortowane_specjalnie_dla_zadania, 1);

    std::fstream file("kursy_usd_eur.csv", std::fstream::in);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line)) {//wczytuje kolejne linie aż do końca pliku
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            Exchange_rate er;
            std::getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = std::stod(double_str);      //zamiana na string->double
            std::getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = std::stod(double_str);      //zamiana na string->double
            std::getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
       }
    }

    cout << "ZADANIE 8" << endl;

    sort_usd(rates);

    for ( int i = rates.size() ; i > rates.size() - 11;  i--)
    {
        cout << "data => " << rates[i].date << "kurs =>" << rates[i].usd << endl;
    }


    std::vector<double> usd_rates;

    for (int i = 0; i < rates.size(); i++)
    {
        usd_rates.push_back(rates[i].usd);
    }

    int position = binarySearch(usd_rates, 3.9011);

    cout << "Kurs znajduje sie na pozycji " << position << "(w wektorze usd_rates, jest posortowany rosnaco)" << endl;

    sort_eur(rates);


    for (int i = 0; i < 10; i++)
    {
        cout << "data => " << rates[i].date << "kurs =>" << rates[i].eur << endl;
    }

    cout << "ZADANIE 9" << endl;

    std::fstream file2("temp02-2020.csv", std::fstream::in);

    if (file2.is_open()) {
        std::string line;
        std::getline(file2, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file2, line)) {//wczytuje kolejne linie aż do końca pliku
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            Stacja_Pogodowa st;
            std::getline(str, st.Date, ','); //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, st.Time, ',');      //zamiana na string->double
            std::getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            st.SpeedOfSound = std::stod(double_str);      //zamiana na string->double
            std::getline(str, double_str, ',');
            st.TempOfSound = std::stod(double_str);
            std::getline(str, double_str, ',');
            st.Pressure = std::stod(double_str);
            std::getline(str, double_str, ',');
            st.Temperatura = std::stod(double_str);
            dane_ze_stacji.emplace_back(st); //dodaje element do kolekcji
        }
    }
    


    sort_Temp();


    int middle = dane_ze_stacji.size() / 2;


    cout << "Najniższa temperatura => " << dane_ze_stacji[0].Temperatura << endl;
    cout << "Mediana => " << dane_ze_stacji[middle].Temperatura<< endl;
    cout << "Najwyższa temperatura =>" << dane_ze_stacji[dane_ze_stacji.size() - 1].Temperatura << endl;;

    return 0;
}
