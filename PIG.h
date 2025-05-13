/********************************
Vers�o da Biblioteca PIG.H
0.2.0
********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "SDL_image.h"
#include "Tipos_PIG.h"
#include "CJogo.h"


/********************************
/ Vari�veis Globais
/********************************/
Jogo jogo=NULL;

/********************************
A fun��o Cria_Jogo � respons�vel pela cria��o da janela do jogo e pelos componentes audio-visuais.
Ela deve ser chamada antes de qualquer outra fun��o da biblioetac PIG.h. N�o � poss�vel criar dois
jogos no mesmo progama. Logo, somente a primeira chamada ter� efeito.
Par�metros:
Largura_Janela (entrada, passagem por valor): indica a largura da janela do jogo em pixels.
Altura_Janela (entrada, passagem por valor): indica a altura da janela do jogo em pixels.
Nome_Janela (entrada, passagem por refer�ncia*): indica o nome que ajanela do jogo mostrar� no seu t�tulo
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
********************************/
void Cria_Jogo(int Largura_Janela, int Altura_Janela,char *Nome_Janela)
{
    if (jogo==NULL)
        jogo = new CJogo(Largura_Janela,Altura_Janela,Nome_Janela);
}


/********************************
A fun��o GetEstado_Jogo() indica o estado do jogo. Este estado � apenas um valor inteiro
que pode ser usado para indicar uma fase do jogo ou a vez de algum jogador por exemplo.
Retorno:
inteiro indicando o valor do estado do jogo;
********************************/
int GetEstado_Jogo()
{
    return jogo->estado;
}

/********************************
A fun��o SetEstado_Jogo() atribui um novo valor ao estado do jogo. Este estado � apenas um valor inteiro
que pode ser usado para indicar uma fase do jogo, ou a vez de algum jogador por exemplo.
Par�metro:
estado (entrada, passagem por valor): indica o novo estado do jogo;
********************************/
void SetEstado_Jogo(int estado)
{
    jogo->estado = estado;
}

/********************************
A fun��o Define_Fundo permite escolher um arquivo fr imagem como fundo (background) do jogo.
Par�metros:
NomeArquivoImagem (entrada, passagem por refer�ncia*): indica o caminho relativo ou absoluto do arquivo de imagem que ser� utilizado como fundo do jogo.
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
********************************/
void Define_Fundo(char *NomeArquivoImagem)
{
    jogo->DefineFundo(NomeArquivoImagem);
}

/********************************
A fun��o Confere_Evento() indica se houve algum tipo de evento desde quando o jogo come�ou ou desde a �ltima vez que a fun��o foi chamada.
Um evento pode ser uma tecla pressionada, um clique do mouse ou outra coisa relacionada � tela do jogo.
Retorno:
Indica o tipo de evento que ocorreu. Se n�o houve evento, retorna o valor 0 (zero).
********************************/
PIG_Evento Confere_Evento()
{
    return jogo->TrataEventos();
}

/********************************
A fun��o Pega_Tecla() indica qual tecla foi pressionada.
Uma lista das poss�veis teclas e seus c�digo pode ser vista em .
Retorno:
O valor de retorno da fun��o � um vetor de n�meros inteiros que indicam se uma determinada tecla (�ndice do vetor) foi
pressionada (valor diferente de 0,zero) ou n�o (valor igual a zero).
********************************/
PIG_Teclado Pega_Teclado()
{
    return jogo->PegaTeclado();
}

/********************************
A fun��o Pega_MouseXY() � respons�vel por obter a posi��o do mouse em rela��o � janela do jogo.
Par�metros:
PosicaoX (sa�da, passagem por refer�ncia): indica a posicao no eixo X do mouse.
PosicaoY (sa�da, passagem por refer�ncia): indica a posicao no eixo Y do mouse.
********************************/
void Pega_MouseXY(int *PosicaoX,int *PosicaoY)
{
    jogo->Pega_MouseXY(PosicaoX,PosicaoY);
}

