#ifndef MAINWINDOW
#define MAINWINDOW

#include <QtWidgets>
#include <QMainWindow>
#include <QSplitter>
#include "RichDataList.hpp"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow();
private:
	QSplitter splitter;
	RichDataList biglist;
	RichDataList smalllist;
};

#endif
