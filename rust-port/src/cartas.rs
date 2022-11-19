#![allow(dead_code)]
#![allow(unused_imports)]

pub mod carta{

    use std::{fs::File, io::{Write, Read}};
    use serde::{Serialize, Deserialize};
    #[derive(Serialize, Deserialize, Debug, Clone, Copy)]
    #[derive(PartialEq, PartialOrd)]
    pub enum Palo{
        Espada,
        Basto,
        Oro,
        Copa
    }
    #[derive(Debug, Clone)]
    #[derive(Serialize, Deserialize)]
    pub struct Carta{
        pub palo: Palo,
        pub nombre: String,
        pub valor: u8
    }
    impl Palo{
        pub fn to_string(&self) -> String {
            match self{
                Palo::Espada => "Espada".to_string(),
                Palo::Basto => "Basto".to_string(),
                Palo::Oro => "Oro".to_string(),
                Palo::Copa => "Copa".to_string(),
            }
        }
    }
    impl Carta {
        pub fn new() -> Carta{
            Carta { palo: Palo::Espada, nombre: String::new(), valor: 0 }
        }
        pub fn from(palo: Palo, nombre: &str, valor: u8) -> Carta{
            Carta { palo: palo, nombre: nombre.to_string(), valor: valor }
        }
        pub fn set_values(&mut self, palo: Palo, nombre: String, valor: u8){
            self.palo = palo;
            self.nombre = nombre;
            self.valor = valor;
        }
        pub fn to_string(&self) -> String {
            return format!("Carta{{ valor: {}, palo: {}, nombre: {} }}", self.valor.to_string(), self.palo.to_string(), self.nombre);
        }
        pub fn get_env_value(&self) -> u8 {
            match self.valor {
                0..=7 => { self.valor },
                8..=12 => { 0 }
                _ => panic!("Valor imposible"),
            }
        }
    }
}
pub mod mazo{
    use rand::{seq::SliceRandom};
    #[derive(Debug)]
    pub struct Mazo{
        pub cartas: Vec<crate::Carta>,
    }
    impl Mazo {
        //Crea un mazo con todas las cartas del truco.
        pub fn new() -> Mazo {
            let mut buf: Vec<crate::Carta> = Vec::with_capacity(40);
            let mut j = 0;
            for _ in 0..10{
                j+=1;
                while j>7 && j<10 { j+=1; }
                buf.push(crate::Carta::from(super::carta::Palo::Espada, format!("{} de {}",j, super::carta::Palo::Espada.to_string()).as_str(), j));
            }
            j=0;
            for _ in 0..10 {
                j+=1;
                while j>7 && j<10 { j+=1; }
                buf.push(crate::Carta::from(super::carta::Palo::Basto, format!("{} de {}",j, super::carta::Palo::Basto.to_string()).as_str(), j));
            }
            j=0;
            for _ in 0..10 {
                j+=1;
                while j>7 && j<10 { j+=1; }
                buf.push(crate::Carta::from(super::carta::Palo::Oro, format!("{} de {}",j, super::carta::Palo::Oro.to_string()).as_str(), j));
            }
            j=0;
            for _ in 0..10 {
                j+=1;
                while j>7 && j<10 { j+=1; }
                buf.push(crate::Carta::from(super::carta::Palo::Copa, format!("{} de {}",j, super::carta::Palo::Copa.to_string()).as_str(), j));
            }
            Mazo { cartas: buf }
        }
        pub fn to_string(&self) -> String{
            let mut s = String::new();
            for i in 0..40 {
                s += &("\n".to_string() + &self.cartas[i].to_string());
            }
            return s;
        }
        pub fn shuffle(&mut self){
            use rand::thread_rng;
            self.cartas.shuffle(&mut thread_rng());
        }
    }
}