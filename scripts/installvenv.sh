#!/bin/bash
echo "installvenv.sh"
if [[ $# -ne 3 ]]; then
  echo "usage: $0 [PYTHON_INTERPRETER] [VENV_DIR_PATH] [REQUIREMENTS_TXT_PATH]";
  exit 1;
fi
echo 'installing venv...';
cd ../../../../../../../;
$1 -m venv $2;
if [[ -f $3 ]]; then
  $1 -m pip install -r $3;
fi
echo 'finished installing venv...';
cd -;