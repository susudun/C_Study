#include <iostream>
using namespace std;




struct Node
{
	Node* NextNode;
	int data;
};

class TestList
{
public:
	int ListCount = 0;
	Node* Head = new Node{ nullptr,0 };
public:
	TestList() {};

	void Add(int Value)
	{
		Node* Nodes = new Node{ nullptr,Value };
		LinkNode(Head, Nodes);
		ListCount++;
	};

	void LinkNode(Node* Node1, Node* Node2)
	{
		Node* Temp = Head;
		if (ListCount == 0)
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
			cout << "삭제할수 없습니다." << endl;
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
			cout << "삭제할수 없습니다." << endl;
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
//		cout << "불가능한 작업" << endl;
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
//		cout << "불가능한 작업" << endl;
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
시작 노드 = StartNode
기능1 : 삽입
기능2 : 삭제
[ 둘다 끝에 삽입 및 삭제 ]
기능3 : 탐색 (ex. int값 3을 가진 노드 찾기 있다면 True, 없다면 False)
기능4 : 중간삽입/삭제 ( n번째 위치에 삽입 및 삭제 )
기능5 : 전체 노드 Show



*/




	return 0;
}