/*
* ��Ԫģʽͨ��������ʵ����ͬ�����ƶ�������á���Ԫģʽ��һ�ֶ���ṹ��ģʽ�����ù�������Ч��֧�ִ���ϸ��������ĸ��á�
* ��Ԫģʽ�Թ���ķ�ʽ��Ч��֧�ִ�����ϸ����������Ԫģʽ����������Ĺؼ��������ڲ�״̬���ⲿ״̬��
�ڲ�״̬���Ǵ洢����Ԫ�����ڲ����Ҳ����滷���ı���ı��״̬������ڲ�״̬���Թ���
�ⲿ״̬���滷���ı���ı�ġ������Թ����״̬����Ԫ������ⲿ״̬�����ɿͻ��˱��棬������Ԫ���󱻴���������Ҫʹ�õ�ʱ���ٴ�����Ԫ�����ڲ���
flyweightִ��ʱ�����״̬�ض����ڲ��Ļ��ⲿ�ġ��ڲ�״̬�洢��ConcreteFlyweight����֮�У����ⲿ��������Client����洢����㡣���û�����flyweight����Ĳ���ʱ������״̬���ݸ�����
ͬʱ���û���Ӧ��ֱ�Ӷ�ConcreteFlyweight�����ʵ��������ֻ�ܴ�FlyweightFactory����õ�ConcreteFlyweight����
����Ա�֤�������ʵ��ؽ��й������ڹ���һ��ʵ���������ڴ������ʵ��ʱ���Ϳ��Կ���ʹ�õ���ģʽ������ʵ�֡�
*�ŵ�:
��1����������ڴ��ж����������ʹ����ͬ��������ƶ������ڴ���ֻ����һ�ݣ�
��2����Ԫ������ⲿ״̬��Զ��������Ҳ���Ӱ�����ڲ�״̬���Ӷ�ʹ����Ԫ��������ڲ�ͬ�Ļ����б�����
ȱ�㣺
��1����Ԫģʽʹ��ϵͳ���Ӹ��ӣ���Ҫ������ڲ�״̬���ⲿ״̬���Ӷ�ʹ�ó�����߼����ӻ���
��2��Ϊ��ʹ������Թ�����Ԫģʽ��Ҫ����Ԫ�����״̬�ⲿ��������ȡ�ⲿ״̬ʹ������ʱ��䳤��
*Ӧ�ã���1����һ��ϵͳ�д�����ͬ�����ƵĶ���������Щ����Ĵ���ʹ�ã�����ڴ�Ĵ����ķѣ�ʹ����Ԫģʽ���Խ�Լ�ڴ�ռ䣬���ϵͳ������
��2������Ĵ󲿷�״̬�������ⲿ�������Խ���Щ�ⲿ״̬��������У�
����һ���ַ����д��ںܶ��ظ����ַ����������ÿһ����ͬ���ַ�����һ����Ԫ���󣬽��������Ԫ���У���Ҫʱ�ٴ���Ԫ��ȡ����
*/

#include"FlyWeightFactory.h"
int main()
{
	FlyWeightFactory* factory = new FlyWeightFactory();//ʵ������Ԫ������
	FlyWeight* flyweight = factory->GetFlyWeight(0);//ͨ����Ԫ��������Ĺ�������������Ԫ����
	flyweight->operation();
	return 0;
}

//UnsharedConcreteFlyweight���ǹ��������Ԫ�ࣩ
//���������еĳ�����Ԫ������඼��Ҫ�������ܱ���������������Ϊ�ǹ��������Ԫ�࣬����Ҫһ���ǹ��������Ԫ��Ķ���ʱ����ֱ��ͨ��ʵ����������




//#include<iostream>
//#include<vector>
//using namespace std;
//
////������ɫ
//enum PieceColor { BLACK, WHITE };
////����λ��
//struct PiecePos
//{
//	int x;
//	int y;
//	PiecePos(int a, int b) : x(a), y(b) {}
//};
////���Ӷ���
//class Piece
//{
//protected:
//	PieceColor m_color; //��ɫ
//public:
//	Piece(PieceColor color) : m_color(color) {}
//	~Piece() {}
//	virtual void Draw() {}
//};
//class BlackPiece : public Piece
//{
//public:
//	BlackPiece(PieceColor color) : Piece(color) {}
//	~BlackPiece() {}
//	void Draw() { cout << "����һ�ź���\n"; }
//};
//class WhitePiece : public Piece
//{
//public:
//	WhitePiece(PieceColor color) : Piece(color) {}
//	~WhitePiece() {}
//	void Draw() { cout << "����һ�Ű���\n"; }
//};
//class PieceBoard
//{
//private:
//	vector<PiecePos> m_vecPos; //������ӵ�λ��
//	Piece* m_blackPiece;       //�������� 
//	Piece* m_whitePiece;       //��������
//	string m_blackName;
//	string m_whiteName;
//public:
//	PieceBoard(string black, string white) : m_blackName(black), m_whiteName(white)
//	{
//		m_blackPiece = NULL;
//		m_whitePiece = NULL;
//	}
//	~PieceBoard() { delete m_blackPiece; delete m_whitePiece; }
//	void SetPiece(PieceColor color, PiecePos pos)
//	{
//		if (color == BLACK)
//		{
//			if (m_blackPiece == NULL)  //ֻ��һ�ź���
//				m_blackPiece = new BlackPiece(color);
//			cout << m_blackName << "��λ��(" << pos.x << ',' << pos.y << ")";
//			m_blackPiece->Draw();
//		}
//		else
//		{
//			if (m_whitePiece == NULL)
//				m_whitePiece = new WhitePiece(color);
//			cout << m_whiteName << "��λ��(" << pos.x << ',' << pos.y << ")";
//			m_whitePiece->Draw();
//		}
//		m_vecPos.push_back(pos);
//	}
//};
//int main()
//{
//	PieceBoard pieceBoard("A", "B");
//	pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
//	pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
//	pieceBoard.SetPiece(BLACK, PiecePos(16, 4));
//	pieceBoard.SetPiece(WHITE, PiecePos(16, 16));
//}