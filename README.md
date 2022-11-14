# Lab: Linux Keylogger

## C Version

Compile with gcc and run it with sudo.

```bash
make
sudo ./keylogger.out
```

## Python Version

For ubuntu server, should install dev at first.

```bash
sudo apt install python3-dev
```

Start virtual envirenment.

```bash
python3 -m venv .env
source .env/bin/activate
```

Install packages.

```bash
pip install -r requirements.txt
```

Run in sudo.

```bash
sudo ./keylogger.py
```

## Hint

Don't use it on ssh remote, because no key interrupt happenned.