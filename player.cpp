#include "player.h"

Player::Player(QObject *parent) : QObject{parent} {}

Player::Player(QString name, QObject *parent) { m_name = name; }

void Player::setName(const QString &name) { m_name = name; }

QString Player::name() const { return m_name; }

void Player::setScore(int score) { m_score = score; }

int Player::score() const { return m_score; }

void Player::setWin(bool flag) { m_isWin = flag; }

bool Player::isWin() const { return m_isWin; }

void Player::setRole(Role role) { m_role = role; }

Player::Role Player::role() const { return m_role; }

void Player::setGender(Gender gender) { m_gender = gender; }

Player::Gender Player::gender() const { return m_gender; }

void Player::setProfileDirection(ProfileDirection direction) {
  m_profile_direction = direction;
}

Player::ProfileDirection Player::profileDirection() const {
  return m_profile_direction;
}

void Player::setType(Type type) { m_type = type; }

Player::Type Player::type() const { return m_type; }

void Player::setPrePlayer(Player *player) { m_pre_player = player; }

Player *Player::prePlayer() const { return m_pre_player; }

void Player::setNextPlayer(Player *player) { m_next_player = player; }

Player *Player::nextPlayer() const { return m_next_player; }

void Player::storeDispatchedCards(const Card &card) { m_cards.add(card); }

void Player::storeDispatchedCards(const Cards &cards) { m_cards.add(cards); }

Cards Player::getCards() const { return m_cards; }

void Player::clearCards() { m_cards.clear(); }

void Player::playCards(Cards &cards) { m_cards.remove(cards); }

void Player::setPlayedInfo(Player *player, const Cards &cards) {
  m_played_cards_player = player;
  m_played_cards = cards;
}

Player *Player::playedPlayer() const { return m_played_cards_player; }

Cards Player::playedCards() const { return m_played_cards; }

void Player::prepareCallLord() {}

void Player::preparePlayCards() {}
