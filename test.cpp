#include <iostream>
#include <locale> 
#include <bits/stdc++.h> 

using namespace std;

// Função para calcular o Ponto de Função
void calcularPontoDeFuncao(int frates[][3], int fac_rate)
{
    // Unidades Funcionais
    string unidadesFuncionais[5] = {
        "Entradas Externas",
        "Saídas Externas",
        "Consultas Externas",
        "Arquivos Lógicos Internos",
        "Arquivos de Interface Externa"};

    // Taxas de Peso
    string taxasDePeso[3] = {"Baixo", "Médio", "Alto"};

    // Fatores de Peso
    int fatoresDePeso[5][3] = {
        {3, 4, 6},
        {4, 5, 7},
        {3, 4, 6},
        {7, 10, 15},
        {5, 7, 10},
    };

    int UFP = 0;

    // Calculando o UFP (Ponto de Função Não Ajustado)
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int freq = frates[i][j];
            UFP += freq * fatoresDePeso[i][j];
        }
    }

    // 14 fatores
    string aspectos[14] = {
        "backup e recuperação confiáveis são necessários?",
        "comunicação de dados é necessária?",
        "há funções de processamento distribuído?",
        "o desempenho é crítico?",
        "o sistema operará em um ambiente operacional já existente e altamente utilizado?",
        "entrada de dados online é necessária?",
        "a entrada de dados online requer que a transação de entrada seja construída em várias telas ou operações?",
        "os arquivos mestres são atualizados online?",
        "as entradas, saídas, arquivos ou consultas são complexos?",
        "o processamento interno é complexo?",
        "o código é projetado para ser reutilizável?",
        "a conversão e instalação estão incluídas no projeto?",
        "o sistema é projetado para múltiplas instalações em diferentes organizações?",
        "o aplicativo é projetado para facilitar mudanças e facilitar o uso pelo usuário?"};

    /*
    Escala de Avaliação dos Fatores
    Avalie os seguintes aspectos em uma escala de 0 a 5:
    0 - Sem influência
    1 - Incidental
    2 - Moderado
    3 - Médio
    4 - Significativo
    5 - Essencial
    */

    int sumF = 0;

    // Recebendo a entrada da taxa dos fatores
    for (int i = 0; i < 14; i++)
    {
        int rate = fac_rate;
        sumF += rate;
    }

    // Calcular o CFP
    double CAF = 0.65 + 0.01 * sumF;

    // Calcular o Ponto de Função (FP)
    double FP = UFP * CAF;

    cout << "Análise de Pontos de Função" << endl;
    cout << "Pontos de Função Não Ajustados (UFP) : " << UFP << endl;
    cout << "Fator de Ajuste de Complexidade (CAF) : " << CAF << endl;
    cout << "Pontos de Função (FP) : " << FP << endl;
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int frates[5][3] = {
        {0, 50, 0},
        {0, 40, 0},
        {0, 35, 0},
        {0, 6, 0},
        {0, 4, 0}};

    int fac_rate = 3;

    calcularPontoDeFuncao(frates, fac_rate);

    return 0;
}