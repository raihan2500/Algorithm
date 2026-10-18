# Linux Command Cheat Sheet — Bandit & SSH
## Commands learned so far

This reference covers basic Linux navigation, file handling, searching, text processing, pipes, redirection, and SSH.

---

## 1. Getting help — `man`

**Purpose:** Read the manual for a Linux command.

**Syntax:**
```bash
man command
```

**Examples:**
```bash
man ls
man grep
man find
man uniq
```

**Useful keys inside a manual:**
- `Space` — move forward one page.
- `b` — move backward one page.
- `/word` — search for a word.
- `n` — jump to the next match.
- `q` — quit the manual.

**Remember:** Manual pages are one of the best ways to learn command options.

---

## 2. Navigating directories — `pwd`, `ls`, `cd`

### `pwd` — Print working directory

Shows the directory you are currently in.

```bash
pwd
```

Example output:
```text
/home/bandit2
```

### `ls` — List directory contents

```bash
ls
```

Useful options:

```bash
ls -l       # Detailed listing
ls -a       # Include hidden files
ls -la      # Detailed listing, including hidden files
ls -lh      # Detailed listing with human-readable file sizes
```

**Important:** Linux filenames beginning with `.` are hidden by default in ordinary `ls` output.

### `cd` — Change directory

```bash
cd inhere       # Enter the inhere directory
cd ..           # Go to the parent directory
cd ~            # Go to your home directory
cd /tmp         # Go to an absolute path
cd -            # Return to the previous directory
```

Relative paths are interpreted from your current directory. Absolute paths begin at `/`.

---

## 3. Reading files — `cat`

**Purpose:** Display file contents in the terminal.

```bash
cat data.txt
```

Read a file with a filename containing spaces:

```bash
cat "--spaces in this filename--"
```

When a filename starts with `-`, use `--` to mark the end of command options:

```bash
cat -- "-filename"
```

Another valid way to read the Bandit filename that starts with dashes is:

```bash
cat ./--spaces\ in\ this\ filename--
```

Here:
- `./` explicitly refers to the current directory.
- `\ ` escapes each space so the shell treats it as part of the filename.
- `--` separates options from filenames when used as an argument to `cat`.

### Display text supplied through a heredoc

```bash
cat <<'EOF'
hello
hello
world
EOF
```

This displays the supplied text in the terminal. `EOF` marks the beginning and end of the heredoc syntax.

**Remember:** `cat "hello hello"` tries to open a file named `hello hello`; it does not treat that argument as arbitrary text.

---

## 4. Checking your identity — `whoami`

Displays the username of the current user.

```bash
whoami
```

Example:
```text
raihan
```

This is especially useful when switching between SSH accounts or working inside a Linux container.

---

## 5. Inspecting file information — `stat`

**Purpose:** Show detailed metadata about a file.

```bash
stat data.txt
stat /var/lib/dpkg/info/bandit7.password
```

Information includes:
- File size in bytes.
- File permissions.
- Owner and group.
- File type.
- Access, modification, and metadata-change timestamps.

For a quick listing of permissions, owner, group, and size:

```bash
ls -l data.txt
```

Example:
```text
-rw-r----- 1 bandit7 bandit6 33 ... bandit7.password
```

The permission string indicates read/write/execute permissions for the owner, group, and others.

---

## 6. Searching text — `grep`

**Purpose:** Find lines matching a pattern.

```bash
grep "millionth" data.txt
```

This was useful for Bandit Level 7 → 8, where the password was stored on the line containing `millionth`.

Useful options:

```bash
grep -i "hello" data.txt     # Case-insensitive search
grep -n "hello" data.txt     # Show line numbers
grep -n -i "hello" data.txt  # Combine options
grep -r "hello" directory/   # Search recursively in files
```

You can also pipe another command's output into `grep`:

```bash
cat data.txt | grep "millionth"
```

For this example, `grep "millionth" data.txt` is simpler because `grep` can read the file directly.

---

## 7. Finding files — `find`

**Purpose:** Search for files and directories based on conditions.

General syntax:

