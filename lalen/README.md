# Lalen

A minimal, lightweight dotfiles manager that leverages Git's bare repository functionality to track configuration files across your entire system without cluttering your home directory.
It is heavily inspired by `chezmoi` but create it solely for levaraging my learnings.

## What is Lalen?

Lalen is a simple wrapper around Git that allows you to version control your dotfiles and configuration files from anywhere in your system. Unlike traditional dotfiles managers that use symbolic links or copy files, Lalen uses Git's `--git-dir` and `--work-tree` options to create a bare repository that treats your home directory (or any directory) as the working tree.

## Features

- **Minimal overhead** - Just a thin wrapper around Git
- **No symbolic links** - Files remain in their original locations
- **Full Git power** - All Git commands available through `lalen`
- **System-wide tracking** - Manage files from anywhere in your system
- **Clean home directory** - Repository data stored in `~/.lalen`
- **Cross-platform** - Works on Linux, macOS, and other Unix-like systems

## Requirements

- Git 1.7.0 or later (recommended: Git 2.0+)
- C compiler (gcc, clang, etc.)
- POSIX-compliant system (Linux, macOS, BSD, etc.)

## Installation

### From Source

```bash
# Clone the repository
git clone https://github.com/taitesen/lalen.git
cd lalen

# Build and install
make
sudo make install
```

This installs `lalen` to `/usr/local/bin/lalen`.

### Manual Installation

```bash
# Build only
make

# Copy to a directory in your PATH
cp build/lalen ~/.local/bin/
# or
sudo cp build/lalen /usr/local/bin/
```

## Quick Start

### 1. Initialize Repository

```bash
# Initialize lalen repository
lalen init
```

This creates a bare Git repository at `~/.lalen` and configures it to use your home directory as the working tree.

### 2. Add Your First Dotfile

```bash
# Add a configuration file
lalen add ~/.bashrc
lalen add ~/.vimrc
lalen add ~/.gitconfig

# Or add entire directories
lalen add ~/.config/nvim
lalen add ~/.config/tmux
```

### 3. Commit Your Changes

```bash
# Commit the files
lalen commit -m "Add initial dotfiles"
```

### 4. Connect to Remote Repository (Optional)

```bash
# Add remote repository
lalen remote add origin https://github.com/yourusername/dotfiles.git

# Push to remote
lalen push -u origin main
```

## Usage

Lalen accepts all standard Git commands. Simply replace `git` with `lalen`:

### Basic Operations

```bash
# Check status
lalen status

# Add files
lalen add ~/.zshrc
lalen add ~/.config/alacritty/alacritty.yml

# Commit changes
lalen commit -m "Update shell configuration"

# Push changes
lalen push

# Pull updates
lalen pull
```

### Advanced Operations

```bash
# View history
lalen log --oneline

# Show differences
lalen diff
lalen diff ~/.vimrc

# Create branches
lalen checkout -b experimental
lalen checkout main

# Restore files
lalen checkout -- ~/.bashrc
lalen restore ~/.vimrc

# Remove files from tracking
lalen rm --cached ~/.config/sensitive-file
```

### Useful Commands

```bash
# List all tracked files
lalen ls-files

# Show file status in detail
lalen status --porcelain

# View repository configuration
lalen config --list

# Add remote repositories
lalen remote -v
```

## Configuration

### Git Configuration

Since Lalen uses Git underneath, you can configure it using standard Git commands:

```bash
# Set user information
lalen config user.name "Your Name"
lalen config user.email "your.email@example.com"

# Set default branch
lalen config init.defaultBranch main

# Configure push behavior
lalen config push.default simple
```

### Ignoring Files

By default, Lalen is configured with `status.showUntrackedFiles=no` to prevent your home directory from being cluttered with untracked files in `lalen status`. You can still add a `.gitignore` file:

```bash
# Create a .gitignore in your home directory
echo "*.log" >> ~/.gitignore
echo ".DS_Store" >> ~/.gitignore
echo "node_modules/" >> ~/.gitignore

# Add it to tracking
lalen add ~/.gitignore
lalen commit -m "Add gitignore"
```

## Setting Up on a New Machine

### Method 1: Clone and Setup

```bash
# Clone your dotfiles
git clone --bare https://github.com/yourusername/dotfiles.git ~/.lalen

# Create temporary alias
alias lalen='git --git-dir=$HOME/.lalen --work-tree=$HOME'

# Configure to not show untracked files
lalen config --local status.showUntrackedFiles no

# Checkout files (backup existing files if conflicts occur)
lalen checkout

# Install lalen binary
# ... (follow installation steps)
```

