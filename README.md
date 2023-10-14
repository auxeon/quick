# Quick

BUCK2 build system starter project

[INSTRUCTIIONS TO INSTALL BUCK2](
https://buck2.build/docs/getting_started/#installing-buck2)

### BUCK2 steps
To create a new BUCK2 project use
```
buck2 init --git
```

Once done just copy the BUCK files, scripts from this repo into your local folder that you just created above

## C++ steps
To run c++ code
```
buck2 run //:app
```

To test c++ code
```
buck2 test //:test
```

## Python steps
Update requirements.txt if you'd like to install a package in venv
Before running python code setup venv using
```
buck2 clean
buck2 build //:py_install_venv
```

To uninstall venv use
```
buck2 build //:py_uninstall_venv
```
To run python code
```
buck2 run //:py_app
```

To test python code
```
buck2 test //:py_test
```

## Tests
To run all tests in the project
```
buck2 test //...
```

## Scripts
You can find helper scripts that wrap above commands here
```
scripts/
```