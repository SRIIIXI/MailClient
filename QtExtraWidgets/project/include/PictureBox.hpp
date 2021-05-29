#ifndef PICTURE_BOX
#define PICTURE_BOX

#include <QLabel>

class PictureBox : public QLabel
{
Q_OBJECT
public:
    explicit PictureBox( const QString& text="", QWidget* parent= nullptr);
    ~PictureBox();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif
