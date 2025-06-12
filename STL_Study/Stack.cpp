#include <iostream>

using namespace std;


class Stack
{
private:
	int* Array;
	int Point=0;
	int Max;
public:
	Stack(int num)
	{
		Max = num;
		Array = new int[Max];
	}
	void Push(int num)
	{
		if (Point >= Max)
		{
			cout << "OverPush" << endl;
		}
		else
		{
			Array[Point] = num;
			++Point;
		}
	}
	void Pop()
	{
		if (Point <= 0)
		{
			cout << "OverPop" << endl;
		}
		else
		{
			Array[Point] = -1;
			--Point;
		}
	}
	//Top조회
	void Peek()
	{
		if (Point <= 0)
		{
			cout << "Net Number" << endl;
		}
		else
		{
			cout << Array[Point - 1] << endl;
		}
		
	};

	//비어 있는지 확인
	void IsEmpty()
	{
		if (Point == 0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	};
	//꽉 찼는지 확인
	void IsFull()
	{
		if (Point == Max)
		{
			cout << "YesFull" << endl;
		}
		else
		{
			cout << "NoFull" << endl;
		}
	};
	//요소 개수 출력
	void Size()
	{
		cout << Point << endl;
	};
	~Stack()
	{
		delete[] Array;
	}
};



int main()
{
	Stack T1(5);
	T1.Push(30);
	T1.Push(40);
	T1.Peek();
	T1.Pop();
	T1.Peek();


	return 0;
}