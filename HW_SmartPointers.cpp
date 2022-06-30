
#include <iostream>
using namespace std;

template<typename T>
class UniquePtr
{
protected:
	T* ptr;
private:
    UniquePtr(UniquePtr<T>&& uptr) noexcept
    {
        ptr = std::move(uptr.ptr);
        uptr.ptr = nullptr;
    }

public:
    UniquePtr(T* obj) { this->ptr = obj; }
    UniquePtr(T& tmp) { this->ptr = &tmp; }
    ~UniquePtr() { delete this->ptr; }

    UniquePtr<T>& operator = (UniquePtr<T>&& uptr) noexcept
    {
        if (this == uptr) 
            return *this;
        ptr = std::move(uptr.ptr);
        uptr.ptr = nullptr;
        return *this;
    }

    void Swap(UniquePtr<T>& other) noexcept
    {
        using std::swap;
        swap(ptr, other.ptr);
    }

    T* Release()
    {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    T* operator -> () { return this->ptr; }
    T& operator * () { return *ptr; }

    UniquePtr(const UniquePtr<T>& uptr) = delete;
    UniquePtr<T>& operator = (const UniquePtr<T>& uptr) = delete;
};

template<typename T>
class SharedPtr
{
protected:
    T* ptr = nullptr;
    uint32_t* counter = nullptr;
    void Clean()
    {
        (*counter)--;
        if (*counter == 0)
        {
            if (nullptr != ptr)
                delete ptr;
            delete counter;
        }
    }

public:
	SharedPtr() : ptr(nullptr), counter(new uint32_t(0)) {}

	SharedPtr(T* ptr) : ptr(ptr), counter(new uint32_t(1)) {}

    ~SharedPtr()
    {
        Clean();
    }

	SharedPtr(const SharedPtr& obj)
	{
		this->ptr = obj.ptr;
		this->counter = obj.counter;
		if (nullptr != obj.ptr)
			(*this->counter)++; 
	}

	SharedPtr& operator=(const SharedPtr& obj)
	{
		Clean();
		this->ptr = obj.ptr; 
		this->counter = obj.counter;
		if (nullptr != obj.ptr)
			(*this->counter)++; 
	}

	SharedPtr(SharedPtr&& dyingObj)
	{
		this->ptr = dyingObj.ptr;
		this->counter = dyingObj.counter;
		dyingObj.ptr = dyingObj.counter = nullptr;
	}

	SharedPtr& operator=(SharedPtr&& dyingObj) 
	{
		Clean();
		this->ptr = dyingObj.ptr;
		this->counter = dyingObj.counter;
		dyingObj.ptr = dyingObj.counter = nullptr;
	}

	uint32_t get_count() { return *counter; }

	T* get() const { return this->ptr; }

	T* operator->() const { return this->ptr; }

    T& operator*() const { return this->ptr; }
};

class Test
{
public:
    int number;
    Test() = default;
    Test(int number) { this->number = number; }
    int GetNumber() { return this->number; }
};

void TestUniquePtr()
{
    UniquePtr <Test> a(new Test(7));
    UniquePtr <Test> b(new Test(5));
    a.Swap(b);
    a.Release();
}

void TestSharedPtr()
{
    SharedPtr <Test> obj;
    cout << obj.get_count() << endl;
    SharedPtr<Test> test1(new Test());
    cout << test1.get_count() << endl;
    SharedPtr<Test> test2(test1);
    cout << test1.get_count() << endl;
    cout << test2.get_count() << endl;
}

int main()
{
    TestUniquePtr();
    TestSharedPtr();

    return 0;
}