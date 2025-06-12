#include <iostream>
#include <stdexcept>

using namespace std;

class Vector
{
private:
	int ArraySize;
	int CheckArray;
	int* DefaultVector;

public:
	Vector() : ArraySize(1), CheckArray(0), DefaultVector(nullptr)
	{
		DefaultVector = new int[ArraySize];
	};
	void Push_Back(int iValue)
	{
		if (CheckArray == ArraySize)
		{
			ArraySize *= 2;
			int* ChangeVector = new int[ArraySize];
			for (int i = 0; i < CheckArray; i++)
			{
				ChangeVector[i] = DefaultVector[i];
			}
			delete[] DefaultVector;
			DefaultVector = new int[ArraySize];
			for (int i = 0; i < CheckArray; i++)
			{
				DefaultVector[i] = ChangeVector[i];
			}
			DefaultVector[CheckArray] = iValue;
			++CheckArray;
			delete[] ChangeVector;
		}
		else
		{
			DefaultVector[CheckArray] = iValue;
			++CheckArray;
		}
		for (int i = 0; i < CheckArray; ++i)
		{
			cout << DefaultVector[i] << endl;
		}

	}
	void Pop_Back()
	{
		CheckArray -= 1;
	}


	int& operator[] (const int ArrayNumber)
	{
		if (ArrayNumber >= ArraySize)
		{
			printf("�����ʰ�\n");
			return;
		}
		return DefaultVector[ArrayNumber];
	}
	void Size()
	{
		cout << CheckArray << endl;
	}
	void capacity()
	{
		cout << ArraySize << endl;
	}
	~Vector()
	{
		delete[] DefaultVector;
	}
};



int main()
{
	Vector Test;
	Test.Push_Back(1);
	Test.Push_Back(2);
	Test.Push_Back(3);
	Test.Pop_Back();
	Test.Push_Back(4);
	Test[7];
	Test.Size();
	Test.capacity();
	Test.Push_Back(4);
	Test.Push_Back(4);
	Test.capacity();




	return 0;
}		if (ListCount == 0)
{
	Head->NextNode = Node2;
	Node2->NextNode = nullptr;
}
else
{
	for (int i = 0; i < ListCount; i++)
	{
		Node* Temp1 = Temp;
		Temp = Temp->NextNode;
	}
	Temp->NextNode = Node2;
	Node2->NextNode = nullptr;
}
	}
	void Delete_Front()
	{
		if (Head->NextNode == nullptr || ListCount == 0)
		{
			cout << "�����Ҽ� �����ϴ�." << endl;
			return;
		}
		Node* Temp = Head->NextNode;
		Head->NextNode = Head->NextNode->NextNode;
		delete Temp;
		--ListCount;
	}
	void Delete_Back()
	{
		if (Head->NextNode == nullptr || ListCount == 0)
		{
			cout << "�����Ҽ� �����ϴ�." << endl;
			return;
		}
		Node* Temp = Head;
		Node* DeleteNode;
		for (int i = 0; i < ListCount - 1; i++)
		{
			Node* Temp1 = Temp;
			Temp = Temp->NextNode;
		}
		DeleteNode = Temp->NextNode;
		Temp->NextNode = nullptr;
		delete DeleteNode;
		--ListCount;
	}
	void Quest(int Value)
	{
		Node* Temp = Head;
		for (int i = 0; i < ListCount; i++)
		{

			Node* Temp1 = Temp;
			Temp = Temp->NextNode;
			if (Temp->data == Value)
			{
				cout << "1" << endl;
				return;
			}
		}
		cout << "0" << endl;
	}
	void FullList()
	{
		Node* Temp = Head->NextNode;
		while (Temp)
		{
			cout << Temp->data << " ";
			Temp = Temp->NextNode;
		}
		cout << endl;
	}
	void FullListDelete()
	{
		Node* Temp = Head->NextNode;
		Node* FullDelete;
		while (Temp)
		{
			FullDelete = Temp;
			Temp = Temp->NextNode;
			delete FullDelete;
		}
		Head->NextNode = nullptr;
		ListCount = 0;
	}
	~TestList()
	{
		delete Head;
	}

};




//Node* MiddleInsertion(int MiddleNumber, int Value)
//{
//	Node* MiddleNewNode = CreateNode(Value);
//	if (MiddleNumber > ListCount || MiddleNumber == 0)
//	{
//		cout << "�Ұ����� �۾�" << endl;
//		return nullptr;
//	}
//	Node* Temp = Head;
//
//	for (int i = 0; i < MiddleNumber; i++)
//	{
//		Node* Temp1 = Temp;
//		Temp = Temp->NextNode;
//	}
//	MiddleNewNode->NextNode = Temp->NextNode;
//	Temp->NextNode = MiddleNewNode;
//
//	return MiddleNewNode;
//};
//void MiddleDelete(int MiddleNumber)
//{
//	if (MiddleNumber == 0 || MiddleNumber > ListCount)
//	{
//		cout << "�Ұ����� �۾�" << endl;
//		return;
//	}
//	Node* Temp = Head;
//
//	Node* DeleteNodes = Head;
//	Node* NextNode;
//	for (int i = 0; i < MiddleNumber - 1; i++)
//	{
//		Node* Temp1 = Temp;
//		Temp = Temp->NextNode;
//
//	}
//	Temp;
//	NextNode = Temp->NextNode->NextNode;
//	DeleteNodes = Temp->NextNode;
//	Temp->NextNode = NextNode;
//	delete DeleteNodes;
//}

int main()
{

	TestList IntNode;
	IntNode.Add(10);
	IntNode.Add(20);
	IntNode.Add(30);
	IntNode.Add(70);
	IntNode.Add(21);
	IntNode.Add(55);
	IntNode.Add(30);
	IntNode.Add(990);
	IntNode.Add(120);
	IntNode.Add(7);

	IntNode.FullList();

	IntNode.Delete_Back();
	IntNode.Delete_Back();
	IntNode.Delete_Back();
	IntNode.Delete_Back();
	IntNode.Delete_Back();

	IntNode.FullList();

	//IntNode.Quest(30);
	//IntNode.FullList();
	//
	//IntNode.Delete_Front();
	//IntNode.FullList();
	//
	//IntNode.Delete_Back();
	//IntNode.FullList();

	/*
���� ��� = StartNode
���1 : ����
���2 : ����
[ �Ѵ� ���� ���� �� ���� ]
���3 : Ž�� (ex. int�� 3�� ���� ��� ã�� �ִٸ� True, ���ٸ� False)
���4 : �߰�����/���� ( n��° ��ġ�� ���� �� ���� )
���5 : ��ü ��� Show



*/




	return 0;
}