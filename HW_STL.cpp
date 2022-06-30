
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    string delim(".:,;()-?!");
    string string;
    size_t str_count = 0;
    size_t index;
    stringstream ss(string);

    map<std::string, size_t> freq;
    cout << "Enter a string -> ";
    getline(cin, string);
    while ((index = string.find_first_of(delim)) != std::string::npos)
        string[index] = ' ';
    while (ss >> string)
    {
        ++str_count;
        freq[string]++;
    }
    cout << "Relative frequency of occurrence of each word:" << endl;
    for (map<std::string, size_t>::iterator iter = freq.begin(); iter != freq.end(); ++iter)
    {
        double p = double(iter->second) / double(str_count) * 100;
        cout << "\'" << iter->first << "\': " << setprecision(4) << p << "%" << endl;
    }
    return 0;
}