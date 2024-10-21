# win-c
C23 standard library for Windows based on the Windows API.

## The problem
The C standard is poorly implemented across most operating systems. Even Unix-like systems (primarily Linux), which should align more closely with the standard, often fail to fully conform. Despite using GNU tools like GCC or Clang, many parts of the standard are loosely followed, leading to implementations that "kinda" work but are far from ideal. Optional features like `threads.h` are often missing. With the arrival of C23, the situation will likely worsen, as its complexity and some developers reluctance to adapt will increase these discrepancies.

On Windows, the issue is even worse. Microsoft has historically not prioritized standard compliance, instead pushing their own **Microsoft-compiler specifics™**. This approach has persisted since the early MSCVRT days, which failed to meet basic C99 compatibility. Even with UCRT, which theoretically improves standard compliance, Microsoft remains focused on its own platform, making cross-platform compilation more difficult. For example, while GNU-style compilers offer variable predefined types to dynamically determine sizes (e.g., `wchar_t`), Microsoft arbitrarily fixes these types, leading to non-portable APIs and conflicts when trying to use Clang with MSCVRT or UCRT. MinGW doesn’t resolve these issues either; it’s a patchwork solution that doesn’t align with any real cross-platform standard.
## The idea
`win-c` aims to fully and correctly implement the C23 standard on Windows, without relying on UCRT or MSCVRT, and instead leveraging standard Windows APIs like KERNEL32, SHELL32, and others. These APIs, present since Windows 95, are solid and reliable, theoretically allowing programs based on C23 to compile on older Windows versions, while also improving overall compatibility.

The first goal is to completely implement or emulate most C23 features, ensuring compliance with the standard. This will be done using the latest Clang compiler, which supports C23. Following that, testing will be done with other GCC-style compilers, and then I will work on perfecting conformance with C17, C11, C99, and C89, on all Windows versions.

Ultimately, due to Clang’s flexible predefined types, `win-c` should also be able to work with the Microsoft compiler, by using macros, emulating a C23-compliant environment.

In the end, `win-c` should be a flexible, efficient, standard-compliant, and standalone C runtime for Windows, enabling the compilation of most standard-conformant C programs.