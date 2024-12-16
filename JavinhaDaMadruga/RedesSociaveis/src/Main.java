import inatel.funcionalidades.com.*;

import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        RedeSocial[] contas = new RedeSocial[]{new Facebook("aaa",123), new Instagram("saunders",10)};
        Usuario user = new Usuario("Gui","gui@gmail.com",contas);
        user.usar("Instagram","compartilhar"); // caso de erro

        user.usar("Instagram","postarFoto");
        user.usar("Instagram","curtirPub");
        user.usar("Instagram","postarComentario");

        user.usar("Facebook", "postarVideo");
        user.usar("Facebook","compartilhar");
        user.usar("Facebook","fazerLive");

        user.usar("Facebook","abrirTrend"); // caso de erro
        user.usar("Reddit","abrirTrend"); // caso de erro
    }
}