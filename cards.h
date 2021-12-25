#ifndef CARDS_H
#define CARDS_H

#include "card.h"

#include <QSet>

class Cards {
public:
  // 定义升序、降序、和无序
  enum SortType { Asc, Desc, NotSort };

  Cards();

  // 添加扑克牌
  void add(const Card &card);
  void add(const Cards &cards);

  // 一次性插入多张扑克牌（操作符重载<<）
  Cards &operator<<(const Card &card);
  Cards &operator<<(const Cards &cards);

  // 删除扑克牌
  void remove(const Card &card);
  void remove(const Cards &cards);

  // 扑克牌数量
  int currCardCount() const;

  // 是否为空
  bool isEmpty() const;

  // 清空扑克牌
  void clear();

  // 最大点数
  Card::CardPoint maxCardPoint();

  // 最小点数
  Card::CardPoint minCardPoint();

  // 指定点数的牌的数量
  int countOfCardPoint(Card::CardPoint point);

  // 某（些）张牌是否在集合中
  bool contains(const Card &card) const;
  bool contains(const Cards &cards) const;

  // 随机取出一张牌
  Card takeARandCard();

  // 扑克牌排序
  Card::CardList sortToCardList(SortType type = Desc);

private:
  QSet<Card> m_cards;
};

#endif // CARDS_H
