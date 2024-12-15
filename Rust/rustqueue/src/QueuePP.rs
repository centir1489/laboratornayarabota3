use serde::{Deserialize, Serialize};
use std::{fs::File, io::{self, Read, Write}};

#[derive(Serialize, Deserialize)]
struct QNode<T> {
    data: T,
    next: Option<Box<QNode<T>>>,
}

#[derive(Serialize, Deserialize)]
pub struct Queue<T> {
    head: Option<Box<QNode<T>>>,
}

impl<T: std::fmt::Display + Serialize + for<'de> Deserialize<'de>> Queue<T> {
    pub fn new() -> Self {
        Queue { head: None }
    }

    pub fn is_empty(&self) -> bool {
        self.head.is_none()
    }

    pub fn push(&mut self, value: T) {
        let new_node = Box::new(QNode {
            data: value,
            next: None,
        });
    
        if self.is_empty() {
            self.head = Some(new_node);
        } else {
            // Начинаем с головы очереди
            let mut current = self.head.as_mut();
            while let Some(node) = current {
                // Если нашли последний узел, добавляем новый узел
                if node.next.is_none() {
                    node.next = Some(new_node);
                    return; // Завершаем выполнение функции
                }
                current = node.next.as_mut(); // Получаем изменяемую ссылку на следующий узел
            }
        }
    }

    pub fn pop(&mut self) {
        if self.is_empty() {
            return;
        }

        let old_head = self.head.take(); // Удаляем старый head
        self.head = old_head.and_then(|node| node.next); //Перемещаем head на следующий элемент
    }

    pub fn size(&self) -> usize {
        let mut amount = 0;
        let mut ptr = &self.head;

        while let Some(ref node) = ptr {
            amount += 1;
            ptr = &node.next;
        }

        amount
    }

    pub fn get(&self) {
        let mut ptr = &self.head;

        while let Some(ref node) = ptr {
            print!("{} ", node.data);
            ptr = &node.next;
        }
        println!();
    }

    pub fn front(&self) -> Option<&T> {
        self.head.as_ref().map(|node| &node.data)
    }

    pub fn back(&self) -> Option<&T> {
        let mut current = &self.head;
        while let Some(ref node) = current {
            if node.next.is_none() {
                return Some(&node.data);
            }
            current = &node.next;
        }
        None
    }

    // в json
    pub fn to_json(&self) -> Result<String, serde_json::Error> {
        serde_json::to_string(self)
    }

    pub fn from_json(json: &str) -> Result<Self, serde_json::Error> {
        serde_json::from_str(json)
    }

    pub fn save_to_file(&self, filename: &str) -> io::Result<()> {
        let serialized = self.to_json().map_err(|e| {
            io::Error::new(io::ErrorKind::Other, e)
        })?;
        let mut file = File::create(filename)?;
        file.write_all(serialized.as_bytes())?;
        Ok(())
    }

    pub fn load_from_file(filename: &str) -> io::Result<Self> {
        let mut file = File::open(filename)?;
        let mut contents = String::new();
        file.read_to_string(&mut contents)?;
        let queue = Self::from_json(&contents).map_err(|e| {
            io::Error::new(io::ErrorKind::Other, e)
        })?;
        Ok(queue)
    }

    // бинарные
    pub fn to_binary(&self) -> Result<Vec<u8>, bincode::Error>{
        bincode::serialize(self)
    }

    pub fn from_binary(bytes: &[u8]) -> Result<Self, bincode::Error>{
        bincode::deserialize(bytes)
    }

    pub fn bin_save_to_file(&self, filename: &str) -> io::Result<()> {
        let serialized = self.to_binary().map_err(|e|{
            io::Error::new(io::ErrorKind::Other, e)
        })?;
        
        let mut file = File::create(filename)?;
        file.write_all(&serialized)?;
        Ok(())
    }

    pub fn bin_load_from_file(filename: &str) -> io::Result<Self>{
        let mut file = File::open(filename)?;
        let mut contents = Vec::new();
        file.read_to_end(&mut contents)?;
        
        let queue = Self::from_binary(&contents).map_err(|e| {
            io::Error::new(io::ErrorKind::Other, e)
        })?;
        Ok(queue)
    }
}
