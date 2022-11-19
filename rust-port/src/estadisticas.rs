#![allow(dead_code)]
#![allow(unused_imports)]
pub mod estadisticas {
    use crate::atributo::atributo::Atributo;

    use std::{fs::File, io::{Write, Read}};
    use serde::{Serialize, Deserialize};
    #[derive(Serialize, Deserialize, Debug)]

    pub struct Estadisticas {
        xp: u64,
        dinero: f64,
        pub a_mentiroso: Atributo,
        pub a_pescador: Atributo,
        pub a_agresividad: Atributo,
        pub a_tramposo: Atributo,
    }
    impl Estadisticas {
        pub fn from(xp: u64, dinero: f64) -> Estadisticas {
            Estadisticas {
                xp: xp,
                dinero: dinero,
                a_mentiroso: Atributo::from("Mentiroso", 0, crate::atributo::atributo::Nivel::MuyBajo),
                a_pescador: Atributo::from("Pescador", 0, crate::atributo::atributo::Nivel::MuyBajo),
                a_agresividad: Atributo::from("Agresividad", 0, crate::atributo::atributo::Nivel::MuyBajo),
                a_tramposo: Atributo::from("Tramposo", 0, crate::atributo::atributo::Nivel::MuyBajo),
            }
        }
        pub fn to_string(&self) -> String {
            return format!("Estadisticas {{ xp: {},\ndinero: {},\na_mentiroso: {}\na_pescador: {}\na_agresividad: {}\na_tramposo: {}\n}}", self.xp, 
            self.dinero, 
            self.a_mentiroso.to_string(), 
            self.a_pescador.to_string(), 
            self.a_agresividad.to_string(), 
            self.a_tramposo.to_string());
        }
        pub fn r_new() -> Estadisticas {
            use crate::atributo::atributo::Nivel;
            Estadisticas {
                xp: 0,
                dinero: 0.0,
                a_mentiroso: Atributo::from("Mentiroso", 0, Nivel::r_new()),
                a_pescador: Atributo::from("Pescador", 0, Nivel::r_new()),
                a_agresividad: Atributo::from("Agresividad", 0, Nivel::r_new()),
                a_tramposo: Atributo::from("Tramposo", 0, Nivel::r_new()),    
            }
        }
    }
}

