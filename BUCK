# constants
COMPATIBLE_WITH = [
    "config//os:macos",
    "config//os:linux",
    "config//os:windows",
]
PYTHON_EXE = "python3"

# cxx
cxx_binary(
    name="app",
    compatible_with=COMPATIBLE_WITH,
    srcs=[
      "app.cpp",
    ],
    include_directories=[
      ".",
    ],
    compiler_flags=[
      "-g",
    ],
    link_style = "static",
    deps=[
      "//deps:glad",
      "//deps:glfw",
    ],
)

cxx_test(
    name="test",
    compatible_with=COMPATIBLE_WITH,
    link_style="static",
    srcs=["test.cpp"],
    deps=["//deps:gtest"],
)

# python
python_library(
    name="py_app_library",
    compatible_with=COMPATIBLE_WITH,
    srcs=["app.py"],
)

python_binary(
    name="py_app",
    compatible_with=COMPATIBLE_WITH,
    main_module="app",
    deps=[
        ":py_app_library",
        ":py_install_venv",
    ],
)

python_test(
    name="py_test",
    compatible_with=COMPATIBLE_WITH,
    srcs=[
        "test.py",
    ],
    deps=[
        "//deps:gtest",
    ],
)

# genrules
sh_binary(
    name="install_venv",
    main="scripts/installvenv.sh",
)
genrule(
    name="py_install_venv",
    compatible_with=COMPATIBLE_WITH,
    out=".",
    cmd="$(exe :install_venv)" + " " + PYTHON_EXE + " venv requirements.txt",
)

sh_binary(
    name="uninstall_venv",
    main="scripts/uninstallvenv.sh",
)
genrule(
    name="py_uninstall_venv",
    compatible_with=COMPATIBLE_WITH,
    out=".",
    cmd="$(exe :uninstall_venv) venv",
)
