package inatel.funcionalidades.com;

public class Twitter extends RedeSocial implements Compartilhamento {

    public Twitter(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    @Override
    void postarFoto() {
        System.out.println("Você postou uma foto no Twitter");
    }

    @Override
    void postarVideo() {
        System.out.println("você postou um vídeo no Twitter");
    }

    @Override
    void postarComentario() {
        System.out.println("Você postou um comentário no Twitter");
    }

    @Override
    public void compartilhar() {
        System.out.println("Você compartilhou no Twitter");
    }
}
