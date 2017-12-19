struct colunaClientes
{
    string codigo;
    string nome;
    string cpf;
    string endereco;
    string telefone;
    string email;
};
class Clientes
{
public:
	Clientes()
	{
 	    this->lerArquivo();
 	}	   

    void executarCRUD(Tela *endJanela)
    {
	    string resp;
	    bool encontrou;
    	int x;
	    this->janela = endJanela;
	    opEscolhida="";
        while(opEscolhida != "S")
        {
            janela->limparArea(25,5,79,22);
	    	opEscolhida=janela->telaCRUD(25,5,78,21,listaClientes,"Clientes","Cadastro");
	    	if(opEscolhida != "S")
        	{
		   	    if(opEscolhida[0] == char(250))//Inicio de cadastro
		   	    {
			  	    janela->limparArea(25,5,79,22);
			  	    this->molduraCadastro("Cadastro de CLIENTE",true);
			  	    this->inclementaCodigo();
			  	    this->mostrarCodigo();
			  	    
			  	    janela->centralizar("Digite o nome do cliente","R");
			  	    this->perguntarNome();
			  	    
			  	    janela->centralizar("Digite o CPF do cliente","R");
			  	    this->perguntarCPF();
			  	    
			  	    janela->centralizar("Digite o endereco do cliente","R");
			  	    this->perguntarEndereco();
			  	    
			  	    janela->centralizar("Digite o telefone do cliente","R");
			  	    this->perguntarTelefone();
			  	    
			  	    janela->centralizar("Digite o E-mail do cliente","R");
			  	    this->perguntarEmail();
			  	    
			  	    resp=janela->perguntar("Confirma cadastro (S/N): ");
			  	    if(resp == "S")
			  	    {
	 		  		    this->adicionarDados(true);
	 		  		    janela->centralizar("Registro gravado com exito!","R");
	 		  		    getch();
			 		}
			  	}//Fim cadastro
			  	else
			  	{
			 	    x = opEscolhida.size();
			 	    opEscolhida.erase(3, x-3);
			 	    this->registro.codigo=opEscolhida;
			 	    
			 	    encontrou=this->verificaCodigo();
			 	    if(encontrou)
			 	    {
		 	  		    janela->limparArea(25,5,79,22);
		 	  		    this->molduraCadastro("Informacoes do CLIENTE",true);
		 	  		    this->mostrarRegistros();
		 	  		    resp=janela->perguntar("Deseja alterar, excluir ou voltar (A/E/V): ");
	 			 	}
	 	   		}
	 	   		
			
				if(resp == "A")
				{
 			        this->menuAlterar();
 				}
 				if(resp == "E")
 				{
 		 	        resp=janela->perguntar("Confirma a exclusao (S/N): ");
 		 	    	if(resp == "S")
 		 	    	{
	 			       this->excluirRegistro();
	 			       janela->centralizar("Registro excluido com exito!","R");
	 			       getch();
		   			}
	 			}
			}
	    	
		}
	}
	
	string verSeExiste(string codigo)
	{
 	    string resp;
 	    bool achou;
 	    this->registro.codigo = codigo;
 	    achou = this->verificaCodigo();
 	    if(achou)
 	    {
 		    resp = this->tabelaClientes[posicao].nome;
 		}
 		
 		if(not achou)
 		{
   		    resp = "";
   		}
 	    
 	    return resp;
 	}
private:
    Tela *janela;
    string opEscolhida;
    int posicao;
    vector<colunaClientes> tabelaClientes;
	vector<string> listaClientes;
	colunaClientes registro;


