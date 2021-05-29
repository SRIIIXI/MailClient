#ifndef CENTRAL_WIDGET
#define CENTRAL_WIDGET

#include <QtCore>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QLineEdit>

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();
    void addWidget(QWidget *widget);
private:
    QHBoxLayout _Layout;
};

#endif
