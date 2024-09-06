#include "jogador.h"
#include <QWidget>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QFont>

jogador::jogador(QWidget *parent, int _posi_xe_cima, int _posi_ye_cima, int _y_limite_cima, int _y_limite_baixo)
    : QWidget(parent)
{
    QPixmap bicicleta(":/Imagens/bicycle_one.png");
    posi_xe_cima = _posi_xe_cima;
    posi_ye_cima = _posi_ye_cima;
    y_limite_cima = _y_limite_cima;
    y_limite_baixo = _y_limite_baixo;
    largura = static_cast<int>(bicicleta.width() * escala_imagem);
    altura = static_cast<int>(bicicleta.height() * escala_imagem);

    //QPixmap scaledPixmap = bicicleta.scaled(largura, altura, Qt::KeepAspectRatio);

    int newWidth = static_cast<int>(bicicleta.width() * escala_imagem);
    int newHeight = static_cast<int>(bicicleta.height() * escala_imagem);
    QPixmap scaledPixmap = bicicleta.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

    bicicleta = bicicleta.scaled(largura, altura, Qt::KeepAspectRatio);

    teste = new QLabel(this);

    //QPainter painter;
    //painter.drawPixmap(posi_xe_cima, posi_ye_cima, scaledPixmap);

    teste->setPixmap(bicicleta);
    teste->move(_posi_xe_cima, _posi_ye_cima);

    //update();
    //teste->hide();
    //incrementa_ye_cima();

    //jogador::paintEvent();
    //QPainter painter(this);
    //painter.drawPixmap(posi_xe_cima, posi_ye_cima, scaledPixmap);

    //teste = new QLabel(this);
    /*teste = new QLabel(this);
    teste->setPixmap(bicicleta);
    teste->resize(largura, altura);  // Ajusta o tamanho do QLabel para a imagem
    teste->move(50, 450);            // Posiciona o QLabel
    teste->show();*/

    //teste->setPixmap(scaledPixmap);
    //teste->move(50, 450);
    //paintEvent(this);
    qDebug() << "Jogador Criado, largura: " << largura << "altura:" << altura;
    setFocusPolicy(Qt::StrongFocus);
    //update();

}

jogador::~jogador()
{
    qDebug() << "Destruindo jogador";

    // Libera a memória alocada para o QLabel
    //delete teste;
}

void jogador::paintEvent(QPaintEvent *event)
{
    /*QWidget::paintEvent(event);

    QPixmap bicicleta(":/Imagens/bicycle_one.png");
    int newWidth = static_cast<int>(bicicleta.width() * escala_imagem);
    int newHeight = static_cast<int>(bicicleta.height() * escala_imagem);
    QPixmap scaledPixmap = bicicleta.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

    QPainter painter(this);
    painter.drawPixmap(posi_xe_cima, posi_ye_cima, scaledPixmap);*/
        //QWidget::paintEvent(event);
        //QPainter painter(this);
        //painter.drawPixmap(posi_xe_cima, posi_ye_cima, bicicleta);
    teste->move(posi_xe_cima, posi_ye_cima);
}


void jogador::incrementa_ye_cima(void)
{
    if(posi_ye_cima > y_limite_cima)
    {
        posi_ye_cima = posi_ye_cima - 3;
        update();
    }
}

void jogador::decrementa_ye_cima(void)
{
    if(posi_ye_cima < y_limite_baixo)
    {
        posi_ye_cima = posi_ye_cima + 3;
        update();
    }
}
