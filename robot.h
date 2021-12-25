#ifndef ROBOT_H
#define ROBOT_H

#include "player.h"
#include <QObject>

class Robot : public Player {
  Q_OBJECT
public:
  // 继承构造函数
  using Player::Player;
  explicit Robot(QObject *parent = nullptr);

  void prepareCallLord() override;
  void preparePlayCards() override;
};

#endif // ROBOT_H
