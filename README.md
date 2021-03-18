# DEFCON Warning System CLI
A simple CLI application written in C. Fetches the current alert level assigned by Thomas Lonely Wolf.

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
This tool depends on `wget`. If not installed, install using above methods.
Clone this repo to your local system:
```bash
git clone https://github.com/ctwoodland/defconwarningsystem
cd defconwarningsystem
```
Run the following command to compile `main.c` into an executable
```bash
gcc main.c -o YOUR_NEW_FILE
```

From here you can copy whatever you named `YOUR_NEW_FILE` (I would recommend `defcon`) to your locally-compiled executable directory (usually /usr/local/bin/)
```bash 
sudo cp YOUR_NEW_FILE /usr/local/bin/
```

You should now be able to run the program by entering your chosen filename into the shell.
```bash

