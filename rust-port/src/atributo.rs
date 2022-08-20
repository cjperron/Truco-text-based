#![allow(dead_code)]
#![allow(unused_imports)]
pub mod atributo {
    use std::{fs::File, io::{Write, Read}};
    use serde::{Serialize, Deserialize};
    
    #[derive(Serialize, Deserialize)]
    #[derive(Debug)]
    pub enum Nivel {
        MuyBajo,
        Bajo,
        Normal,
        Alto,
        MuyAlto,
        Extremo,
        Maximo,
        Dios,
    }
    impl Nivel {
        pub fn to_string(&self) -> String {
            match self {
                Nivel::MuyBajo => "Muy Bajo".to_string(),
                Nivel::Bajo => "Bajo".to_string(),
                Nivel::Normal => "Normal".to_string(),
                Nivel::Alto => "Alto".to_string(),
                Nivel::MuyAlto => "Muy Alto".to_string(),
                Nivel::Extremo => "Extremo".to_string(),
                Nivel::Maximo => "Maximo".to_string(),
                Nivel::Dios => "Dios".to_string(),
            }
        }
    }
    #[derive(Debug)]    
    #[derive(Serialize, Deserialize)]
    pub struct Atributo {
        nombre: String,
        xp_interna: i32,
        estado: Nivel,
    }
    impl Atributo {
        pub fn new() -> Atributo {
            Atributo {
                nombre: String::new(),
                xp_interna: 0,
                estado: Nivel::MuyBajo,
            }
        }
        pub fn from(nombre: &str, xp_interna: i32, estado: Nivel) -> Atributo {
            Atributo {
                nombre: nombre.to_string(),
                xp_interna: xp_interna,
                estado: estado,
            }
        }
        pub fn to_string(&self) -> String {
            return format!(
                "Atributo {{ nombre: {}, xp_interna: {}, estado: {} }}",
                self.nombre,
                self.xp_interna,
                self.estado.to_string()
            );
        }
    }
}