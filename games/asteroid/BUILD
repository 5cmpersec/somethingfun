load("@rules_cc//cc:defs.bzl", "cc_binary")

filegroup(
    name = "resources",
    srcs = ["res"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "asteroid",
    srcs = [
        "animator.cc",
        "animator.h",
        "asset_manager.cc",
        "asset_manager.h",
        "asteroid.cc",
        "asteroid.h",
        "bullet.cc",
        "bullet.h",
        "collision.cc",
        "collision.h",
        "explosion.cc",
        "explosion.h",
        "game.cc",
        "game.h",
        "spaceship.cc",
        "spaceship.h",
        "main.cc",
    ],
    data = [":resources"],
    env = {
        "RESOURCES_DIR": "$(location :resources)",
    },
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "@sfml_hdrs//:audio",
        "@sfml_hdrs//:graphics",
        "@sfml_hdrs//:system",
        "@spdlog"
    ],
)
