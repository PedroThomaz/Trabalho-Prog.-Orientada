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
#include "testando.h"
#include "obstaculo.h"
#include "pista.h"
#include <QRandomGenerator>
#include <vector>

using namespace std;

scenegame::scenegame(QWidget *parent)
    : QWidget(parent),
    fundo(":/Imagens/Cidade_game2.png")
{
    qDebug() << "Cena do jogo criada";
    // Criar o QLabel para a imagem de fundo
    // Criar o QLabel para a imagem de fundo
    label_fundo = new QLabel(this);
    sorteador_espaço = 1;
    count_desl_esq = 0;
    //QPixmap fundo(":/Imagens/Cidade_game.png");
    minha_pista = new pista(fundo, 360, 565, this);

    // Ajusta o tamanho da janela para caber a largura da imagem e altura desejada
    setFixedSize(800, 680);  // Ajuste conforme necessário

    // Configurar o QLabel para exibir parte da imagem
    label_fundo->setGeometry(0, 0, 800, 680);  // Define a geometria do QLabel

    // Ajusta o tamanho da janela para caber a imagem
    setFixedSize(800, 680);  // Tamanho da tela, ajuste conforme necessário
    //qDebug() << "Antes do timer";

    ///
    /// Timer evento -> Carrossel fundo da imagem, add obstaculos, verificar colisão
    ///
    // Configura um timer para atualizar a imagem
    //startTimer(30);  // Atualiza a cada 30 ms
    timerId = startTimer(30);
    /*
    label2 = new QLabel("Bike", this);
    QFont font;
    font.setBold(true);
    font.setPointSize(40);
    label2->setFont(font);

    QPixmap bicicleta(":/Imagens/bicycle_one.png");
    double scaleFactor = 2;

    // Calcula o novo tamanho da imagem
    int newWidth = static_cast<int>(bicicleta.width() * scaleFactor);
    int newHeight = static_cast<int>(bicicleta.height() * scaleFactor);

    // Redimensiona a imagem proporcionalmente
    QPixmap scaledPixmap = bicicleta.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

    label2 = new QLabel(this);


    label2->setPixmap(scaledPixmap);
    label2->move(50, 450);*/

    //testando *novoteste = new testando(this);
    //novoteste->show();
    //minha_pista = new pista(fundo, 360, 565, this);

    meu_Jogador = new jogador(this, 40, 450, 360, 565); // 40, 450
    meu_Jogador -> show();
    this->setFocus();

    //minha_pista -> cria_obstaculo(500, 360);
    minha_pista -> cria_obstaculo(500, 450);
    //minha_pista -> cria_obstaculo(500, 540);
    //minha_pista -> cria_obstaculo(500, 380);



    //obstaculo *meu_obstaculo = new obstaculo(this, 110, 450);
    //obstaculo *meu_obstaculo2 = new obstaculo(this, 110, 420);
    //meu_obstaculo2->stackUnder(meu_obstaculo);
    //meu_Jogador -> stackUnder(meu_obstaculo);
    //obstaculo *meu_obstaculo = new obstaculo(this, 500, 360); //-60 a 780
    //meu_obstaculo -> show();


    //QPixmap img_obstaculo(":/Imagens/cone.png");
    //QLabel *teste = new QLabel(this);

    // Define o novo tamanho desejado (por exemplo, metade da largura e altura originais)
    //int nova_largura = img_obstaculo.width() / 5;
    //int nova_altura = img_obstaculo.height() / 5;

    // Redimensiona a imagem mantendo a proporção
    //QPixmap img_redimensionada = img_obstaculo.scaled(nova_largura, nova_altura, Qt::KeepAspectRatio);

    // Define o QPixmap redimensionado no QLabel
    //teste->setPixmap(img_redimensionada);

    // Posiciona o QLabel
    //teste->move(-20, 450);

    //update();

    //meu_Jogador -> paint_bicycle();
    //meu_Jogador -> show();

    //qDebug() << "obter_posi_xe_cima: " << meu_Jogador->obter_posi_xe_cima();

}

scenegame::~scenegame()
{
    qDebug() << "Destruindo Cena do Jogo";

    // Libera a memória alocada para os objetos criados dinamicamente
    //delete label_fundo;
    delete minha_pista;
    delete meu_Jogador;

    // Se label_fundo também foi alocado dinamicamente, libere-o
    if (label_fundo) {
        delete label_fundo;  // Libera a memória alocada para label se ela não for nullptr
    }
    /*if (label2) {
        delete label2;  // Libera a memória alocada para label se ela não for nullptr
    }*/

}

