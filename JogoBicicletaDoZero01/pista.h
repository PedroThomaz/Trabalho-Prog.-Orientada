#ifndef PISTA_H
#define PISTA_H

#include <QPixmap>
#include "obstaculo.h"
#include <vector>

using namespace std;

class pista
{
public:
    pista(const QPixmap& _imagem_fundo, int _y_limite_cima, int _y_limite_baixo, QWidget *_wid_tela);
    ~pista();
    void cria_obstaculo(int _posi_xe_cima, int _posi_ye_cima);
    void dec_vet_obstaculos(int _vel);
    void destroi_obstaculo(void);

    int obter_y_lim_cima(void){    return y_limite_cima;}
    int obter_y_lim_baixo(void){    return y_limite_baixo;}
    // Primeiro const é para retornar o ponteiro vet_obstaculos com permissão de leitura
    // O segundo const é uma proteção adicional aos dados, mas poderia ser retirado
    vector<obstaculo*>& obter_vet_obstaculos(void){    return vetor_obstaculos;}

private:
    QPixmap imagem_fundo;// Seria o tipo de pista, cada uma tem sua tela de fundo
    int y_limite_cima;  // 360, cada pista tem os seus limites
    int y_limite_baixo;  // 565
    int distancia;
    QWidget *wid_tela;

    std::vector<obstaculo*> vetor_obstaculos;
};

#endif // PISTA_H