/********************************
A fun��o Pega_MouseBotao() � respons�vel por indicar qual dos bot�es (direito, esquerdo ou central/rodinha)
do mouse foi pressionado ou liberado.
Retorno:
Indica o c�digo do bot�o (MOUSE_DIREITO, MOUSE_ESQUERDO, MOUSE_CENTRAL).
********************************/
int Pega_MouseBotao(){
    return jogo->Pega_Botao();
}

/********************************
A fun��o Inicia_Desenho � respons�vel por preparar a janela do jogo para que os objetos gr�ficos
possam ser mostrados, al�m de desenhar a imagem de fundo do jogo.
Deve ser chamada repetidamente a cada novo quadro (frame) a ser desenhado.
********************************/
void Inicia_Desenho()
{
    jogo->IniciaDesenho();
}

/********************************
A fun��o Encerra_Desenho � respons�vel por encerrar o desenho que foi criado. Ap�s a execu��o dos frames,
ele encerra a anima��o. Deve ser chamado toda vez que um frame acabar de ser executado.
********************************/
void Encerra_Desenho()
{
    jogo->EncerraDesenho();
}

/********************************
A fun��o Salva_Screen � respons�vel por criar um arquivo Bitmap, contendo uma c�pia da tela do jogo naquele momento.
Par�metros:
nomeBMP (entrada, passagem por refer�ncia*): indica o nome do arquivo Bitmap que ser� salvo. O valor do par�metro deve conter a extens�o ".bmp".
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
********************************/
void Salva_Screen(char *nomeBMP)
{
    jogo->saveScreenshotBMP(nomeBMP);
}

/********************************
A fun��o Jogo_Rodando � repons�vel por retornar o funcionamento do jogo. Ela chama o m�todo que
vai retornar um valor inteiro indicando se o jogo ainda est� ativo ou n�o.
Retorno:
inteiro que indica se o jogo ainda est� sendo executado (valor diferente de zero) ou n�o (valor igual a 0, zero).
********************************/
int Jogo_Rodando()
{
    return jogo->rodando;
}

/********************************
A fun��o Finaliza_Jogo � respons�vel por encerrar com a execu��o final do jogo. Ap�s tudo ser realizado
a fun��o pode ser chamada e ela ir� realizar a interrup��o do jogo e a sua finaliza��o.
********************************/
void Finaliza_Jogo()
{
    delete jogo;
}

/********************************
A fun��o Desenha_Retangulo() � respons�vel por desenhar um ret�ngulo na tela em uma posi��o desejada pelo usu�rio.
O mesmo pode ser colocado em qualquer lugar do campo de vis�o da tela.
Par�metros:
PosicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja colocar o ret�ngulo.
PosicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja colocar o ret�ngulo.
Altura (entrada, passagem por valor): Valor onde o usu�rio ir� fornecer o n�mero correspondente em pixels � altura desse ret�ngulo.
Largura (entrada, passagem por valor): Valor onde o usu�rio ir� fornecer o n�mero correspondente em pixels � largura desse ret�ngulo.
Cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho do ret�ngulo;
********************************/
void Desenha_Retangulo(int PosicaoX, int PosicaoY, int Altura, int Largura, PIG_Cor cor)
{
    jogo->DesenhaRetangulo(PosicaoX,PosicaoY,Altura,Largura,cor);
}

/********************************
A fun��o Espera() "congela" a tela do jogo por alguns milisegundos, impedindo que qualquer outro comando seja executado enquanto isso.
Par�metros:
tempo (entrada, passagem por valor): indica a quantidade de milisegundos durante a qual o jogo ser� pausado.
********************************/
void Espera(int tempo)
{
    SDL_Delay(tempo);
}

/********************************
A fun��o Escrever() � respons�vel por exibir uma string na tela de jogo, escrevendo qualquer informa��o
deseja pelo usu�rio.
Par�metros:
PosicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja come�ar a escrever a string.
PosicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja come�ar a escrever a string.
Altura (entrada, passagem por valor): Valor onde o usu�rio ir� fornecer o n�mero correspondente em pixels � altura dessa string.
Largura (entrada, passagem por valor): Valor onde o usu�rio ir� fornecer o n�mero correspondente em pixels � largura dessa string.
Cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho da string;
********************************/
void Escrever(char *frase, int PosicaoX, int PosicaoY, int Altura, int Largura, PIG_Cor cor)
{
    jogo->EscreveString(frase,PosicaoX,PosicaoY,Altura,Largura,cor);
}

/********************************
A fun��o Cria_Objeto() � respons�vel por criar um objeto. Qualquer objeto que for necess�rio,
pode ser criado atrav�s dessa fun��o. O objeto ainda n�o ser� desenhado, apenas criado dentro do jogo.
Par�metros:
nomeArquivo (entrada, passagem por refer�ncia): string que informa o nome do arquivo da imagem do objeto a ser criado.
Retorno:
inteiro que representa o identificador �nico do objeto. Todas as opera��es subsequentes com este objeto dever�o receber este identificador como par�metro.
********************************/
int Cria_Objeto(char* nomeArquivo)
{
    return jogo->Cria_Objeto(0,0,nomeArquivo);
}

/********************************
A fun��o Destroi_Objeto() � respons�vel por eliminar o objeto em quest�o do jogo.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser exclu�do.
********************************/
void Destroi_Objeto(int id_objeto)
{
    jogo->Destroi_Objeto(id_objeto);
}

/********************************
A fun��o SetValorInt_Objeto() � respons�vel incorporar a um objeto um atributo inteiro.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): relaciona um n�mero inteiro ao atributo.
valor (entrada, passagem por valor): valor do atributo inteiro a ser associado ao objeto.
********************************/
void SetValorInt_Objeto(int id_objeto,int indice,int valor)
{
    jogo->objetos[id_objeto]->valoresInt[indice] = valor;
}


/********************************
A fun��o SetValorFloat_Objeto() � respons�vel incorporar a um objeto um atributo float.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): relaciona um n�mero inteiro ao atributo.
valor (entrada, passagem por valor): valor do atributo float a ser associado ao objeto.
********************************/
void SetValorFloat_Objeto(int id_objeto,int indice,int valor)
{
    jogo->objetos[id_objeto]->valoresFloat[indice] = valor;
}


/********************************
A fun��o GetValorInt_Objeto() � respons�vel recuperar o valor de um atributo int relacionado a um objeto.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): indica o n�mero do atributo que se deseja recuperar.
Retorno:
Retorna o valor do atributo int solicitado pelo usu�rio.
********************************/
int GetValorInt_Objeto(int id_objeto,int indice)
{
    return jogo->objetos[id_objeto]->valoresInt[indice];
}

/********************************
A fun��o GetValorFloat_Objeto() � respons�vel recuperar o valor de um atributo float relacionado a um objeto.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
indice (entrada, passagem por valor): indica o n�mero do atributo que se deseja recuperar.
Retorno:
Retorna o valor do atributo float solicitado pelo usu�rio.
********************************/
float GetValorFloat_Objeto(int id_objeto,int indice)
{
    return jogo->objetos[id_objeto]->valoresFloat[indice];
}

/********************************
A fun��o GetXY_Objeto() � respons�vel recuperar o valor da posi��o (X,Y) do objeto de acordo com o sistema de coordenadas do jogo.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
PosicaoX (sa�da, passagem por referencia): indica a posicao no eixo X do objeto.
PosicaoY (sa�da, passagem por referencia): indica a posicao no eixo Y do objeto.
********************************/
void GetXY_Objeto(int id_objeto,int *PosicaoX,int *PosicaoY)
{
    jogo->objetos[id_objeto]->GetXY(*PosicaoX,*PosicaoY);
}

/********************************
A fun��o Move_Objeto() � respons�vel por movimentar um determinado obeto para uma nova posi��o informada.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser movido.
PosicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja reposicionar o objeto.
PosicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja reposicionar o objeto.
********************************/
void Move_Objeto(int id_objeto,int PosicaoX,int PosicaoY)
{
    jogo->objetos[id_objeto]->Move(PosicaoX,PosicaoY);
}

