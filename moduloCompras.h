typedef struct compra Compra;

struct compra {
    char codCompra[7];
    char dataCompra[11];
    char horaCompra[9];
    char status;
    char codItem[14];
    char dataValidade[11];
    char nomeItem[51];
    int quant;
    double valorItem;
};

char menuCompras(void);

void cadastrarCompra(void);

void gravarCompra(Compra*);

void exibirTudo(Compra*);

void exibirCompra(Compra*);

void exibirItens(Compra*);

long int telaPesquisarCompra(void);

Compra* pegarCompra(long int);

void pesquisarCompra(void);

long int telaExcluirCompra(void);

void excluirCompraLog(Compra*);

void excluirCompra(void);

long int telaAlterarCompra(void);

char* telaPreencheData(void);

char* telaPreencheHora(void);

int telaPreencheQuant(void);

char telaEscolha(void);

void regravarCompra(Compra* com);

void alterarCompra(void);

/*void cadastrarCompra(void);

Chave* telaPesquisarCompra(void);

Chave* telaExcluirCompra(void);

Compra* pegarCompra(Chave*);

void excluirLogicamente(Compra*);

void excluirCompra(void);

Chave* telaAlterarCompra();

void alterarTudo(Compra*);

void alterarItem(Compra*);

void alterarCompra(void);
*/
void listarCompras(void);
