#include <iostream>

using namespace std;

class Queue
{
private:
	int* Array;
	int Size;
	int Point=0;
	int Last = 0;
public:
	Queue(int size)
	{
		Size = size;
		Array = new int[Size];
	}
	void Push(int num)
	{
		Array[Point] = num;
		++Point;
	}
	void Pop()
	{
		Last++;
	}
	void Front()
	{
		cout<<Array[Last]<<endl;
	}
	~Queue()
	{
		delete[]Array;
	}
};

int main()
{
	Queue T1(50);
	T1.Push(500);
	T1.Push(600);
	T1.Push(700);
	T1.Front();
	T1.Pop();
	T1.Front();
	return 0;
}