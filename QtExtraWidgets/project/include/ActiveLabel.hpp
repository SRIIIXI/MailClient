#ifndef ACTIVE_LABEL
#define ACTIVE_LABEL

#include <QtCore>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QLineEdit>

class ActiveLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ActiveLabel( const QString& text="", QWidget* parent= nullptr );
    ~ActiveLabel();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif
