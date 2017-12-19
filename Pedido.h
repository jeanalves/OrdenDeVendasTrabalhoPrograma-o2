struct colunaPedido
{
    string codigo;
    string cliente;
    string peca;
    string servico;
    string descricao;
    string dateTime;
    
    string valor;
};
class Pedido
{
public:
    void executarPedido(Tela *endJanela, Pecas *endPec, Servicos *endSer, Clientes *endCli)
    {
	    this->janela = endJanela;
	    this->pec = endPec;
	    this->ser = endSer;
	    this->cli = endCli;
	    this->gerarPedido();
	    
	}
private:
    vector<colunaPedido> tabelaPedido;
    colunaPedido registro;
    Tela *janela;
    Pecas *pec;
	Servicos *ser; 
	Clientes *cli;  

	void gerarPedido()
	{
        string resp;
        
 	    this->molduraPedido();
		this->inclementaCodigo();
		janela->centralizar("Digite o codigo do cliente","R");
		textcolor(DARKGRAY);
		gotoxy(36,8); cout << this->registro.codigo;
		resp="";
		while(resp == "")
		{
		    janela->centralizar("Digite o codigo do cliente","R");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(26,10); cout << "                    ";
			gotoxy(26,10); cout << "Cliente : "; getline(cin, registro.cliente);
			textcolor(WHITE);
			textbackground(BLACK);
		
			resp=cli->verSeExiste(this->registro.cliente);
			if(resp == "")
			{
		        janela->centralizar("Cliente nao existe, tente denovo","R");
		        getch();
			}
			else
			{
			 	this->registro.cliente = resp;
	 		    gotoxy(36,11); cout << this->registro.cliente;
	 		    getch();
	 		}
		}
 	}


    void molduraPedido()
    {
        int y;
	 	 
	    janela->montarMoldura(25,5,78,7,0);
	    janela->montarMoldura(25,15,78,19,0);
	    janela->montarMoldura(25,7,78,21,1);
	    for(y=5+1; y<15; y++)
	    {
	   	    gotoxy(46,y); cout << char(186);
	   	    gotoxy(62,y); cout << char(186);
	   	}
	   	gotoxy(25,7); cout << char(204);
	   	gotoxy(78,7); cout << char(185);
	   	
	   	gotoxy(46,7); cout << char(206);
	   	gotoxy(62,7); cout << char(206);
	   	
	   	gotoxy(46,5); cout << char(203);
	   	gotoxy(62,5); cout << char(203);
	   	
	   	textcolor(LIGHTGREEN);
	   	gotoxy(26,6); cout << "Dados do pedido";
	   	gotoxy(47,6); cout << "Pecas";
	   	gotoxy(63,6); cout << "Servicos";
	   	textcolor(WHITE);
	   	
	   	gotoxy(26,8); cout <<  "Codigo  :";
	   	gotoxy(26,10); cout << "Cliente :";
	   	gotoxy(26,11); cout << "Nome    :";
	   	
	   	textcolor(DARKGRAY);
	   	gotoxy(26,16); cout << "Situacao:";
	    textcolor(WHITE);
	    
	    gotoxy(26,20); cout << "Valor :";
	    
	}
	
	void inclementaCodigo()
	{
 	    int ultimoNumero, codigo, x, c;
 	    stringstream stringCodigo;
 	    
 	    if(this->tabelaPedido.size() == 0)
 		{
 	 	    this->registro.codigo = "00001";
 	 	}
 	 	else
 	 	{
 	        ultimoNumero = this->tabelaPedido.size()-1;//Captura o ultimo codigo da tabela
 	    	this->registro.codigo = this->tabelaPedido[ultimoNumero].codigo;
 	    	codigo = atoi ( this->registro.codigo.c_str());
 	    	codigo++;//Inclementa codigo
 	    	stringCodigo << codigo;
 	    	this->registro.codigo = stringCodigo.str();
 	    	if(registro.codigo.size() < 5)
 	    	{
 		        c= 5 - registro.codigo.size();
 		    	stringCodigo.str("");
 		    	for(x=0; x<c; x++)
	    	 	{
 			        stringCodigo << "0";
 				}
 				stringCodigo << codigo;
 				this->registro.codigo = stringCodigo.str();
 			}
 		}
 		//Criar laço que procure por outro codigo não usado
 		/*
 		if(registro.codigo == "1000")
 		{
   		    for(x=0; x<this->tabelaClientes.size(); x++)
   		    {
		 	    if()
		 	}
   		}
 	    */
 	}

};
