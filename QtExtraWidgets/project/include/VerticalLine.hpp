#ifndef VERTICAL_LINE
#define VERTICAL_LINE

#include <QtCore>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QLineEdit>

class VerticalLine : public QWidget
{
    Q_OBJECT
public:
    VerticalLine(int sz = -1, QWidget* ptr = nullptr);
    virtual ~VerticalLine() override;
    void SetHeight(int sz);
protected:
    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *event) override;
private:
    int widgetHeight;
};

#endif
