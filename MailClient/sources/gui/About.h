#ifndef _ABOUT
#define _ABOUT

#include <QtCore>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTextBrowser>
#include <QListWidget>
#include <QPushButton>

#include "ThemeHandler.h"

class About : public QWidget
{
    Q_OBJECT
public:
	About(QWidget *parent = 0);
};

#endif
