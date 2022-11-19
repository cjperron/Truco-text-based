mod atributo;
mod cartas;
mod estadisticas;
mod item;
mod jugador;
mod oponente;
mod partido;
use cartas::{carta::Carta, mazo};
use console::Term;
use jugador::jugador::Jugador;
use owo_colors::OwoColorize;
use std::{
    fs::{self, File},
    io::{stdin, stdout, Read, Write},
};

fn limpiar_pantalla() {
    use clearscreen::clear;
    clear().expect("Error borrando la pantalla!");
}
fn print_menu() {
    println!(
        "{}\t\t{}\n{}",
        "T  R  U  C  O".green(),
        "Unix Version".cyan(),
        "1.Jugar\n2.Opciones\n3.Salir\n".white(),
    );
}
fn main() {
    let mut mazo = mazo::Mazo::new();
    let mut result_p1 = Jugador::read_from_sel();
    let mut p1 = match result_p1.1 {
        true => result_p1.0,
        false => {
            let tmp = Jugador::ask_in();
            tmp.write_to_file(&(tmp.nombre.to_owned() + ".json"));
            tmp.write_to_sel();
            tmp
        }
    };
    loop {
        mazo.shuffle();
        limpiar_pantalla();
        print_menu();
        println!("Personaje seleccioando: {}", p1.nombre.magenta());
        //DEBUG
        p1.mano[0] = mazo.cartas[0].clone();
        p1.mano[1] = mazo.cartas[1].clone();
        p1.mano[2] = mazo.cartas[2].clone();
        println!("Cartas del jugador: \n{}\n{}\n{}\n", p1.mano[0].to_string(),p1.mano[1].to_string(),p1.mano[2].to_string());
        println!("Envido: {}", p1.calc_envido());
        //DEBUG
        print!("{}", ">>".blue());
        stdout().flush().expect("Error flusheando stdout");
        let mut s = String::new();
        stdin().read_line(&mut s).expect("Error leyendo linea");
        match s.trim() {
            "1" => {
                menu_juego(&mut p1);
            }
            "2" => {
                let term = Term::stdout();
                limpiar_pantalla();
                println!(
                    "{}\n1. {}\n2. {}",
                    "O P C I O N E S".cyan().bold(),
                    "Eliminar Datos".white().bold(),
                    "Salir".red().bold()
                );
                loop {
                    print!("{}", ">>".blue());
                    stdout().flush().expect("Error flusheando stdout");
                    let res = term.read_char().unwrap();
                    match res {
                        '1' => {
                            let paths = fs::read_dir("./").unwrap();
                            for path in paths {
                                let buf = String::from(path.unwrap().path().display().to_string());
                                if buf.contains(".json") {
                                    fs::remove_file(buf).expect("Error removiendo archivo");
                                }
                            }
                            fs::remove_file("./bin/tot.json").unwrap();
                            fs::remove_file("./bin/sel.json").unwrap();
                            result_p1 = Jugador::read_from_sel();
                            p1 = match result_p1.1 {
                                true => result_p1.0,
                                false => {
                                    let tmp = Jugador::ask_in();
                                    tmp.write_to_file(&(tmp.nombre.to_owned() + ".json"));
                                    tmp.write_to_sel();
                                    tmp
                                }
                            };
                            println!("Datos eliminados!");
                        }
                        '2' => {
                            break;
                        }
                        _ => println!("{}", "Error: No reconocido".red()),
                    }
                }
            }
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

fn menu_juego(p1: &mut Jugador) {
    loop {
        limpiar_pantalla();
        println!(
            "{}\n{}\n{}\n{}",
            "1. Partido vs IA".green(),
            "2. Torneo 'San Bonifacio'".yellow(),
            "3. Personaje".cyan(),
            "4. Salir".red()
        );
        println!("Personaje seleccioando: {}", p1.nombre.magenta());
        print!("{}", ">>".blue());
        stdout().flush().expect("Error flusheando stdout");
        let mut s = String::new();
        stdin().read_line(&mut s).expect("Error leyendo linea");
        match s.trim() {
            "1" => {}                       //Faltaria desarrollar la IA
            "2" => {}                       //SI
            "3" => menu_personaje(p1), //Pj
            "4" => {
                break;
            }
            _ => println!("{}", "Error: No reconocido".red()),
        }
    }
}

fn menu_personaje(pj: &mut Jugador) {
    // let mut buf = String::new();
    let term = Term::stdout();
    loop {
        limpiar_pantalla();
        println!(
            "{}\n{}\n{}\n{}\n",
            "P E R S O N A J E".cyan(),
            "1. Crear Personaje".yellow(),
            "2. Elegir personaje".magenta(),
            "3. Salir".red()
        );
        print!("{}", ">>".blue());
        stdout().flush().expect("Error flusheando stdout");
        let res = term.read_char().unwrap();
        match res {
            '1' => {
                if Jugador::create_user() {
                    *pj = Jugador::read_from_sel().0;
                }
            }
            '2' => {
                //No anda
                let term_s = Term::stdout();
                println!("{}", "Elejir personaje".italic());
                let paths = fs::read_dir("./").unwrap();
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
                let mut buf = String::new();
                while buf.is_empty() || not_contain_num(&buf){
                    buf.clear();
                    print!("Seleccione jugador ({}): ", "id".blue().bold());
                    stdout().flush().unwrap();
                    buf = term_s.read_line().unwrap();
                }
                let num: u32 = buf.parse().unwrap();
                if Jugador::select_player(num).1 {
                    pj.write_to_sel();
                    //DEBUG
                    println!("Escrito");
                    *pj = Jugador::select_player(num).0;
                } else {
                    println!("{}", "No existe jugador.".red().italic());
                }
            }
            '3' => {
                break;
            }
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
fn not_contain_num(s: &String) -> bool {
    for c in s.as_str().chars() {
    if c.is_numeric() {
        continue;
    }
    return true;
    }
    false
}
