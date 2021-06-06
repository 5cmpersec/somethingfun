load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "system",
    hdrs = glob([
        "Config.hpp",
        "System.hpp",
        "System/*",
    ]),
    include_prefix = "SFML",
    visibility = ["//visibility:public"],
    deps =[
        "@sfml_lib//:system",
    ]
)

cc_library(
    name = "window",
    hdrs = glob([
        "Window.hpp",
        "Window/*",
    ]),
    include_prefix = "SFML",
    deps = [
        ":system",
        "@sfml_lib//:window",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "graphics",
    hdrs = glob([
        "Graphics.hpp",
        "Graphics/*",
    ]),
    include_prefix = "SFML",
    deps = [
        ":window",
        ":system",
        "@sfml_lib//:graphics",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "audio",
    hdrs = glob([
        "Audio.hpp",
        "Audio/*",
    ]),
    include_prefix = "SFML",
    deps = [
        ":system",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "network",
    hdrs = glob([
        "Network.hpp",
        "Network/*",
    ]),
    include_prefix = "SFML",
    deps = [
        ":system",
    ],
    visibility = ["//visibility:public"],
)