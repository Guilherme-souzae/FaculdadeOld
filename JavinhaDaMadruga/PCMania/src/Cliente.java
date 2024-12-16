public class Cliente {
    public String nome;
    public long cpf;
    public int numcompras;
    public Computador[] computadores;
    public int matricula;

    // metodo que realiza a compra com base nos código de compra inserido pelo cliente
    public void compra(int promo, boolean usb)
    {
        Computador novoPC = null;
        MemoriaUSB novoUSB = null;
        switch (promo)
        {
            case 1:
                novoPC = new Computador("Positivo",this.matricula,"Pentium Core i3",2200,"Memoria RAM",8,"HD",500,"Linux Ubuntu",32);
                novoUSB = new MemoriaUSB("Pen drive",16);
                break;
            case 2:
                novoPC = new Computador("Acer",this.matricula + 1234,"Pentium Core i5",3370,"Memoria RAM", 16, "HD", 1000, "Windows 8", 64);
                novoUSB = new MemoriaUSB("Pen drive",32);
                break;
            case 3:
                novoPC = new Computador("vaio",this.matricula + 5678, "Pentium Core i7", 4500, "Memoria RAM", 32, "HD", 2000, "Windows 10", 64);
                novoUSB = new MemoriaUSB("HD externo",1000);
                break;
        }

        for (int i = 0; i < this.computadores.length; i++)
        {
            if (this.computadores[i] == null)
            {
                this.computadores[i] = novoPC;
                if (usb) novoPC.addMemoriaUSB(novoUSB);
                break;
            }
        }
    }

    public float calculaTotalCompra()
    {
        float total = 0;
        for (int i = 0; i < this.computadores.length; i++)
        {
            if (this.computadores[i] != null)
            {
                total += this.computadores[i].preco;
            }
        }
        return total;
    }
}
