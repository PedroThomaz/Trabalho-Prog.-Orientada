#include "pista.h"
#include "obstaculo.h"

pista::pista(const QPixmap& _imagem_fundo, int _y_limite_cima, int _y_limite_baixo, QWidget *_wid_tela)
    : imagem_fundo(_imagem_fundo),
    wid_tela(_wid_tela)
{
    //wid_tela = _wid_tela;
    y_limite_cima = _y_limite_cima;
    y_limite_baixo = _y_limite_baixo;
}

pista::~pista()
{
    // Libera a memória de todos os obstáculos criados
    for (obstaculo* obs : vetor_obstaculos)
    {
        delete obs;  // Deleta o objeto obstaculo
    }
    vetor_obstaculos.clear();  // Limpa o vetor após a exclusão dos obstáculos
}

void pista::cria_obstaculo(int _posi_xe_cima, int _posi_ye_cima)
{
    obstaculo* novo_obstaculo = new obstaculo(wid_tela, _posi_xe_cima, _posi_ye_cima);
    vetor_obstaculos.push_back(novo_obstaculo);
    novo_obstaculo->show();
    //setFocusPolicy(Qt::StrongFocus);
}

void pista::dec_vet_obstaculos(int _vel)
{
    for (obstaculo* obs : vetor_obstaculos)
    {
        obs->decrementa_xe_cima(_vel);
        //update();
    }
}

void pista::destroi_obstaculo(void)
{
    if (!vetor_obstaculos.empty())
    {
        delete vetor_obstaculos.front();  // Exclui o objeto apontado pelo primeiro ponteiro
        vetor_obstaculos.erase(vetor_obstaculos.begin());  // Remove o primeiro ponteiro do vetor
    }
}
