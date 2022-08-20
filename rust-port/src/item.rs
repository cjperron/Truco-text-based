#![allow(dead_code)]
#![allow(unused_imports)]

pub mod item {
    
    use rand::Rng;
    use std::{fs::File, io::{Write, Read}};
    use serde::{Serialize, Deserialize};
    #[derive(Serialize, Deserialize, Debug)]
    
    pub struct Item {
        precio: f64,
        cant_disponible: u16,
        descripcion: String,
        id: u16,
    }

    #[derive(Debug)]
    #[derive(Serialize, Deserialize)]
    pub struct Codigo {
        cant_disponible: u16,
        codigo: String,
        id: u16,
    }

    impl Item {
        pub fn new() -> Item {
            Item {
                precio: 0.0,
                cant_disponible: 0,
                descripcion: String::new(),
                id: 0,
            }
        }
        pub fn from(id: u16,precio: f64, cant_disponible: u16, descripcion: &str) -> Item {
            Item {
                precio: precio,
                cant_disponible: cant_disponible,
                descripcion: descripcion.to_string(),
                id: id
            }
        }
        pub fn to_string(&self) -> String {
            return format!(
                "Item {{ id: {}, precio: {}, cant_disponible: {}, descripcion: {} }}",self.id,
                self.precio, self.cant_disponible, self.descripcion
            );
        }
    }

    impl Codigo {
        pub fn new() -> Codigo {
            Codigo {
                cant_disponible: 0,
                codigo: String::new(),
                id: 0,
            }
        }
        pub fn r_new() -> Codigo {
            let mut rng = rand::thread_rng();
            Codigo {
                cant_disponible: rng.gen_range(1..=std::u16::MAX),
                codigo: String::new(),
                id: rng.gen_range(1..=std::u16::MAX),
            }
        }
        pub fn from(cant_disponible: u16, codigo: &str, id: u16) -> Codigo {
            Codigo {
                cant_disponible: cant_disponible,
                codigo: codigo.to_string(),
                id: id,
            }
        }
        pub fn to_string(&self) -> String {
            return format!(
                "Codigo {{ cant_disponible: {}, codigo: {}, id: {} }}",
                self.cant_disponible, self.codigo, self.id
            );
        }
        //Faltaria una que verifique el id, y basado en eso, haga la accion en el jugador.
    }
}