```bash
find starting_directory conditions
```

Examples:

```bash
find . -type f
```

Find all regular files under the current directory, including subdirectories.

```bash
find . -type f -size 1033c
```

Find regular files whose size is exactly 1033 bytes.

```bash
find . -type f -size 1033c ! -executable
```

Find regular files that are exactly 1033 bytes and are not executable according to the permission checks used by `find`.

Useful options and expressions:

- `.` — start searching from the current directory.
- `-type f` — regular files.
- `-type d` — directories.
- `-size 1033c` — exactly 1033 bytes (`c` means bytes).
- `!` — negate a condition.
- `-name "*.txt"` — match names ending in `.txt`; quote the pattern to prevent shell expansion.
- `-user bandit7` — files owned by user `bandit7`.
- `-group bandit6` — files belonging to group `bandit6`.

For example, to search the entire current directory tree for text files:

```bash
find . -type f -name "*.txt"
```

**Important:** `find` searches for matching files; it does not automatically print their contents. Use `cat` afterward when appropriate.

---

## 8. Sorting lines — `sort`

**Purpose:** Sort lines of text, alphabetically by default.

```bash
sort data.txt
```

This prints sorted output to the terminal. It does not modify `data.txt`.

Useful examples:

```bash
sort data.txt
sort data.txt > output.txt
sort data.txt | uniq -c
```

The second command saves the sorted result to `output.txt`. The third counts consecutive identical lines after sorting.

### Overwriting the input file intentionally

```bash
sort data.txt -o data.txt
```

The `-o` option specifies the output file. `sort` supports using the same file as input and output.

**Remember:** `>` redirects output to a file and can overwrite that file. It does not mean “show output in the terminal.”

---

## 9. Removing or counting adjacent duplicates — `uniq`

**Purpose:** Process consecutive identical lines.

```bash
uniq data.txt
```

By default, `uniq` collapses consecutive duplicate lines into one line.

### Common options

```bash
uniq -c data.txt
```

Prefix each output line with its number of consecutive occurrences.

```bash
uniq -d data.txt
```

Print only lines that have adjacent duplicates.

```bash
uniq -u data.txt
```

Print only lines that occur once in their consecutive group.

### Why `sort` and `uniq` are often used together

Suppose `data.txt` contains:

```text
apple
banana
apple
apple
orange
banana
```

Running:

```bash
uniq data.txt
```

does not merge all occurrences of `apple` because the lines are not adjacent.

Running:

```bash
sort data.txt | uniq
```

sorts the lines first, bringing identical lines together, and then collapses consecutive duplicates.

Running:

```bash
sort data.txt | uniq -c
```

counts each distinct line.

For the Bandit Level 8 → 9 challenge, the useful command is:

```bash
sort data.txt | uniq -u
```

It identifies the line that occurs exactly once in the sorted data.

---

## 10. Pipes — `|`

**Purpose:** Send the standard output of one command to the standard input of another command.

Example:

```bash
sort data.txt | uniq -u
```

Execution flow:

1. `sort data.txt` reads the file and produces sorted lines.
2. `|` passes those lines to the next command.
3. `uniq -u` prints lines that occur only once in consecutive groups.

Another example:

```bash
cat data.txt | grep "millionth"
```

**Important:** A pipe does not create an output file by itself. Unless redirected, the final command's output normally appears in the terminal.

---

## 11. Output redirection — `>` and `>>`

### `>` — Write output to a file

```bash
sort data.txt > output.txt
```

Creates `output.txt` if it does not exist, or overwrites it if it already exists.

### `>>` — Append output to a file

```bash
echo "hello" >> output.txt
```

Adds the text to the end of the file instead of replacing its existing contents.

### Terminal versus file output

```bash
sort data.txt
```

Prints the sorted result to the terminal.

```bash
sort data.txt > output.txt
```

Writes the result to a file instead.

The original `data.txt` remains unchanged in both cases.

---

## 12. Supplying text directly — `printf`, heredocs, and `Ctrl+D`

### `printf`

Prints formatted text:

