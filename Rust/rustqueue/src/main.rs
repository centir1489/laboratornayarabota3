mod QueuePP; // Подключаем модуль queue

use QueuePP::Queue;

fn main() {
    // Создаем новую очередь
    let mut queue: Queue<i32> = Queue::new();

    // Проверяем, что очередь пуста
    assert!(queue.is_empty());
    println!("Очередь пуста: {}", queue.is_empty());

    // Добавляем элементы в очередь
    queue.push(1);
    queue.push(2);
    queue.push(3);
    println!("Элементы в очереди после добавления: ");
    queue.get(); // Ожидаем: 1 2 3

    // Проверяем размер очереди
    println!("Размер очереди: {}", queue.size()); // Ожидаем: 3

    // Проверяем первый и последний элементы
    if let Some(front) = queue.front() {
        println!("Первый элемент: {}", front); // Ожидаем: 1
    }
    if let Some(back) = queue.back() {
        println!("Последний элемент: {}", back); // Ожидаем: 3
    }

    // Удаляем элемент из очереди
    queue.pop();
    println!("Элементы в очереди после удаления: ");
    queue.get();

    println!("Размер очереди: {}", queue.size());

    // Сериализация в JSON
    match queue.to_json() {
        Ok(json) => println!("Сериализованный JSON: {}", json),
        Err(e) => println!("Ошибка сериализации: {}", e),
    }
    let seri = queue.to_json().unwrap();
    println!("После сериализации: {}", seri);
    let _queue1 : Queue<i32> = Queue::from_json(&seri).unwrap();
    println!("После десериализации: ");
    _queue1.get();
    

}