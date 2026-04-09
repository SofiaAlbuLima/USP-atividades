import java.util.Scanner;

public class Main{

    static public void main(String[] args){
        Scanner sc = new Scanner(System.in);

        // Pesquisei um metodo de ter a string completa para converter em um ints, já q ele nn insere o tamanho do tabuleiro
        String string_posicao_inicial = sc.nextLine();
        String[] partes_posicao_inicial = string_posicao_inicial.split(" ");
        int[] vetor = new int[partes_posicao_inicial.length];


        for(int i = 0; i < partes_posicao_inicial.length; i++){
            vetor[i] = Integer.parseInt(partes_posicao_inicial[i]);
        }

        // Criando tabuleiro
        Tabuleiro t = new Tabuleiro(vetor);

        // lendo movimentos
        String movimentos = sc.nextLine();

        t.imprimir();

        // executando movimentos
        for (int i = 0; i < movimentos.length(); i++) {
            char m = movimentos.charAt(i);

            t.mover_peca(m);
            t.imprimir();
        }

        // verifica solução
        if (t.verificar_solucao()) {
            System.out.println("Posicao final: " + t.verificar_solucao());
        } else {
            System.out.println("Posicao final: " + t.verificar_solucao());
        }

        sc.close();
    }

}