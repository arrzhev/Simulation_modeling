#include "Window.h"
#include <QtWidgets/QApplication>

#pragma comment(lib,"DevIL.lib")
#pragma comment(lib,"ILU.lib")
#pragma comment(lib,"ILUT.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
	w.show();
    return a.exec();
}
