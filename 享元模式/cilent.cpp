/*
* 享元模式通过共享技术实现相同或相似对象的重用。享元模式是一种对象结构型模式。运用共享技术有效地支持大量细颗粒对象的复用。
* 享元模式以共享的方式高效地支持大量的细颗粒对象，享元模式能做到共享的关键是区分内部状态和外部状态。
内部状态：是存储在享元对象内部并且不会随环境改变而改变的状态，因此内部状态可以共享；
外部状态：随环境改变而改变的、不可以共享的状态。享元对象的外部状态必须由客户端保存，并在享元对象被创建后，在需要使用的时候再传入享元对象内部。
flyweight执行时所需的状态必定是内部的或外部的。内部状态存储于ConcreteFlyweight对象之中；而外部对象则由Client对象存储或计算。当用户调用flyweight对象的操作时，将该状态传递给它。
同时，用户不应该直接对ConcreteFlyweight类进行实例化，而只能从FlyweightFactory对象得到ConcreteFlyweight对象，
这可以保证对它们适当地进行共享；由于共享一个实例，所以在创建这个实例时，就可以考虑使用单例模式来进行实现。
*优点:
（1）极大减少内存中对象的数量，使得相同对象或相似对象在内存中只保存一份；
（2）享元对象的外部状态相对独立，而且不会影响其内部状态，从而使得享元对象可以在不同的环境中被共享。
缺点：
（1）享元模式使得系统更加复杂，需要分离出内部状态和外部状态，从而使得程序的逻辑复杂化。
（2）为了使对象可以共享，享元模式需要将享元对象的状态外部化，而读取外部状态使得运行时间变长。
*应用：（1）当一个系统有大量相同或相似的对象，由于这些对象的大量使用，造成内存的大量耗费；使用享元模式可以节约内存空间，提高系统的性能
（2）对象的大部分状态都可以外部化，可以将这些外部状态传入对象中；
比如一个字符串中存在很多重复的字符，可以针对每一个不同的字符创建一个享元对象，将其放在享元池中，需要时再从享元池取出。
*/

#include"FlyWeightFactory.h"
int main()
{
	FlyWeightFactory* factory = new FlyWeightFactory();//实例化享元工厂类
	FlyWeight* flyweight = factory->GetFlyWeight(0);//通过享元工厂对象的工厂方法返回享元对象
	flyweight->operation();
	return 0;
}

//UnsharedConcreteFlyweight（非共享具体享元类）
//并不是所有的抽象享元类的子类都需要共享，不能被共享的子类则设计为非共享具体享元类，当需要一个非共享具体享元类的对象时可以直接通过实例化创建。




//#include<iostream>
//#include<vector>
//using namespace std;
//
////棋子颜色
//enum PieceColor { BLACK, WHITE };
////棋子位置
//struct PiecePos
//{
//	int x;
//	int y;
//	PiecePos(int a, int b) : x(a), y(b) {}
//};
////棋子定义
//class Piece
//{
//protected:
//	PieceColor m_color; //颜色
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
//	void Draw() { cout << "绘制一颗黑棋\n"; }
//};
//class WhitePiece : public Piece
//{
//public:
//	WhitePiece(PieceColor color) : Piece(color) {}
//	~WhitePiece() {}
//	void Draw() { cout << "绘制一颗白棋\n"; }
//};
//class PieceBoard
//{
//private:
//	vector<PiecePos> m_vecPos; //存放棋子的位置
//	Piece* m_blackPiece;       //黑棋棋子 
//	Piece* m_whitePiece;       //白棋棋子
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
//			if (m_blackPiece == NULL)  //只有一颗黑棋
//				m_blackPiece = new BlackPiece(color);
//			cout << m_blackName << "在位置(" << pos.x << ',' << pos.y << ")";
//			m_blackPiece->Draw();
//		}
//		else
//		{
//			if (m_whitePiece == NULL)
//				m_whitePiece = new WhitePiece(color);
//			cout << m_whiteName << "在位置(" << pos.x << ',' << pos.y << ")";
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