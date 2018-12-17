#pragma once
template <typename T>
class CSingleton
{
private:
	static T* p;
public:
	static T* GetInstance()
	{
		if (p == NULL)
			p = new T;
		return p;
	}

	static void ReleaseInstance()
	{
		if (p != NULL)
			delete p;
		p = nullptr;
	}
};

template <typename T>
T* CSingleton<T>::p = nullptr;