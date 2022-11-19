#![allow(dead_code)]
#![allow(unused_imports)]
pub mod partido {

    use console::Term;
    use owo_colors::OwoColorize;

    use crate::{
        cartas::mazo::{self, Mazo},
        jugador::jugador::Jugador,
        oponente::oponente::Oponente,
    };

    pub enum Ronda<T> {
        Irse,
        Tirar(T),
        Mostrar(T),
        Canto(T),
        Error(T),
        Nada
    }
    pub enum Respuesta<T> {
        Quiero,
        NoQuiero,
        Mas(T),
    }
    pub enum Envido {
        Envido,
        Envido2,
        RealEnvido,
        FaltaEnvido
    }
    pub enum Truco {
        Truco,
        ReTruco,
        ValeCuatro,
    }
    pub enum Flor {
        Flor,
        ContraFlor,
        ContraFlorAlResto
    }
    pub struct Partido {
        player: Jugador,
        rival: Oponente,
        mazo: Mazo,
        puntos_player: u8,
        puntos_oponente: u8,
    }
    impl Partido {
        pub fn from(player: Jugador, rival: Oponente, mazo: Mazo) -> Partido {
            Partido {
                player: player,
                rival: rival,
                mazo: mazo,
                puntos_player: 0,
                puntos_oponente: 0,
            }
        }
        pub fn jugar(&mut self) -> Option<bool> {
            println!(
                "{} vs {}",
                self.player.nombre.magenta(),
                self.rival.nombre.white().bold()
            );
            while self.puntos_player < 30 || self.puntos_oponente < 30 {
                let puntos = self.jugar_mano().unwrap();
                self.puntos_player += puntos.0;
                self.puntos_oponente += puntos.1;
            }
            if self.puntos_player >= 30 {
                return Some(true);
            }
            return Some(false);
        }
        pub fn jugar_mano(&self) -> Option<(u8, u8)> {
            use std::io::{stdin, Write};
            let term = Term::stdout();
            let /* mut */ puntos_player: u8 = 0;  // Los
            let /* mut */ puntos_rival: u8 = 0;   // Puntos de la mano
            //ronda 1
            let mut s = String::new();
            {
                while s.is_empty() {
                    s.clear();
                    print!("{}", ">>".blue());
                    std::io::stdout().flush().expect("Error flusheando stdout");
                    s = term.read_line().expect("Error leyendo de read line");
                }

            }
            //ronda 2

            //ronda 3

            return Some((puntos_player, puntos_rival));
        }
    }
    fn read_cmd(cmd: String) -> Ronda<String> {
        let cmds = cmd.split(" ").collect::<Vec<&str>>();
        if cmds.len() > 2 {
            return Ronda::Error(format!("Error: {}", "Muchos argumentos".red().bold()));
        }
        match cmds[0].to_lowercase().as_str() {
            "cantar" => {
                return Ronda::Canto(cmds[1].to_string().to_lowercase());
            }
            "irse" => {
                return Ronda::Irse;
            }
            "tirar" => {
                return Ronda::Tirar(cmds[1..].concat().to_string());
            },
            _ => return Ronda::Error(format!("Error: {}", "No reconocido".red().bold())),
        }
    }
}
