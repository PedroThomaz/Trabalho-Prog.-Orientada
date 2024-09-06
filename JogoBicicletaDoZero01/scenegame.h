#ifndef SCENEGAME_H
#define SCENEGAME_H

#include <QGraphicsScene>
#include <QTimer>
#include <QLabel>
#include <QMainWindow>
#include "jogador.h"
#include "pista.h"

class scenegame : public QWidget
{

public:
    explicit scenegame(QWidget *parent = nullptr);
    ~scenegame();  // Destrutor
    //void setAxis(bool value);
    //QWidget* obtem_widget() { return this; }

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event) override;

private:
    QLabel *label_fundo;
    QLabel *label2;
    int offset;
    const int speed = 2;  // Velocidade do efeito carrossel
    int count_desl_esq;
    int sorteador_espaço;
    int timerId;

    QPixmap fundo;
    jogador *meu_Jogador;
    pista *minha_pista;
};

#endif // SCENEGAME_H
