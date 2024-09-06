#include "obstaculo.h"
#include <QWidget>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QFont>

obstaculo::obstaculo(QWidget *parent, int _posi_xe_cima, int _posi_ye_cima)
    : QWidget(parent), imagem_obstaculo(":/Imagens/cone.png")
{
    posi_xe_cima = _posi_xe_cima;
    posi_ye_cima = _posi_ye_cima;
    largura = imagem_obstaculo.width()*escala_imagem;
    altura = imagem_obstaculo.height()*escala_imagem;
    qDebug() << "Largura: "<< largura << "Altura: " << altura;

    imagem_obstaculo = imagem_obstaculo.scaled(largura, altura, Qt::KeepAspectRatio);

    imagem = new QLabel(this);

    imagem->setPixmap(imagem_obstaculo);
    imagem->move(posi_xe_cima, posi_ye_cima);
}

obstaculo::~obstaculo()
{

    qDebug() << "Obstáculo destruído";
}

void obstaculo::paintEvent(QPaintEvent *event)
{
    imagem->move(posi_xe_cima, posi_ye_cima);
}

void obstaculo::decrementa_xe_cima(int _offset)
{
    posi_xe_cima = posi_xe_cima - _offset;
    imagem->move(posi_xe_cima, posi_ye_cima);
    update();
}

