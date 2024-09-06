#ifndef TESTANDO_H
#define TESTANDO_H

#include <QGraphicsScene>
#include <QTimer>
#include <QLabel>
#include <QMainWindow>
#include <QWidget>

class testando : public QWidget
{

    Q_OBJECT

public:
    explicit testando(QWidget *parent = nullptr);
    ~testando();


private:
    QLabel *label_imagem;
};

#endif // TESTANDO_H
