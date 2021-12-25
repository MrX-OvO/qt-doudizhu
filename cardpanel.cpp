#include "cardpanel.h"

#include <QPainter>

CardPanel::CardPanel(QWidget *parent) : QWidget{parent} {
  // 初始化扑克牌显示正面且未被选中
  m_isFrontSide = true;
  m_isSeclected = false;
}

void CardPanel::setCardImage(const QPixmap &front, const QPixmap &behind) {
  m_front = front;
  m_behind = behind;
  // 设置窗口大小和扑克牌一致
  setFixedSize(front.size());
  // 调用update()后，qt框架自动调用paintEvent()
  update();
}

QPixmap CardPanel::cardImage() const { return m_front; }

void CardPanel::setFrontSide(bool flag) { m_isFrontSide = flag; }

bool CardPanel::isFrontSide() const { return m_isFrontSide; }

void CardPanel::setSeclected(bool flag) { m_isSeclected = flag; }

bool CardPanel::isSeclected() const { return m_isSeclected; }

void CardPanel::setCard(const Card &card) { m_card = card; }

Card CardPanel::card() const { return m_card; }

void CardPanel::setCardOwner(Player *player) { m_player = player; }

Player *CardPanel::cardOwner() const { return m_player; }

void CardPanel::paintEvent(QPaintEvent *) {
  QPainter p(this);
  if (m_isFrontSide) {
    p.drawPixmap(rect(), m_front);
  } else {
    p.drawPixmap(rect(), m_behind);
  }
}

void CardPanel::mousePressEvent(QMouseEvent *event) {}
