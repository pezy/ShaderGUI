#include <QApplication>
#include "sgmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SGMainWindow main_window;
    main_window.show();

    return a.exec();
}
