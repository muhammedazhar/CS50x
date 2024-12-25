# Code for custom `make.sh` file

## Overview

This custom make script provides automatic Makefile selection for CS50 assignments. It determines whether to use the CS50-specific Makefile or the system default based on the current working directory.

## Installation

1. Create the scripts directory if it doesn't exist:

    ```bash
    mkdir -p ~/.scripts
    ```

2. Save the script below as `make.sh` in your scripts directory:

    ```bash
    #!/bin/bash
    # -*- coding: utf-8 -*-

    : <<'END_COMMENT'
    CS50 Makefile Selection Script
    -----------------------------
    This script handles Makefile selection logic for CS50 assignments. It automatically
    determines whether to use the CS50-specific Makefile or the default system
    Makefile based on the current working directory.

    Author: Muhammed Azhar
    Date: December 2024
    END_COMMENT

    # ------------------------------------------------------------
    # Environment Variables
    # ------------------------------------------------------------
    # Allow override via environment variable, otherwise use default path
    CS50DIR=${CS50DIR:-"$HOME/Developer/CS50x"}
    CS50MAKE="$CS50DIR/Docs/Makefile"

    # ------------------------------------------------------------
    # Directory Validation
    # ------------------------------------------------------------
    # Check if directory exists
    if [ ! -d "$CS50DIR" ]; then
        echo -e "Error: CS50 directory not found: $CS50DIR\n"
        exit 1
    fi

    # ------------------------------------------------------------
    # Makefile Selection Logic
    # ------------------------------------------------------------
    # Check if the current directory is inside the project directory
    if [[ "$(pwd)" == "$CS50DIR"* ]]; then
        # Call make with -f flag to specify the Makefile location
        /usr/bin/make -f "$CS50MAKE" "$@"
    else
        # Call the real make command normally
        /usr/bin/make "$@"
    fi
    ```

    This script is also available on [GitHub](https://github.com/muhammedazhar/muhammedazhar/blob/main/.scripts/make.sh) as file which you download it directly on local machine. Moreover, this version is more likely to be the updated from the one in the repository.

3. Make the script executable:

    ```bash
    chmod +x ~/.scripts/make.sh
    ```

4. Add the following line to your `.zshrc` file:

    ```bash
    alias make="bash /Users/muhammedazhar/.scripts/make.sh"
    ```

## Configuration

### Environment Variables

- `CS50DIR`: Path to your CS50 working directory

  - Default: `~/Developer/CS50x`
  - Can be overridden by setting the environment variable in your `.zshrc`:

    ```bash
    export CS50DIR="/path/to/your/cs50/directory"
    ```

## Usage

The script works transparently as a replacement for the standard `make` command:

- Inside CS50 project directories: Uses the CS50-specific Makefile
- Outside CS50 directories: Uses the system default make behavior

### Examples

```bash
# Build CS50 project
cd ~/Developer/CS50x/pset1
make hello

# Build non-CS50 project
cd ~/other-project
make
```

## Troubleshooting

Common issues and solutions:

1. **Script not found**:
   - Verify the script path in your alias
   - Check if the script is executable

2. **CS50 directory not found**:
   - Verify the `CS50DIR` environment variable
   - Check if the directory exists and has correct permissions

3. **Make command not working**:
   - Source your `.zshrc`: `source ~/.zshrc`
   - Verify the alias is set: `alias make`

## Contributing

Feel free to submit issues and enhancement requests.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
