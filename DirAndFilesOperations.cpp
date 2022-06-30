

#include <boost/filesystem/operations.hpp>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
using namespace boost;

uint32_t SizeDir(boost::filesystem::path dir)
{
    size_t size = 0;
    for (boost::filesystem::recursive_directory_iterator it(dir);
        it != boost::filesystem::recursive_directory_iterator();
        ++it)
    {
        if (!boost::filesystem::is_directory(*it))
            size += boost::filesystem::file_size(*it);
    }
    return size;
}
struct HumanReadable
{
    std::uintmax_t size{};
private:
    friend std::ostream& operator<<(std::ostream& os, HumanReadable hr)
    {
        int i{};
        double mantissa = hr.size;
        for (; mantissa >= 1024.; mantissa /= 1024., ++i) {}
        mantissa = std::ceil(mantissa * 10.) / 10.;
        os << mantissa << " " << "BKMGTPE"[i];
        return i == 0 ? os : os << "B ";
    }
    friend std::ostream& operator<<(std::ostream& os, uint32_t size)
    {
        int i{};
        double mantissa = size;
        for (; mantissa >= 1024.; mantissa /= 1024., ++i) {}
        mantissa = std::ceil(mantissa * 10.) / 10.;
        os << mantissa << " " << "BKMGTPE"[i];
        return i == 0 ? os : os << "B ";
    }
};
void CreateDir(string path, string namedir)
{
    boost::system::error_code error;
    boost::filesystem::create_directories(path + '/' + namedir, error);
    assert(!error);
}
void RemoveDir(string path, string namedir)
{
    try
    {
        if (boost::filesystem::exists(path + '/' + namedir))
            boost::filesystem::remove_all(path + '/' + namedir);
    }
    catch (boost::filesystem::filesystem_error const& e)
    {
        cout << e.what() << endl;
        std::system("pause");
    }
}
void RenameDir(string path)
{
    string old_name, new_name;
    cout << "Enter old name dir: ";
    getline(cin, old_name);
    cout << "Enter new name dir: ";
    getline(cin, new_name);
    try
    {
        if (boost::filesystem::exists(path + '/' + old_name))
            boost::filesystem::rename(path + '/' + old_name, path + '/' + new_name);
    }
    catch (boost::filesystem::filesystem_error const& e)
    {
        cout << e.what() << endl;
        std::system("pause");
    }
}
void PrintDir(string path)
{
    boost::filesystem::directory_iterator begin(path);
    boost::filesystem::directory_iterator end;
    boost::filesystem::path file;
    cout << "\t" << left << setfill(' ') << setw(45) << "Filename"
        << "Size" << right << setfill(' ') << setw(50) << "Type" << endl;
    for (; begin != end; ++begin)
    {
        boost::filesystem::file_status fs = boost::filesystem::status(*begin);
        file = *begin;
        cout << left << setfill('-') << setw(50) << file.filename().string();
        switch (fs.type())
        {
        case boost::filesystem::regular_file:
            cout << HumanReadable{ boost::filesystem::file_size(*begin) }
            << right << setfill('-') << setw(45) << "FILE" << endl;
            break;
        case boost::filesystem::symlink_file:
            cout << HumanReadable{ SizeDir(*begin) } << right << setfill('-')
                << setw(45) << "SYMLINK" << endl;
            break;
        case boost::filesystem::directory_file:
            cout << HumanReadable{ SizeDir(*begin) } << right << setfill('-')
                << setw(45) << "DIRECTORY" << endl;
            break;
        default:
            cout << HumanReadable{ SizeDir(*begin) } << right << setfill('-')
                << setw(45) << "OTHER" << endl;
            break;
        }
    }
}

