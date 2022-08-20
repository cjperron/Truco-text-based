mod cartas;
mod jugador;
mod estadisticas;
mod item;
mod atributo;
use cartas::{carta::Carta, mazo};
use jugador::jugador::{Jugador};
use std::{io::{stdin, stdout, Write, Read},  fs::File};
use owo_colors::OwoColorize;
use console::Term;

fn limpiar_pantalla() {
    let term = Term::stdout();
    term.clear_screen().unwrap();
}
fn print_menu() {
    println!(
        "{}\t\t{}\n{}",
        "T  R  U  C  O".green(), "Unix Version".cyan(), "1.Jugar\n2.Opciones\n3.Salir\n".white(),
    );
}

fn main() {
    let _mazo = mazo::Mazo::new();
    let result_p1 = Jugador::read_from_sel();
    let mut p1 = match result_p1.1 {
        true => result_p1.0, 
        false => {
            let tmp = Jugador::ask_in();
            tmp.write_to_file(&(tmp.nombre.to_owned()+".json"));
            tmp.write_to_sel();
            tmp
        },
    };
    loop {
        limpiar_pantalla();
        print_menu();
        //println!("{}", ej.to_gl_string());
        print!("{}", ">>".blue());
        stdout().flush().expect("Error flusheando stdout");
        let mut s = String::new();
        stdin().read_line(&mut s).expect("Error leyendo linea");
        match s.trim() {
            "1" => {
                loop {
                    limpiar_pantalla();
                    println!("{}\n{}\n{}\n{}", "1. Partido vs IA".green(), "2. Torneo 'San Bonifacio'".yellow(), "3. Personaje".cyan(), "4. Salir".red());
                    print!("{}", ">>".blue());
                    stdout().flush().expect("Error flusheando stdout");
                    let mut s = String::new();
                    stdin().read_line(&mut s).expect("Error leyendo linea");
                    match s.trim() {
                        "1" => {} //Faltaria desarrollar la IA
                        "2" => {} //SI
                        "3" => {menu_personaje(&mut p1)} //Pj
                        "4" => {
                            break;
                        }
                        _ => println!("{}", "Error: No reconocido".red()),
                    }
                }
            }
            "2" => {}
            "3" => {
                break;
            }
            _ => {
                println!("{}", "Error: No reconocido".red());
            }
        }
    }
    pause();
    limpiar_pantalla();
}

fn menu_personaje(pj: &mut Jugador){
    // let mut buf = String::new();
    let term = Term::stdout();
    loop {
        limpiar_pantalla();
        println!("{}\n{}\n{}\n{}\n", "P E R S O N A J E".cyan(), "1. Crear Personaje".yellow(), "2. Elejir personaje".magenta(), "3. Salir".red());
        print!("{}", ">>".blue());
        stdout().flush().expect("Error flusheando stdout");
        let res = term.read_char().unwrap();
        match res {
            '1' => {
                if Jugador::create_user() {
                    *pj = Jugador::read_from_sel().0;
                }
            }
            '2' => { //No anda
                println!("{}", "Elejir personaje".italic());
                use std::fs;
                let paths = fs::read_dir("./").unwrap();
                //DEBUG
                for path in paths {
                    let buf = String::from(path.unwrap().path().display().to_string());
                    if buf.contains(".json") {
                        // println!("path: {}", buf); tengo el path correcto.
                        let mut file = File::open(buf).unwrap();
                        let mut s_json = String::new();
                        file.read_to_string(&mut s_json).unwrap();
                        let tmpj: Jugador = serde_json::from_str(s_json.as_str()).unwrap();
                        println!("{}", tmpj.pretty_string());
                        println!("-----------------");
                    }
                }
                //Se mostraron los jugadores creados

            }
            '3' => {break;},
            _ => {
                println!("{}", "Error: No reconocido".red());
            }
        }
        pause();
    }
}
fn pause() {
    use std::io;
    let term = Term::stdout();
    let mut stdout = io::stdout();
    write!(stdout, "Press any key to continue...").unwrap();
    stdout.flush().unwrap();
    let _ = term.read_char().unwrap();
}