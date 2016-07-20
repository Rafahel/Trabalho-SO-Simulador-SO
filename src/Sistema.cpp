#include "Sistema.h"





void Sistema::create(string proc, int cic, int p)
{
    processos.push_back(proc);
    pid.push_back(p);
    estado.push_back(0);
    //cout << processos.size();
    ciclos.push_back(cic);

    horario.push_back(hora());
}

void Sistema::ps()
{

    int j = processos.size();
    //cout << processos.size();
    string est;
    cout << "PID        FILE        CRIACAO         ESTADO" << endl;//          CICLOS RESTANTES" << endl;
    for(int i = 0; i < j; i++)
        {

            if(estado[i] == 0)
                est = "Apto";
            else
                est = "Executando";
            cout << pid[i] << "           "<< processos[i]  << "        " << horario[i] <<"         " << est <<"             " <<endl; // ciclos[i] << endl;
        }
        cout << "\n";


}

string Sistema::hora()
{
    string hora;
    std::time_t rawtime;
    std::tm* timeinfo;
    char buffer [80];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer,80,"%H:%M:%S",timeinfo);
    //std::puts(buffer);
    hora = buffer;
    //cout << buffer << endl;
    return buffer;


}


void Sistema::termina_processo()
{
    processos.erase(processos.begin(),processos.begin()+1);
    pid.erase(pid.begin(),pid.begin()+1);
    estado.erase(estado.begin(),estado.begin()+1);
    ciclos.erase(ciclos.begin(),ciclos.begin()+1);
    horario.erase(horario.begin(),horario.begin()+1);
}



int Sistema::processos_size()
{

    return processos.size();
}





void Sistema::executa()
{
    int i = 0;

    while(ciclos[i] > 0 )
    {
        estado[i] = 1;
        //cout << "Ciclos = " << ciclos[0] << endl;
        ciclos[i]--;
        Sleep(1000);
    }
    termina_processo();
    i++;

}


void Sistema::kill(int id)
{
    int x = processos.size();

    for(int i = 0; i < x; i++)
    {

        if(pid[i] == id )
        {
            processos.erase(processos.begin() + i);
            ciclos.erase(ciclos.begin() + i);
            pid.erase(pid.begin() + i);
            estado.erase(estado.begin() + i);
            horario.erase(horario.begin() + i);

        }

    }

}


void Sistema::desliga()
{
    int n_processos = processos.size();
//    cout << "Numero de processos a eliminar: " << n_processos << endl;
    for(int i = n_processos; i > 0; i--)
    {
        cout << "Eliminando processo: " << processos[i-1] << endl;
        processos.erase(processos.begin() + i);
        Sleep(1000);
    }
}
Sistema::Sistema()
{
    //*Rafa*/
}

Sistema::~Sistema()
{
    //*Rafa*/
}
