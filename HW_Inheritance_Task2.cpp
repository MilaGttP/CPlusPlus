
#include <iostream>
using namespace std;

class String
{
protected:
	string str;
public:
	String() = default;
	String(const String& other) { this->str = other.str; }
	String(string str) { this->str = str; }
	~String() = default;
	//T& T::operator = (const T& b);
	String& operator = (const String& other)
	{
		if (this == &other)
			return *this;
		this->~String();
		this->str = other.str;
		return *this;
	}
	uint32_t GetStrLength()
	{
		uint32_t len = strlen(this->str.c_str());
		return len;
	}
	//T T::operator + (const T& b) const;
	String operator + (const String& other) const
	{
		string newVal = this->str + other.str;
		return newVal;
	}
	//bool T::operator ==(const T& b) const;
	bool operator == (const String& other) const
	{
		if (this->str == other.str)
			return true;
		else
			return false;
	}
	//bool T::operator !=(const T& b) const;
	bool operator != (const String& other)
	{
		return !(*this == other);
	}
	void Print()
	{
		cout << endl << "Str: " << this->str << endl;
	}
};

class BitString : public String
{
protected:
	string bitStr;
public:
	BitString() = default;
	BitString(const BitString& other) { this->bitStr = other.bitStr; }
	BitString(string bitStr) { this->bitStr = bitStr; }
	~BitString() = default;
	bool IsBitStr()
	{
		for (char ch : this->bitStr)
		{
			switch (ch)
			{
			case '0': return true; break;
			case '1': return true; break;
			default: this->bitStr = nullptr; return false; break;
			}
		}
	}
	BitString& operator = (const BitString& other)
	{
		if (this == &other)
			return *this;
		this->~BitString();
		this->bitStr = other.bitStr;
		return *this;
	}
	BitString operator + (const BitString& other) const
	{
		string newVal = this->bitStr + other.bitStr;
		return newVal;
	}
	bool operator == (const BitString& other) const
	{
		if (this->bitStr == other.bitStr)
			return true;
		else
			return false;
	}
	bool operator != (const BitString& other)
	{
		return !(*this == other);
	}
	void Print()
	{
		cout << endl << "BitStr: " << this->bitStr << endl;
	}
};

int main()
{
	String str("549684u76"); String str2;
	str.Print();
	cout << "Str length: " << str.GetStrLength() << endl;
	str2 = str;
	str2.Print();
	if (str2 == str)
		cout << "Strings are the same" << endl;
	else if (str2 != str)
		cout << "Strings aren`t the same" << endl;
	String str3 = str2 + str;
	str3.Print();

	BitString bitStr("01010101"); BitString bitStr2;
	cout << endl << endl << "bitStr.IsBitStr: " << bitStr.IsBitStr();
	bitStr.Print();
	bitStr2 = bitStr;
	bitStr2.Print();
	if (bitStr2 == bitStr)
		cout << "BitStrings are the same" << endl;
	else if (bitStr2 != bitStr)
		cout << "BitStrings aren`t the same" << endl;
	BitString bitStr3 = bitStr2 + bitStr;
	bitStr3.Print();

	return 0;
}