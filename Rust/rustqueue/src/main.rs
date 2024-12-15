mod QueuePP;

use QueuePP::Queue;

fn main() -> Result<(), Box<dyn std::error::Error>>{
    let mut queue = Queue::new();
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    
    println!("До сериализации:");
    queue.get();


    let filename = "queue.json";
    queue.save_to_file(filename)?;

    let loaded_queue : Queue<i32>= Queue::load_from_file(filename)?;
    println!("После в json десериализации:");
    loaded_queue.get();

    let filename = "queue.bin";
    queue.save_to_file(filename)?;

    let loaded_queue: Queue<i32> = Queue::load_from_file(filename)?;

    println!("После бинарной десериализации::");
    loaded_queue.get();


    Ok(())
    

}