typedef struct consumo Consumo;
struct consumo {
    char quantItens[10];
    Produto itens[100];
    char dataConsumo[11];
    char horaConsumo[6];
    char status[10];
};

typedef struct chaveC ChaveC;

struct chaveC{
    char dataConsumo[11];
    char horaConsumo[6];
};

char menuConsumo(void);

Consumo* telaCadastrarConsumo(void);

void cadastrarConsumo(void);

void gravarConsumo(Consumo*);

void exibirConsumo(Consumo*);

ChaveC* telaPesquisarConsumo(void);

Consumo* pegarConsumo(ChaveC*);

void pesquisarConsumo(void);

void telaExcluirConsumo(Consumo*);

ChaveC* telaAlterarConsumo(void);

void alterarTudoC(Consumo*);

void alterarItemC(Consumo*);

void alterarConsumo(void);

void telaListarConsumos(void);
