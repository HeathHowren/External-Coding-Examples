# External-Coding-Examples

Four short C++ files that go with the **Reverse Engineering Fundamentals** lessons on the [Cyborg Elf YouTube channel](https://www.youtube.com/@CyborgElf). Each one isolates a single idea you need before writing an external memory tool.

| File | What it shows | Lesson |
|---|---|---|
| [`Operators.cpp`](Operators.cpp) | What `*` (dereference) and `&` (address-of) actually do, printed side by side | [Pointers and references in C++](https://www.youtube.com/watch?v=bKnEAzxrWcI) |
| [`Adding Offsets.cpp`](Adding%20Offsets.cpp) | Finding a process and module by name with Toolhelp32, then following a base address plus offsets | [Reading and writing a pointer with offsets](https://www.youtube.com/watch?v=epyamsQtAGs) |
| [`Null Pointer Checks.cpp`](Null%20Pointer%20Checks.cpp) | The same pointer walk, checked at every level so a zero halfway down the chain does not crash you | [Reading and writing a pointer with offsets](https://www.youtube.com/watch?v=epyamsQtAGs) |
| [`Threading Example.cpp`](Threading%20Example.cpp) | Running several features at once on their own `std::thread`s | [Threads in C++](https://www.youtube.com/watch?v=XdxwmDG7E60) |

> Written in 2020. Practice on software you own or on open-source games, never on online multiplayer games. [Pointer Lab](https://gamereversal.club/tools/pointer-lab/), the free, open-source memory tool, ships with a tutorial target built for exactly this kind of practice.

## Building

Each file is a standalone program. Create an empty Visual Studio C++ project, add one file, and set the character set to **Multi-Byte**.

## Related

- More companion code for the video lessons: [gamereversal.club/course-materials](https://gamereversal.club/course-materials/).
- Pointers and offsets are covered in full in Part II of [The Game Hacker's Handbook](https://gamereversal.club/books/game-hackers-handbook/).

## Author

Heath Howren, known online as Cyborg Elf. Questions go to the [Game Reversal Club Discord](https://discord.gg/NwRFmp3J2J). MIT licensed, see [LICENSE](LICENSE).
