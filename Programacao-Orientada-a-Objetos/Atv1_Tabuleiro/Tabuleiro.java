/* Aprendendo Java!!!
    Requisitos gerais:
        -
    Classe Pública: qualquer outra classe pode usar esta    [public class Nome] => O arquivo .java deve ter o nome da classe
    Membros: São atributos da classe (pode pensar como característica)
        -> Public: São aqueles acessíveis de fora da classe em que são definidos    [public tipo nome]
        -> Private: As variáveis dentro de uma classe não podem ser acessadas fora da classe    [private tipo nome]
    Métodos: ações na classe [public void metodo]
        -> Main: É a classe principal e é onde a execução começa e termina
        -> Construtor: Método que cria um objeto (deve ter sempre pelo menos um) => Deve ter o mesmo nome da classe e não tem tipo
        -> Getters: Métodos para acessar dados privados
*/  

public class Tabuleiro{
    // Esta classe será responsável por: guardar o estado atual, mover peças, imprimir e verificar solução

    // Os seguintes Membros devem ser privados, já que só serão alterados por métodos
    private int[] posicao_atual;
    private int tamanho;
    private int posicao_zero;

    // Criando métodos, obviamente publicos
    public Tabuleiro(int[] inicial){
        tamanho = inicial.length;
        posicao_atual = new int[tamanho];

        for (int i = 0; i < tamanho; i++) {
            posicao_atual[i] = inicial[i];

            if (posicao_atual[i] == 0) {
                posicao_zero = i;
            }
        }
    }

    public void atualizar_estado(int i, int j){
        int temp = posicao_atual[i];
        posicao_atual[i] = posicao_atual[j];
        posicao_atual[j] = temp;
    }

    public void mover_peca(char movimento){
        int n = (int) Math.sqrt(tamanho); // tamanho da linha
        int nova_posicao = posicao_zero;

        if (movimento == 'd') {
            if (posicao_zero >= n) {
                nova_posicao = posicao_zero - n;
            } else return;
        }

        else if (movimento == 'u') {
            if (posicao_zero < tamanho - n) {
                nova_posicao = posicao_zero + n;
            } else return;
        }

        else if (movimento == 'r') {
            if (posicao_zero % n != 0) {
                nova_posicao = posicao_zero - 1;
            } else return;
        }

        else if (movimento == 'l') {
            if ((posicao_zero + 1) % n != 0) {
                nova_posicao = posicao_zero + 1;
            } else return;
        }

        // faz a troca
        atualizar_estado(posicao_zero, nova_posicao);

        // atualiza posição do zero
        posicao_zero = nova_posicao;

    }

    public void imprimir() {
        int n = (int) Math.sqrt(tamanho);

        for (int i = 0; i < n; i++) {

            // linha de separação
            for (int j = 0; j < n; j++) {
                System.out.print("+------");
            }
            System.out.println("+");

            // linha de valores
            for (int j = 0; j < n; j++) {
                int valor = posicao_atual[i * n + j];
                System.out.printf("| %3d  ", valor);
            }
            System.out.println("|");
        }

        // última linha
        for (int j = 0; j < n; j++) {
            System.out.print("+------");
        }
        System.out.println("+");

        System.out.println();
    }

    public boolean verificar_solucao(){
         // primeiro deve ser 0
        if (posicao_atual[0] != 0) {
            return false;
        }

        for (int i = 0; i < tamanho - 1; i++) {
            if (posicao_atual[i] != i) {
                return false;
            }
        }

        return true;
    }

}