#ifndef HORIZONTAL_LINE
#define HORIZONTAL_LINE

#include <QtCore>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QLineEdit>

class HorizontalLine : public QWidget
{
    Q_OBJECT
public:
    HorizontalLine(int sz = -1, QWidget* ptr = nullptr);
    virtual ~HorizontalLine() override;
    void SetWidth(int sz);
protected:
    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *event) override;
private:
    int widgetWidth;
};

#endif
