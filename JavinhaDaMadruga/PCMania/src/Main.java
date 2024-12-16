import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // o objeto "cliente" é inteiramente definido pela entrada de dados
        Cliente cliente = new Cliente();
        System.out.println("Insira o seu nome:");
        cliente.nome = scanner.next();

        System.out.println("Insira o seu cpf:");
        cliente.cpf = scanner.nextLong();

        System.out.println("Insira a sua matricula:");
        cliente.matricula = scanner.nextInt();

        System.out.println("Quantas compras você gostaria de fazer?");
        cliente.numcompras = scanner.nextInt();
        cliente.computadores = new Computador[cliente.numcompras];

        // as compras são computadas por meio de um metodo do cliente que recebe a entrada de dados referente ao código da promoção
        // cada código chama um construtor da classe "computador" com parametros unicos
        for (int i = 0; i < cliente.numcompras; i++) {
            int promocode;
            String insertusb;

            System.out.println("Insira o codigo das compras (1,2,3):");
            
            do
            {
                promocode = scanner.nextInt();
            } while (promocode != 1 && promocode != 2 && promocode != 3);

            System.out.println("Você deseja inserir o USB? (false, true): ");
            insertusb = scanner.next();
            if (insertusb.equals("true"))
            {
                cliente.compra(promocode,true);
            }
            else
            {
                cliente.compra(promocode,false);
            }
        }

        System.out.println("Detalhes da compra:");
        System.out.println("Nome do cliente: "+cliente.nome);
        System.out.println("CPF do cliente: "+cliente.cpf);
        System.out.println("Matricula do cliente: "+cliente.matricula);
        System.out.println("Num compras: "+cliente.numcompras);
        System.out.println("");
        for (int i = 0; i < cliente.numcompras; i++) {
            cliente.computadores[i].mostraPCConfigs();
            System.out.println("");
        }
        System.out.println("Preço total: "+cliente.calculaTotalCompra());
        scanner.close();
    }
}