void scenegame::timerEvent(QTimerEvent *)
{
    ///
    /// ---------------- Carrossel da Imagem do Fundo ----------------
    ///
    qDebug() << "evento cenário criado ";
    //QPixmap fundo(":/Imagens/Cidade_game2.png");
    int imageWidth = fundo.width();
    //int imageHeight = fundo.height();

    QPixmap combinedPixmap(800, 680);
    QPainter painter(&combinedPixmap);

    // Desenha a primeira parte da imagem, que ainda cabe na tela
    QPixmap croppedPixmap1 = fundo.copy(offset, 0, qMin(800, imageWidth - offset), 680);
    painter.drawPixmap(0, 0, croppedPixmap1);

    // Se a primeira imagem não preencher a tela, desenhe a segunda parte
    if (offset + 800 > imageWidth) {
        int remainingWidth = 800 - (imageWidth - offset);
        QPixmap croppedPixmap2 = fundo.copy(0, 0, remainingWidth, 680);
        painter.drawPixmap(imageWidth - offset, 0, croppedPixmap2);
    }

    label_fundo->setPixmap(combinedPixmap);
    //label_fundo->show();

    offset += speed;
    if (offset >= imageWidth) {
        offset -= imageWidth;  // Reinicia o offset para criar o loop
    }

    ///
    /// ---------------- Avança, Controla sobreposição de Imagens e Verifica a colisão ----------------
    ///
    minha_pista -> dec_vet_obstaculos(2);

    //vector<obstaculo*> vet_obst_pista;
    //vet_obst_pista = minha_pista->obter_vet_obstaculos();
    // O for já pode ser feito direto, vai iterar até o ultimo obstaculo sem precisar declarar um iterador
    for (obstaculo* obs : minha_pista->obter_vet_obstaculos())
    {
        int x_jogador = meu_Jogador->obter_posi_xe_cima();
        int x_obstaculo = obs->obter_posi_xe_cima();

        int y_jogador = meu_Jogador->obter_posi_ye_cima();
        int y_obstaculo = obs->obter_posi_ye_cima();

        if(x_obstaculo < 140)
        {
            /// ------- Faz o controle da sobreposição de Imagens aqui ---------
            if(y_jogador  < y_obstaculo)
                obs -> raise();
            else
                obs -> stackUnder(meu_Jogador);

            /// ------- Verificação da Colisão ---------
            ///
            // Sobre 2 porque ele printa a partir do meio da imagem
            // (x_obstaculo < x_jogador + meu_Jogador->obter_largura()/2) // inicio cone bike
            // (x_obstaculo < x_jogador - meu_Jogador->obter_largura()/2)) // fim cone bike
            if((x_obstaculo < x_jogador + meu_Jogador->obter_largura()/2)) // Frente da bicicleta
            {
                if(x_obstaculo > x_jogador - meu_Jogador->obter_largura()/2)  // Trás da bicicleta
                {
                    // Sobre 2 porque ele printa a partir do meio da imagem
                    // (x_jogador  > x_obstaculo - obs->obter_largura() + 20) // posi 38 inicio cone bike
                    // (x_jogador - (meu_Jogador ->obter_largura())/2 > x_obstaculo) // posi -24 fim cone bike

                    if((y_jogador < y_obstaculo + 5)&&(y_jogador + meu_Jogador->obter_altura()/2 - 15 > y_obstaculo)) // Verificar parte de baixo do cone
                    {
                        /*label2 = new QLabel("Game Over", this);
                        QFont font;
                        font.setBold(true);
                        font.setPointSize(40);
                        label2->setFont(font);*/

                        //label2->adjustSize();
                        //label2->move(50, 100);
                        //label2->show();
                        killTimer(timerId);
                        int count_aux = 0;
                        while(1)
                        {
                            count_aux = count_aux + 1;
                        }
                    }
                }
            }
            if(x_obstaculo < -80)
            {
                minha_pista -> destroi_obstaculo();
            }
        }
        /*
        // Sobre 2 porque ele printa a partir do meio da imagem
        // (x_jogador  > x_obstaculo - obs->obter_largura() + 20) // posi 38 inicio cone bike
        // (x_jogador - (meu_Jogador ->obter_largura())/2 > x_obstaculo) // posi -24 fim cone bike
        if((x_jogador  > x_obstaculo - obs->obter_largura() + 20)&&(x_jogador - (meu_Jogador ->obter_largura())/2 > x_obstaculo))
        {
            qDebug() << "Posição " << x_jogador - (meu_Jogador ->obter_largura())/2;

            // (y_jogador < y_obstaculo + 5) // Condição 1
            // (y_jogador + meu_Jogador->obter_altura()/2 - 15 > y_obstaculo) // Condição 2
            // A bicicleta terá uma largura de 10, seria um retângulo com largura 10
            if((y_jogador < y_obstaculo + 5)&&(y_jogador + meu_Jogador->obter_altura()/2 - 15 > y_obstaculo))
            {

                killTimer(timerId);
                int count_aux = 0;
                while(1)
                {
                    count_aux = count_aux + 1;
                }
                QLabel *label_game_over = new QLabel("Game\nOver", this);
                QFont font;
                font.setBold(true);
                font.setPointSize(80);
                label_game_over->setFont(font);

                label_game_over->adjustSize();
                label_game_over->move(100, 100);
            }
        }*/
    }

    ///
    /// ---------------- Criar Obstáculos ----------------
    ///
    // 60 -> Largura para os cones ficarem lado a lado, mas tem a velocidade, então pode encurtar60/speed
    // O rand do Qt é para saber se será criado a seguir ou dois "espaços cone" entre o prox cone a criar
    if(count_desl_esq > (60)*sorteador_espaço)
    {
        qDebug() << "Entrada função criar obstaculo ";
        // For para gerar o número de obstáculos na coluna
        //minha_pista -> cria_obstaculo(600, 400);
        int posi_y = QRandomGenerator::global()->bounded(2);
        if(posi_y == 0)
        {
            minha_pista -> cria_obstaculo(780, QRandomGenerator::global()->bounded(minha_pista -> obter_y_lim_cima(),
            minha_pista -> obter_y_lim_baixo()));
        }
        else
        {
            // Sortear posição do cone na coluna
            posi_y = QRandomGenerator::global()->bounded(minha_pista -> obter_y_lim_cima(),
                                                             minha_pista -> obter_y_lim_baixo());

            // Sortear se o proximo cone será colocado em cima ou em baixo do cone criado
            if(QRandomGenerator::global()->bounded(1) == 0)
            {
                if(posi_y + 30 < minha_pista -> obter_y_lim_baixo())
                {
                    // Adicionar o cone 1 na coluna no vetor de obstaculos, porque ele terá uma ordem menor na impressão
                    // Ele está "atrás"
                    minha_pista -> cria_obstaculo(780, posi_y);
                    minha_pista -> cria_obstaculo(780, QRandomGenerator::global()->bounded(posi_y + 30,
                                                                    minha_pista -> obter_y_lim_baixo()));
                }
                else
                {
                    minha_pista -> cria_obstaculo(780,
                    QRandomGenerator::global()->bounded(minha_pista -> obter_y_lim_cima(),
                    minha_pista -> obter_y_lim_baixo())-30);

                    minha_pista -> cria_obstaculo(780, posi_y);
                }
            }
            else
            {
                if(posi_y - 30 > minha_pista -> obter_y_lim_cima())
                {
                    minha_pista -> cria_obstaculo(780, QRandomGenerator::global()->bounded(
                                                         minha_pista -> obter_y_lim_cima(), posi_y - 30));

                    minha_pista -> cria_obstaculo(780, posi_y);
                }
                else
                {
                    minha_pista -> cria_obstaculo(780, posi_y);

                    minha_pista -> cria_obstaculo(780,
                    QRandomGenerator::global()->bounded(posi_y + 30,
                    minha_pista -> obter_y_lim_baixo()));
                }
            }
        }
        count_desl_esq = 0;
        sorteador_espaço = QRandomGenerator::global()->bounded(1,3);
    }
    else
    {
        count_desl_esq = count_desl_esq + 1;
    }
    /*
    if(count_desl_esq<30)
    {
        minha_pista -> dec_vet_obstaculos(2);
        count_desl_esq = count_desl_esq + 1;
    }
    else
    {
        qDebug() << "Novo obstaculo criado. ";
        minha_pista -> cria_obstaculo(400, 300);
        count_desl_esq = 0;
    }*/
}

void scenegame::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key Press Event in Scene";
    if (event->key() == Qt::Key_Up)
    {
        qDebug() << "Cima";
        meu_Jogador -> incrementa_ye_cima();
        //update();
        //meu_Jogador -> paint_bicycle();
        //meu_Jogador -> paintEvent();
    } else if (event->key() == Qt::Key_Down)
            {
                meu_Jogador -> decrementa_ye_cima();
        //update();
                //meu_Jogador -> paint_bicycle();
            }
            else
            {
                // Ignora o evento para outras teclas
                event->ignore();
            }
}
