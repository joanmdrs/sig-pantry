typedef struct consumo Consumo;

struct consumo {
    char dataConsumo[11];
    char horaConsumo[6];
    char quantItens[10];
    Produto itens[100];
    char status[10];
};

typedef struct chaveC ChaveC;

struct chaveC{
    char dataConsumo[11];
    char horaConsumo[6];
};

void gravarConsumo(Consumo*);

void exibirConsumo(Consumo*);

char menuConsumo(void);

Consumo* telaCadastrarConsumo(void);

void cadastrarConsumo(void);

ChaveC* telaPesquisarConsumo(void);

Consumo* pegarConsumo(ChaveC*);

void pesquisarConsumo(void);

ChaveC* telaExcluirConsumo(void);

void excluirLogicamente(Consumo*);

void excluirConsumo(void);

ChaveC* telaAlterarConsumo(void);

void alterarTudoC(Consumo*);

void alterarItemC(Consumo*);

void alterarConsumo(void);

void listarConsumos(void);
