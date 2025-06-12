#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	Test() { cout << "생성" << endl; }
	~Test() { cout << "삭제" << endl; }
	void ToTEXT() { cout << "텍스트 출력 테스트" << endl; }
};



int main()
{	
	//uniqu_ptr 유니크 포인터
	//get 소유권은 스마트포인터가 가지고있고 그냥 객체하나 더만드는거
	//unique_ptr<int>ft = make_unique<int>(20);
	//int* fest = ft.get();

	////release 사용방식 및 간단한설명 unique 포인트 해제및 소유권 전달
	//unique_ptr<int[]>tf = make_unique<int[]>(30);
	//int* test = tf.release();
	//delete[] test;

	////reset 연결된 객체 해제 및 새로운 객체 지정
	//Test MyObj;
	//unique_ptr<Test>ffff = make_unique<Test>(); //ffff객체 생성 
	//ffff.reset(new Test(MyObj)); //클래스 객체 설정
	//ffff.reset(); //nullptr로 변경

	//swap 
	//설명이 필요없다 그냥 스왑이다 ptr1.swap(ptr2) 그냥 서로 바꾸는거지 뭐 가리키는거

	//그냥 간단하게 포인터를 사용하여 if문 사용법
	/*
	포인터가 걸린것을 
	if(ptr) 넣으면 nullptr이 아니면 참으로 동작 아니면 동작안함
	
	*/
	//shared 쉐얼 포인트 유니크포인터는 하나에 객체를 가지고 살지만
	//shared는 하나에 객체를 만들고 그것을 복사하여 사용할수 있습니다.
	//소유권도 가지고 있어서 메모리 해제가 시작되면 복사본부터 하나식 풀린다.
	shared_ptr<Test> MyFly = make_shared<Test>();
	MyFly->ToTEXT();
	cout << MyFly.use_count() << endl;
	shared_ptr<Test> Fun = MyFly;
	cout << MyFly.use_count() << endl;

	//weak 위크 포인터 흠흠 간단하게 읽기전용  소유권도 없고 함수를 호출도 빡시고
	// 뭘 수정하기 어려움 그러니 그냥 사실상 유저에게 출력을 위한 방식
	weak_ptr<Test> tft = MyFly;
	auto tft_ToTEXT = tft.lock();
	if (tft_ToTEXT)
	{
		tft_ToTEXT->ToTEXT();
	}

	return 0;
}