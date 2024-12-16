package inatel.funcionalidades.com;

public class Instagram extends RedeSocial {

    public Instagram(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    @Override
    void postarFoto() {
        System.out.println("Você postou uma foto no Instagram");
    }

    @Override
    void postarVideo() {
        System.out.println("você postou um vídeo no Instagram");
    }

    @Override
    void postarComentario() {
        System.out.println("Você postou um comentário no Instagram");
    }
}
