#include<iostream>
#include<conio2.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

#include"Tela.h"
#include"Categorias.h"
#include"Pecas.h"
#include"Servicos.h"
#include"Clientes.h"
#include"Pedido.h"

main()
{
    Tela janela;
    Categorias cat;
	Pecas pec;
	Servicos ser;
	Clientes cli;
	Pedido ped;
    vector <string> tabelaOpecoes;
    string op;
    
    tabelaOpecoes.push_back("1 - Manter Categorias");
    tabelaOpecoes.push_back("2 - Manter Pecas");
    tabelaOpecoes.push_back("3 - Manter Servicos");
    tabelaOpecoes.push_back("4 - Manter Cliente");
    tabelaOpecoes.push_back("5 - Gerar Pedido");
    tabelaOpecoes.push_back("6 - Consulta");
    tabelaOpecoes.push_back("0 - Sair");
    
    while(true)
    {
        clrscr();
        
        textcolor(WHITE);
        //Rodapé
        janela.montarMoldura(1,23,80,25,0);
        janela.centralizar("Escolha uma opcao","R");
        //Cabeçalho
        janela.montarMoldura(1,1,80,3,0);
        janela.centralizar("Ordem de venda","T");
        
        op=janela.montarMenu(1,5,0,tabelaOpecoes,"",true);
        
        if(op[0] == '1')
        {
    	    cat.executarCRUD(&janela);
 	  	}
        
        if(op[0] == '2')
        {
    	    pec.executarCRUD(&janela, &cat);
 	  	}
        
        if(op[0] == '3')
        {
	        ser.executarCRUD(&janela, &cat);
 	  	}
 	  	
 	  	if(op[0] == '4')
        {
	        cli.executarCRUD(&janela);
 	  	}
 	  	
 	  	if(op[0] == '5')
 	  	{
 		    ped.executarPedido(&janela, &pec, &ser, &cli);
 		}
        
        if(op[0] == '0')break;
    }

}
