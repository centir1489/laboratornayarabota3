use serde::{Deserialize, Serialize};
use std::fs::File;
use std::io::Read;

use crate::Queue;

fn read_json(file_path: &str) -> Result<Queue<String>, Box<dyn std::error::Error>>{
    let mut file = File::open(file_path)?;
    let mut contents = String::new();
    file.read_to_string(&mut contents)?;
    let data: MyData = serde_json::from_str(&contents)?;
    Ok(data)
}