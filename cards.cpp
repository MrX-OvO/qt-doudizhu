#include "cards.h"

#include <QRandomGenerator>

Cards::Cards() {}

void Cards::add(const Card &card) { m_cards.insert(card); }

void Cards::add(const Cards &cards) { m_cards.unite(cards.m_cards); }

Cards &Cards::operator<<(const Card &card) {
  add(card);
  return *this;
}

Cards &Cards::operator<<(const Cards &cards) {
  add(cards);
  return *this;
}

void Cards::remove(const Card &card) { m_cards.remove(card); }

void Cards::remove(const Cards &cards) { m_cards.subtract(cards.m_cards); }

int Cards::currCardCount() const { return m_cards.count(); }

bool Cards::isEmpty() const { return m_cards.isEmpty(); }

void Cards::clear() { m_cards.clear(); }

Card::CardPoint Cards::maxCardPoint() {
  Card::CardPoint point = Card::Card_Point_Begin;
  if (!m_cards.isEmpty()) {
    for (auto it = m_cards.begin(); it != m_cards.end(); ++it) {
      if (it->cardPoint() > point) {
        point = it->cardPoint();
      }
    }
  }
  return point;
}

Card::CardPoint Cards::minCardPoint() {
  Card::CardPoint point = Card::Card_Point_End;
  if (!m_cards.isEmpty()) {
    for (auto it = m_cards.begin(); it != m_cards.end(); ++it) {
      if (it->cardPoint() < point) {
        point = it->cardPoint();
      }
    }
  }
  return point;
}

int Cards::countOfCardPoint(Card::CardPoint point) {
  int count = 0;
  if (!m_cards.isEmpty()) {
    for (auto it = m_cards.begin(); it != m_cards.end(); ++it) {
      if (it->cardPoint() == point) {
        ++count;
      }
    }
  }
  return count;
}

bool Cards::contains(const Card &card) const { return m_cards.contains(card); }

bool Cards::contains(const Cards &cards) const {
  return m_cards.contains(cards.m_cards);
}

Card Cards::takeARandCard() {
  // 生成一个随机数
  QRandomGenerator *generator = QRandomGenerator::global();
  int rand = generator->bounded(m_cards.size());
  QSet<Card>::const_iterator it = m_cards.constBegin();
  for (int i = 0; i < rand; ++i, ++it)
    ;
  Card card = *it;
  m_cards.erase(it);
  return card;
}

Card::CardList Cards::sortToCardList(SortType type) {
  Card::CardList list;
  for (auto it = m_cards.begin(); it != m_cards.end(); ++it) {
    list << *it;
  }
  if (type == Asc) {
    std::sort(list.begin(), list.end(),
              [=](const Card &card1, const Card &card2) {
                return card1.cardPoint() < card2.cardPoint() ||
                       (card1.cardPoint() == card2.cardPoint() &&
                        card1.cardSuit() < card2.cardSuit());
              });
  } else if (type == Desc) {
    std::sort(list.begin(), list.end(),
              [=](const Card &card1, const Card &card2) {
                return card1.cardPoint() > card2.cardPoint() ||
                       (card1.cardPoint() == card2.cardPoint() &&
                        card1.cardSuit() > card2.cardSuit());
              });
  }
  return list;
}
