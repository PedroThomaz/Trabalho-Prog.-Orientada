#include "testando.h"
#include "scenegame.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsLineItem>
#include "menu_corrida_c.h"
#include "ui_menu_corrida_c.h"
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QPixmap>
#include <QWidget>
#include <QTimerEvent>
#include <QVBoxLayout>
#include <QPainter>
#include <QFont>
#include "jogador.h"

testando::testando(QWidget *parent)
    : QWidget(parent)
{
    QPixmap bicicleta(":/Imagens/bicycle_one.png");
    double scaleFactor = 2;

    // Calcula o novo tamanho da imagem
    int newWidth = static_cast<int>(bicicleta.width() * scaleFactor);
    int newHeight = static_cast<int>(bicicleta.height() * scaleFactor);

    // Redimensiona a imagem proporcionalmente
    QPixmap scaledPixmap = bicicleta.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

    label_imagem = new QLabel(this);


    label_imagem->setPixmap(scaledPixmap);
    label_imagem->move(40, 565);
}

testando::~testando() {
    qDebug() << "Destruindo testando";

    // Libera a memória alocada para label_imagem se não for nullptr
    if (label_imagem) {
        delete label_imagem;
        label_imagem = nullptr;  // Para evitar problemas de dangling pointers
    }
}
