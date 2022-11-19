#![allow(dead_code)]
//#![allow(unused_imports)]
pub mod oponente {
    use crate::{
        cartas::carta::{Carta, /* Palo */},
        estadisticas::estadisticas::Estadisticas,
        item::item::Codigo,
        partido::partido::{/* Envido ,*/ Respuesta, Ronda},
    };
    use serde::{Deserialize, Serialize};
    #[derive(Debug, Serialize, Deserialize)]
    pub struct Oponente {
        mano: [Carta; 3],
        pub nombre: String,
        pub stats: Estadisticas,
        codigos: [Codigo; 5],
    }

    impl Oponente {
        pub fn r_new() -> Oponente {
            let nm = String::new();
            //Randomizar el nombre con un archivo.
            Oponente {
                mano: [Carta::new(), Carta::new(), Carta::new()],
                nombre: nm,
                stats: Estadisticas::r_new(),
                codigos: [
                    Codigo::r_new(),
                    Codigo::r_new(),
                    Codigo::r_new(),
                    Codigo::r_new(),
                    Codigo::r_new(),
                ],
            }
        }
        pub fn calc_envido(&self) -> u8 {
            if self.mano[0].palo == self.mano[1].palo && self.mano[1].palo == self.mano[2].palo { //tiene flor
                let mut ordered = [self.mano[0].get_env_value(), self.mano[1].get_env_value(), self.mano[2].get_env_value()];
                ordered.sort();
                return ordered[1] + ordered[2] + 20;
            }
            let conds = (self.mano[0].palo == self.mano[1].palo, self.mano[1].palo == self.mano[2].palo, self.mano[2].palo == self.mano[0].palo); // busco si hay palos que se repiten.
            if conds.0 { 
                return self.mano[0].get_env_value() + self.mano[1].get_env_value() + 20;
            } 
            else if conds.1 {
                return self.mano[1].get_env_value() + self.mano[2].get_env_value() + 20;
            }
            else if conds.2 {
                return self.mano[0].get_env_value() + self.mano[2].get_env_value() + 20;
            }
            else { //no hay cartas iguales.
                let mut aux: u8 = 0;
                for carta in &self.mano {
                    if carta.get_env_value() > aux {
                        aux = carta.get_env_value();
                    }
                }
                return aux;
            }
        }
        // IA
        pub fn responder_al_tanto(&self, ) -> Respuesta<bool> {

            Respuesta::NoQuiero
        }
        pub fn cantar_tanto(&self) -> Ronda<bool> {
            Ronda::Nada
        }
    }
}