/********************************
A fun��o Define_Angulo() � respons�vel pela angula��o de determinado objeto. A angula��o � calculada em sentido
anti-hor�rio a partir do eixo X (0 graus). O objeto ser� desenhado com a angula��o informada no pr�ximo comando
Desenha_Objeto(). A detec��o de colis�o n�o funciona com objetos fora da angula��o padr�o (0 graus).
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
angulo (entrada, passagem por valor): valor para indicar a angula��o do objeto em graus.
********************************/
void Define_Angulo(int id_objeto, float angulo)
{
    jogo->objetos[id_objeto]->SetAngulo(angulo);
}

/********************************
A fun��o Define_Pivo() define um ponto (X,Y) em rela��o ao ponto (0,0) do objeto, sobre o qual o objeto ser�
rotacionado quando a fun��o Define_Angulo() for executada.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
PosicaoX (entrada, passagem por valor): Valor da coordenada X em rela��o ao ponto (0,0) do objeto.
PosicaoY (entrada, passagem por valor): Valor da coordenada Y em rela��o ao ponto (0,0) do objeto.
********************************/
void Define_Pivo(int id_objeto,int PosicaoX,int PosicaoY)
{
    jogo->objetos[id_objeto]->SetPivo(PosicaoX,PosicaoY);
}

/********************************
A fun��o Define_Flip() � respons�vel por virar o objeto, invertendo-o em alguma dire��o. O objeto somente ser�
desenhado na nova orienta��o no pr�ximo comando Desenha_Objeto().
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser virado.
valor (entrada, passagem por valor): valor do tipo de Flip. Pode ser FLIP_NENHUM (nenhum tipo de invers�o),
FLIP_HORIZONTAL (inverte da esquerda para a direita), FLIP_VERTICAL (inverte de cima para baixo),
ou FLIP_HORIZ_VERT (inverte da esquerda para direita e de cima para baixo).
********************************/
void Define_Flip(int id_objeto,PIG_Flip valor)
{
    jogo->objetos[id_objeto]->SetFlip(valor);
}


/********************************
A fun��o Define_Dimensoes() � respons�vel por delimitar a altura e a largura do objeto que ser� desenhado na tela,
independentemente do tamanho original do arquivo de imagem.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
Altura (entrada, passagem por valor): altura em pixels do objeto a ser desenhado.
Largura (entrada, passagem por valor): largura em pixels do objeto a ser desenhado.
********************************/
void Define_Dimensoes(int id_objeto, int Altura, int Largura)
{
    jogo->objetos[id_objeto]->SetDimensoes(Altura,Largura);
}

/********************************
A fun��o Pega_Dimensoes() � respons�vel por recuperar a altura e a largura da �rea a ser usada
para desenhar o objeto na tela.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
Altura (sa�da, passagem por refer�ncia): altura em pixels do objeto a ser desenhado.
Largura (sa�da, passagem por refer�ncia): largura em pixels do objeto a ser desenhado.
********************************/
void Pega_Dimensoes(int id_objeto, int *Altura, int *Largura)
{
    jogo->objetos[id_objeto]->GetDimensoes(*Altura,*Largura);
}

/********************************
A fun��o Define_Frame() � respons�vel por delimitar o posicionamento dos pixels do arquivo de imagem
que ser�o utilizados para representar o objeto na tela. Desta forma, nem toda a imagem ser� automaticamente
utilizada para representar o objeto.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
Altura (entrada, passagem por valor): altura em pixels do objeto a ser desenhado.
Largura (entrada, passagem por valor): largura em pixels do objeto a ser desenhado.
********************************/
void Define_Frame(int id_objeto,int xBitmap, int yBitmap,int Altura,int Largura)
{
    jogo->objetos[id_objeto]->CriaFrame(xBitmap,yBitmap,Altura,Largura);
}

/********************************
A fun��o Modifica_Coloracao() � respons�vel por mesclar uma determinada cor com os pixels do arquivo de imagem.
Ap�s a modifica��o, todos os desenhos deste objeto ser�o mostrados j� com a mesclagem definida.
Para voltar ao padr�o original de pixels, deve-se chamar a fun��o, passando a cor branca (255,255,255).
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
cor (entrada,passagem por valor): cor do sistema RGB utilizada para mesclagem com o arquivo de imagem
********************************/
void Modifica_Coloracao(int id_objeto,PIG_Cor cor)
{
    jogo->objetos[id_objeto]->Modifica_Coloracao(cor);
}

