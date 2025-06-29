ParCrypt 🔐
A modular, multithreaded C++ file encryption and decryption utility using XOR cipher and user-defined passwords.

📦 Features
- Encrypt and decrypt any type of file (text, image, PDF, etc.)
- Multithreaded for faster XOR encryption
- User provides password at runtime
- Password is securely embedded in encrypted file
- Separate encrypt/ and decrypt/ folders for output files
- Simple Makefile for building and cleaning

🗂️ Project Structure
ParCrypt/
├── include/
│   ├── encryptor.h
│   ├── file_manager.h
│   └── thread_manager.h
├── src/
│   ├── encryptor.cpp
│   ├── file_manager.cpp
│   └── thread_manager.cpp
├── obj/                # Auto-created on build
├── encrypt/            # Stores encrypted files
├── decrypt/            # Stores decrypted files
├── main.cpp            # Entry point
├── Makefile            # Build system
└── README.md           

🔧 Build Instructions
Requirements:
- C++23 compatible compiler (GCC 13+ or MinGW 15+)
- make or mingw32-make

To compile:
> make          (or mingw32-make on Windows)

To clean:
> make clean

🧾 Usage
Run the program:

> ./ParCrypt

Encryption:
- Enter path of file to encrypt
- Enter password
- Enter name for encrypted file (e.g. secret.bin)
→ Saved to encrypt/ folder

Decryption:
- Enter name of encrypted file (from encrypt/)
- Enter password used during encryption
- Enter name for decrypted file (e.g. final.txt)
→ Saved to decrypt/ folder

📌 Note from Siddharth : This project demonstrates file encryption with XOR for educational purposes. For sensitive data, use industry-grade encryption libraries.