void RewriteFile(string path, string fileName)
{
    fstream stream;
    string tmp; string buff;
    uint32_t count = 1;
    stream.open(fileName, ios::in);
    if (stream.is_open())
    {
        cout << "\nPrevious text is: \n";
        while (getline(stream, tmp))
            cout << tmp << endl;
        stream.close();
    }
    else
        cout << "Erorr! File isn`t opened" << endl;

    cout << endl;
    stream.open(fileName, ios::out | ios::app);
    if (stream.is_open())
    {
        while (true)
        {
            cout << right << setfill(' ') << setw(8) << count << "| ";
            getline(cin, buff);
            if (buff[0] == '0')
            {
                cout << "Wrote!" << endl;
                break;
            }
            else
            {
                stream << buff << endl;
                count++;
            }
        }
        stream.close();
    }
    else
        cout << "Erorr! File isn`t opened" << endl;
}

void AppendFile(string path, string fileName)
{
    cout << endl;
    fstream stream; string buff;
    uint32_t count = 1;
    stream.open(fileName, ios::app);
    if (stream.is_open())
    {
        while (true)
        {
            cout << right << setfill(' ') << setw(8) << count << "| ";
            getline(cin, buff);
            if (buff[0] == '0')
            {
                cout << "Compiled!" << endl;
                break;
            }
            else
            {
                stream << buff << endl;
                count++;
            }
        }
        stream.close();
    }
    else
        cout << "Erorr! File isn`t opened" << endl;
}

void CopyFiles(string path, string pathFrom, string pathTo)
{
    fstream from; fstream to;
    string buff;
    from.open(pathFrom, ios::in);
    if (from.is_open())
    {
        to.open(pathTo, ios::out | ios::app);
        if (to.is_open())
        {
            cout << "\nText, which we will copy: \n";
            while (getline(from, buff))
            {
                cout << buff << endl;
                to << buff << endl;
            }
            from.close();
            to.close();
        }
        else
            perror("FileTo: Erorr! File isn`t opened");
    }
    else
        perror("FileFrom: Erorr! File isn`t opened");
}

int main()
{
    string path;
    string namedir; string to;
    char switch_on;
    cout << "Enter path: ";
    getline(cin, path);
    do
    {
        std::system("cls");
        PrintDir(path);
        cout << "0 - Exit" << endl;
        cout << "1 - Create dir" << endl;
        cout << "2 - Remove dir or file" << endl;
        cout << "3 - Rename dir" << endl;
        cout << "4 - Open dir" << endl;
        cout << "5 - Back" << endl;
        cout << "6 - Rewrite file" << endl;
        cout << "7 - Append file" << endl;
        cout << "8 - Copy files" << endl;
        cout << "Enter: ";
        cin >> switch_on;
        switch (switch_on)
        {
        case '0':
        {
            exit(0);
        }break;
        case '1':
        {
            cin.ignore();
            cout << "Enter name of new dir: ";
            getline(cin, namedir);
            CreateDir(path, namedir);
        }break;
        case '2':
        {
            cin.ignore();
            cout << "Enter name dir for remove: ";
            getline(cin, namedir);
            RemoveDir(path, namedir);
        }break;
        case '3':
        {
            cin.ignore();
            RenameDir(path);
        }break;
        case '4':
        {
            cin.ignore();
            cout << "Enter name of dir: ";
            getline(cin, namedir);
            boost::filesystem::current_path(path + '/' + namedir);
            path = boost::filesystem::current_path().string();
        }break;
        case '5':
        {
            boost::filesystem::path p = boost::filesystem::current_path();
            path = p.parent_path().string();
            boost::filesystem::current_path(path);
        }break;
        case '6':
        {
            cin.ignore();
            cout << "Enter file name for rewriting: ";
            getline(cin, namedir);
            RewriteFile(path, namedir);
        }break;
        case '7':
        {
            cin.ignore();
            cout << "Enter file name for appending: ";
            getline(cin, namedir);
            AppendFile(path, namedir);
        }break;
        case '8':
        {
            cin.ignore();
            cout << "Enter file name from: ";
            getline(cin, namedir);
            cout << "Enter file name to: ";
            getline(cin, to);
            CopyFiles(path, namedir, to);
        }break;
        }
    } while (true);
    return 0;
}
