#ifndef CARD_H
#define CARD_H

#include <QVector>

class Card {
public:
  // 定义类型别名
  using CardList = QVector<Card>;
  // 花色
  enum CardSuit {
    Card_Black_Joker_Suit,
    Diomand, // 方块
    Club,    // 梅花
    Heart,   // 红桃
    Spade,   // 黑桃
    Card_Red_Joker_Suit
  };
  // 点数
  enum CardPoint {
    Card_Point_Begin,
    Card_Point_3,
    Card_Point_4,
    Card_Point_5,
    Card_Point_6,
    Card_Point_7,
    Card_Point_8,
    Card_Point_9,
    Card_Point_J,
    Card_Point_Q,
    Card_Point_K,
    Card_Point_A,
    Card_Point_2,
    Card_Black_Joker, // 小王
    Card_Red_Joker,   // 大王
    Card_Point_End
  };

  Card();
  Card(CardSuit suit, CardPoint point);

  // 设置和获取花色和点数
  void setCardSuit(CardSuit suit);
  void setCardPoint(CardPoint point);
  CardSuit cardSuit() const;
  CardPoint cardPoint() const;

private:
  CardSuit m_card_suit;
  CardPoint m_card_point;
};

// 操作符重载（==）
bool operator==(const Card &lhs, const Card &rhs);

// 重写全局函数qHash()
uint qHash(const Card &card);

#endif // CARD_H
