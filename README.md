# ParCrypt 🔐
A modular, multithreaded C++ file encryption and decryption utility using XOR cipher.

## 📦 Features
- Encrypts and decrypts any file using XOR.
- Multithreaded for faster performance.
- Key is loaded securely from a `.env` file.
- Includes a `Makefile` for easy build and cleanup.

## 🗂️ Project Structure

```
ParCrypt/
├── include/
│   ├── constants.h
│   ├── encryptor.h
│   ├── env_loader.h
│   ├── file_manager.h
│   └── thread_manager.h
├── src/
│   ├── encryptor.cpp
│   ├── env_loader.cpp
│   ├── file_manager.cpp
│   └── thread_manager.cpp
├── obj/                  # (Created by make)
├── .env
├── .gitignore
├── main.cpp
├── Makefile
└── README.md
```

## 🔧 Build Instructions

### 🛠️ Requirements
- C++23 compatible compiler (e.g. GCC 13+, MinGW 15.1.0)
- `mingw32-make` or `make`

### 🧪 Compile
From inside the `ParCrypt` directory:

```bash
mingw32-make
```

### 🔁 Clean Build Files

```bash
mingw32-make clean
```

## 🧾 Usage

### 1. Prepare `.env` file:
```
XOR_KEY=0x5A
```

> The XOR key must be a valid integer. Can be in hex (`0x5A`) or decimal (`90`) format.

### 2. Run Program
```bash
./ParCrypt
```

You’ll be prompted to:
- Enter a file path to encrypt/decrypt.
- Choose mode: `E` for encryption, `D` for decryption.

### 3. Output
- If encrypted: `encrypted.dat`
- If decrypted: `decrypted.txt`
