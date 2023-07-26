#ifndef LEITURA_HPP
#define LEITURA_HPP

#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <locale>
#define endl '\n'

using namespace std;

typedef struct palavra {
    int quantidade = 1;
    vector<int> linha;
    vector<int> distancia;
    vector<int> posicao;
    vector<int> paragrafo;
    vector<int> sentenca;
}Sword;

typedef struct sentecas {
    int numeroPalavrasComStopWord = 0, numeroPalavraSemStopWord = 0;

}Senteca;

typedef struct conjunto {
    int linhaF, linhaI, numSetencas;
    vector<Senteca> vetorSentencas;

}Paragrafo;

void readPrincipal();

void preencheMapPontos(unordered_map<char, bool> &pontos);
void readStopWords(unordered_map<string, bool> &stopWords);
void readExpressoes(unordered_map<string, vector<int>> &expressoes);

void inserePrintPorParagrafo(map<string, Sword> &mapPrintPorParagrafo, string palavraLinha, Sword &wordParagrados, int cont, int supremeConte, int paragrafoQuantidade, int contSentencas);
void inserePrintGeral(unordered_map<string, Sword> &mapPrintGeral, string palavraLinha, Sword &wordParagrados, int cont, int supremeConte, int paragrafoQuantidade, int contSentencas, int &contPalavras);

void checaExpressao(unordered_map<string, vector<int>> &map, int cont, string line);
string tiraReticencia(string linha);
string removePontuacao(string num, unordered_map<char, bool>pontos);
string converterAcentuadasParaMinusculas(string num);
bool temNumero(string palavra);
bool Pontuacao(string *num, int *contExpressoes, int &Num_StopWord);
void DistanciaParagrafo(map<string, Sword> &m1);
void DistanciaGeral(unordered_map<string, Sword> &m1);
void outputGeral(vector<Senteca> sentecas, vector<Paragrafo> paragrafos, int quantParagrafos, unordered_map<string, Sword> &m1, unordered_map<string, vector<int>>expressoes);
void outputParagrafos(vector<Senteca> sentecas, vector<Paragrafo> paragrafos, int quantParagrafos, vector< map<string, Sword> > &m1, unordered_map<string, vector<int>>expressoes, int *aux);
bool isPonto(char c, unordered_map<char, bool>pontos);
#endif