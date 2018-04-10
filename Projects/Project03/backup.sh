#!/bin/bash
# arg vars
argCount=$#
list=false
count=false
help=false

# case 0: no args given
if [ $argCount -eq 0 ]; then
  echo "The usage of this command is: backup [options] targetFileList"
fi

if [ ! -d ~/.backup ]; then
  echo ""
  echo "Making ~/.backup"
  mkdir ~/.backup
fi

# case 1: args specified
for var in "$@"
do
  if [ "$var" == '-nl' ] || [ "$var" == '-ln' ]; then
    list=true
    count=true
  elif [ "$var" == '-l' ]; then
    list=true
  elif [ "$var" == '-n' ]; then
    count=true
  elif [ "$var" == "--help" ]; then
    help=true
  elif [[ "$var" == -* ]]; then
    echo "backup.sh: invalid option $var"
  elif [ -f "$var" ]; then
    cp -c $var ~/.backup
    echo "$var in ~/.backup"
  elif [ -d "$var" ]; then
    cp -Rc $var ~/.backup
    echo "$var in ~/.backup"
  else
    echo ""
    echo "backup.sh: $var does not exist!"
  fi
done

# echo list files in ~/.backup
if [ "$list" == true ]; then
  list=$(ls ~/.backup)
  echo $'\nls in ~/.backup:'
  echo "$list"
fi

# echo num of files in ~/.backup
if [ "$count" == true ]; then
  filecount=$(ls ~/.backup | wc -l)
  size=$(du -hLc ~/.backup/*)
  echo ""
  echo "Num files in ~/.backup: $filecount"
  echo ""
  echo "Size of ~/.backup:"
  echo "$size"
fi

# echo help menu
if [ "$help" == true ]; then
  echo $'\nHelp:'
  echo "backup.sh performs a backup of files to ~/.backup"
  echo "Format:"
  echo "backup.sh [options] targetFileList"
  echo "Options:"
  echo "-l           list files in backup directory"
  echo "-n           number of files in backup directory"
  echo "-nl -ln      list files and number of files in"
  echo "--help       show help menu"
fi
