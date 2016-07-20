#include <Sistema.h>


/*
        ------------------- TODOS OS COMANDOS PODEM SER DIGITADOS EM LETRAS MAIÚSCULAS OU MINÚSCULAS -----------------------

        Para usar o programa use o create como um comando normal de console. Ex: para criar o processo teste: "create teste"
        Logo após vai perguntar o número de ciclos que o processo tem para executar (apenas números inteiros);
        Para ver a hora atual do sistema apenas digite "time" (horario real do sistema);
        Para ver a lista de processos que esta sendo executado ou na fila digite "ps"
        Para eliminar um processo use o comando kill e depois digite o PID do processo (que pode ser visto com o comando ps);
        Para "Desligar o sistema" digite shutdown (os processos serão encerrados e saira do programa)
        Para limpar o console digite "clear" <- Não foi pedido mas é útil!


*/







using namespace std;
Sistema sys;
string para_maiusculo(string op);
void WINAPI ThreadUm ( void )
{

    sys.create("SYS INI",1,0);
    Sleep(200);
    sys.create("ini1",9999,1);
    Sleep(1000);
    sys.create("ini2",19999,2);
    Sleep(1000);
    sys.create("ini3",18888,3);
    Sleep(2000);
    sys.create("ini4",12222,4);
    while(true)
    {
        //cout << sys.processos_size() << endl;
        if(sys.processos_size() > 0)
            sys.executa();
        Sleep(2000);

    }


}


int main ( void )
{

	unsigned long iID;
	HANDLE hThreadUm; // hThreadDois;
    string nome;
    hThreadUm = CreateThread ( NULL, 0, (LPTHREAD_START_ROUTINE)ThreadUm, NULL, 0, &iID);
	//hThreadDois = CreateThread ( NULL, 0, (LPTHREAD_START_ROUTINE)ThreadDois, NULL, 0, &iID);
    string op;
    int ciclos;
    int process_id = 0;

    int pid;
	while (true)
	{

//			cout << "Lista de comandos: " <<endl;
//			cout << "CREATE para criar processos" <<endl;
//			cout << "TIME para ver o horario atual" <<endl;
//			cout << "PS para ver a lista de processos" <<endl;
//			cout << "KILL para terminar um processo" <<endl;
//			cout << "SHUTDOWN para desligar o sistema" <<endl;
			getline(cin,op);



			op = para_maiusculo(op);

            if(!op.find("CREATE"))
            {
                cout << "Numero de ciclos do processo: ";
                cin >> ciclos;
                nome = op;
                nome.erase(0,7);
                //cout << nome << "<<<" <<endl;
                process_id++;
                sys.create(nome, ciclos, process_id);
            }
            if(op == "TIME")
            {
                cout << "Horario atual: " <<sys.hora()<< endl;
            }
            if(op == "PS")
            {
                sys.ps();
            }
            if(op == "KILL")
            {
                cout << "PID do processo: ";
                cin >> pid;
                sys.kill(pid);
            }
            if(op == "SHUTDOWN")
            {
                sys.desliga();
                cout << "Desligando em ";
                for(int des = 3; des > 0; des--)
                {
                    cout << des << "...";
                    Sleep(1000);
                }
                cout << endl;
                break;
            }
             if(op == "CLEAR")
            {
                system("cls");
            }

            fflush(stdin);

	}

	TerminateThread(hThreadUm,0);
    system("cls");
    cout << "Aperte qualquer tecla para sair..." << endl;
	getchar();

 return/*Rafa*/ 0;
}

string para_maiusculo(string op)
{
    for(unsigned int j = 0; j <  op.length(); j++) // coloca tudo em maiusculo para não ter problemas
                op[j] = toupper(op[j]);
    return/*Rafa*/ op;
}

