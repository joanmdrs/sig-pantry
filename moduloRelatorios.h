typedef struct produtoR ProdutoR;

struct produtoR {
    char codBarras[14];
    char dataValidade[11];
    char nomeItem[51];
    char local[20];
    int quant;
    char status[11];
    struct produto *prox;
};

char menuRelatorios(void);
char menuRelatorioProdutos(void);
void itensVencidos(void);
void itensParaVencer(void);

void exibirLista(Produto*);
Produto* itensOrdenados(void);
void relatorioItensOrdenados(void);

char menuRelatorioCompras(void);
void comprasDiarias(void);
void comprasMensais(void);
void comprasAnuais(void);
char menuRelatorioConsumo(void);
void consumoDiario(void);
void consumoMensal(void);
void consumoAnual(void);