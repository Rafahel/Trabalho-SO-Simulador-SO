#ifndef SISTEMA_H
#define SISTEMA_H
#include <cstdio>
#include <windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <time.h>
#include <vector>
#include <ctime>

using namespace std;
class Sistema
{
    public:
        Sistema();
        virtual ~Sistema();
        void create(string proc, int cic, int p);
        string hora();
        void ps();
        void kill(int id);
        void termina_processo();
        void checa_ciclos();
        int processos_size();
        void executa();
        void desliga();


    protected:
        vector<string> processos;
        vector<int> pid;
        vector<int> ciclos;
        vector<string> horario;
        vector<int> estado;
        char time[80];


    private:
};

#endif // SISTEMA_H /*Rafa*/
