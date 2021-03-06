struct colunaPecas
{
    string codigo;
    string nome;
    string categoria;
    string valor;
};
class Pecas
{
public:
	
	Pecas()
	{
 	    this->lerArquivo();
	}   
    
    void executarCRUD(Tela *endJanela, Categorias *endCat)
    {
	    string resp;
	    bool encontrou;
	    int x;
        this->janela = endJanela;
        this->cat = endCat;
        
        opEscolhida="";
        while(opEscolhida != "S")
        {
            janela->limparArea(25,5,79,22);
        	opEscolhida=janela->telaCRUD(25,5,78,21,listaPecas,"Pecas","Cadastrar");
        	if(opEscolhida != "S")
        	{
		   	    if(opEscolhida[0] == char(250))//Inicio de cadastro
		   	    {
	 			    janela->limparArea(25,5,79,22);
	        		this->molduraCadastro("Cadastro de PECAS",true);
					encontrou=true;   
	 			    while(encontrou)
	 			    {
 				        //Valida��o de codigo
		   		        this->perguntarCodigo();
		   		    	encontrou=this->verificaCodigo();
		   		    	if(encontrou)
		   		    	{
 			 			    janela->centralizar("Registro ja existente, tente outro","R");
 			 			    janela->limparArea(39,8,64,8);
 			 			}
 			 			else if(this->registro.codigo.size() > 3)
 			 			{
		 	 			    janela->centralizar("O Codigo nao pode ultrapassar os 3 digitos","R");
		 	 			    janela->limparArea(39,8,64,8);
		 	 			    encontrou=true;
			  			}
			  			else if(this->registro.codigo.size() < 3)
			  			{
			 	 	        janela->centralizar("O codigo deve ter 3 digitos","R");
		 	 			    janela->limparArea(39,8,64,8);
		 	 			    encontrou=true;
			  			}
			  			//Pergunta nome, Categoria, Valor
			  			else if(not encontrou)
			  			{
			 	 	        janela->centralizar("Digite um nome para a peca","R");
			 			    this->perguntarNome();
			 			    janela->centralizar("Digite o codigo de categoria para a peca","R");
			 			    resp="";
			 			    while(resp == "")
			 			    {
		 		   			    this->perguntarCategoria();
			 			    	resp=cat->retornaNome(this->registro.categoria);
			 			    	if(resp == "")
			 			    	{
					 			    janela->centralizar("Codigo de categoria inexistente, tente novamente","R");
					 			    janela->limparArea(39,10,69,10);
					 			}
					 			else
					 			{
								 	this->registro.categoria=resp;
			 			    	    this->mostraCategoria(resp);
			 			    	    this->perguntarValor(false);
			 			    		resp=janela->perguntar("Confirma cadastro (S/N): ");
			 			    		if(resp == "S")
			 			    		{
		 					    	    this->adicionarDados(true);
		 					    		janela->centralizar("Registro cadastrado com exito!","R");
		 					    		getch();
	 		 						}
								}
					 		}
			 			    
 				   		}
 				   		
					}
		   		}//Fim de cadastro
		   		else
		   		{
			 	    //Ajustar o tamanho da palavra
			 	    x = opEscolhida.size();
			 	    opEscolhida.erase(3,x-3);
			 	    this->registro.codigo=opEscolhida;
			 	    
			 	    encontrou=this->verificaCodigo();
			 	    if(encontrou)
			 	    {
		 			    janela->limparArea(25,5,79,22);
 			            this->molduraCadastro("Informacoes da PECA",true);
 			            this->mostrarRegistros();
 			 		    resp=janela->perguntar("Deseja alterar, excluir ou voltar (A/E/V): ");
 			 		}
			 	    
	 	 		}
		   		if(resp == "A")
		   		{
		            this->menuAlterar();
		 		    
					 /*
			 	    janela->limparArea(39,8,69,11);
			    	this->molduraCadastro("PECA",false);
			    	this->verificaCodigo();
			    
			    	textcolor(DARKGRAY);
			    	gotoxy(39,8); cout << this->tabelaPecas[posicao].codigo;
			    	textcolor(WHITE);
			    
			    	janela->centralizar("Digite o novo nome para peca","R");
			    	this->perguntarNome();
			    
			    	janela->centralizar("Digite o codigo de categoria para peca","R");
			    	resp="";
			    	while(resp =="")
			    	{
			    	    this->perguntarCategoria();
			    		resp=cat->retornaNome(this->registro.categoria);
			    		if(resp == "")
			    		{
				 		    janela->centralizar("Codigo de categoria inexistente, tente novamente","R");
		 			    	janela->limparArea(39,10,69,10);
		 			 	}
			    		else
			    		{
				 		    this->mostraCategoria(resp);
		 			    	this->registro.categoria=resp;
							janela->centralizar("Digite o novo valor para peca","R");
			    			this->perguntarValor();
			    
			    			resp=janela->perguntar("Confirma cadastro (S/N): ");
			    			if(resp == "S")
			    			{
	 			    	        this->alterarDados();
	 			    			janela->centralizar("Registro foi alterado com exito!","R");
	 			    			getch();
 							}   
		 				}
					}*/  
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
		   	
		}//La�o do CRUD
	}
private:
    Tela *janela;
    Categorias *cat;
    string opEscolhida;
    int posicao;
    colunaPecas registro;
    vector<colunaPecas> tabelaPecas;
    vector<string> listaPecas;
    
    void molduraCadastro(string titulo, bool moldura)
    {
	    if(moldura)
	    {
	        janela->montarMoldura(27,5,70,7,0);
	    	janela->montarMoldura(27,7,70,12,1);
	    
	    	gotoxy(27,7); cout << char(204);
			gotoxy(70,7); cout << char(185);
			textcolor(LIGHTBLUE);
			gotoxy(28,6); cout << titulo;
			textcolor(WHITE);
		
			gotoxy(28,8); cout <<  "Codigo   :";
			gotoxy(28,9); cout <<  "Nome     :";
			gotoxy(28,10); cout << "Categoria:";
			gotoxy(28,11); cout << "Valor    :";
		}
		else
		{
 		    textcolor(LIGHTBLUE);
			gotoxy(28,6); cout << titulo;
			textcolor(WHITE);
 		}	    
	}
    
    void perguntarCodigo()
    {
 	    gotoxy(39,8); getline(cin, this->registro.codigo);
 	}
 	
 	void perguntarNome()
 	{
 	    gotoxy(39,9); getline(cin, this->registro.nome);
 	}
 	
 	void perguntarCategoria()
 	{
  	    gotoxy(39,10); getline(cin, this->registro.categoria);
 	}
 	
 	void perguntarValor(bool cadastro)
 	{
	    string temp;
    	textcolor(GREEN);
    	gotoxy(39,11); cout<< "R$:";
	    if(cadastro) textcolor(BLACK);
    	else textcolor(WHITE); 		    
 		getline(cin, temp);
  		this->registro.valor="R$:"+temp;
 	}
 	
 	void mostraCategoria(string categoria)
 	{
	    textcolor(DARKGRAY);
 	    gotoxy(43,10); cout <<"| " << categoria;
 	    textcolor(WHITE);
 	}
 	
 	void mostrarRegistros()
 	{
 	    textcolor(DARKGRAY);
 	    gotoxy(39,8); cout << tabelaPecas[posicao].codigo;
 	    textcolor(WHITE);
 	    gotoxy(39,9); cout << tabelaPecas[posicao].nome;
 	    gotoxy(39,10); cout << tabelaPecas[posicao].categoria;
 	    gotoxy(39,11); cout << tabelaPecas[posicao].valor;
 	}
 	
 	bool verificaCodigo()
 	{
 	    bool achei=false;
 	    int x;
 	    for(x=0; x<this->tabelaPecas.size(); x++)
 	    {
 		    if(this->tabelaPecas[x].codigo == this->registro.codigo)
 		    {
  			    achei=true;
  			    posicao=x;
  			    break;
  			}
 		}
 		return achei;
 	}
 	
 	void alterarDados()
 	{
 	    this->tabelaPecas[posicao].nome = this->registro.nome;
		this->tabelaPecas[posicao].categoria = this->registro.categoria;
		this->tabelaPecas[posicao].valor = this->registro.valor;
		
		this->gravarArquivo();
 	}
 	
 	void menuAlterar()
 	{
 	    vector<string> menu;
 	    string op, resp;
 	    
  	   	janela->centralizar("Pressione G para gravar as alteracoes ou ESC para sair a qualquer momento","R");
 	    
 	    this->registro.nome = this->tabelaPecas[posicao].nome;
 	    this->registro.categoria = this->tabelaPecas[posicao].categoria;
 	    this->registro.valor = this->tabelaPecas[posicao].valor;
 	    
 	    while(op != "G")
 	    {
	 	    menu.clear();
	 	    menu.push_back("Nome     : "+this->registro.nome);
 	    	menu.push_back("Categoria: "+this->registro.categoria);
 	    	menu.push_back("Valor    : "+this->registro.valor);
 	    	op = janela->montarMenu(27,8,70,menu,"",false);
 	    	//Nome
 	    	if(op[0] == 'N')
 	    	{
	 		    textcolor(BLACK); textbackground(WHITE);
 	    		janela->limparArea(39,9,69,9);
 		        this->perguntarNome();
 		        textcolor(WHITE); textbackground(BLACK);
 		        janela->limparArea(39,9,69,9);
	 		}
 	    	//Categoria
 	    	if(op[0] == 'C')
 	    	{
	 		    textcolor(BLACK); textbackground(WHITE);
 	    		janela->limparArea(39,10,69,10);
 		        
 		        resp="";
 		        while(resp == "")
 		        {
			 	    this->perguntarCategoria();
			 	    resp=cat->retornaNome(this->registro.categoria);
			 	    if(resp == "")
			 	    {
	 				    janela->centralizar("Codigo de categoria inexistente, tente novamente","R");
	 			    	janela->limparArea(39,10,69,10);
	 				}
	 				else
	 				{
				 	    this->mostraCategoria(resp);
	 			    	this->registro.categoria=resp;
	 			    	getch();
					}
				}
 		        
 		        textcolor(WHITE); textbackground(BLACK);
 		        janela->limparArea(39,10,69,10);
	 		}
 	    	//Endere�o
 	    	if(op[0] == 'V')
 	    	{
 		 	    textcolor(BLACK); textbackground(WHITE);
 	    		janela->limparArea(39,11,69,11);
 		 	    this->perguntarValor(true);
 		 	    textcolor(WHITE); textbackground(BLACK);
 		 	    janela->limparArea(39,11,69,11);
 		 	}
 	    	
 	    	//Sair da fun��o
 	    	if(op == "S") break;
 	    	
 	    	//Gravar cadastro
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
 	    this->tabelaPecas.erase(this->tabelaPecas.begin() + this->posicao);
 	    this->gravarArquivo();
 	}
 	
 	void adicionarDados(bool gravar)
 	{
        this->tabelaPecas.push_back(this->registro);
        if(gravar) this->gravarArquivo();
 	}
 	
 	void ajustaListaString(int ci, int cf)
 	{
 	    int espaco, c, x, y;
 	    stringstream juncao;
 	    
 	    for(x=0; x<tabelaPecas.size(); x++)
 	    {
	        espaco=cf-ci-2;
	 	    juncao.str("");
	 	    juncao << tabelaPecas[x].codigo<<"|";
	 		espaco-=tabelaPecas[x].codigo.size();
	 		
	 		espaco-=10;//Espa�o para ultimo valor inserido na string
	 		espaco=(espaco/2);
	 		
	 		//Ajusta tamanho do nome
	 		if(tabelaPecas[x].nome.size() > espaco)
	 		{
	   		    for(y=0; y<espaco-1; y++)
	   		    {
 		 		    juncao << tabelaPecas[x].nome[y];
 		 		}
 		 		juncao <<".|";
	   		}
	   		else if(tabelaPecas[x].nome.size() == espaco)
	   		{
	 	 	    juncao << tabelaPecas[x].nome<<"|";
		   	}
		   	else
		   	{
 			    c=espaco-tabelaPecas[x].nome.size();
 			    juncao << tabelaPecas[x].nome;
 			    for(y=0; y<c; y++)
 			    {
	 		 	    juncao << " ";
	 		 	}
	 		 	juncao<<"|";
 		   	}
 		   	//Ajusta tamanho da categoria
 		   	if(tabelaPecas[x].categoria.size() > espaco)
 		   	{
	   		    for(y=0; y<espaco-1; y++)
	   		    {
 		 		    juncao << tabelaPecas[x].categoria[y];
 		 		}
 		 		juncao <<".|";
	   		}
	   		else if(tabelaPecas[x].categoria.size() == espaco)
	   		{
	 	 	    juncao << tabelaPecas[x].categoria<<"|";
	   		}
	   		else
		   	{
 			    c=espaco-tabelaPecas[x].categoria.size();
 			    juncao << tabelaPecas[x].categoria;
 			    for(y=0; y<c; y++)
 			    {
	 		 	    juncao << " ";
	 		 	}
	 		 	juncao<<"|";
 		   	}
 		   	espaco=10;
 		   	//Ajusta tamanho do valor
 		   	if(tabelaPecas[x].valor.size() > espaco)
 		   	{
	   		    for(y=0; y<espaco-3; y++)
	   		    {
 		 		    juncao << tabelaPecas[x].valor[y];
 		 		}
 		 		juncao <<"...";
	   		}
	   		else if(tabelaPecas[x].valor.size() == espaco)
	   		{
	 	 	    juncao << tabelaPecas[x].valor;
	   		}
	   		else
		   	{
 			    c=espaco-tabelaPecas[x].valor.size();
 			    juncao << tabelaPecas[x].valor;
 			    for(y=0; y<c; y++)
 			    {
	 		 	    juncao << " ";
	 		 	}
 		   	}
 		   	//Salva string
	   		listaPecas.push_back(juncao.str());
 		}
 	}
 	
 	void lerArquivo()
 	{
 	    ifstream arquivo;
 	    
 	    arquivo.open("pecas.txt");
 	    
 	    while(not arquivo.eof())
 	    {
  		    getline(arquivo, registro.codigo, '|');
  		    getline(arquivo, registro.nome, '|');
  		    getline(arquivo, registro.categoria, '|');
  		    getline(arquivo, registro.valor);
  		    
  		    if(this->registro.codigo != "")
  		    {
	 		    this->adicionarDados(false);
	 		}
  		}
  		
  		arquivo.close();
  		
  		this->ajustaListaString(26,78);
 	}
 	
 	void gravarArquivo()
 	{
 	    ofstream arquivo;
 	    int x;
 	    
 	    arquivo.open("pecas.txt");
 	    
 	    for(x=0; x<tabelaPecas.size(); x++)
 	    {	 	    
	 	    arquivo << this->tabelaPecas[x].codigo
	 	    		<< "|"
	 	    		<< this->tabelaPecas[x].nome
	 	    		<< "|"
	 	    		<< this->tabelaPecas[x].categoria
	 	    		<< "|"
	 	    		<< this->tabelaPecas[x].valor
	 	    		<< endl;
	 	}
	 	
	 	arquivo.close();
	 	
	 	this->listaPecas.clear();
	 	this->ajustaListaString(26,78);
 	}
	
};
