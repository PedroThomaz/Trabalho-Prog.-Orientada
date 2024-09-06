#include "menu_corrida_c.h"
#include "ui_menu_corrida_c.h"
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QDebug>
#include <QPixmap>
#include "scenegame.h"

menu_corrida_c::menu_corrida_c(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu_corrida_c)
{
    ui->setupUi(this);
    setWindowTitle("Bike Racing");
    this->resize(this->width(), 680);

    ///
    /// Configuração Texto Bike Racing
    ///
    label = new QLabel("Bike Racing", this);
    QFont font;
    font.setBold(true);
    font.setPointSize(40);
    label->setFont(font);

    label->adjustSize();
    label->move((width() - label->width()) / 2, 50);



    ///
    /// Configuração Botão Start Game
    ///
    button = new QPushButton("Start Game", this);
    font = button->font();
    font.setPointSize(16);  // Define o tamanho da fonte para 16 pontos
    button->setFont(font);
    button->setFixedSize(150, 50);
    //button->setStyleSheet("text-align: center;");
    button->move((width() - button->width()) / 2, (height() - button->height()) / 2);

    qDebug() << "Conectar Botão Start Game.";
    connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

}

menu_corrida_c::~menu_corrida_c()
{
    qDebug() << "Destruindo menu_corrida_c";

    // Libera a memória alocada para os objetos criados dinamicamente
    button = nullptr;
    label = nullptr;
    _scene = nullptr;
    _viewport = nullptr;
    _layout = nullptr;
    //delete _viewport;
    //delete _layout;

    // Libera a memória alocada para o objeto UI
    delete ui;
}

void menu_corrida_c::onButtonClicked()
{
    // Apagar a tela inicial
    qDebug() << "Botão Start Game clicado.";
    button->hide();
    label -> hide();
    //button->deleteLater();
    //label -> deleteLater();
    //label = nullptr;
    //delete button;
    //delete label;
    int windowWidth = this->width();
    int windowHeight = this->height();

    qDebug() << "Largura da janela:" << windowWidth;
    qDebug() << "Altura da janela:" << windowHeight;

    _scene = new scenegame(this);
    _scene->show();
    //jogo->show();
    //QPixmap fundo(":/Imagens/Cidade_game.png");
    //label_fundo = new QLabel(this);
    //label -> setPixmap(fundo);
    //QPixmap scaledPixmap = fundo.scaled(800, 680, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Define o QPixmap redimensionado na QLabel
    //label->setPixmap(scaledPixmap);

    // Ajusta o tamanho da QLabel para caber na imagem redimensionada
    //label->setFixedSize(scaledPixmap.size());

    // Centraliza a QLabel na janela
    //label->move((width() - label->width()) / 2, (height() - label->height()));

    // Configura o label como widget central
    //setCentralWidget(label);
    // Redimensiona a imagem para caber em uma tela de 800x680, mantendo a proporção
    //QPixmap scaledPixmap = pixmap.scaled(800, 680, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Define o QPixmap redimensionado na QLabel
    //label->setPixmap(scaledPixmap);

    // Ajusta o tamanho da QLabel para caber na imagem redimensionada
    //label->setFixedSize(scaledPixmap.size());

    //label->move((width() - label->width()) / 2, (height() - label->height()) / 2);

    // Configura o label como widget central
    //setCentralWidget(label);

    /*_scene = new scenegame(this);
    //_scene->setAxis(false);
    _viewport = new QGraphicsView(this);
    _viewport->setScene(_scene);
    //_viewport->setBackgroundBrush(QPixmap(":/images/space.jpg"));
    _layout = new QVBoxLayout(this);
    _layout->addWidget(_viewport);
    setLayout(_layout);
    //setFixedSize(sizeHint());
    setFixedSize(800, 680); // Configurar tamanho da janela da scene
    //setWindowTitle("Asteroids");*/

}
