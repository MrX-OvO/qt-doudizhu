#ifndef CARDPANEL_H
#define CARDPANEL_H

#include "card.h"
#include "player.h"
#include <QWidget>

class CardPanel : public QWidget {
  Q_OBJECT
public:
  explicit CardPanel(QWidget *parent = nullptr);

  // 设置和获取图片函数
  void setCardImage(const QPixmap &front, const QPixmap &behind);
  QPixmap cardImage() const;

  // 扑克牌显示哪一面
  void setFrontSide(bool flag);
  bool isFrontSide() const;

  // 记录当前扑克牌（窗口）是否被选中
  void setSeclected(bool flag);
  bool isSeclected() const;

  // 设置和获取扑克牌花色和点数
  void setCard(const Card &card);
  Card card() const;

  // 扑克牌的所有者
  void setCardOwner(Player *player);
  Player *cardOwner() const;

protected:
  void paintEvent(QPaintEvent *);
  void mousePressEvent(QMouseEvent *event);

signals:

private:
  QPixmap m_front;
  QPixmap m_behind;
  bool m_isFrontSide;
  bool m_isSeclected;
  Card m_card;
  Player *m_player;
};

#endif // CARDPANEL_H
