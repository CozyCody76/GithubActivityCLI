# Roadmap.sh Project 

https://roadmap.sh/projects/github-user-activity

# GithubActivityCLI

A small C++/Python project that fetches GitHub activity and stores it in `events.json`.

## Components

- **main.cpp** - C++ command-line interface.
- **fetch.py** - Python script for downloading data.
- **json.hpp** - Header-only JSON library.
- **events.json** - Output data file.

## Usage

1. Run `fetch.py` with Python to update `events.json`.
2. Build and execute `main.cpp` using your C++ compiler.

This is a simple example project for working with GitHub API responses in C++ and Python.

## Example

```sh
# Fetch GitHub activity for a user
python fetch.py your-username

# Build the C++ CLI
g++ main.cpp -o github-activity-cli

# Run the CLI to process and display activity
./github-activity-cli
```