class Tela
{
public:
       
    Tela()
    {
 	    /*
	    registro.codigo="001";
	    registro.nome="Placa de video uhuu";
	    registro.valor="550.00";
	    tabelaDados.push_back(registro);
	    */
	    
	    //this->lerArquivo();
	    //this->gravarArquivo();
	}
	
    string telaCRUD(int ci, int li, int cf, int lf, 
		            vector<string>lista, string titulo, string funcao)
    {
        int opAtual, coluna, linha, c;//Atributos para laços e funções
		int limSup=0, limInf=0, intervalo=0, limiteDeBarras;//Atributos de efeito
		stringstream juncao; //Atributo para concatenar duas ou mais strings
		bool sair=false;
		string opEscolhida;
		vector<string> listaN;
  		
  		this->centralizar("Tecle enter na opcao que desejar","R");
  		
	    if(titulo != "")//Se ouver titulo
	    {
	        this->montarMoldura(ci,li,cf,li+2,0);
	        li=li+2;//espaço para linha da moldura e titulo 
	    	this->montarMoldura(ci,li,cf,lf,1);
	    	gotoxy(ci,li); cout << char(204);
	    	gotoxy(cf,li); cout << char(185);
	    	
	    	li++;
	    	
	    	coluna=(((cf-ci)-titulo.size())/2)+ci;
	    	gotoxy(coluna,6); cout << titulo;
	    	
	    	limiteDeBarras=lf-li;
	    	limInf=limiteDeBarras;
		}
		else//Se não ouver titulo
		{
 		    this->montarMoldura(ci,li,cf,lf,1);
 		    gotoxy(1,3); cout << "entrou";
 		    li++;//espaço para linha da moldura
 		    limiteDeBarras=lf-li;
 		    limInf=limiteDeBarras;
		}
	    
	    if(funcao != "") //Se existir uma função, concatena com a lista
	    {
  		    c=(((cf-ci)-funcao.size())/2)-2;
  		    juncao << char(250);
  		    for(coluna=0; coluna<c; coluna++)
  		    {
			    juncao << " ";
			    if(coluna == c-1) juncao << funcao;
  			}
  			listaN.push_back(juncao.str());
  			juncao.str("");
  			for(coluna=ci+1; coluna<cf; coluna++)
  			{
	 		    juncao << "-";
	 		}
	 		listaN.push_back(juncao.str());
	 		
	 		for(coluna=0; coluna<lista.size(); coluna++)
	 		{
		  	    listaN.push_back(lista[coluna]);
		  	}
		  	lista.clear();
	 		for(coluna=0; coluna<listaN.size(); coluna++)
	 		{
		  	    lista.push_back(listaN[coluna]);
		  	}
  		}
	    
	    if(lista.size() == 0)
	    {
  		    this->centralizar("Nao existem produtos cadastrados, tecle enter para sair","R");
  		    getch();
  		    sair=true;
  		}
	    
	    for(coluna=0; coluna<lista.size(); coluna++)
	    {
  		    if(limiteDeBarras == coluna) break;
		  	gotoxy(ci+1,li+coluna); cout << lista[coluna];
		  	
		}
		
		opAtual=0;
		while(true)
		{	
			//encerra função
			if(sair) break;
			
			
			//Faz reimpressão para efeito de rolagem
			if(lista.size() >= limiteDeBarras)
			{
		        linha=li;
		        for(coluna=ci+1; coluna<cf; coluna++)
		        {
		 		    gotoxy(coluna,linha); cout << " ";
		 		}
 	    		for(coluna=limSup; coluna<limInf; coluna++)
  				{	    
   			        gotoxy(ci+1,linha); cout << lista[coluna];
   		 			linha++;
  				}
			}
			
	   		
			//Inverte as cores para selesionado
  			textcolor(BLACK);
    		textbackground(WHITE);
 			
 			//Seleciona opção
 			linha=li+intervalo;
			for(coluna=ci+1; coluna<cf; coluna++)
   			{
	 		    gotoxy(coluna,linha); cout << " ";
			}
			gotoxy(ci+1,linha); cout << lista[opAtual];
			
			//Volta ao normal
  		    textcolor(WHITE);
  		    textbackground(BLACK);
  		    
  		    //Captura tecla
  		    c = getch();
  		    
  		    //ENTER
  		    if(c == 13)
  		    {
	 	 	    opEscolhida = lista[opAtual];
	 	 	    break;
 	 		}
 	 		
  		    //ESC
  		    if(c == 27) 
	  		{
	 		    opEscolhida="S";
	 	 	    break;
			}
				
  		    if(c == 224)
  		    {
 	 	        //Desmarca opção
 	 	        linha=li+intervalo;
 		 	    for(coluna=ci+1; coluna<cf; coluna++)
  		    	{
	 		        gotoxy(coluna,linha); cout << " ";
	 			}
	 			gotoxy(ci+1,linha); cout << lista[opAtual];
	 			
				
				//Captura tecla
 	 	 	    c = getch();
 	 	 	    
 	 	 	    //Para cima
	 	 	    if(c == 72)
	 	 	    {
 	 	 		    if(opAtual != 0)
 	 	 		    {
		 		   	    opAtual--;
 		   	    		if(intervalo == 0)
				 		{
		    		            limSup--;
		    			        limInf--;
						}
						if(intervalo > 0)intervalo--;
		 		   	}
		 		   	
	 	 		}
		
	 	 		//Para baixo
	 	 		if(c == 80)
	 	 		{
	 		   	    if(opAtual != lista.size()-1)
	 		   	    {
 		   		        opAtual++;
 		   		        if(intervalo == limiteDeBarras-1)
						{
	 			 		    limSup++;
	 			 		    limInf++;
						}
						if(intervalo < limiteDeBarras-1)intervalo++;
                    }
	 	 	 	}
	 	 	}

  		}
  		return opEscolhida;
	}
	
	
	