    void molduraCadastro(string titulo, bool moldura)
    {
	    if(moldura)
	    {
	        janela->montarMoldura(27,5,70,7,0);
	    	janela->montarMoldura(27,7,70,14,1);
	    
	    	gotoxy(27,7); cout << char(204);
			gotoxy(70,7); cout << char(185);
			textcolor(LIGHTBLUE);
			gotoxy(28,6); cout << titulo;
			textcolor(WHITE);
		
			gotoxy(28,8); cout <<  "Codigo   :";
			gotoxy(28,9); cout <<  "Nome     :";
			gotoxy(28,10); cout << "CPF      :";
			gotoxy(28,11); cout << "Endereco :";
			gotoxy(28,12); cout << "Telefone :";
			gotoxy(28,13); cout << "E-mail   :";
		}
		else
		{
 		    textcolor(LIGHTBLUE);
			gotoxy(28,6); cout << titulo;
			textcolor(WHITE);
 		}	    
	}
	
	void mostrarCodigo()
	{
 	    textcolor(DARKGRAY);
 		gotoxy(39,8); cout << this->registro.codigo;
 	    textcolor(WHITE);
 	}
	
	void mostrarRegistros()
	{
 	    this->mostrarCodigo();
 	    gotoxy(39,9); cout << this->tabelaClientes[posicao].nome;
 	    gotoxy(39,10); cout << this->tabelaClientes[posicao].cpf;
 	    gotoxy(39,11); cout << this->tabelaClientes[posicao].endereco;
 	    gotoxy(39,12); cout << this->tabelaClientes[posicao].telefone;
 	    gotoxy(39,13); cout << this->tabelaClientes[posicao].email;
 	}
	
	void perguntarNome()
	{
 	    gotoxy(39,9); getline(cin, this->registro.nome);
 	}
	
	void perguntarCPF()
	{
 	    gotoxy(39,10); getline(cin, this->registro.cpf);
 	}
 	
 	void perguntarEndereco()
	{
 	    gotoxy(39,11); getline(cin, this->registro.endereco);
 	}
 	
 	void perguntarTelefone()
	{
 	    gotoxy(39,12); getline(cin, this->registro.telefone);
 	}
 	
 	void perguntarEmail()
	{
 	    gotoxy(39,13); getline(cin, this->registro.email);
 	}
	
	void alterarDados()
	{
 	    this->tabelaClientes[posicao].nome = this->registro.nome;
 	    this->tabelaClientes[posicao].cpf = this->registro.cpf;
 	    this->tabelaClientes[posicao].endereco = this->registro.endereco;
 	    this->tabelaClientes[posicao].telefone = this->registro.telefone;
 	    this->tabelaClientes[posicao].email = this->registro.email;
 	    
 	    this->gravarArquivo();
 	}
	
