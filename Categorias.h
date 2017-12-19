struct colunaCategorias
{
    string codigo;
	string nome;
};
class Categorias
{
public:
	   
    Categorias()
    {
	    this->lerArquivo();
	}
	   
    void executarCRUD(Tela *endJanela)
    {
	    string resp;
	    bool encontrou=true;
	    int x;
	    this->janela=endJanela;
	    
	    opEscolhida="";
	    while(opEscolhida != "S")
	    {
 		    janela->limparArea(25,5,79,22);
   			opEscolhida=janela->telaCRUD(25,5,78,21,listaCategorias,"Categorias","Cadastrar");
			if(opEscolhida != "S")
			{	
		        if(opEscolhida[0] == char(250))//Inicio de cadastro
				{
		            janela->limparArea(25,5,79,22);
  		    		this->molduraCadastro("Cadastro de CATEGORIA",true);
  		    		encontrou=true;
	    			while(encontrou)
	    			{
			    		this->perguntaCodigo();
	    				encontrou=this->verificaCodigo();
	    		
	    				if(encontrou)
	    				{
	 			            janela->centralizar("Codigo ja existente, tente outro","R");
	 			            janela->limparArea(37,8,64,8);
   						}
	 					else if(this->registro.codigo.size() > 3)
	 					{
		 	 	            janela->centralizar("O Codigo nao pode ultrapassar os 3 digitos","R");
		 	 	            janela->limparArea(37,8,64,8);
		 	 	    		encontrou=true;
						}
		 	 			else if(this->registro.codigo.size() < 3)
		 	 			{
	 	 	 	            janela->centralizar("O codigo deve ter 3 digitos","R");
	 	 	 	            janela->limparArea(37,8,64,8);
	 	 	 	    		encontrou=true;
						}
	 					else
	 					{
			 	            janela->centralizar("Digite um nome para a categoria","R");
			 	    		this->perguntaNome();
	    		    		resp=janela->perguntar("Confirma cadastro (S/N): ");
	    					if(resp=="S")
	    					{
	                            this->adicionarDados(true);
	    					 	janela->centralizar("Registro cadastrado com exito!","R");
		  						getch();
   							}
 						}
					}
				    	
				}//Fim de cadastro	 					  
 				else
  				{
     		        //Ajustar o tamanha da palavra
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
			}
			
	    	if(resp == "A")
	    	{
	            janela->limparArea(37,8,64,9);
	        	this->molduraCadastro("Categoria",false);
	        
	        	textcolor(DARKGRAY);
	        	gotoxy(37,8); cout << this->tabelaCategorias[posicao].codigo;
	        	textcolor(WHITE);
	        
	        	janela->centralizar("Digite o novo nome para categoria","R");
	        	textcolor(BLACK); textbackground(WHITE);
	        	gotoxy(28,9); cout<< "Nome   :                             ";
	        	this->perguntaNome();
	        	textcolor(WHITE); textbackground(BLACK);
	        	resp=janela->perguntar("Confirma alteracao (S/N): ");
	        	if(resp == "S")
	        	{
 		 	        this->alterarRegistro();
 		 	    	janela->centralizar("Registro alterado com exito!","R");
 		 	    	getch();
				}    
	 		}
	    
	    	if(resp == "E")
	    	{
	   	        resp=janela->perguntar("Confirma exclusao (S/N): ");
	   	    	if(resp=="S")
	   	    	{
		 	    	this->excluirRegistro();
		 	    	janela->centralizar("Registro excluido com exito!","R");
					getch();		 	    
		 		}
	   		}
		}
	}
 	
 	string retornaNome(string codigo)
 	{
  	    string nome;
  	    bool achou;
  	    this->registro.codigo=codigo;
  	    achou=this->verificaCodigo();
  	    if(achou)
  	    {
	 	    nome=this->tabelaCategorias[posicao].nome;
	 	}
	 	else nome="";
	 	
	  	return nome;
  	}
	   
private:
    Tela *janela;
    string opEscolhida;
    int posicao;
    vector<colunaCategorias> tabelaCategorias;
    vector<string> listaCategorias;
    colunaCategorias registro;
    
    void molduraCadastro(string titulo,bool moldura)
    {
	    if(moldura)
	    {
	        janela->montarMoldura(27,5,65,7,0);
	    	janela->montarMoldura(27,7,65,10,1);
	    
	    	gotoxy(27,7); cout << char(204);
	    	gotoxy(65,7); cout << char(185);
	    
	    	textcolor(LIGHTBLUE);
	    	gotoxy(28,6); cout << titulo;
	    	textcolor(WHITE);
	    
	    	gotoxy(28,8); cout<< "Codigo :";
	    	gotoxy(28,9); cout<< "Nome   :";
		}
		else
		{
 		    textcolor(LIGHTBLUE);
 		    janela->limparArea(28,6,64,6);
	    	gotoxy(28,6); cout << titulo;
	    	textcolor(WHITE);
 		}
	}
	
	void perguntaCodigo()
	{
 	    gotoxy(37,8); getline(cin, this->registro.codigo);
 	}
 	
 	void perguntaNome()
 	{
 	    gotoxy(37,9); getline(cin, this->registro.nome);
 	}
 	
 	void mostrarRegistros()
 	{
 	    textcolor(DARKGRAY);
 	    gotoxy(39,8); cout << tabelaCategorias[posicao].codigo;
 	    textcolor(WHITE);
 	    gotoxy(39,9); cout << tabelaCategorias[posicao].nome;
 	}
 	
 	bool verificaCodigo()
 	{
	    int x;
	    bool achou;
 	    for(x=0; x<tabelaCategorias.size(); x++)
 	    {
	 	    if(tabelaCategorias[x].codigo == registro.codigo)
	 	    {
  			    achou=true;
  			    this->posicao=x;
  			    break;
  			}
	 	}
	 	return achou;
 	}
 	
 	void alterarRegistro()
 	{
  	    this->tabelaCategorias[posicao].nome = this->registro.nome;
  	    this->gravarArquivo();
 	}
 	
 	void excluirRegistro()
 	{
 	    this->tabelaCategorias.erase(this->tabelaCategorias.begin() + this->posicao);
 	    this->gravarArquivo();
 	}
 	
 	void adicionarDados(bool gravar)
 	{
 	    this->tabelaCategorias.push_back(registro);
 	    if(gravar) this->gravarArquivo();
 	}
 	
 	void ajustaListaString(int ci, int cf)
 	{
 	    int espaco, c, x, y;
 	    stringstream juncao;
 	    
 	    for(x=0; x<tabelaCategorias.size(); x++)
 	    {
 	        espaco=cf-ci-2;
 	        juncao.str("");
 	        juncao << tabelaCategorias[x].codigo<<" | ";
 	        espaco-=2;
 	        espaco-=tabelaCategorias[x].codigo.size();
 	        
 	        
 	        if(tabelaCategorias[x].nome.size() > espaco)
	 		{
	   		    for(y=0; y<espaco-3; y++)
	   		    {
 		 		    juncao << tabelaCategorias[x].nome[y];
 		 		}
 		 		juncao <<"...";
	   		}
	   		else if(tabelaCategorias[x].nome.size() == espaco)
	   		{
	 	 	    juncao << tabelaCategorias[x].nome;
		   	}
		   	else
		   	{
 			    c=espaco-tabelaCategorias[x].nome.size();
 			    juncao << tabelaCategorias[x].nome;
 			    for(y=0; y<c; y++)
 			    {
	 		 	    juncao << " ";
	 		 	}
 		   	}
 	        this->listaCategorias.push_back(juncao.str());
 	        
	 	}
 	}
 	
 	void lerArquivo()
 	{
 	    ifstream arquivo;
 	    
 	    arquivo.open("categorias.txt");
 	    
 	    while(not arquivo.eof())
 	    {
  		    getline(arquivo, registro.codigo, '|');
  		    getline(arquivo, registro.nome);
  		    if(registro.codigo != "")
  		    {
  			    this->adicionarDados(false);
  			}
  		}
  		arquivo.close();
  		
		this->ajustaListaString(25,78);    
 	}
 	
 	void gravarArquivo()
 	{
  	    int x;
	 	ofstream arquivo;
 	    
 	    arquivo.open("categorias.txt");
 	    
 	    for(x=0; x<tabelaCategorias.size(); x++)
 	    {
	 	    arquivo << tabelaCategorias[x].codigo
	 	    		<< "|"
	 	    		<< tabelaCategorias[x].nome
	 	    		<< endl;
	 	}
	 	arquivo.close();
	 	
	 	this->listaCategorias.clear();//Limpa a lista antes de prenchela novamente
	 	this->ajustaListaString(25,78);
 	}
};
