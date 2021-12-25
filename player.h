#ifndef PLAYER_H
#define PLAYER_H

#include "cards.h"
#include <QObject>

class Player : public QObject {
  Q_OBJECT
public:
  // 角色
  enum Role { Lord, Farmer };
  // 性别
  enum Gender { Male, Female };
  // 头像显示方向
  enum ProfileDirection { Left, Right };
  // 玩家类型
  enum Type { Robot, User, UnKnow };

  explicit Player(QObject *parent = nullptr);
  explicit Player(QString name, QObject *parent = nullptr);

  // 设置和获取名字
  void setName(const QString &name);
  QString name() const;

  // 设置和获取分数
  void setScore(int score);
  int score() const;

  // 设置和获取比赛结果
  void setWin(bool flag);
  bool isWin() const;

  // 设置和获取角色
  void setRole(Role role);
  Role role() const;

  // 设置和获取性别
  void setGender(Gender gender);
  Gender gender() const;

  // 设置和获取头像显示方向
  void setProfileDirection(ProfileDirection direction);
  ProfileDirection profileDirection() const;

  // 设置和获取玩家类型
  void setType(Type type);
  Type type() const;

  // 设置和获取当前对象（玩家）的上家/下家（对象）
  void setPrePlayer(Player *player);
  Player *prePlayer() const;
  void setNextPlayer(Player *player);
  Player *nextPlayer() const;

  // 叫地主/抢地主
  void grabLordBet(int point);

  // 存储扑克牌
  void storeDispatchedCards(const Card &card);
  void storeDispatchedCards(const Cards &cards);

  // 得到所有的牌，进行展示
  Cards getCards() const;

  // 游戏结束，清空玩家手中所有的牌
  void clearCards();

  // 出牌
  void playCards(Cards &cards);

  // 设置和获取出牌的玩家和已经待处理的扑克牌
  void setPlayedInfo(Player *player, const Cards &cards);
  Player *playedPlayer() const;
  Cards playedCards() const;

  // 虚函数
  virtual void prepareCallLord();
  virtual void preparePlayCards();

signals:

protected:
  QString m_name;
  int m_score;
  bool m_isWin;
  Role m_role;
  Gender m_gender;
  ProfileDirection m_profile_direction;
  Type m_type;
  Player *m_pre_player;
  Player *m_next_player;
  Cards m_cards; // 存储多张扑克牌（玩家手中的牌）
  Player *m_played_cards_player; // 存储一个回合打出的扑克牌的对应玩家
  Cards m_played_cards; // 存储一个玩家一个回合打出的扑克牌
};

#endif // PLAYER_H
