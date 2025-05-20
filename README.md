# Indicate (WIP)

**A lightweight, C++23 library for pretty console progress reports**

`indicate` provides easy-to-use progress bars, spinners, human-friendly formatting, and ANSI-color output with automatic terminal-width detection—all built on modern C++ modules (C++20/C++23).

---

## 🎯 Motivation

Inspired by the fantastic rust crate [`indicatif`](https://github.com/console-rs/indicatif), `indicate` adapts its core ideas to C++23:

* **Zero external dependencies** — only the C++ standard library.
* **C++20 modules** — no legacy headers.
* **Thread‑safe** — redraws with minimal locking.
* **Automatic width detection** — (POSIX & Windows).
* **ANSI escape codes** — for colors & styles, with sensible fallbacks.

---

## 🧩 Features

* **ProgressBar**: bounded bars with customizable fill, width, prefix/suffix, percentage, elapsed/remaining time.
* **Spinner**: unbounded “spinner” animation, manual or steady‑tick mode.
* **Human formatting**:
    * `bytes_to_string`, `duration_to_string`, `count_to_string` for human‑readable values.
* **Colors & styles**: red, green, bold, italic, underlined, etc.
* **Dynamic width**: uses `ioctl(TIOCGWINSZ)` on Unix and `GetConsoleScreenBufferInfo` on Windows; falls back to `COLUMNS` or 80.
* **Terminal detection**: suppresses output when not attached to a tty (checks `isatty`).

---

## 📦 Platform Support

* **Linux**
* **macOS**
* **Windows 10+** (ANSI escapes)

*Caveat*: pre‑Win10 consoles require enabling virtual terminal processing.
