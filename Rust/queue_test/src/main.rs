use serde::{Deserialize, Serialize};
use std::{fs::File, io::{self, Read, Write}};

fn main() {

}

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
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_queue_new() {
        let queue: Queue<i32> = Queue::new();
        assert!(queue.is_empty());
        assert_eq!(queue.size(), 0);
    }

    #[test]
    fn test_queue_push_and_size() {
        let mut queue = Queue::new();
        queue.push(1);
        queue.push(2);
        queue.push(3);
        
        assert!(!queue.is_empty());
        assert_eq!(queue.size(), 3);
    }

    #[test]
    fn test_queue_pop() {
        let mut queue = Queue::new();
        queue.push(1);
        queue.push(2);
        queue.push(3);
        
        queue.pop();
        assert_eq!(queue.size(), 2);
        assert_eq!(queue.front(), Some(&2));
        
        queue.pop();
        assert_eq!(queue.size(), 1);
        assert_eq!(queue.front(), Some(&3));
        
        queue.pop();
        assert!(queue.is_empty());
    }

    #[test]
    fn test_queue_front_and_back() {
        let mut queue = Queue::new();
        queue.push(1);
        queue.push(2);
        queue.push(3);
        
        assert_eq!(queue.front(), Some(&1));
        assert_eq!(queue.back(), Some(&3));
        
        queue.pop();
        assert_eq!(queue.front(), Some(&2));
        assert_eq!(queue.back(), Some(&3));
        
        queue.pop();
        queue.pop();
        assert!(queue.is_empty());
        assert_eq!(queue.front(), None);
        assert_eq!(queue.back(), None);
    }

    #[test]
    fn test_queue_get() {
        let mut queue = Queue::new();
        queue.push(1);
        queue.push(2);
        queue.push(3);
        
        // Здесь мы просто проверяем, что метод get не вызывает панику
        queue.get(); // Ожидаем, что это не вызовет панику
    }
}