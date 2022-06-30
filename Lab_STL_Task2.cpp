
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class Dictionary
{
protected:
    map <string, string> dictionary;
    string eng; 
    string ukr;

public:
    Dictionary() { dictionary.clear(); }
    void Add()
    {
        cout << "Enter eng word: "; cin >> this->eng;
        cout << "Enter ukr word: "; cin >> this->ukr;
        dictionary.emplace(make_pair(this->eng, this->ukr));
    }
    void Output()
    {
        if (dictionary.empty())
            cout << "Dictionary is empty!" << endl;
        else
            for (auto item = dictionary.begin(); item != dictionary.end(); item++)
                cout << "Eng: " << item->first << " -> " << "Ukr: " << item->second << endl;
    }
    auto Search()
    {
        string buff; 
        uint32_t tmp;
        cout << "By which word will you search?" << endl;
        cout << "\t1 - Eng" << endl;
        cout << "\t2 - Ukr" << endl;
        cout << "Enter: ";
        cin >> tmp;
        cin.ignore();
        cout << "Enter searched word: ";
        getline(cin, buff);
        switch (tmp)
        {
        case 1:
        {
            for (auto item = dictionary.begin(); item != dictionary.end(); ++item)
                if (item->first == buff)
                    return item->second;       
        }break;
        case 2:
        {
            for (auto item = dictionary.begin(); item != dictionary.end(); ++item)
                if (item->second == buff)
                    return item->first;        
        }break;
        }
    }
    auto Edit()
    {
        string was;
        string became;
        uint32_t tmp;
        cout << "By which word will you edit?" << endl;
        cout << "\t1 - Eng" << endl;
        cout << "\t2 - Ukr" << endl;
        cout << "Enter: ";
        cin >> tmp;
        switch (tmp)
        {
        case 1:
        {
            cin.ignore();
            cout << "Enter word for editing: ";
            getline(cin, was);
            cout << "Enter new word: ";
            getline(cin, became);
            for (auto item = dictionary.begin(); item != dictionary.end(); ++item)
            {
                if (item->first == was)
                {
                    item->first == became;
                    return item->first;
                }
            }      
        }break;
        case 2:
        {
            cin.ignore();
            cout << "Enter word for editing: ";
            getline(cin, was);
            cout << "Enter new word: ";
            getline(cin, became);
            for (auto item = dictionary.begin(); item != dictionary.end(); ++item)
            {
                if (item->second == was)
                {
                    item->second == became;
                    return item->second;
                }
            }  
        }break;
        }
    }
    void Delete()
    {
        dictionary.clear();
        if (dictionary.empty())
            cout << "Dictionary was cleared!" << endl;
    }
    void Save()
    {
        string fileName;
        cin.ignore();
        cout << "Enter path for saving: ";
        getline(cin, fileName);
        ofstream fout;
        fout.open(fileName, ofstream::app);
        if (!fout.is_open())
            cout << "File opening error! " << endl;
        else
        {
            cout << endl << "File opened!" << endl;
            fout.write((char*)this, sizeof(Dictionary));
        }
        fout.close();
    }
    void Load()
    {
        string fileName;
        cin.ignore();
        cout << "Enter path for loading: ";
        getline(cin, fileName);
        ifstream fin;
        fin.open(fileName);
        if (!fin.is_open())
            cout << "File opening error! " << endl;
        else
        {
            cout << endl << "File opened!" << endl;
            Dictionary dc;
            while (fin.read((char*)&dc, sizeof(Dictionary)))
                this->Output();
        }
        fin.close();
    }
};

int main()
{
    uint32_t switch_on;
    Dictionary dc;
    cout << endl << "\tMenu: " << endl << endl;
    while (true)
    {
        cout << "\t0 - Exit" << endl;
        cout << "\t1 - Add" << endl;
        cout << "\t2 - Show all words" << endl;
        cout << "\t3 - Search" << endl;
        cout << "\t4 - Edit" << endl;
        cout << "\t5 - Delete" << endl;
        cout << "\t6 - Save" << endl;
        cout << "\t7 - Load" << endl << endl;
        cout << "\tYour choice: ";
        cin >> switch_on;
        switch (switch_on)
        {
        case 0:
        {
            exit(0);
        }break;
        case 1:
        {
            dc.Add();
        }break;
        case 2:
        {
            dc.Output();
        }break;
        case 3:
        {
            cout << "Translation: " << dc.Search() << endl << endl;
        }break;
        case 4:
        {
            cout << "Edited: " << dc.Edit() << endl << endl;
        }break;
        case 5:
        {
            dc.Delete();
        }break;
        case 6:
        {
            dc.Save();
        }break;
        case 7:
        {
            dc.Load();
        }break;
        }
    }

    return 0;
}