# ParCrypt 🔐

**ParCrypt** is a multithreaded C++ file encryption and decryption tool using XOR cipher and user-defined passwords.

It demonstrates concepts like:
- File I/O
- Basic encryption (XOR)
- Threading
- Modular project design
- Custom build via Makefile

---

## 📦 Features

- 🔐 Supports **any file type** (text, images, PDFs, etc.)
- 🔑 Password provided by user during runtime
- 🧵 Uses **multiple threads** to speed up encryption
- 📁 Stores:
  - Encrypted files in `encrypt/`
  - Decrypted files in `decrypt/`
- 🛠️ Includes a `Makefile` for easy build & cleanup

---

## 🗂️ Project Structure

```
ParCrypt/
├── include/
│   ├── encryptor.h
│   ├── file_manager.h
│   └── thread_manager.h
├── src/
│   ├── encryptor.cpp
│   ├── file_manager.cpp
│   └── thread_manager.cpp
├── obj/                # Auto-created when building
├── encrypt/            # Output folder for encrypted files
├── decrypt/            # Output folder for decrypted files
├── main.cpp            # Entry point
├── Makefile            # Build system
└── README.md
```

---

## 🔧 Build Instructions

### ✅ Requirements

- C++ compiler with **C++23 support** (e.g. GCC 13+, MinGW 15+)
- `make` or `mingw32-make` (Windows)

### ⚙️ Build

```bash
make          # or mingw32-make on Windows
```

This will:
- Create the `obj/` directory (if not present)
- Compile all `.cpp` files from `src/`
- Output the executable `ParCrypt.exe` (Windows) or `ParCrypt` (Linux/macOS)

### 🧹 Clean Build Files

```bash
make clean
```

This will:
- Delete the `obj/` directory
- Delete the executable (`ParCrypt.exe` or `ParCrypt`)

---

## 🧾 How to Use

```bash
./ParCrypt
```

You’ll be prompted for:

### 🔐 Encryption
1. File path to encrypt
2. Password
3. Output name (stored in `encrypt/`)

### 🔓 Decryption
1. Name of encrypted file (from `encrypt/`)
2. Password used during encryption
3. Output name (saved in `decrypt/`)

---