    string montarMenu(int ci, int li, int cf, vector<string> opcoes, string mensagem, bool moldura)
    {
        int lf, c, x, opAtual;
        string opEscolhida;
        bool detalheMenu=false;
        
        
        if(cf == 0)
        {
            c=0;
        	for(x=0; x<opcoes.size(); x++)
        	{
                if(c < opcoes[x].size())
            	{
                    c = opcoes[x].size();
           		}
       		}
            //Coluna final
        	cf=ci+c+1;
		}
		 
        //Faz titulo de Topo
        if(mensagem != "")
        {
		    this->montarMoldura(ci,li,cf,li+2,0);
		    li+=2;
		    
			c = (((cf-ci)-mensagem.size())/2)+ci;
		    gotoxy(c,li-1); cout << mensagem;
			
			detalheMenu=true;	    
		}
		
        //Linha final
        lf=li+opcoes.size()+1;
        if(moldura)
        {
            this->montarMoldura(ci,li,cf,lf,1); if(detalheMenu)
												{
				 			   				        gotoxy(ci,li); cout << char(204);
		    										gotoxy(cf,li); cout << char(185);
				 			   					} 
		} 
        
        for(x=0; x<opcoes.size(); x++)
        {
            gotoxy(ci+1,li+x+1);
            cout << opcoes[x];
        }
        
        //Imprime barras
        opAtual=0;
        while(true)
        {
            
            textcolor(BLACK);
            textbackground(WHITE);
            
            for(x=ci+1; x<cf; x++)
            {
			    gotoxy(x,li+opAtual+1); cout << " ";
			}
            gotoxy(ci+1,li+opAtual+1);
            cout << opcoes[opAtual];
            
            textcolor(WHITE);
            textbackground(BLACK);
            
            c = getch();
            
            //Tecla G "Gravar"
            if(c == 103)
            {
		 	    opEscolhida="G";
		 	    break;
 	 		}
            
            //Enter
            if(c == 13)
            {
                opEscolhida = opcoes[opAtual];
                break;
            }
            
            //Esc - Sair
            if(c == 27)
			{
 	 		    opEscolhida="S";
 	 		    break;
 	 		}
            
            if(c == 224)
            {
                 for(x=ci+1; x<cf; x++)
            	 {
			        gotoxy(x,li+opAtual+1); cout << " ";
			     }
                 gotoxy(ci+1,li+opAtual+1);
                 cout << opcoes[opAtual];
                 
                c = getch();
                //Para cima
                if(c == 72)
                {
                    opAtual--;
                    if(opAtual < 0)
                    {
                        opAtual=opcoes.size()-1;
                    }
                }
                
                //Para baixo
                if(c == 80)
                {
                    opAtual++;
                    if(opAtual == opcoes.size())
                    {
                        opAtual=0;
                    }
                }
            }
        }
        return opEscolhida;
    }  
    
    void montarMoldura(int ci, int li, int cf, int lf, int sombra)
    {
        int coluna, linha;
        for(coluna=ci; coluna<=cf; coluna++)
        {
            gotoxy(coluna,li); cout << char(205);
            gotoxy(coluna,lf); cout << char(205);
        }
        for(linha=li; linha<=lf; linha++)
        {
            gotoxy(ci,linha); cout << char(186);
            gotoxy(cf,linha); cout << char(186);
        }
        gotoxy(ci,li); cout << char(201);
        gotoxy(ci,lf); cout << char(200);
        gotoxy(cf,li); cout << char(187);
        gotoxy(cf,lf); cout << char(188);
        
        if(sombra==1)
        {
            for(coluna=ci+1; coluna<=cf+1; coluna++)
            {
                gotoxy(coluna,lf+1); cout << char(177);
            }
            for(linha=li+1; linha<=lf+1; linha++)
            {
                gotoxy(cf+1,linha); cout << char(177);
            }
        }
    }
    
    void centralizar(string mensagem, string onde)
    {
  	    int coluna;
  	    
  	    coluna=(80-mensagem.size())/2;
  	    
  	    if(onde=="T")
  	    {
	 	    this->limparLinha(2);
		    gotoxy(coluna,2); cout << mensagem;
		}
		
		if(onde=="R")
		{
  		    this->limparLinha(24);
	   	    gotoxy(coluna,24); cout << mensagem;
	 	}
	}
    
    /*
    string perguta (string mensagem, string acao1, string acao2)
    {
 	    
 	}
    */
    
    string perguntar(string mensagem)
    {
 	    string perg;
	    this->centralizar(mensagem,"R");
		cin >> perg;
		fflush(stdin);
		
		perg=toupper(perg[0]);
		return perg;
 	}
    
    void limparLinha(int linha)
    {
	    int coluna;
	    for(coluna=2; coluna<=79; coluna++)
	    {
 		    gotoxy(coluna,linha); cout <<" ";
 		}
 	}
 	
 	void limparArea(int ci, int li, int cf, int lf)
 	{
 	    int i,j;
 	    for(i=ci; i<=cf; i++)
 	    {
  		    for(j=li; j<=lf; j++)
  		    {
  			    gotoxy(i,j); cout << " ";
  			}
  		}
 	}
 	
private:
    
};
