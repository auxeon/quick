#!/bin/bash
echo "uninstallvenv.sh"
if [[ $# -ne 1 ]]; then
  echo "usage: $0 [VENV_PATH]";
  exit 1;
fi
echo 'uninstalling venv...';
cd ../../../../../../../;
if [[ -d $1 ]]; then
  rm -rf $1 -y;
fi
echo 'finished uninstalling venv...';
cd -;