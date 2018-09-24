# DEFCON Warning System CLI
A simple CLI application written in C. Fetches the current DEFCON level assigned by hobbyist Thomas Lonely Wolf.

#### DISCLAIMER: I am not affiliated nor do I necessarily agree with [The DEFCON Warning System](defconwarningsystem.com). This tool is being developed as a project to benefit anyone who might derive use out of it.

Taken from their website:

> The DEFCON Warning System is a private intelligence organization which has monitored and assessed nuclear threats against the United States by national entities since 1984. It is not affiliated with any government agency and does not represent the alert status of any military branch. The public should make their own evaluations and not rely on the DEFCON Warning System for any strategic planning. At all times, citizens are urged to learn what steps to take in the event of a nuclear attack.

## To compile:

Of course you can compile it according to your usual habits. But for newbies to C (like myself), this may be helpful:

Install `gcc`
### GNU/Linux
  #### Debian/Ubuntu-based distros
  ```bash
  sudo apt-get install gcc
  ```
  #### Arch-based distros
  ```bash
  sudo pacman -S gcc
  ```
  or
  ```bash
  yaourt gcc
  ```
### Mac OS X/macOS
  #### Homebrew
  ```bash
  brew install gcc
  ```
__________
Run the following command to compile `main.c` into an executable
```bash
gcc PATH_TO_main.c -o YOUR_NEW_FILE
```