	void menuAlterar()
	{
 	    vector<string> menu;
 	    string op, resp;
 	    
 	    janela->centralizar("Pressione G para gravar as alteracoes ou ESC para sair a qualquer momento","R");
 	    
 	    this->registro.nome = this->tabelaClientes[posicao].nome;
 	    this->registro.cpf = this->tabelaClientes[posicao].cpf;
 	    this->registro.endereco = this->tabelaClientes[posicao].endereco;
 	    this->registro.telefone = this->tabelaClientes[posicao].telefone;
 	    this->registro.email = this->tabelaClientes[posicao].email;
 	    
 	    while(op != "G")
 	    {
 		    menu.clear();
			menu.push_back("Nome     : "+this->registro.nome);
 	    	menu.push_back("CPF      : "+this->registro.cpf);
 	    	menu.push_back("Endereco : "+this->registro.endereco);
 	    	menu.push_back("Telefone : "+this->registro.telefone);
 	    	menu.push_back("E-mail   : "+this->registro.email); 
 	        op = janela->montarMenu(27,8,70,menu,"",false);
 	    
 	    	janela->centralizar("Tecle enter para concluir a insercao do dado","R");
 	    
 	    	if(op[0] == 'N')
 	    	{
		 		textcolor(BLACK); textbackground(WHITE);
 	    		janela->limparArea(39,9,69,9);
 		        this->perguntarNome();
 		        textcolor(WHITE); textbackground(BLACK);
 		        janela->limparArea(39,9,69,9);
 			}
 			
 			if(op[0] == 'C')
 	    	{
		 		textcolor(BLACK); textbackground(WHITE);
 	    		janela->limparArea(39,10,69,10);
 		        this->perguntarCPF();
 		        textcolor(WHITE); textbackground(BLACK);
 		        janela->limparArea(39,10,69,10);
 			}
 			
 			if(op[0] == 'E' && op[1] == 'n')
 	    	{
		 		textcolor(BLACK); textbackground(WHITE);
 	    		janela->limparArea(39,11,69,11);
 		        this->perguntarEndereco();
 		        textcolor(WHITE); textbackground(BLACK);
 		        janela->limparArea(39,11,69,11);
 			}
 			
 			if(op[0] == 'T')
 	    	{
		 		textcolor(BLACK); textbackground(WHITE);
 	    		janela->limparArea(39,12,69,12);
 		        this->perguntarTelefone();
 		        textcolor(WHITE); textbackground(BLACK);
 		        janela->limparArea(39,12,69,12);
 			}
 			
 			if(op[0] == 'E' && op[1] == '-')
 	    	{
		 		textcolor(BLACK); textbackground(WHITE);
 	    		janela->limparArea(39,13,69,13);
 		        this->perguntarEmail();
 		        textcolor(WHITE); textbackground(BLACK);
 		        janela->limparArea(39,13,69,13);
 			}
 		
 			//Sair da função
 	    	if(op == "S") break;
 			
			//Gravar alterações		
 			if(op[0] == 'G')
 			{
		        resp=janela->perguntar("Confirma alteracoes (S/N): ");
		    	if(resp== "S")
		    	{
 		            this->alterarDados();
 		    		janela->centralizar("Registro alterado com exito!","R");
 		    		getch();
				}
			}
			janela->centralizar("Pressione G para gravar as alteracoes ou ESC para sair a qualquer momento","R");
		}
		
 	}
	
	void excluirRegistro()
	{
 	    this->tabelaClientes.erase(this->tabelaClientes.begin() + this->posicao);
 	    this->gravarArquivo();
 	}
	
	bool verificaCodigo()
 	{
 	    bool achei=false;
 	    int x;
 	    for(x=0; x<this->tabelaClientes.size(); x++)
 	    {
 		    if(this->tabelaClientes[x].codigo == this->registro.codigo)
 		    {
  			    achei=true;
  			    posicao=x;
  			    break;
  			}
 		}
 		return achei;
 	}
	
