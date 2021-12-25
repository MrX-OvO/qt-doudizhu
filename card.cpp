#include "card.h"

Card::Card() {}

Card::Card(CardSuit suit, CardPoint point) {
  m_card_suit = suit;
  m_card_point = point;
}

void Card::setCardSuit(CardSuit suit) { m_card_suit = suit; }

void Card::setCardPoint(CardPoint point) { m_card_point = point; }

Card::CardSuit Card::cardSuit() const { return m_card_suit; }

Card::CardPoint Card::cardPoint() const { return m_card_point; }

bool operator==(const Card &lhs, const Card &rhs) {
  return lhs.cardSuit() == rhs.cardSuit() && lhs.cardPoint() == rhs.cardPoint();
}

uint qHash(const Card &card) {
  return card.cardSuit() * 100 + card.cardPoint();
}
