#include "include/mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include "../ui/ui_send.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QResizeEvent>
#include <QToolButton>
#include <QFile>
#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QScrollArea>
#include <QLineEdit>
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qtoolbutton.h>
#include <qwidget.h>
#include <QFontMetrics>
#include "hpp/tools.hpp"
#include <QSplitter>
#include <QMessageLogger>

MainWindow::MainWindow(QMainWindow *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  send_ui(new Ui::Send),
  window(new QWidget(this)) {
  ui->setupUi(this);
  show();
  yuri::Tools::init();
  yuri::Tools::loadQss(":qss/left_wid.qss", ui->left_wid);
  yuri::Tools::loadQss(":qss/main_wid.qss", ui->main_wid);
  QHBoxLayout *layout = new QHBoxLayout(ui->main_wid);
  QSplitter *splitter = new QSplitter(Qt::Horizontal, ui->main_wid);

  QWidget *leftLabel = new QWidget(splitter);
  leftLabel->setMinimumWidth(450);
  QSplitter *r_splitter = new QSplitter(Qt::Vertical, splitter);

  

  splitter->setStretchFactor(1, 1);
  QWidget *r_top = new QWidget(r_splitter);
  QWidget *r_but = new QWidget(r_splitter);
  send_ui->setupUi(r_but);
  connect(send_ui->pushButton, &QPushButton::clicked, [this](bool click) {
    qinfo << click;
  });

  r_but->setMinimumWidth(300);

  layout->addWidget(splitter);
  layout->setContentsMargins(0, 0, 0, 0);
  // r_splitter->setStretchFactor(0, 30);
  // r_splitter->setStretchFactor(1, 3);
  r_splitter->setSizes({400, 200});

  // splitter->show();
  ui->main_wid->setLayout(layout);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
  QMainWindow::resizeEvent(event);
}

void MainWindow::paintEvent(QPaintEvent *event) {
}

MainWindow::~MainWindow() {
  delete ui;
  delete send_ui;
}