	void inclementaCodigo()
	{
 	    int ultimoNumero, codigo, x, c;
 	    stringstream stringCodigo;
 	    
 	    if(this->tabelaClientes.size() == 0)
 		{
 	 	    this->registro.codigo = "001";
 	 	}
 	 	else
 	 	{
 	        ultimoNumero = this->tabelaClientes.size()-1;//Captura o ultimo codigo da tabela
 	    	this->registro.codigo = this->tabelaClientes[ultimoNumero].codigo;
 	    	codigo = atoi ( this->registro.codigo.c_str());
 	    	codigo++;//Inclementa codigo
 	    	stringCodigo << codigo;
 	    	this->registro.codigo = stringCodigo.str();
 	    	if(registro.codigo.size() < 3)
 	    	{
 		        c= 3 - registro.codigo.size();
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
	
	void adicionarDados(bool gravar)
	{
 	    this->tabelaClientes.push_back(this->registro);
 	    if(gravar) this->gravarArquivo();
 	}
	
	void ajustaListaString(int ci, int cf)
 	{
 	    int espaco, c, x, y;
 	    stringstream juncao;
 	    
 	    for(x=0; x<tabelaClientes.size(); x++)
 	    {
	        espaco=cf-ci-2;
	 	    juncao.str("");
	 	    juncao << tabelaClientes[x].codigo<<"|";
	 		espaco-=tabelaClientes[x].codigo.size();
	 		
	 		espaco-=18;//Espaço para ultimo valor inserido na string
	 		espaco=(espaco/2);
	 		espaco-=2;////////////////////////////
	 		//Ajusta tamanho do nome
	 		if(tabelaClientes[x].nome.size() > espaco)
	 		{
	   		    for(y=0; y<espaco-1; y++)
	   		    {
 		 		    juncao << tabelaClientes[x].nome[y];
 		 		}
 		 		juncao <<".|";
	   		}
	   		else if(tabelaClientes[x].nome.size() == espaco)
	   		{
	 	 	    juncao << tabelaClientes[x].nome<<"|";
		   	}
		   	else
		   	{
 			    c=espaco-tabelaClientes[x].nome.size();
 			    juncao << tabelaClientes[x].nome;
 			    for(y=0; y<c; y++)
 			    {
	 		 	    juncao << " ";
	 		 	}
	 		 	juncao<<"|";
 		   	}
 		   	//Ajusta tamanho da categoria
 		   	espaco+=2;/////////////////////////////
 		   	if(tabelaClientes[x].telefone.size() > espaco)
 		   	{
	   		    for(y=0; y<espaco-1; y++)
	   		    {
 		 		    juncao << tabelaClientes[x].telefone[y];
 		 		}
 		 		juncao <<".|";
	   		}
	   		else if(tabelaClientes[x].telefone.size() == espaco)
	   		{
	 	 	    juncao << tabelaClientes[x].telefone<<" | ";
	   		}
	   		else
		   	{
 			    c=espaco-tabelaClientes[x].telefone.size();
 			    juncao << tabelaClientes[x].telefone;
 			    for(y=0; y<c; y++)
 			    {
	 		 	    juncao << " ";
	 		 	}
	 		 	juncao<<"|";
 		   	}
 		   	espaco=18;
 		   	//Ajusta tamanho do valor
 		   	if(tabelaClientes[x].email.size() > espaco)
 		   	{
	   		    for(y=0; y<espaco-3; y++)
	   		    {
 		 		    juncao << tabelaClientes[x].email[y];
 		 		}
 		 		juncao <<"...";
	   		}
	   		else if(tabelaClientes[x].email.size() == espaco)
	   		{
	 	 	    juncao << tabelaClientes[x].email;
	   		}
	   		else
		   	{
 			    c=espaco-tabelaClientes[x].email.size();
 			    juncao << tabelaClientes[x].email;
 			    for(y=0; y<c; y++)
 			    {
	 		 	    juncao << " ";
	 		 	}
 		   	}
 		   	//Salva string
	   		this->listaClientes.push_back(juncao.str());
 		}
 	}
	
	void lerArquivo()
 	{
 	    ifstream arquivo;
 	    
 	    arquivo.open("clientes.txt");
 	    
 	    while(not arquivo.eof())
 	    {
  		    getline(arquivo, registro.codigo, '|');
  		    getline(arquivo, registro.nome, '|');
  		    getline(arquivo, registro.cpf, '|');
  		    getline(arquivo, registro.endereco, '|');
  		    getline(arquivo, registro.telefone, '|');
  		    getline(arquivo, registro.email);
  		    
  		    if(this->registro.codigo != "")
  		    {
	 		    this->adicionarDados(false);
	 		}
  		}
  		
  		arquivo.close();
  		
  		this->ajustaListaString(25,78);
 	}
 	
 	void gravarArquivo()
 	{
 	    ofstream arquivo;
 	    int x;
 	    
 	    arquivo.open("clientes.txt");
 	    
 	    for(x=0; x<tabelaClientes.size(); x++)
 	    {	 	    
	 	    arquivo << this->tabelaClientes[x].codigo
	 	    		<< "|"
	 	    		<< this->tabelaClientes[x].nome
	 	    		<< "|"
	 	    		<< this->tabelaClientes[x].cpf
	 	    		<< "|"
	 	    		<< this->tabelaClientes[x].endereco
	 	    		<< "|"
	 	    		<< this->tabelaClientes[x].telefone
	 	    		<< "|"
	 	    		<< this->tabelaClientes[x].email
	 	    		<< endl;
	 	}
	 	
	 	arquivo.close();
	 	
	 	this->listaClientes.clear();
	 	this->ajustaListaString(25,78);
 	}
	
};