```bash
printf "hello\nworld\n"
```

The `\n` characters create line breaks.

### Heredoc piped into a command

```bash
cat <<'EOF' | sort | uniq -u
apple
banana
apple
orange
EOF
```

This supplies several lines directly to a command pipeline without creating an input file.

For the example above, `uniq -u` prints `banana` and `orange`, because `apple` occurs twice after sorting.

### `Ctrl+D`

In a terminal, `Ctrl+D` signals end-of-file when the terminal is reading input. It can finish interactive input for commands that read from standard input.

---

## 13. Secure remote login — `ssh`

**Purpose:** Connect to another machine through an encrypted SSH connection.

General syntax:

```bash
ssh username@hostname
```

For the OverTheWire Bandit server:

```bash
ssh bandit0@bandit.labs.overthewire.org -p 2220
```

The important parts:
- `ssh` — starts the SSH client.
- `bandit0` — username.
- `bandit.labs.overthewire.org` — remote hostname.
- `-p 2220` — connect to port 2220 rather than the default SSH port 22.

For later levels, change the username:

```bash
ssh bandit8@bandit.labs.overthewire.org -p 2220
ssh bandit9@bandit.labs.overthewire.org -p 2220
```

Each Bandit level uses the password obtained from the previous level.

### Connecting to your own computer

```bash
ssh "$USER"@127.0.0.1
```

Here:
- `$USER` expands to your current username in the shell.
- `127.0.0.1` is the loopback address, meaning the same computer.

This requires an SSH server listening on the target port.

---

## 14. Reading SSH connection details — `SSH_CONNECTION`

`SSH_CONNECTION` is an environment variable, not a command.

```bash
echo "$SSH_CONNECTION"
```

Inside an SSH session, it normally contains four fields:

```text
client_ip client_port server_ip server_port
```

For example, an SSH connection from the same computer may show loopback addresses.

This variable is useful for understanding which client and server addresses and ports are involved in the current SSH session.

---

## 15. Essential shell concepts

### Relative and absolute paths

```bash
cat data.txt
cat /var/lib/dpkg/info/bandit7.password
```

The first uses a relative path. The second uses an absolute path starting from `/`.

### Spaces in filenames

```bash
cat "my file.txt"
cat my\ file.txt
```

Both forms allow the shell to treat the spaces as part of the filename.

### Hidden filenames

```bash
ls -a
```

Shows hidden entries, including names beginning with `.`.

### Command chaining

```bash
sort data.txt | uniq -u
```

This combines two commands into a pipeline without storing an intermediate result in a file.

---

## Quick revision table

| Command / symbol | Main purpose |
|---|---|
| `man` | Read command documentation |
| `pwd` | Show current directory |
| `ls` | List files and directories |
| `cd` | Change directory |
| `cat` | Display or concatenate file contents |
| `whoami` | Show current username |
| `stat` | Inspect file metadata |
| `grep` | Search text patterns |
| `find` | Search the filesystem |
| `sort` | Sort lines |
| `uniq` | Process consecutive duplicate lines |
| `ssh` | Connect to a remote machine securely |
| `echo` | Print text or variable values |
| `printf` | Print formatted text |
| `|` | Pipe output into another command |
| `>` | Redirect output, replacing a file's contents |
| `>>` | Redirect output, appending to a file |
| `-` | Often introduces an option; meaning depends on context |
| `./` | Refer to a path in the current directory |
| `..` | Refer to the parent directory |
| `~` | Refer to the current user's home directory |
| `Ctrl+D` | Signal end-of-file in terminal input |

---

## Practice routine

For every new command you learn:

1. Run `man command`.
2. Try the simplest form of the command.
3. Experiment with one option at a time.
4. Combine commands using pipes.
5. Check whether a command changes files or only displays output.

**Bandit commands worth remembering together:**

```bash
grep "millionth" data.txt
find . -type f -size 1033c ! -executable
sort data.txt | uniq -u
sort data.txt | uniq -c
ssh bandit9@bandit.labs.overthewire.org -p 2220
```

