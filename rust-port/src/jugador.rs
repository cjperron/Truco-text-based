#![allow(dead_code)]
#![allow(unused_imports)]
pub mod jugador {
    use std::fmt::format;
    use std::fs::File;
    use std::io::{Write, Read};
    use std::result;

    use crate::cartas::carta::Carta;
    use crate::estadisticas::estadisticas::Estadisticas;
    use crate::item::item::{Codigo, Item};
    use crate::pause;
    use console::Term;
    use owo_colors::OwoColorize;
    use serde::{Serialize, Deserialize, ser::SerializeStruct};
    use serde_json::json;
    
    #[derive(Debug)]
    #[derive(Serialize, Deserialize)]
    pub enum Sexo {
        Masculino,
        Femenino,
    }
    impl Sexo {
        pub fn to_string(&self) -> String {
            match self {
                Sexo::Masculino => "Masculino".to_string(),
                Sexo::Femenino => "Femenino".to_string(),
            }
        }

        pub fn to_u8(&self) -> u8 {
            match self {
                Sexo::Masculino => 0,
                Sexo::Femenino => 1,
            }
        }
        pub fn u8_to_sexo(x: u8) -> Self {
            match x{
                0 => Sexo::Masculino,
                1 => Sexo::Femenino,
                _ => panic!("Error, valor u8 no valido convertido a sexo"),
            }
        }
        pub fn str_to_sexo(s: &str) -> Self {
            match s.trim() {
                "m" | "Masculino" | "M" => Self::Masculino,
                "f" |  "Femenino" | "F" => Self::Femenino,
                _ => panic!("Error valor no permitido."),
            }
        }
    }
    #[derive(Debug)]
    #[derive(Serialize, Deserialize)]
    pub struct Jugador {
        id: u32,
        lvl: u8,
        sexo: Sexo,
        descripcion: String,
        pub nombre: String,
        estadisticas: Estadisticas,
        mano: [Carta; 3],
        codigos: Vec<Codigo>,
        items: Vec<Item>,
    }
    #[derive(Debug)]
    #[derive(Serialize, Deserialize)]
    pub struct Dev{
        tot: u32
    }
    impl Jugador {
        pub fn from(id: u32, lvl: u8, sexo: Sexo, descripcion: &str, nombre: &str) -> Jugador {
            Jugador {
                id: id,
                lvl: lvl,
                sexo: sexo,
                descripcion: descripcion.to_string(),
                nombre: nombre.to_string(),
                estadisticas: Estadisticas::from(0, 0.0),
                mano: [Carta::new(), Carta::new(), Carta::new()],
                codigos: Vec::new(),
                items: Vec::new(),
            }
        }
        pub fn s_codigos(&self) -> String {
            let mut s = String::new();
            for codigo in self.codigos.iter() {
                s += &codigo.to_string();
            }
            return s;
        }
        pub fn s_items(&self) -> String {
            let mut s = String::new();
            for item in self.items.iter() {
                s += &item.to_string();
            }
            return s;
        }
        pub fn to_string(&self) -> String {
            return format!(
                "Jugador {{\nid: {},\nlvl: {},\nsexo: {}\nnombre: {}\ndescripcion: {}\nestadististicas: {}\nmano:\n1: {}\n2: {}\n3: {}\ncodigos: {}\nitems: {}\n}}",
                self.id, 
                self.lvl,
                self.sexo.to_string(),
                self.nombre,
                self.descripcion,
                self.estadisticas.to_string(),
                self.mano[0].to_string(),
                self.mano[1].to_string(),
                self.mano[2].to_string(),
                self.s_codigos(),
                self.s_items(),
            );
        }
        pub fn pretty_string(&self) -> String {
            return format!("id[{}], lvl[{}]\n{}{}\nDescripcion: {}\nSexo: {}",self.id.magenta().bold(), self.lvl.yellow().bold(), "Nombre: ".white().bold(), self.nombre,self.descripcion.italic(), self.sexo.to_string().underline());
        }
        pub fn write_total_player(tot: u32) {
            let mut file = File::create("./bin/tot.json").expect("Error creando archivo");
            
            let s_json = String::from("{\n\"tot\": ".to_owned()+tot.to_string().as_str()+"\n}\n");
            file.write_all(s_json.as_bytes()).unwrap();
        }
        pub fn get_total_player() -> (u32, bool) {
            let result_file = File::open("./bin/tot.json");
            let mut file = match result_file {
                Ok(result_file) => result_file,
                Err(_error) => return (0, false),
            };
            let mut s_json = String::new();
            file.read_to_string(&mut s_json).unwrap();
            let tot: Dev = serde_json::from_str(&s_json).unwrap();
            (tot.tot, true)
        }
        pub fn ask_in() -> Jugador {
            let term = Term::stdout();
            std::io::stdout().flush().expect("Error flusheando stdout");
            print!("Ingrese {}: ", "nombre".white().bold());
            std::io::stdout().flush().expect("Error flusheando stdout");
            let nombre = term.read_line().unwrap();
            print!("Ingrese {}: ", "descripcion".white().bold());
            std::io::stdout().flush().expect("Error flusheando stdout");
            let descripcion = term.read_line().unwrap();
            let mut sexo = String::new();
            loop {
                print!("Ingrese {} {}: ", "sexo".magenta().bold(), "(m/f)".italic());
                std::io::stdout().flush().expect("Error flusheando stdout");
                std::io::stdin().read_line(&mut sexo).expect("Error leyendo linea");
                match sexo.trim() {
                    "m"| "f" | "M" | "F" => break,
                    _ => println!("Error: {}", "No reconocido".red()),
                }
            }
            //Tengo que modificar el tema del id
            if Jugador::get_total_player().1 == false {
                Jugador::write_total_player(1); //El archivo probablemente no existia
            }
            else {
                Jugador::write_total_player(Jugador::get_total_player().0+1); //total++
            }
            Jugador::from(Jugador::get_total_player().0, 1, Sexo::str_to_sexo(sexo.as_str()), descripcion.trim(), nombre.trim())
        }
        pub fn create_user() -> bool {
            std::io::stdout().flush().expect("Error flusheando stdout");
            let player = Jugador::ask_in(); //++total
            player.write_to_file(&(player.nombre.to_owned()+".json"));
            let mut buf = String::new();
            loop{
                print!("\nDesea {} el jugador? (s/n): ", "seleccionar".white().bold());
                std::io::stdout().flush().expect("Error flusheando stdout");
                std::io::stdin().read_line(&mut buf).expect("Error leyendo linea");
                match buf.trim() {
                    "s"| "S" => {
                        player.write_to_sel();
                        return true;
                    },
                    "n"| "N" => {
                        return false;
                    },
                    _ => println!("Error: {}", "No reconocido".red()),
                }
            }
        }
        pub fn write_to_file(&self, path: &str){
            let mut file = File::create(path).unwrap();
            let serialized = serde_json::to_string(&self).unwrap();
            file.write_all(&serialized.as_bytes()).unwrap();
        }
        pub fn write_to_sel(&self) -> bool {
            let mut file = File::create("./bin/sel.json").unwrap();
            let serialized = serde_json::to_string(&self).unwrap();
            file.write_all(&serialized.as_bytes()).unwrap();
            true
        }
        pub fn read_from_sel() -> (Jugador, bool) {
            let result_file = File::open("./bin/sel.json");
            let mut file = match result_file{
                Ok(result_file) => result_file,
                Err(_error) => return (Jugador::from(0, 1, Sexo::Masculino, "", ""), false),
            };
            let mut json_string = String::new();
            file.read_to_string(&mut json_string).unwrap();
            let pj: Jugador = serde_json::from_str(json_string.as_str()).expect("Error leyendo");
            (pj, true)
        }
        
    }
    fn u32_to_u8arr(x: u32) -> [u8; 4] {
        let p1: u8 = ((x >> 24) & 0xff) as u8;
        let p2: u8 = ((x >> 16) & 0xff) as u8;
        let p3: u8 = ((x >> 8) & 0xff) as u8;
        let p4: u8 = (x & 0xff) as u8;
        return [p1,p2,p3,p4];
    }
    fn u8arr_to_u32(arr: &[u8; 4]) -> u32 {
        
            ((arr[0] as u32) << 24) +
            ((arr[1] as u32) << 16) +
            ((arr[2] as u32) << 8) +
            ((arr[3] as u32) << 0)
    }
    fn u8_to_u8arr(x: u8) -> [u8;1] {
        return [x];
    }
    fn u8arr_to_u8(arr: [u8;1]) -> u8 {
        return arr[0];
    }
}
