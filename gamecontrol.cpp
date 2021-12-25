#include "gamecontrol.h"

#include <QRandomGenerator>

GameControl::GameControl(QObject *parent) : QObject{parent} {}

void GameControl::initPlayer() {
  // 对象实例化
  m_robot_left = new Robot("机器人A", this);
  m_robot_left = new Robot("机器人A", this);
  m_user_player = new UserPlayer("玩家", this);

  // 头像显示
  m_robot_left->setProfileDirection(Player::Left);
  m_robot_left->setProfileDirection(Player::Right);
  m_user_player->setProfileDirection(Player::Right);

  // 性别
  Player::Gender gender;
  QRandomGenerator *generator = QRandomGenerator::global();
  int random = generator->bounded(2);
  gender = static_cast<Player::Gender>(random);
  m_robot_left->setGender(gender);
  random = generator->bounded(2);
  gender = static_cast<Player::Gender>(random);
  m_robot_right->setGender(gender);
  random = generator->bounded(2);
  gender = static_cast<Player::Gender>(random);
  m_user_player->setGender(gender);

  // 出牌顺序
  // 对于用户玩家
  m_user_player->setPrePlayer(m_robot_left);
  m_user_player->setNextPlayer(m_robot_right);
  // 对于左侧机器人
  m_user_player->setPrePlayer(m_robot_right);
  m_user_player->setNextPlayer(m_user_player);
  // 对于右侧机器人
  m_user_player->setPrePlayer(m_user_player);
  m_user_player->setNextPlayer(m_robot_left);

  // 指定当前玩家
  m_curr_player = m_user_player;
}

Robot *GameControl::leftRobot() const { return m_robot_left; }

Robot *GameControl::rightRobot() const { return m_robot_right; }

UserPlayer *GameControl::userPlayer() const { return m_user_player; }

void GameControl::setCurrPlayer(Player *player) { m_curr_player = player; }

Player *GameControl::currPlayer() const { return m_curr_player; }

Player *GameControl::playedPlayer() const { return m_played_layer; }

Cards GameControl::playerCards() const { return m_played_cards; }

void GameControl::initAllCards() {
  // 先清空牌
  m_all_cards.clear();
  for (auto suit = Card::Diomand; suit <= Card::Spade;
       suit = static_cast<Card::CardSuit>(suit + 1)) {
    for (auto point = Card::Card_Point_3; point <= Card::Card_Point_2;
         point = static_cast<Card::CardPoint>(point + 1)) {
      Card card(suit, point);
      m_all_cards.add(card);
    }
  }
  // 大小王
  m_all_cards.add(Card(Card::Card_Black_Joker_Suit, Card::Card_Black_Joker));
  m_all_cards.add(Card(Card::Card_Red_Joker_Suit, Card::Card_Red_Joker));
}

Card GameControl::dispatchOneCard() { return m_all_cards.takeARandCard(); }

Cards GameControl::lastThreeCards() const { return m_all_cards; }

void GameControl::resetCards() {
  // 洗牌
  initAllCards();
  // 清空玩家手里的牌
  m_robot_left->clearCards();
  m_robot_right->clearCards();
  m_user_player->clearCards();
  // 初始化出牌玩家对象和牌
  m_played_layer = nullptr;
  m_played_cards.clear();
}

void GameControl::startGame() {
  // 当前玩家准备叫地主
  m_curr_player->prepareCallLord();
}

void GameControl::becomeLord(Player *player) {
  // 设置角色
  player->setRole(Player::Lord);
  player->prePlayer()->setRole(Player::Farmer);
  player->nextPlayer()->setRole(Player::Farmer);

  // 设置当前玩家和给地主底牌
  m_curr_player = player;
  player->storeDispatchedCards(m_all_cards);

  // 准备出牌
  m_curr_player->preparePlayCards();
}

void GameControl::clearPlayerScore() {
  m_robot_left->setScore(0);
  m_robot_right->setScore(0);
  m_user_player->setScore(0);
}
