# Linux Command Master List
## OverTheWire Bandit + Ubuntu + SSH Networking

**Legend**

- ★★★★★ — Essential; use regularly
- ★★★★☆ — Very useful; practice often
- ★★★☆☆ — Specialized; use when needed

---

# Category 1: Everyday Linux Commands

These are the foundation of working in a Linux terminal. Learn these first.

### 1. `pwd` — Print working directory ★★★★★

Shows the directory you are currently in.

```bash
pwd
```

### 2. `ls` — List directory contents ★★★★★

```bash
ls
ls -l       # Detailed listing
ls -a       # Include hidden files
ls -la      # Detailed listing including hidden files
ls -lh      # Human-readable file sizes
```

### 3. `cd` — Change directory ★★★★★

```bash
cd /tmp       # Enter /tmp
cd ..         # Parent directory
cd ~          # Home directory
cd -          # Previous directory
cd dir_name   # Enter a subdirectory
```

### 4. `cat` — Read and concatenate files ★★★★★

```bash
cat data.txt
cat file1 file2
cat -- -filename
```

Useful for reading Bandit passwords, text files, and command output.

### 5. `file` — Identify file types ★★★★★

```bash
file data.txt
file data.bin
file *
```

Identifies file formats from their contents, not merely their extensions. Particularly useful in Bandit Levels 9–13.

### 6. `man` — Read manual pages ★★★★★

```bash
man grep
man find
man ssh
man openssl
```

Use `/pattern` to search within a manual and `q` to exit.

### 7. `whoami` — Identify the current user ★★★★☆

```bash
whoami
```

Useful when switching between Bandit accounts.

### 8. `stat` — Inspect file metadata ★★★☆☆

```bash
stat data.txt
```

Displays file size, ownership, permissions, and timestamps.

---

# Category 2: Searching and Processing Text

These commands are extremely useful in competitive Linux challenges, log analysis, and automation.

### 9. `grep` — Search text ★★★★★

```bash
grep "pattern" data.txt
grep -i "hello" data.txt
grep -n "hello" data.txt
grep -r "pattern" directory/
```

- `-i`: ignore case.
- `-n`: show line numbers.
- `-r`: search recursively.

### 10. `find` — Search for files ★★★★★

```bash
find . -type f
find . -type d
find . -type f -name "*.txt"
find . -type f -size 1033c
find . -type f ! -executable
```

Combine conditions to locate files based on their name, type, size, permissions, owner, and more.

### 11. `sort` — Sort lines ★★★★★

```bash
sort data.txt
sort data.txt | uniq
sort data.txt | uniq -c
```

Useful before counting duplicate lines.

### 12. `uniq` — Handle repeated lines ★★★★★

```bash
uniq data.txt
uniq -c data.txt
uniq -d data.txt
uniq -u data.txt
```

Important: `uniq` detects consecutive duplicates. Use `sort` first when duplicates may be scattered throughout a file.

### 13. `strings` — Extract readable strings ★★★★☆

```bash
strings data.bin
strings data.bin | grep "pattern"
```

Extracts printable character sequences from binary files. This was important in Bandit Level 9 → 10.

### 14. `tr` — Translate or delete characters ★★★★☆

```bash
tr 'a-z' 'A-Z' < data.txt
tr 'A-Z' 'a-z' < data.txt
tr 'A-Za-z' 'N-ZA-Mn-za-m' < data.txt
tr -d ' ' < data.txt
```

The third example implements ROT13, used in Bandit Level 11 → 12.

- `tr SET1 SET2`: translate characters.
- `tr -d SET`: delete specified characters.
- `tr -s SET`: squeeze repeated characters.

### 15. `diff` — Compare files ★★★★☆

```bash
diff passwords.old passwords.new
diff -u passwords.old passwords.new
```

Shows differences between files. Useful for Bandit Level 17 → 18, where one line differs between two password files.

### 16. `echo` — Print text or variables ★★★★☆

```bash
echo "Hello Linux"
echo "$HOME"
echo "$SSH_CONNECTION"
```

For more predictable formatting, especially when including escape sequences, prefer `printf`.

### 17. `printf` — Format output ★★★★☆

```bash
printf "Hello\nWorld\n"
printf '%s\n' "$HOME"
```

Useful in shell scripts and when generating exact text.

---

# Category 3: File Formats, Encoding and Compression

These commands are particularly important for Bandit Levels 9–13.

### 18. `base64` — Encode and decode Base64 ★★★★☆

```bash
base64 data.txt
base64 -d data.txt
```

