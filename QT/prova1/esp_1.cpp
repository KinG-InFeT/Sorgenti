#include <qapplication.h>
#include <qpushbutton.h>

int main(int argc, char **argv) {
	QApplication App1(argc, argv);
	QPushButton Hello("Hello", 0);
	App1.setMainWidget(&Hello);
	Hello.show();
	return App1.exec();
}