/********************************
A fun��o Desenha_Objeto() � respons�vel por desenhar um objeto na tela. O objeto ser� desenhado de acordo com todos as defini��es
de posi��o e �ngulo informado at� o momento. Al�m disso, se o objeto estiver virado (flipping), isso tamb�m ser� levado em considera��o.
Par�metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
********************************/
void Desenha_Objeto(int id_objeto)
{
    jogo->objetos[id_objeto]->Desenha();
}

/********************************
A fun��o Testa_Colis�o() � respons�vel por testar se dois objetos se colidiram ou n�o, ao passar
os identificadores dos objetos por par�metro.
Par�metros:
id_objeto1 (entrada, passagem por valor): Identificador do primeiro objeto.
id_objeto2 (entrada, passagem por valor): Identificador do segundo objeto.
Retorno:
Inteiro indicando se houve colis�o (valor diferente de zero) ou n�o (valor igual a 0, zero).
********************************/
int Testa_Colisao(int id_objeto1,int id_objeto2)
{
    Objeto obj1 = jogo->objetos[id_objeto1];
    Objeto obj2 = jogo->objetos[id_objeto2];
    return obj2->Colisao(obj1);
}

/********************************
A fun��o Cria_GeradorParticulas() cria um novo gerador de part�culas (GDP). As part�culas em si precisam ser criadas
posteriormente atrav�s da fun��o Cria_Particula(), passando o identificador do GDP como par�metro.
Par�metros:
maxParticulas (entrada, passagem por valor): informa o maior n�mero de part�culas que o gerador ter� simultaneamente. O maior valor aceito � 1000 part�culas.
nomeArquivo (entrada, passagem por refer�ncia): indica o caminho relativo ou absoluto do arquivo de imagem,
 que ser� utilizado para cada part�cula do GDP.
********************************/
int Cria_GeradorParticulas(int maxParticulas,char* nomeArquivo)
{
    return jogo->Cria_GeradorParticulas(maxParticulas,nomeArquivo);
}

/********************************
A fun��o Destroi_GeradorParticulas() encerra um gerador de part�culas (GDP). Todas as part�culas relacionadas a ele tamb�m s�o finalizadas
neste momento.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
********************************/
void Destroi_GeradorParticulas(int id_gerador)
{
    jogo->Destroi_GeradorParticulas(id_gerador);
}

/********************************
A fun��o Move_GeradorParticulas() reposiciona um gerador de part�culas (GDP). Na pr�tica, isto significa que as novas part�culas que
forem criadas posteriormente ter�o esse ponto de origem.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
PosicaoX (entrada, passagem por valor): informa a nova posi��o X do GDP, em rela��o ao sistema de coordenadas do jogo.
PosicaoY (entrada, passagem por valor): informa a nova posi��o Y do GDP, em rela��o ao sistema de coordenadas do jogo.
********************************/
void Move_GeradorParticulas(int id_gerador,int PosicaoX,int PosicaoY)
{
    jogo->geradores[id_gerador]->Move(PosicaoX,PosicaoY);
}

/********************************
A fun��o MudaDirecao_Particulas() modifica a dire��o na qual as part�culas se movimentar�o ap�s serem criadas.
Somente as part�culas criadas posteriormente seguir�o a dire��o especificada.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
valorX (entrada, passagem por valor): informa a componente X da dire��o a ser definida para as part�culas.
valorY (entrada, passagem por valor): informa a componente Y da dire��o a ser definida para as part�culas.
********************************/
void MudaDirecao_Particulas(int id_gerador,int valorX,int valorY)
{
    jogo->geradores[id_gerador]->MudaDirecao(valorX,valorY);
}

/********************************
A fun��o Cria_Particula() adiciona uma nova part�cula ao jogo relacionada com o GDP passado como par�metro.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
Retorno:
inteiro indicando se a part�cula foi criada (valor maior ou igual a zero) ou n�o (valor menor do que zero).
A part�cula n�o ser� criada se j� houver o n�mero m�ximo de part�culas ativas.
********************************/
int Cria_Particula(int id_gerador)
{
    return jogo->geradores[id_gerador]->CriaParticula();
}

