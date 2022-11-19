#![allow(dead_code)]
#![allow(unused_imports)]
pub mod atributo {
    use std::{fs::File, io::{Write, Read}};
    use rand::Rng;
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
        pub fn r_new() -> Self {
            let mut rng = rand::thread_rng();
            match rng.gen_range(1..=8) {
                1 => return Self::MuyBajo,
                2 => return Self::Bajo,
                3 => return Self::Normal,
                4 => return Self::Alto,
                5 => return Self::MuyAlto,
                6 => return Self::Extremo,
                7 => return Self::Maximo,
                8 => return Self::Dios,
                _ => return Self::MuyBajo,
            }
        }
        pub fn get_prob(&self) -> f32 {
            match self {
                Nivel::MuyBajo => 5.0,
                Nivel::Bajo => 14.67,
                Nivel::Normal => 27.32,
                Nivel::Alto => 38.32,
                Nivel::MuyAlto => 53.23,
                Nivel::Extremo => 67.34,
                Nivel::Maximo => 82.45,
                Nivel::Dios => 99.45,
            }
        }
    }
    #[derive(Debug)]    
    #[derive(Serialize, Deserialize)]
    pub struct Atributo {
        pub nombre: String,
        pub xp_interna: i32,
        pub estado: Nivel,
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