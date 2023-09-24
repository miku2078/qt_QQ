#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QResizeEvent>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qlayoutitem.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qpainterpath.h>
#include <qpicture.h>
#include <qpixmap.h>
#include <qsizepolicy.h>
#include <qtypes.h>
#include <qwidget.h>

class Chat : public QWidget {
  Q_OBJECT
public:
  Chat(QWidget *parent = nullptr) :
    QWidget(parent) {
    setMinimumHeight(60);
    QHBoxLayout *layout = new QHBoxLayout(this);
    avatar = new QLabel("头像");
    msg = new QLabel("这是消息捏");
    avatar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    avatar->setMinimumSize(QSize(60, 60));
    layout->addWidget(avatar);
    layout->addWidget(msg);
    setLayout(layout);
  }

  Chat(const QString &message, int max_height) {
    QHBoxLayout *layout = new QHBoxLayout(this);

    QWidget *left = new QWidget;
    QVBoxLayout *av_layout = new QVBoxLayout(left);
    avatar = new QLabel();
    // avatar ->setPicture(QPicture());
    left->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // left->setMinimumWidth(60);
    avatar->setFixedSize(QSize(60, 60));
    av_layout->addWidget(avatar);
    // QPixmap pixmap(":/picture/avatar.jpg");
    // avatar->setPixmap(drawAvatar(pixmap));
    drawAvatar(avatar);
    auto space = new QSpacerItem(60, 40, QSizePolicy::Fixed, QSizePolicy::Expanding);
    av_layout->addItem(space);
    left->setLayout(av_layout);

    msg = new QLabel(message);
    msg->setWordWrap(true);
    msg->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    if (max_height < 60) {
      max_height = 60;
    }
    msg->setMaximumHeight(max_height);
    setMaximumHeight(max_height);

    // msg->setMaximumHeight(100);
    layout->addWidget(msg);
    layout->addWidget(left);

    layout->setContentsMargins(0, 0, 0, 0);
    av_layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
  }

  virtual ~Chat() {
  }

private:
  QLabel *avatar;
  QLabel *msg;

  QPixmap drawAvatar(QLabel *avatar) {
    QPixmap pixmap(":/picture/avatar.jpg");
    qreal w_real = static_cast<qreal>(60.0 / pixmap.width());
    qreal h_real = static_cast<qreal>(60.0 / pixmap.height());
    QPixmap n_pixmap = pixmap.scaled(
      pixmap.width() * w_real,
      pixmap.height() * h_real,
      Qt::KeepAspectRatio,
      Qt::SmoothTransformation);
    QPixmap a_pixmap(n_pixmap.size());
    a_pixmap.fill(Qt::transparent);

    QPainter painter(&a_pixmap);

    QPainterPath path;
    path.addEllipse(a_pixmap.rect());
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, n_pixmap);
    avatar->setPixmap(a_pixmap);
    avatar->setStyleSheet("QLabel { "
      "border-radius: 30px;"
      "border: none;"
      "background-color: transparent;"
      "padding: 0px;"
    "}");
    return pixmap;
  }

protected:
  virtual void resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
  }
};

#endif