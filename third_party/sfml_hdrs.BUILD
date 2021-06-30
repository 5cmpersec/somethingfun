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
    deps = [
        "@sfml_lib//:system",
    ],
)

cc_library(
    name = "window",
    hdrs = glob([
        "Window.hpp",
        "Window/*",
    ]),
    include_prefix = "SFML",
    visibility = ["//visibility:public"],
    deps = [
        ":system",
        "@sfml_lib//:window",
    ],
)

cc_library(
    name = "graphics",
    hdrs = glob([
        "Graphics.hpp",
        "Graphics/*",
    ]),
    include_prefix = "SFML",
    visibility = ["//visibility:public"],
    deps = [
        ":system",
        ":window",
        "@sfml_lib//:graphics",
    ],
)

cc_library(
    name = "audio",
    hdrs = glob([
        "Audio.hpp",
        "Audio/*",
    ]),
    include_prefix = "SFML",
    visibility = ["//visibility:public"],
    deps = [
        ":system",
        "@sfml_lib//:audio",
    ],
)

cc_library(
    name = "network",
    hdrs = glob([
        "Network.hpp",
        "Network/*",
    ]),
    include_prefix = "SFML",
    visibility = ["//visibility:public"],
    deps = [
        ":system",
        "@sfml_lib//:audio",
    ],
)