/********************************
A fun��o Move_Particulas() faz com que todas as part�cula ativas do GDP em quest�o se movimentem de acordo com as componentes
X e Y passadas na fun��o MudaDirecao_Particulas(). As part�culas que sa�rem da tela de jogo ou aqueles que j� existerm a mais de 10000 segundos
ser�o consideradas inativas e deixar�o de existir.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
********************************/
void Move_Particulas(int id_gerador)
{
    jogo->geradores[id_gerador]->MoveParticulas();
}

/********************************
A fun��o Quantidade_ParticulasAtivas() indica quantas part�culas do GDP em quest�o ainda est�o ativas. As part�culas deixam de
ser ativas quando saem da tela do jogo, quando colidem com algum objeto ou depois de 10000 segundos de vida.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
Retorno:
inteiro que indica o n�mero de part�culas ativas.
********************************/
int Quantidade_ParticulasAtivas(int id_gerador)
{
    return jogo->geradores[id_gerador]->ativas;
}

/********************************
A fun��o Desenha_Particulas() desenha todas as part�culas ativas do GDP na posi��o que estiverem.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
********************************/
void Desenha_Particulas(int id_gerador)
{
    jogo->geradores[id_gerador]->Desenha();
}

/********************************
A fun��o Colisao_Particulas() indica se houve colis�o de alguma part�cula ativa do GDP com um outro objeto espec�fico, atrav�s do seu identificador.
Par�metros:
id_gerador (entrada, passagem por valor): informa o identificador do GDP passado como retorno da fun��o Cria_GeradorParticulas().
id_objeto (entrada, passagem por valor): identificador do objeto que pode ter colidido com as part�culas do GDP.
Retorno:
inteiro que indica se houve colis�o de alguma part�cula ativa do GDP (valor diferente de zero) ou n�o (valor igual a 0, zero).
********************************/
int Colisao_Particulas(int id_gerador,int id_objeto)
{
    Objeto obj = jogo->objetos[id_objeto];
    return jogo->geradores[id_gerador]->Colisao(obj);
}

/********************************
A fun��o Cria_Timer() � respons�vel por criar um timer (temporizador). Ap�s a cria��o o tempo decorrido
poder� ser obtido a partir da fun��o Tempo_Decorrido(), informando o identificador que � passado na resposta.
Retorno:
inteiro que identifica o timer criado.
********************************/
int Cria_Timer()
{
    return jogo->Cria_Timer();
}

/********************************
A fun��o Tempo_Decorrido() � respons�vel por informar o tempo decorrido desde a cria��o do timer
at� a hora em que a fun��o for chamada.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
Retorno:
n�mero real indicando o tempo (em segundos) desde a cria��o do timer.
********************************/
float Tempo_Decorrido(int id_timer)
{
    return jogo->timers[id_timer]->GetTempoDecorrido();
}

/********************************
A fun��o Pausa() � respons�vel por realizar uma pausa na contagem do tempo de um timer. Ap�s a despausa,
o timer continuar� a contar o tempo normalmente.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Pausa_Timer(int id_timer)
{
    jogo->timers[id_timer]->Pausa();
}

/********************************
A fun��o Despausa() � respons�vel por retomar a contagem do tempo de um timer ap�s uma pausa.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Despausa_Timer(int id_timer)
{
    jogo->timers[id_timer]->Despausa();
}

/********************************
A fun��o Reinicia_Timer() � respons�vel por zerar a contagem do tempo de um timer, idependente do tempo j� decorrido.
Na pr�tica, � equivalente a encerrer um temporizador e recri�-lo em seguida.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Reinicia_Timer(int id_timer)
{
    jogo->timers[id_timer]->Reinicia();
}

/********************************
A fun��o Destroi_Timer() � respons�vel por encerrar a utiliza��o de timer.
Seu identificador n�o poder� ser utilizado ap�s a fun��o ser executada.
Par�metros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void Destroi_Timer(int id_timer)
{
    jogo->Destroi_Timer(id_timer);
}
