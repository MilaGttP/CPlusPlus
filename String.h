
#pragma once

class String
{
private:
	static int counter;
	char* str;
	int id;

public:
	String();
	String(const int len);
	String(const char* string);
	~String();

	void SetName (const char* value);
	char* GetName() const { return str; }

	void Input() const;
	void Out(const char* prompt) const;
};