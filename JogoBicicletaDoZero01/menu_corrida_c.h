#ifndef MENU_CORRIDA_C_H
#define MENU_CORRIDA_C_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "scenegame.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class menu_corrida_c;
}
QT_END_NAMESPACE

class menu_corrida_c : public QMainWindow
{
    Q_OBJECT

public:
    menu_corrida_c(QWidget *parent = nullptr);
    ~menu_corrida_c();

private slots:  // Define slots privados
    void onButtonClicked();  // Slot personalizado para o clique do botão

private:
    Ui::menu_corrida_c *ui;
    QPushButton *button;
    QLabel *label;

    scenegame  * _scene;
    QGraphicsView   * _viewport;
    QVBoxLayout     * _layout;
};
#endif // MENU_CORRIDA_C_H
