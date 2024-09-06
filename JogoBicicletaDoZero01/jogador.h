#ifndef JOGADOR_H
#define JOGADOR_H
#include <QLabel>
#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QPainter>


#define LARG_BIKE_ORI 63
#define ALT_BIKE_ORI 46

class jogador: public QWidget
{

public:
    explicit jogador(QWidget *parent, int _posi_xe_cima, int _posi_ye_cima, int _y_limite_cima, int _y_limite_baixo);
    ~jogador();  // Destrutor
    void paintEvent(QPaintEvent *event);
    void incrementa_ye_cima(void);
    void decrementa_ye_cima(void);

    int obter_posi_xe_cima(void){   return posi_xe_cima;}
    int obter_posi_ye_cima(void){   return posi_ye_cima;}
    int obter_largura(void){   return largura;}
    int obter_altura(void){   return altura;}

private:
    // Constante
    QPixmap bicicleta;
    const double escala_imagem = 2;
    int largura;
    int altura;
    QLabel *teste;
    int y_limite_cima;
    int y_limite_baixo;

    // Variável
    int posi_xe_cima;
    int posi_ye_cima;

};

#endif // JOGADOR_H
