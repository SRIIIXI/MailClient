#ifndef RICH_OPTION_LIST
#define RICH_OPTION_LIST

#include <QtCore>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QLineEdit>

class RichOptionListItemDelegate : public QAbstractItemDelegate
{
public:
    RichOptionListItemDelegate(bool large = true, QObject *parent = nullptr);
    void paint( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    virtual ~RichOptionListItemDelegate();
private:
    bool detailedRendering;
    int  rowHeight;
};

class RichOptionList : public QListWidget
{
    Q_OBJECT
public:
    explicit RichOptionList(bool large);
    virtual ~RichOptionList();
};

#endif
