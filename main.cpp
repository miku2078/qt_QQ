#include <QApplication>
#include "include/mainwindow.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);
  MainWindow window;
  return app.exec();
}

// #include <QtWidgets>
// #include <qnamespace.h>

// class CircularLabel : public QLabel {
// public:
//   CircularLabel(QWidget *parent = nullptr) :
//     QLabel(parent) {
//     // setFixedSize(200,200); // 设置圆形 QLabel 的大小
//     setStyleSheet("border-radius: 50px; background-color: transparent;"); // 创建圆形样式
//   }

//   void setCircularPixmap(const QPixmap &pixmap) {
//     int targetWidth = 60;
//     int targetHeight = 60;
//     qreal scaleFactor = 1.0;
//     if (pixmap.width() > targetWidth || pixmap.height() > targetHeight) {
//       qreal widthScaleFactor = static_cast<qreal>(targetWidth) / pixmap.width();
//       qreal heightScaleFactor = static_cast<qreal>(targetHeight) / pixmap.height();
//       // 选择较小的比例，以保持纵横比
//       scaleFactor = qMin(widthScaleFactor, heightScaleFactor);
//     }

//     // 缩小图片
//     QPixmap scaledPixmap = pixmap.scaled(
//       pixmap.width() * scaleFactor,
//       pixmap.height() * scaleFactor,
//       Qt::KeepAspectRatio,     // 保持纵横比
//       Qt::SmoothTransformation // 使用平滑的缩放算法
//     );

//     resize(scaledPixmap.size());

//     QPixmap roundedPixmap(scaledPixmap.size()); // 新建一个新的pixmap
//     roundedPixmap.fill(Qt::transparent); // 设置透明填充
//     QPainter painter(&roundedPixmap); // 设置在pixmap上绘画
//     painter.setRenderHint(QPainter::Antialiasing, true); // 设置抗锯齿
//     QPainterPath path;                                   // 设置路径
//     // 添加圆形路径
//     path.addEllipse(roundedPixmap.rect());
//     painter.setClipPath(path);
//     painter.drawPixmap(0, 0, scaledPixmap); // 将头像绘制到圆形背景上

//     setPixmap(roundedPixmap); // 设置圆形头像
//   }
// };

// int main(int argc, char *argv[]) {
//   QApplication app(argc, argv);

//   QMainWindow window;
//   window.setWindowTitle("圆形头像");

//   CircularLabel label(&window);

//   // 加载头像
//   QPixmap avatar(":/picture/avatar.jpg"); // 替换为您的头像路径
//   if (!avatar.isNull()) {
//     // 设置头像并居中显示
//     label.setCircularPixmap(avatar);
//     label.setAlignment(Qt::AlignCenter);
//     window.resize(avatar.size());
//   } else {
//     label.setText("无法加载头像");
//   }

//   window.setCentralWidget(&label);
//   window.show();

//   return app.exec();
// }