Decode Base64-encoded content with `-d`. This was used in Bandit Level 10 → 11.

### 19. `xxd` — Inspect binary data in hexadecimal ★★★★☆

```bash
xxd data.bin
xxd -l 32 data.bin
xxd -r data.hex
```

- `xxd file`: hexadecimal dump.
- `xxd -l 32 file`: show the first 32 bytes.
- `xxd -r`: reverse a hexadecimal dump into binary data.

Useful when a file has to be identified or reconstructed from a hexadecimal representation.

### 20. `gzip` — Compress and decompress files ★★★★☆

```bash
gzip file.txt
gzip -d file.txt.gz
gunzip file.txt.gz
```

Compression normally replaces the original file with its compressed version.

### 21. `bzip2` — Bzip2 compression ★★★★☆

```bash
bzip2 file.txt
bzip2 -d file.txt.bz2
bunzip2 file.txt.bz2
```

Useful when dealing with `.bz2` files.

### 22. `tar` — Archive files ★★★★☆

```bash
tar -cf archive.tar file.txt
tar -tf archive.tar
tar -xf archive.tar
```

- `-c`: create an archive.
- `-t`: list archive contents.
- `-x`: extract.
- `-f`: specify the archive filename.

Inspect an archive before extracting it when you are unsure what it contains.

### 23. `mktemp` — Create temporary files or directories ★★★☆☆

```bash
mktemp
mktemp -d
```

Creates a temporary file or directory with a unique name. This is useful when solving Bandit challenges involving nested archives and intermediate files.

---

# Category 4: Networking and Remote Access

These are essential for understanding how Linux machines communicate and how you access Bandit remotely.

### 24. `ssh` — Secure Shell ★★★★★

```bash
ssh username@hostname
ssh bandit0@bandit.labs.overthewire.org -p 2220
```

Creates an encrypted remote terminal session.

- `username`: remote account.
- `hostname`: server address.
- `-p`: SSH port.

### 25. `scp` — Secure file copy ★★★★☆

```bash
scp -P 2220 user@host:~/file .
scp -P 2222 file.txt user@host:~/destination/
```

Copies files between machines using SSH.

**Important:** `scp` uses uppercase `-P` for the port, while `ssh` uses lowercase `-p`.

### 26. `nc` / `netcat` — TCP and UDP networking ★★★★★

```bash
nc localhost 30000
nc -l 12345
```

The first connects to a service on the local machine. The second listens on port 12345 on systems where this option is supported.

We discussed how Netcat establishes TCP connections and how two terminal sessions can exchange messages.

Useful for:
- Testing network services.
- Sending text to a TCP service.
- Learning client/server communication.
- Solving Bandit levels that use local ports.

### 27. `openssl` — Cryptographic toolkit ★★★★☆

```bash
openssl version
openssl s_client -connect localhost:30001
openssl s_client -connect localhost:30001 -quiet
```

`openssl` provides tools for TLS connections, cryptographic operations, certificates, and keys.

### 28. `openssl s_client` — Inspect TLS connections ★★★★☆

```bash
openssl s_client -connect hostname:port
openssl s_client -connect localhost:30001 -quiet
```

Connects to a TLS-enabled service and lets you interact with it.

We used this in Bandit Level 15 → 16 to send a password over SSL/TLS.

Remember: `nc` alone does not perform a TLS handshake. Use an appropriate TLS client when the service requires encryption.

### 29. `nmap` — Network and port scanning ★★★★☆

```bash
nmap localhost
nmap -p 31000-32000 localhost
```

Scans hosts and ports to identify network services. This is useful for the Bandit level that asks you to find a service among a range of ports.

Only scan systems and networks you own or are authorized to test.

---

# Category 5: Permissions, Users and Security

These concepts matter increasingly as you progress through Bandit.

### 30. `chmod` — Change file permissions ★★★★☆

```bash
chmod u+x script.sh
chmod 700 private_file
chmod 644 public_file
```

- `u+x`: add execute permission for the owner.
- `700`: owner has read, write, and execute; group and others have no permissions.
- `644`: owner has read/write; group and others have read access.

We discussed Linux file permissions and how executable files can affect access to privileged operations.

### 31. `./bandit20-do` — Run the Bandit privilege helper ★★★★☆

```bash
./bandit20-do whoami
./bandit20-do cat /etc/bandit_pass/bandit20
```

This is a specific executable supplied by the Bandit challenge, not a general Linux command.

The `./` tells the shell to execute the program from the current directory. The helper runs the supplied command with the identity and privileges configured for that challenge.

