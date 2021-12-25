#ifndef USERPLAYER_H
#define USERPLAYER_H

#include "player.h"
#include <QObject>

class UserPlayer : public Player {
  Q_OBJECT
public:
  // 继承构造函数
  using Player::Player;
  explicit UserPlayer(QObject *parent = nullptr);

  void prepareCallLord() override;
  void preparePlayCards() override;
};

#endif // USERPLAYER_H
