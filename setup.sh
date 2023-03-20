#!/bin/bash

if [ -d "/home/$USER/.config/cbl" ]; then
    echo ".config/cbl directory is present"
else
    echo ".config/cbl directory does not exist, creating..."
    mkdir "/home/$USER/.config/cbl"
    echo "place your cbl text files in .config/cbl/..."
fi

sudo cp -fv cbl "/usr/local/bin"
