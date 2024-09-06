#include "menu_corrida_c.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu_corrida_c w;
    w.show();
    return a.exec();
}
