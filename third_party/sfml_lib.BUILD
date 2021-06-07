load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "system",
    srcs = ["libsfml-system.so"],
    linkopts = ["-lsfml-system"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "window",
    srcs = ["libsfml-window.so"],
    linkopts = ["-lsfml-window"],
    visibility = ["//visibility:public"],
    deps = [
        ":system",
    ],
)

cc_library(
    name = "graphics",
    srcs = ["libsfml-graphics.so"],
    linkopts = ["-lsfml-graphics"],
    visibility = ["//visibility:public"],
    deps = [
        ":system",
        ":window",
    ],
)

cc_library(
    name = "audio",
    srcs = ["libsfml-audio.so"],
    linkopts = ["-lsfml-audio"],
    visibility = ["//visibility:public"],
    deps = [
        ":system",
    ],
)

cc_library(
    name = "network",
    srcs = ["libsfml-network.so"],
    linkopts = ["-lsfml-network"],
    visibility = ["//visibility:public"],
    deps = [
        ":system",
    ],
)