### 32. `ls -l` — Inspect permissions ★★★★★

```bash
ls -l
ls -l /etc/bandit_pass/
```

A listing such as:

```text
-rwxr-xr-x
```

indicates read, write, and execute permissions for the owner, followed by permissions for the group and others.

### 33. `echo "$SSH_CONNECTION"` — Inspect SSH session information ★★★☆☆

```bash
echo "$SSH_CONNECTION"
```

Inside an SSH session, the variable normally contains the client IP, client port, server IP, and server port.

This is an environment variable, not an independent Linux command.

---

# Category 6: Shell Operators and Fundamental Syntax

These aren't standalone commands, but they are among the most important things we've learned.

### 34. Pipe — `|` ★★★★★

```bash
sort data.txt | uniq -u
strings data.bin | grep "password"
```

Passes one command's standard output to another command's standard input.

### 35. Output redirection — `>` and `>>` ★★★★★

```bash
sort data.txt > sorted.txt
echo "hello" >> notes.txt
```

- `>` writes output and normally overwrites the destination.
- `>>` appends output.

### 36. Input redirection — `<` ★★★★☆

```bash
tr 'a-z' 'A-Z' < data.txt
```

Feeds a file to a command through standard input.

### 37. Absolute and relative paths ★★★★★

```bash
cat /etc/hostname
cat ./data.txt
cd ..
cd ~
```

- `/etc/hostname`: absolute path.
- `./data.txt`: path relative to the current directory.
- `..`: parent directory.
- `~`: current user's home directory.

### 38. Quoting and escaping ★★★★★

```bash
cat "file with spaces.txt"
cat file\ with\ spaces.txt
cat -- -filename
```

Quotes and backslashes help the shell interpret filenames correctly. The `--` argument tells many commands that subsequent arguments are not options.

### 39. Environment variables ★★★★☆

```bash
echo "$HOME"
echo "$USER"
echo "$PATH"
```

Environment variables store information about the current shell environment. `$PATH` contains directories searched for executable commands.

### 40. Heredocs and `Ctrl+D` ★★★☆☆

```bash
cat <<'EOF'
first line
second line
EOF
```

A heredoc supplies multiple lines of input directly to a command.

`Ctrl+D` signals end-of-file when a terminal is reading input.

---

# Category 7: The Most Useful Command Combinations

These examples combine several commands into practical workflows.

### A. Find a file with a particular size

```bash
find . -type f -size 1033c
```

### B. Find a unique line in a file

```bash
sort data.txt | uniq -u
```

### C. Count repeated lines

```bash
sort data.txt | uniq -c
```

### D. Search binary content for readable strings

```bash
strings data.bin | grep "pattern"
```

### E. Decode Base64 content

```bash
base64 -d data.txt
```

### F. Transform text using ROT13

```bash
tr 'A-Za-z' 'N-ZA-Mn-za-m' < data.txt
```

### G. Compare two files

```bash
diff passwords.old passwords.new
```

### H. Inspect and extract an archive

```bash
file data.bin
tar -tf data.bin
tar -xf data.bin
```

Use the extraction command only after confirming that the file is a tar archive.

### I. Connect to a remote Bandit level

```bash
ssh bandit19@bandit.labs.overthewire.org -p 2220
```

### J. Connect to a TLS service

```bash
openssl s_client -connect localhost:30001 -quiet
```

---

# Learning Priority

| Priority | Commands and concepts |
|---|---|
| **Tier 1 — Daily essentials** | `pwd`, `ls`, `cd`, `cat`, `file`, `man`, `grep`, `find`, `ssh`, pipes, redirection, paths |
| **Tier 2 — Core problem-solving** | `sort`, `uniq`, `strings`, `tr`, `diff`, `base64`, `tar`, `gzip`, `bzip2`, `xxd` |
| **Tier 3 — Networking and security** | `nc`, `openssl s_client`, `nmap`, `scp`, `chmod`, file permissions, SSH keys |
| **Tier 4 — Supporting tools** | `whoami`, `stat`, `echo`, `printf`, `mktemp`, heredocs, environment variables |
| **Tier 5 — Challenge-specific** | `./bandit20-do` and other executables supplied by individual challenges |

---

## Important note

This is a consolidated reference to the commands and concepts appearing in our available project discussions, including commands used in examples. It is not a verified transcript of every command typed in every earlier message, and some entries are supporting commands rather than commands we studied in depth.

As you continue Bandit, add each new command with its purpose, syntax, options, and one example. That will make this a much more useful reference than memorizing isolated commands.