### Method 2: Using Lalen Binary

If you already have `lalen` installed on the new machine:

```bash
# Initialize new repository
lalen init

# Add your remote
lalen remote add origin https://github.com/yourusername/dotfiles.git

# Pull your dotfiles
lalen pull origin main
```

## Best Practices

### 1. Start Small
Begin by tracking a few essential files:
```bash
lalen add ~/.bashrc ~/.vimrc ~/.gitconfig
lalen commit -m "Add core dotfiles"
```

### 2. Organize with Directories
Track entire configuration directories:
```bash
lalen add ~/.config/nvim
lalen add ~/.config/tmux
lalen add ~/.config/git
```

### 3. Use Meaningful Commit Messages
```bash
lalen commit -m "nvim: add LSP configuration"
lalen commit -m "tmux: update key bindings"
lalen commit -m "shell: add custom aliases"
```

### 4. Regular Backups
```bash
# Daily backup routine
lalen add -u  # Add all modified tracked files
lalen commit -m "Daily backup $(date)"
lalen push
```

### 5. Use Branches for Experiments
```bash
lalen checkout -b new-vim-config
# ... make changes ...
lalen add ~/.vimrc
lalen commit -m "Experiment with new vim config"
lalen checkout main
lalen merge new-vim-config
```

## Common Workflows

### Daily Development
```bash
# Check what's changed
lalen status

# Add modified files
lalen add ~/.vimrc ~/.zshrc

# Commit with descriptive message
lalen commit -m "Update editor and shell configs"

# Push to remote
lalen push
```

### Trying New Configurations
```bash
# Create experimental branch
lalen checkout -b experiment

# Make changes and commit
lalen add ~/.config/nvim/init.lua
lalen commit -m "Try new nvim colorscheme"

# If you like it, merge back
lalen checkout main
lalen merge experiment

# If not, just switch back
lalen checkout main
```

## Troubleshooting

### Repository Already Exists
If you see "lalen repository already exists":
```bash
# Check status
lalen status

# If you want to reinitialize, remove the directory first
rm -rf ~/.lalen
lalen init
```

### File Conflicts on New Machine
```bash
# Backup existing files
mkdir ~/dotfiles-backup
mv ~/.bashrc ~/dotfiles-backup/
mv ~/.vimrc ~/dotfiles-backup/

# Then checkout
lalen checkout
```

### Untracked Files Showing Up
This shouldn't happen due to the default configuration, but if it does:
```bash
lalen config --local status.showUntrackedFiles no
```

### Permission Issues
```bash
# If you get permission errors during installation
sudo make install

# Or install to user directory
make
cp build/lalen ~/.local/bin/
```

## Advanced Usage

### Multiple Profiles
You can create different lalen repositories for different purposes:

```bash
# Work configuration
LALEN_DIR=~/.lalen-work lalen init
LALEN_DIR=~/.lalen-work lalen add ~/work-configs/

# Personal configuration
LALEN_DIR=~/.lalen-personal lalen init
LALEN_DIR=~/.lalen-personal lalen add ~/.personal-configs/
```

### System-wide Configuration
Track system configuration files (requires appropriate permissions):

```bash
# Track system configs (be careful!)
sudo lalen add /etc/nginx/nginx.conf
sudo lalen add /etc/systemd/system/myservice.service
```

## Comparison with Other Tools

| Feature | Lalen | Chezmoi | GNU Stow | Dotbot |
|---------|-------|---------|----------|--------|
| Complexity | Minimal | Feature-rich | Simple | Moderate |
| Learning Curve | Low (if you know Git) | High | Low | Moderate |
| File Management | Direct Git | Templates/transforms | Symlinks | Symlinks/copy |
| Flexibility | High (full Git) | Very High | Low | Moderate |
| Dependencies | Git only | Go binary | Perl | Python |

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

### Development

```bash
# Clone the repository
git clone https://github.com/yourusername/lalen.git
cd lalen

# Build
make

# Test
make test

# Clean
make clean
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Inspired by the bare Git repository method popularized by various dotfiles management tutorials
- Built as a simpler alternative to more complex dotfiles managers
- Thanks to the Git developers for creating such a flexible version control system

## Support

If you encounter any issues or have questions:

1. Check the [Issues](https://github.com/yourusername/lalen/issues) page
2. Create a new issue with detailed information about your problem
3. Include your system information and the output of `lalen --version`

---

**Happy dotfile management!** 🎉
