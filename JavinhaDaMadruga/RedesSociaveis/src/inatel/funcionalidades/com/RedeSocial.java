package inatel.funcionalidades.com;

abstract public class RedeSocial {
    protected String senha;
    protected int numAmigos;

    public RedeSocial(String senha, int numAmigos) {
        this.senha = senha;
        this.numAmigos = numAmigos;
    }

    abstract void postarFoto();
    abstract void postarVideo();
    abstract void postarComentario();

    void curtirPublicacao() {
        System.out.println("Você curtiu uma publicação");
    }
}
