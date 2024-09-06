#ifndef OBSTACULO_H
#define OBSTACULO_H
#include <QLabel>
#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QPainter>

class obstaculo: public QWidget
{
public:
    explicit obstaculo(QWidget *parent, int _posi_xe_cima, int _posi_ye_cima);
    ~obstaculo();
    void decrementa_xe_cima(int _offset);
    void paintEvent(QPaintEvent *event);

    int obter_posi_xe_cima(void){   return posi_xe_cima;}
    int obter_posi_ye_cima(void){   return posi_ye_cima;}
    int obter_largura(void){   return largura;}
    int obter_altura(void){   return altura;}

private:
    // Constante
    QPixmap imagem_obstaculo;
    const double escala_imagem = 1.0/5;
    int largura;
    int altura;
    QLabel *imagem;

    // Variável
    int posi_xe_cima;
    int posi_ye_cima;
};

#endif // OBSTACULO_H
