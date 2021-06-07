load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "ftxui",
    srcs = glob(
        [
            "src/ftxui/dom/*.hpp",
            "src/ftxui/component/*.hpp",
            "src/ftxui/screen/*.cpp",
            "src/ftxui/dom/*.cpp",
            "src/ftxui/component/*.cpp",
        ],
        exclude = ["src/ftxui/**/*_test.cpp"],
    ),
    hdrs = glob([
        "include/ftxui/util/*.hpp",
        "include/ftxui/screen/*.hpp",
        "include/ftxui/dom/*.hpp",
        "include/ftxui/component/*.hpp",
    ]),
    includes = [
        "include",
        "src",
    ],
    linkopts = ["-lpthread"],
    linkstatic = True,
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
