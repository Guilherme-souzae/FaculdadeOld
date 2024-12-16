public class Computador {
    public String marca;
    public float preco;

    public SistemaOperacional sistemaOperacional;
    public HardwareBasico processador;
    public HardwareBasico memoriaram;
    public HardwareBasico discorigido;
    public MemoriaUSB memoriaUSB;

    Computador(String marcaPC, float precoPC, String nomeCPU, int capacidadeCPU, String nomeRAM, int capacidadeRAM, String nomeHD, int capacidadeHD, String nomeSO, int tipoSO)
    {
        this.marca = marcaPC;
        this.preco = precoPC;
        this.processador = new HardwareBasico(nomeCPU,capacidadeCPU);
        this.memoriaram = new HardwareBasico(nomeRAM,capacidadeRAM);
        this.discorigido = new HardwareBasico(nomeHD, capacidadeHD);
        this.sistemaOperacional = new SistemaOperacional(nomeSO,tipoSO);
    }

    void mostraPCConfigs()
    {
        System.out.println("Marca: "+this.marca);
        System.out.println("Processador: "+this.processador.nome+" "+this.processador.capacidade+"MHz");
        System.out.println("MemoriaRAM: "+this.memoriaram.nome+" "+this.memoriaram.capacidade+"Gb");
        System.out.println("Disco rigido: "+this.discorigido.nome+" "+this.discorigido.capacidade+"Gb");
        System.out.println("Sistema operacional: "+this.sistemaOperacional.nome+" "+this.sistemaOperacional.tipo+"bits");
        if (this.memoriaUSB != null) System.out.println("Armazenamento externo: "+this.memoriaUSB.nome+" "+this.memoriaUSB.capacidade+"Gb");
    }

    void addMemoriaUSB(MemoriaUSB musb)
    {
        this.memoriaUSB = musb;
    }
}
