# How to setup your environment for CS50x assignments on Mac?

This is a guide to setup your environment for **CS50x assignments** and to install required libraries on a Mac.

```bash
conda create --name CS50x python=3.11.7
conda activate CS50x
```

```bash
brew install libmagic
brew install cowsay
```

Then install the necessary Python libraries using following command:

```bash
pip install -r Docs/requirements.txt
```

This [`requirements.txt`](./requirements.txt) file contains all the libraries required for the assignments.

---

# How to setup `cs50.h` library in VS Code for Mac?

Assuming you have Visual Studio already installed and with all C/C++ extensions required for compiling and running C codes, I was able to get mine working on my Mac with Visual Studio Code as follow:

1. Download the CS50 Library from [libcs50's GitHub release](https://github.com/cs50/libcs50/releases) page.
2. Extract/unzip the downloaded zipped folder.
3. Open Terminal and change directory to the unzipped CS50 library folder.

   > For example if folder is on **Developer/CS50x/Week01-C/LibraryFiles/** and the folder is named **libcs50-11.0.2**, then terminal command should be: `cd ~/Developer/CS50x/Week01-C/LibraryFiles/libcs50-11.0.2/`

4. Still in terminal after changing directory, then run the command: `sudo make install`
5. After installation, close terminal, go to visual studio and write your C program. `#include <cs50.h>`
6. Link cs50 when compiling your code with clang. Example if your file name is hello.c
   ```bash
   clang hello.c -o hello -lcs50
   ```
7. Paste the following code block into the `~/.zshrc` file. This will allow to use the cs50 library in the code workspace.
   ```bash
   # Intializing 'cs50.h' library for CS50x assignments.
   export LIBRARY_PATH="/usr/local/lib:$LIBRARY_PATH"
   export C_INCLUDE_PATH="/usr/local/include:$C_INCLUDE_PATH"
   export LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"
   export DYLD_LIBRARY_PATH="/usr/local/lib:$DYLD_LIBRARY_PATH"
   ```
8. Run the following command in terminal to reload the `.zshrc` file.
   ```bash
   source ~/.zshrc
   ```
9. Finally, use the [`Makefile`](./Makefile) by running the `make` command in the terminal.

