package inatel.funcionalidades.com;

public class Facebook extends RedeSocial implements Compartilhamento, VideoConferencia {

    public Facebook(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    @Override
    void postarFoto() {
        System.out.println("Você postou uma foto no Facebook");
    }

    @Override
    void postarVideo() {
        System.out.println("você postou um vídeo no Facebook");
    }

    @Override
    void postarComentario() {
        System.out.println("Você postou um comentário no Facebook");
    }

    @Override
    public void compartilhar() {
        System.out.println("Você compartilhou no Facebook");
    }

    @Override
    public void fazSteaming() {
        System.out.println("Você abriu uma livestream no Facebook");
    }
}