These examples cover searching for text, locating files by properties, processing repeated lines, and connecting to the next Bandit level.


TR COMMAND (Linux)
=================

Purpose
-------
`tr` stands for translate. It reads text from standard input and writes the
transformed text to standard output. It can translate characters, delete
characters, and squeeze repeated characters.

General syntax
--------------
    tr [OPTION]... SET1 [SET2]

- SET1: characters to match.
- SET2: replacement characters (used for translation).
- OPTIONS: flags that change the behavior.
- Input usually comes from a pipe (`|`) or redirection (`<`).
- Output goes to the terminal unless redirected with `>`.

1. Translate characters
-----------------------
Syntax:
    tr 'SET1' 'SET2'

Characters are mapped by position.

Example:
    echo "hello world" | tr 'a-z' 'A-Z'
Output:
    HELLO WORLD

Example:
    echo "abc" | tr 'abc' 'xyz'
Output:
    xyz

2. Character ranges
-------------------
Ranges such as `a-z`, `A-Z`, and `0-9` represent characters in those ranges.

Example:
    echo "a1b2c3" | tr '0-9' '9876543210'
Output:
    a9b8c7

3. Delete characters: -d
------------------------
`-d` deletes characters that appear in SET1. SET2 is not used.

Example:
    echo "hello123world456" | tr -d '0-9'
Output:
    helloworld

4. Squeeze repeated characters: -s
----------------------------------
`-s` reduces each consecutive run of selected characters to one character.

Example:
    echo "heyyy    there" | tr -s ' y'
Output:
    hey there

Example:
    echo "aaabbbccc" | tr -s 'abc'
Output:
    abc

5. Complement: -c or -C
-----------------------
`-c` complements SET1 by bytes; `-C` complements SET1 by characters.
With `-d`, this can delete everything except the selected set.

Example:
    echo "abc123" | tr -cd 'a-z'
Output:
    abc

6. Character classes
--------------------
Common classes include:
    [:lower:]   lowercase letters
    [:upper:]   uppercase letters
    [:digit:]   digits
    [:alpha:]   alphabetic characters
    [:alnum:]   letters and digits
    [:space:]   whitespace
    [:punct:]   punctuation

Use the class inside single quotes, including its brackets.

Example:
    echo "Hello123WORLD" | tr '[:upper:]' '[:lower:]'
Output:
    hello123world

7. ROT13 (Bandit Level 11 -> 12)
--------------------------------
ROT13 rotates each English letter by 13 positions.

Command:
    cat data.txt | tr 'A-Za-z' 'N-ZA-Mn-za-m'

This maps uppercase A-Z to N-Z followed by A-M, and lowercase a-z
to n-z followed by a-m. Numbers, spaces, and punctuation remain unchanged.
ROT13 applied twice restores the original text.

8. Pipes and redirection
------------------------
A pipe (`|`) sends one command's output to another command.

Example:
    cat data.txt | tr 'a-z' 'A-Z'

Save transformed output to a new file:
    cat data.txt | tr 'a-z' 'A-Z' > output.txt

`>` redirects output to a file, creating it or overwriting it. These commands
do not modify the original `data.txt`.

Notes and rules
---------------
- `tr` transforms individual characters, not words or regular-expression
  patterns. Use `grep` to search for text patterns.
- SET1 and SET2 are matched by position.
- If SET2 is shorter than SET1, its final character is repeated to fill the
  mapping. Avoid relying on this unless you intend it.
- If SET2 is longer than SET1, extra characters in SET2 are ignored.
- Quote sets, especially when they contain spaces or shell-special characters.
- `tr` does not normally take a filename as an argument; feed it input through
  a pipe or redirection.

Quick reference
--------------
    tr 'a-z' 'A-Z'        # lowercase -> uppercase
    tr 'A-Z' 'a-z'        # uppercase -> lowercase
    tr -d '0-9'           # delete digits
    tr -s ' '             # squeeze repeated spaces
    tr -cd '0-9'          # keep digits only
    tr 'A-Za-z' 'N-ZA-Mn-za-m'  # ROT13





