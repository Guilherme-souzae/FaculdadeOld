package inatel.funcionalidades.com;

public class GooglePlus extends RedeSocial implements Compartilhamento, VideoConferencia {

    public GooglePlus(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    @Override
    void postarFoto() {
        System.out.println("Você postou uma foto no GooglePlus");
    }

    @Override
    void postarVideo() {
        System.out.println("você postou um vídeo no GooglePlus");
    }

    @Override
    void postarComentario() {
        System.out.println("Você postou um comentário no GooglePlus");
    }

    @Override
    public void compartilhar() {
        System.out.println("Você compartilhou no GooglePlus");
    }

    @Override
    public void fazSteaming() {
        System.out.println("Você abriu uma livestream no GooglePlus");
    }
}
