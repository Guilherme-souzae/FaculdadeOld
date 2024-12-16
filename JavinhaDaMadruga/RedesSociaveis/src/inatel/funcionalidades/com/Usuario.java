package inatel.funcionalidades.com;

import inatel.exceptions.com.contaInexistenteException;
import inatel.exceptions.com.funcaoInexistenteException;

import java.util.HashMap;
import java.util.Map;

public class Usuario {
    private String nome;
    private String email;
    public Map<String, RedeSocial> contas;

    public Usuario(String nome, String email, RedeSocial[] redeSociais) {
        this.nome = nome;
        this.email = email;

        this.contas = new HashMap<>();
        for (RedeSocial redeSocial : redeSociais) {
            if (redeSocial instanceof Facebook) {
                contas.put("Facebook", redeSocial);
            }
            else if (redeSocial instanceof GooglePlus) {
                contas.put("GooglePlus", redeSocial);
            }
            else if (redeSocial instanceof Twitter) {
                contas.put("Twitter", redeSocial);
            }
            else if (redeSocial instanceof Instagram) {
                contas.put("Instagram", redeSocial);
            }
        }
    }

    public void usar(String keyRede, String acao) {
        try {
            usarAux(keyRede, acao);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private void usarAux(String keyRede, String acao) throws Exception {
        RedeSocial redeSocial = contas.get(keyRede);
        if (redeSocial == null) throw new contaInexistenteException("conta inexistente");

        switch (acao) {
            case "postarFoto":
                redeSocial.postarFoto();
                break;

            case "postarVideo":
                redeSocial.postarVideo();
                break;

            case "postarComentario":
                redeSocial.postarComentario();
                break;

            case "curtirPub":
                redeSocial.curtirPublicacao();
                break;

            case "fazerLive":
                if (redeSocial instanceof Facebook) {
                    ((Facebook) redeSocial).fazSteaming();
                    break;
                }
                else if (redeSocial instanceof GooglePlus) {
                    ((GooglePlus) redeSocial).fazSteaming();
                    break;
                }
            case "compartilhar":
                if (redeSocial instanceof Facebook) {
                    ((Facebook) redeSocial).compartilhar();
                    break;
                }
                else if (redeSocial instanceof GooglePlus) {
                    ((GooglePlus) redeSocial).compartilhar();
                    break;
                }
                else if (redeSocial instanceof Twitter) {
                    ((Twitter) redeSocial).compartilhar();
                    break;
                }
            default:
                throw new funcaoInexistenteException("funcionalidade inexistente");
        }
    }
}
