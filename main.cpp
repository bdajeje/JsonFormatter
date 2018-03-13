#include "main_window.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.setWindowIcon(QIcon("./resources/logo.png"));
	w.show();

	return a.exec();
}
