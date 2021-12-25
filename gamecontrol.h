#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "robot.h"
#include "userplayer.h"
#include <QObject>

class GameControl : public QObject {
  Q_OBJECT
public:
  // 游戏状态
  enum GameStatus {
    DispatchCards, // 发牌
    CallingLord,   // 叫地主
    PlayingCards   // 出牌
  };
  // 玩家状态
  enum PlayerStatus {
    ThinkForCallingLord,  // 考虑叫地主
    ThinkForPlayingCards, // 考虑出牌
    Win                   // 获胜
  };

  explicit GameControl(QObject *parent = nullptr);

  // 初始化玩家
  void initPlayer();

  // 得到玩家实例对象
  Robot *leftRobot() const;
  Robot *rightRobot() const;
  UserPlayer *userPlayer() const;

  // 设置和获取当前玩家
  void setCurrPlayer(Player *player);
  Player *currPlayer() const;

  // 获取出牌玩家和打出的牌
  Player *playedPlayer() const;
  Cards playerCards() const;

  // 初始化扑克牌
  void initAllCards();

  // 每次发一张牌
  Card dispatchOneCard();
  // 得到最后三张底牌
  Cards lastThreeCards() const;
  // 重置扑克牌数据
  void resetCards();

  // 准备叫地主
  void startGame();
  // 成为地主
  void becomeLord(Player *player);

  // 处理叫地主
  // 处理出牌

  // 清空所有玩家的得分
  void clearPlayerScore();

signals:

private:
  Robot *m_robot_left;
  Robot *m_robot_right;
  UserPlayer *m_user_player;
  Player *m_curr_player;
  Player *m_played_layer; // 已出牌玩家
  Cards m_played_cards;   // 已出牌玩家打出的牌
  Cards m_all_cards;      // 54张扑克牌
};

#endif // GAMECONTROL_H
